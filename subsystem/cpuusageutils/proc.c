/*
 *  Copyright (C) 2016-2017  gatieme <gatieme@163.com>
 *
 *  Licensed under the terms of the GNU GPL License version 2.
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <fcntl.h>
#include <unistd.h>


//#define __DEBUG__   1
#include "cpuusage.h"

#define MAX_LINE_LEN 255
#define PROC_STAT_FILE "/proc/stat"



/*  获取所有cpu的总stat信息并组织成链表             */
struct cpuusage_jiffies_stat *
proc_get_jiffies_stat_list( )
{
    unsigned int cpunums = get_nprocs( );

    FILE        *fp = NULL;
    char        buf[128];
    char        cpu[6];
    long int    user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    //long int total_jiffies_stat;
    struct cpuusage_jiffies_stat        *head_jiffies_stat_list = NULL;
    struct cpuusage_jiffies_stat        *total_jiffies_stat = NULL;
    struct cpuusage_jiffies_stat        *prev_jiffies_stat = NULL;
    struct cpuusage_jiffies_stat        *curr_jiffies_stat = NULL;


#ifdef __DEBUG__
    printf("there are %d cpus in your machine\n", cpunums);
#endif

    fp = fopen(PROC_STAT_FILE, "r");
    if(fp == NULL)
    {
        perror("fopen ");
        exit (0);
    }

	for(unsigned int cpuid = 0;
        cpuid <=  cpunums && !feof(fp);
        cpuid++)
    {
		if (!fgets(buf, sizeof(buf), fp))
        {
			goto error;
		}

		if (strlen(buf) > (MAX_LINE_LEN - 10))
        {
			goto error;
		}
#if __DEBUG__
        printf("buf=%s",buf);
#endif
        sscanf(buf,"%s%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld",
                cpu, &user, &nice, &system, &idle, &iowait,
                &irq, &softirq, &steal, &guest, &guest_nice);

#if __DEBUG__
        printf("%s, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld\n",
            cpu, user, nice, system, idle, iowait,
            irq, softirq, steal, guest, guest_nice);
#endif
        if((curr_jiffies_stat = cpuusage_set_jiffies_stat(cpu, user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice, NULL, NULL)) == NULL)
        {
            perror("error ");
            exit(-1);
        }
#define TOTAL_IN_TAIL   1
#if defined(TOTAL_IN_HEAD)      //  total stat放在链表的头部
        // 则链表的顺序为 total, cpu0, cpu1, cpu2, cpu3, ......
        if(head_jiffies_stat_list == NULL)
        {
            //  当前结点就是total结点, 作为链表的头结点
            head_jiffies_stat_list = curr_jiffies_stat;
            total_jiffies_stat = curr_jiffies_stat;
        }
        else
        {
            prev_jiffies_stat->next        = curr_jiffies_stat;
        }
        curr_jiffies_stat->next     = NULL;
        curr_jiffies_stat->first    = head_jiffies_stat_list;

        prev_jiffies_stat           = curr_jiffies_stat;
#elif defined(TOTAL_IN_TAIL)    //  total stat放在链表的尾部
        // 则链表的顺序为 cpu0, cpu1, cpu2, cpu3, total, ......
        if(head_jiffies_stat_list == NULL)  // 第一个节点
        {
            if(total_jiffies_stat == NULL)
            {
                //  当前结点就是total结点, 不作为链表的头结点
                total_jiffies_stat = curr_jiffies_stat;
                total_jiffies_stat->next = NULL;
            }
            else
            {
                //  再次读取的结点cpu0作为头结点
                head_jiffies_stat_list = curr_jiffies_stat;

                curr_jiffies_stat->next = total_jiffies_stat;
                curr_jiffies_stat->first = head_jiffies_stat_list;

                total_jiffies_stat->first = head_jiffies_stat_list;
            }
        }       //  cpu0->total
        else
        {
            curr_jiffies_stat->next     = prev_jiffies_stat->next;
            curr_jiffies_stat->first    = head_jiffies_stat_list;
            prev_jiffies_stat->next        = curr_jiffies_stat;
        }

        prev_jiffies_stat           = curr_jiffies_stat;
#endif
    }

    fclose(fp);

    // 当前链表的顺序是,
    return head_jiffies_stat_list;

error:
	fclose(fp);
	return NULL;
}





