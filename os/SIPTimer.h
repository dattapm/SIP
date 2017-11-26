#ifndef SIPTIMER_H
#define SIPTIMER_H

#include<string>

class Timer {
    timer_t timerid;
    struct sigevent sev;
    struct itimerspec its;
    sigset_t mask;
    struct sigaction sa;
    
    int CLOCKID;
    int SIGNALID;
    
    void ErrorExit(std::string);
    
    public:
       Timer(int);
       ~Timer(){};
       
       void CreateTimer();
       void StartTimer(int);
       void BlockSignal();
       void UnblockSignal();
       void CreateHandler();
       static void handler(int sig, siginfo_t *si, void *uc);
};

#endif