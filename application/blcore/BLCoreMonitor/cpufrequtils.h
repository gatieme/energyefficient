#ifndef __CPUFREQUTILS_H_INCLUDE__
#define __CPUFREQUTILS_H_INCLUDE__

#include <QObject>
#include <QList>
#include <QDebug>

#ifdef __cplusplus
extern "C"
{
#endif

#include "cpufreq.h"

#ifdef __cplusplus
}
#endif


//  可用频率的链表和可用调频策略的链表有两种实现方案
//#define CNODE_IN_QLIST    //
//#define CLIST_TO_QLIST
#define USE_CLIST


/*
#if defined(CNODE_IN_QLIST)
    一种是将节点重新组织在QList中
    QList<struct cpufreq_available_frequencies *>   m_availableFrequencies;       //  可用的CPU频率值
    QList<struct cpufreq_available_governors *>     m_availableGovernors;         //  可用的CPU频率调节器
#elif defined(CLIST_TO_QLIST)
    另一种是近将节点的数据域组织在QList, 即将CLIST转换为QLIST
    QList<QString>                                     m_availableFrequencies;       //  可用的CPU频率值
    QList<unsigned long>                            m_availableGovernors;         //  可用的CPU频率调节器
#elif defined(USE_CLIST)
    另外一种方式是直接使用CLIST
    struct cpufreq_available_frequencies*           m_availableFrequencies;       //  可用的CPU频率值
    struct cpufreq_available_governors*             m_availableGovernors;         //  可用的CPU频率调节器
#endif
*/

// 每个CPU的结构体
class CpuFreqUtils : public QObject
{
    Q_OBJECT
public:
    explicit CpuFreqUtils(QObject *parent = 0, unsigned int cpuid = 0);
    virtual ~CpuFreqUtils( )
    {

    }
    friend std::ostream &operator<<(std::ostream &os, const CpuFreqUtils &info);
    friend QDebug operator<<(QDebug dbg, const CpuFreqUtils &info);



    ///////////////////////////////////////////////////////////////////
    /// 1--CPU信息CpuFreq的操作
    ///////////////////////////////////////////////////////////////////
    /////////////////////
    //  1.1--获取当前CPU的信息
    /////////////////////
    unsigned int GetCpuId( );
    CpuFreqUtils* GetCpuInfo( );                    //  获取当前CPU完整信息
    bool GetIsOnline( );                          //  当前CPU是否online
    unsigned long GetTransitionLatency( );        //  当前cpu完成频率切换所需要的时间
    unsigned long GetScalingMinFrequency( );      //  当前CPU的最小运行频率
    unsigned long GetScalingMaxFrequency( );      //  当前CPU的最大运行频率
    unsigned long GetScalingCurFrequency( );      //  当前CPU的当前运行频率
    unsigned long GetCpuInfoMinFrequency( );      //  当前CPU的最小运行频率
    unsigned long GetCpuInfoMaxFrequency( );      //  当前CPU的最大运行频率
    unsigned long GetCpuInfoCurFrequency( );      //  当前CPU的当前运行频率
    struct cpufreq_policy*   GetCpuFreqPolicy( );

#if defined(CNODE_IN_QLIST)
    //一种是将节点重新组织在QList中
    QList<struct cpufreq_available_frequencies *>& GetAvailableFrequencies( );   //  可用的CPU频率值
    QList<struct cpufreq_available_governors *>& GetAvailableGovernors( );         //  可用的CPU频率调节器
#elif defined(CLIST_TO_QLIST)
    //另一种是近将节点的数据域组织在QList, 即将CLIST转换为QLIST
    QList<QString>& GetAvailableFrequencies( );   //  可用的CPU频率值
    QList<unsigned long >& GetAvailableGovernors( );         //  可用的CPU频率调节器
#elif defined(USE_CLIST)
    //另外一种方式是直接使用CLIST
    struct cpufreq_available_frequencies *GetAvailableFrequencies( );   //  可用的CPU频率值
    struct cpufreq_available_governors *GetAvailableGovernors( );         //  可用的CPU频率调节器
#endif


