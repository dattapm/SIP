#ifndef SIP_H
#include "SIP.h"
#endif

void Timer::ErrorExit(string msg){
    LOG(ERROR)<<msg;
    exit(EXIT_FAILURE);
}   

Timer::Timer(int SIGNALID):SIGNALID(SIGNALID),CLOCKID(CLOCK_REALTIME){}

void Timer::CreateTimer() {
    // Create the timer 
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGNALID;
    sev.sigev_value.sival_ptr = &timerid;
    
    if (timer_create(CLOCKID, &sev, &timerid) == -1){
        ErrorExit("timer_create failed");
    }
    
    LOG(DEBUG)<<"Timer created successfully with ID: "<<(long) timerid;
    
};                             

void Timer::StartTimer(int timeout){
    // Create the timer 
  
    CreateHandler();
    CreateTimer();
    
    BlockSignal();
    UnblockSignal();
    
    //Start the timer.
    its.it_value.tv_sec = timeout;
    its.it_value.tv_nsec = 0;
    
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;

    if (timer_settime(timerid, 0, &its, NULL) == -1){
        ErrorExit("timer_settime failed");
    }
        
    LOG(DEBUG)<<"Timer started"<<std::endl;
}

void Timer::CreateHandler() {
    // Establish handler for timer signal.
    
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = Timer::handler;
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGNALID, &sa, NULL) == -1){
        ErrorExit("sigaction failed");
    }

    LOG(DEBUG)<<"Signal handler created for signal ID: "<<SIGNALID;
}

void Timer::BlockSignal(){
    // Block timer signal temporarily 
    sigemptyset(&mask);
    sigaddset(&mask, SIGNALID);
    
    if (sigprocmask(SIG_SETMASK, &mask, NULL) == -1){
        ErrorExit("sigprocmask failed");
    }
    
    LOG(DEBUG)<<"Blocked signal with signal ID: "<<SIGNALID;
}


void Timer::UnblockSignal(){
    
    // Unlock the timer signal, so that timer notification can be delivered 
   if (sigprocmask(SIG_UNBLOCK, &mask, NULL) == -1){
       ErrorExit("sigprocmask failed");
   }
       
   LOG(DEBUG)<<"Unblocking signal for signal ID: "<< SIGNALID;   
}


void Timer::handler(int sig, siginfo_t *si, void *uc)
{
    std::cout<<"SIGNAL RECEIVED: "<<sig<<std::endl;
}


/*
int main(int argc, char* argv[]) {
    
    Timer timer(SIGRTMIN + 1);
    timer.StartTimer(10);
    sleep(100);
    exit(EXIT_SUCCESS);
       
    
}
*/