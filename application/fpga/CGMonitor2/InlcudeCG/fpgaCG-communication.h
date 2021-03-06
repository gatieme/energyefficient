// 通信模块
// fpgaCG-srv-communication.h
// 这个模块就是提供一些调用接口给别的模块使用，
//服务端/客户端都是用这一个通信模块


#ifndef  fpgaCG_srv_communication

#define fpgaCG_srv_communication



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <unistd.h> // for close
 #include <arpa/inet.h>
/**************相关结构体****************************/


struct FuZhu {  //它里边的东西，都是进程相关的，不能跨进程使用
	struct sockaddr sockaddr ;
	unsigned int pid;
	int connfd; 
	
	int Sourshmid; //当前进程的shmid
	void* sourmem;
	int Tarshmid; //当前进程的shmid
	void* tarmem;
	int ConShmid; //当前进程的shmid
	void* ConMem;
	int sem_id;
	
  int illegal; //非法请求，taskReturn使用，==1时是表示非法请求

};


struct CGOptTask{
		unsigned int Optype; //操作类型，1--DES加密内存数据 
		unsigned char OptName[8]; //操作名称，DES,JPEG等 
		
		unsigned int HowT0; //向服务器申请，如何完成这项任务，必须用重构？必须不用重构？正常？最短时间？....
		
		unsigned int sourMem; //源共享内存,SHM_ID_key,跨进程有效,叫做sourShMKey更合理
		unsigned int sourOffset; //在源共享内存中的偏移
		unsigned int sourLens; //源操作数的长度
		
		unsigned int tarMem; //目的共享内存，SHM_ID_key,跨进程有效,叫做tarShMKey更合理
		unsigned int tarOffset; //目的偏移
		unsigned int tarLens; //目的操作数长度
		
		unsigned int conShMKey; //控制字段 sharemem Key
		unsigned int conOffset; //控制偏移
		unsigned int conLens; //目的操作数长度
		
		void* control; //控制字段，客户端与服务器另行约定好的，某结构体指针
		
		struct FuZhu * something; //指向辅助结构内容，就是函数传参时使用，并不在客户端与服务端传递
			
};

struct CGOptTaskReturn{
		unsigned int type; //操作类型
		unsigned char OptName[8]; //操作名称，DES,JPEG等 
		unsigned int howTo; //如何进行操作
		unsigned int portNumber; //新端口号
		unsigned int SemKey; //信号量Key
		
		struct FuZhu * something; //指向辅助结构内容，就是函数传参时使用，并不在客户端与服务端传递
			
			
};

#define SERVERPORT 2222

/*****************服务端函数**************************/

/*功能：初始化套接字
参数：无
返回值：0--正确返回
        -1 ---socket初始化错误
        -2 ---bind 错误
        -3 ---listen 错误
*/
int CGSrvInitSocket(); //初始化沟通手段，socket的初始化



/*功能：接收客户端发来的请求，解析为一个task
参数：CGOptTask结构体，OUT返回给调用方
返回值：0--正确返回
        -1 ---accept出错
        -2 ---收到请求格式不合法
        -3 ---请求太长了，超出缓冲区
*/
int CGSrvAcceptTask(struct CGOptTask *task);

/*功能：向客户端返回一个服务应答*/
int CGSrvResponseTask(struct CGOptTaskReturn* taskreturn);

/*功能：关闭套接字连接*/
int CGSrvCloseSocket(struct CGOptTask* task);

/*****************客户端函数*********************/


/*功能：初始化套接字
参数：无
返回值：0--正确返回
        -1 ---socket初始化错误
        -2 ---bind 错误
*/
int CGCliInitSocket(int *sockfd);  //客户端初始化套接字

/*功能：客户端发送一个task给服务进程
参数：CGOptTask结构体，OUT返回给调用方
返回值：0--正确返回
        -1 ---参数不合法
        -2 ---发送失败
*/
int CGCliRequestTask(int *sockfd,struct CGOptTask* task);  


/*功能：客户端接收task的返回信息
参数：CGOptTask结构体，OUT返回给调用方
返回值：0--正确返回
        -2 ---接收失败
*/
int CGCliGetReturn(struct CGOptTaskReturn *taskreturn);  

/*功能：关闭套接字连接*/
int CGCliCloseSocket(struct CGOptTask* task);





/*---------------------共享内存相关操作--------------------------*/
int CGCliShmCreate(struct CGOptTask *task);
int CGCliShmRemove(struct CGOptTask *task);
void* CGCliShmSourMem(struct CGOptTask *task,int *size);
void* CGCliShmTarMem(struct CGOptTask *task,int *size);

int CGSvrShmCreate(struct CGOptTask *task);
void* CGSvrShmSourMem(struct CGOptTask *task,int *size);
void* CGSvrShmTarMem(struct CGOptTask *task,int *size);
int CGSvrShmRemove(struct CGOptTask *task);

/*---------------------信号量相关操作--------------------------*/
int CGCliSemaphoreCreate(struct CGOptTaskReturn *task); //返回sem_id
int CGCliSemaphoreWait(int sem_id);
int CGCliSemaphoreDelete(int sem_id);

int CGSvrSemaphoreCreate(struct CGOptTaskReturn *task);
int CGSvrSemaphoreLaunch(int sem_id);
int CGSvrSemaphoreDelete(int sem_id);



int CGCliSendAsk(int *sockfd,struct CGOptTask* task);
int CGCliSend_OK(int *sockfd,struct CGOptTask* task);
int CGCliSendEcho(int *sockfd,unsigned char* optname);
int CGCliSendDone(int *sockfd,unsigned char* optname);
int CGCliSendError(int *sockfd,unsigned char* optname);
int CGCliRecvAns(int *sockfd,struct CGOptTaskReturn* task);
int CGCliRecvEcho(int *sockfd);

int CGCliRecvFinished(int *sockfd);

int CGCliCreatNewPortSocket(int* sockfd,int newPort);

int CGCliSendSetDataControl(int status);
#endif 