    /////////////////////
    //  1.2--更新当前CPU的信息
    /////////////////////
    CpuFreqUtils* UpdateCpuInfo( );                 //  获取当前CPU完整信息
    bool UpdateIsOnline( );                             //  当前CPU是否online
    unsigned long UpdateTransitionLatency( );     //  当前cpu完成频率切换所需要的时间
    unsigned long UpdateScalingMinFrequency( );         //  当前CPU的最小运行频率
    unsigned long UpdateScalingMaxFrequency( );         //  当前CPU的最大运行频率
    unsigned long UpdateScalingCurFrequency( );         //  当前CPU的当前运行频率
    bool UpdateCpuInfoLimitsFrequency();
    unsigned long UpdateCpuInfoMinFrequency( );         //  当前CPU的最小运行频率
    unsigned long UpdateCpuInfoMaxFrequency( );         //  当前CPU的最大运行频率
    unsigned long UpdateCpuInfoCurFrequency( );         //  当前CPU的当前运行频率

#if defined(CNODE_IN_QLIST)
    //一种是将节点重新组织在QList中
    QList<struct cpufreq_available_frequencies *>& UpdateAvailableFrequencies( );   //  可用的CPU频率值
    QList<struct cpufreq_available_governors *>& UpdateAvailableGovernors( );         //  可用的CPU频率调节器
#elif defined(CLIST_TO_QLIST)
    //另一种是近将节点的数据域组织在QList, 即将CLIST转换为QLIST
    QList<QString>& UpdateAvailableFrequencies( );   //  可用的CPU频率值
    QList<unsigned long >& UpdateAvailableGovernors( );         //  可用的CPU频率调节器
#elif defined(USE_CLIST)
    //另外一种方式是直接使用CLIST
    struct cpufreq_available_frequencies *UpdateAvailableFrequencies( );   //  可用的CPU频率值
    struct cpufreq_available_governors *UpdateAvailableGovernors( );         //  可用的CPU频率调节器
#endif


    struct cpufreq_policy*   UpdateCpuFreqPolicy( );

    /////////////////////
    //  1.3--更新当前CPU的信息
    /////////////////////
    bool SetPolicy(struct cpufreq_policy *policy);
    bool SetPolicyMin(unsigned long min_freq);
    bool SetPolicyMax(unsigned long max_freq);
    bool SetPolicyGovernor(QString *governor);
    bool SetFrequency(unsigned long targetFrequency);

signals:


public slots:


protected :
    unsigned int    m_cpuid;                      //  当前CPU的编号
    bool            m_isonline;                   //  当前CPU是否在线
    unsigned long   m_transitionLatency;          //  频率切换所消耗的时间


    struct cpufreq_policy                         *m_curPolicy;                  //  当前使用的cpufreq
    //  注意cpufreq_policy中包含了min, max和governor
    unsigned long   m_scalingMinFrequency;        //  理论上最小运行频率
    unsigned long   m_scalingMaxFrequency;        //  理论上最大运行频率
    unsigned long   m_scalingCurFrequency;        //  理论上当前运行频率

    unsigned long   m_cpuinfoMinFrequency;        //  硬件读取的实际最小运行频率
    unsigned long   m_cpuinfoMaxFrequency;        //  硬件读取的实际最大运行频率
    unsigned long   m_cpuinfoCurFrequency;        //  硬件读取的实际当前运行频率


#if defined(CNODE_IN_QLIST)
    //一种是将节点重新组织在QList中
    QList<struct cpufreq_available_frequencies *>   m_availableFrequencies;       //  可用的CPU频率值
    QList<struct cpufreq_available_governors *>     m_availableGovernors;         //  可用的CPU频率调节器
#elif defined(CLIST_TO_QLIST)
    //另一种是近将节点的数据域组织在QList, 即将CLIST转换为QLIST
    QList<QString>                                     m_availableFrequencies;       //  可用的CPU频率值
    QList<unsigned long>                            m_availableGovernors;         //  可用的CPU频率调节器
#elif defined(USE_CLIST)
    //另外一种方式是直接使用CLIST
    struct cpufreq_available_frequencies*           m_availableFrequencies;       //  可用的CPU频率值
    struct cpufreq_available_governors*             m_availableGovernors;         //  可用的CPU频率调节器
#endif
};

#endif // __CPUFREQUTILS_H_INCLUDE__
