#include<iostream>
#include<unistd.h>

void* call_this_func(void*){
    std::cout<<"FROM THREAD"<<std::endl;
    sleep(100);
}

int main(int argc, char* argv[]){
    pthread_t tid1, tid2;
    
    if(pthread_create(&tid1, NULL, call_this_func, NULL) != 0) {
        std::cout<<"thread creation not successful"<<std::endl;
        //exit(1);
        
    }
    
    if(pthread_create(&tid2, NULL, call_this_func, NULL) != 0) {
        std::cout<<"thread creation not successful"<<std::endl;
        //exit(1);
        
    }
    if(pthread_join(tid1, NULL) != 0){
        std::cout<<"THREAD JOIN NOT SUCCESSFUL"<<std::endl;
    }
    
    if(pthread_join(tid2, NULL) != 0){
        std::cout<<"THREAD JOIN NOT SUCCESSFUL"<<std::endl;
    }
    
    return 0;
}