/////////////////////
/// cpuusage_jiffies_stat的处理函数
/////////////////////

/*  获取cpu的总stat信息             */
struct cpuusage_jiffies_stat *
proc_get_total_jiffies_stat( )
{
    FILE *fp = NULL;
    char buf[128];
    char cpu[6];
    long int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    //long int total_jiffies_stat;
    struct cpuusage_jiffies_stat    *jiffies_stat = NULL;

    fp = fopen(PROC_STAT_FILE, "r");
    if(fp == NULL)
    {
        perror("fopen:");
        exit (0);
    }
	if (!fgets(buf, sizeof(buf), fp))
    {
		goto error;
	}

	if (strlen(buf) > (MAX_LINE_LEN - 10))
    {
		goto error;
    }

    {
#if __DEBUG__
        printf("buf=%s",buf);
#endif
        sscanf(buf,"%s%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld",
                cpu, &user, &nice, &system, &idle, &iowait,
                &irq, &softirq, &steal, &guest, &guest_nice);

#if __DEBUG__
        printf("%s, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld\n",
            cpu, user, nice, system, idle, iowait,
            irq, softirq, steal, guest, guest_nice);
#endif

    }
    //total_jiffies_stat = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;
    fclose(fp);

    if((jiffies_stat = cpuusage_set_jiffies_stat(cpu, user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice, NULL, NULL)) == NULL)
    {
        perror("error ");
        exit(-1);
    }

    return jiffies_stat;
error:
	fclose(fp);
	return NULL;
}





/*  获取cpu的stat信息(/proc/stat)   */
struct cpuusage_jiffies_stat *
proc_get_jiffies_stat(unsigned int cpuid)
{
    FILE        *fp = NULL;
    char        buf[128];
    char        cpu[6];
    long int    user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    //long int  total_jiffies_stat;
    struct      cpuusage_jiffies_stat   *jiffies_stat = NULL;

    fp = fopen(PROC_STAT_FILE, "r");
    if(fp == NULL)
    {
        perror("fopen:");
        exit (0);
    }
	if (!fgets(buf, sizeof(buf), fp))
    {
		goto error;
	}

	if (strlen(buf) > (MAX_LINE_LEN - 10))
    {
		goto error;
    }

#if USE_LSEEK

    if (lseek(fp, offset, SEEK_CUR) == (off_t)-1)
    {
        perror("lseek failed");
        return -1;
    }
    else
    {
#else
	for(unsigned int id = 0;
        id <= cpuid && !feof(fp);
        id++)
    {
		if (!fgets(buf, sizeof(buf), fp))
        {
			goto error;
		}

		if (strlen(buf) > (MAX_LINE_LEN - 10))
        {
			goto error;
		}
#if 0   //__DEBUG__
        printf("id = %d, offset = %d\n", id, cpuid);
#endif
        if(id != cpuid)
        {
            continue;
        }
#endif
#if __DEBUG__
        printf("buf=%s",buf);
#endif
        sscanf(buf,"%s%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld",
                cpu, &user, &nice, &system, &idle, &iowait,
                &irq, &softirq, &steal, &guest, &guest_nice);

#if __DEBUG__
        printf("%s, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld\n",
            cpu, user, nice, system, idle, iowait,
            irq, softirq, steal, guest, guest_nice);
#endif
        fclose(fp);
    }

    if((jiffies_stat = cpuusage_set_jiffies_stat(cpu, user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice, NULL, NULL)) == NULL)
    {
        perror("error ");
        exit(-1);
    }
    return jiffies_stat;

error:
	fclose(fp);
	return NULL;
}



