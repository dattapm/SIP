
#ifndef SIP_h
#include "SIP.h"
#endif


#ifndef SIPHEADERPARSER_H
#include "SIPHeaderParser.h"
#endif

#ifndef SIPSOCKET_H
#include "SIPSocket.h"
#endif

using namespace sip_utils;

char PORT[] = "49101";

INITIALIZE_EASYLOGGINGPP


int main(int argc, char* argv[]) {
   START_EASYLOGGINGPP(argc, argv);
    
    int nready, maxfd, sockfd;
    fd_set readset;
    
    //Create TCP and UDP socket listeneing to 'port'.
    int tcpsockfd = CreateTCPSocket(PORT);
    int udpsockfd = CreateUDPSocket(PORT); 
    
    
    maxfd = max(tcpsockfd, udpsockfd);
    
    FD_ZERO(&readset);
    FD_SET(tcpsockfd, &readset);
    FD_SET(udpsockfd, &readset);
    
    for(;;){
        
        if((nready = pselect(maxfd + 1, &readset, NULL, NULL, NULL, NULL)) < 0) {
            if(errno == EINTR){
                LOG(ERROR)<<"EINTR error with pselect";
              continue;
            }
                
            LOG(ERROR)<<"Error with select: "<<errno;
            exit(EXIT_FAILURE);
        }
       
        struct SocketParams tmp;
        if(FD_ISSET(tcpsockfd, &readset)) { 
          // new TCP client connection
          struct sockaddr_in cliaddr;
          socklen_t clilen;
          long connfd;
          
          LOG(DEBUG)<<"TCP Client connection received on: "<<tcpsockfd;
          
          connfd = accept(tcpsockfd, (struct sockaddr*) &cliaddr, &clilen); 
          if(connfd < 0) {
            LOG(ERROR)<<"Unable to connect to TCP socket Id: "<<tcpsockfd;
            exit(EXIT_FAILURE);
          }
         
          tmp.sockfd = connfd;
          tmp.sock_type = TCP;
          
          
          //create a new thread and assign it to handle the new connection.
          if(pthread_create(&tmp.tid, NULL, ProcessSIPData, (void*)&tmp) != 0) {
             LOG(ERROR)<<"TCP client thread creation not successful";
             exit(EXIT_FAILURE);
          }
          
        
        }// end of TCP if condition
       
       if(FD_ISSET(udpsockfd, &readset)) { 
          // new UDP client connection
          
          tmp.sockfd = udpsockfd;
          tmp.sock_type = UDP;
          
          LOG(DEBUG)<<"UDP Client connection received on: "<<udpsockfd;
          
          //create a new thread and assign it to handle the new connection.
          if(pthread_create(&tmp.tid, NULL, ProcessSIPData, (void*)&tmp) != 0) {
             LOG(ERROR)<<"UDP client thread creation not successful";
             exit(EXIT_FAILURE);
          }
          
       } // end of UDP read process.
       
       //join the newly created thread here.
       if(pthread_join(tmp.tid, NULL) != 0){
          LOG(ERROR)<<"Thread join not successful: socket fd is: "<<tmp.sockfd<<"thread id is:  "<<tmp.tid;
       }
       
   }// end of endless-for loop
   
   if(close(tcpsockfd) < 0) {
    LOG(ERROR)<<"Unable to close TCP Socket: "<<tcpsockfd;
    exit(EXIT_FAILURE);
   }
   
   if(close(udpsockfd) < 0) {
    LOG(ERROR)<<"Unable to close UDP Socket: "<<udpsockfd;
    exit(EXIT_FAILURE);
   }
    
return EXIT_SUCCESS;

}

