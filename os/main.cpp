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

int main(int argc, char* argv[]) {

    char port[] = "49101";
    
    int nready, maxfd, i, maxi, sockfd;
    int client[FD_SETSIZE];
    
    fd_set readset, allset;
    
    //Create TCP and UDP socket listeneing to 'port'.
    int tcpsockfd = CreateTCPSocket(port);
    int udpsockfd = CreateUDPSocket(port); 
    
    maxfd = max(tcpsockfd, udpsockfd);
    maxi = -1;
    for(i = 0; i < FD_SETSIZE;i++){
        client[i] = -1;
    }
    
    FD_ZERO(&allset);
    FD_SET(tcpsockfd, &allset);
    FD_SET(udpsockfd, &allset);
    
    for(;;){
       readset = allset;    
        
       if((nready = pselect(maxfd + 1, &readset, NULL, NULL, NULL, NULL)) < 0) {
           std::cout<<"ERROR WITH SELECT"<<std::endl;
       }
       
       if(FD_ISSET(tcpsockfd, &readset)) { /* new TCP client connection  */
          std::cout<<"SELECT: CLIENT CONNECTION RECEIVED ON: "<<tcpsockfd<<std::endl;
          struct sockaddr_in cliaddr;
          socklen_t clilen;
          int connfd;
          
          connfd = accept(tcpsockfd, (struct sockaddr*) &cliaddr, &clilen); 
          if(connfd < 0) {
            std::cout<<"UNABLE TO CONNECT TO SOCKET"<<std::endl;
            exit(EXIT_FAILURE);
          }
          std::cout<<"SOCKET ACCEPT SUCCESSFUL"<<std::endl;
       
          for(i = 0; i < FD_SETSIZE;i++){
              std::cout<<"DATTA1: "<<i<<std::endl;
              if(client[i] < 0){
                  client[i] = connfd;
                  break;
              }
              std::cout<<"DATTA2: "<<i<<std::endl;
          }
          std::cout<<"DATTA3: "<<i<<" "<<FD_SETSIZE<<std::endl;
          if(i == FD_SETSIZE){
            std::cout<<"TOO MANY TCP CLIENT CONNECTIONS RECEIVED"<<std::endl;
          }
          
          FD_SET(connfd, &allset);
          
          if(connfd > maxfd){
            maxfd = connfd;
          }
          
          if(i > maxi){
            maxi = i;
          }
          
          if(--nready <= 0){
              continue;
          }
          
       }// end of if condition
       
       if(FD_ISSET(tcpsockfd, &readset)) { /* new UDP client connection  */
       
       
       
       } // end of UDP read process.
       
      //read data from the client connections.
      for(i = 0; i <= maxi;i++){
          
          if((sockfd = client[i]) < 0)
             continue;
             
          if(FD_ISSET(sockfd, &readset)){
              
              std::cout<<"SELECT: DATA AVAILABLE ON: "<<sockfd<<std::endl;
             //Data is available on sockfd.
             // Read data from the socket 
             
             // Read and parse the data.
             ProcessSIPData(sockfd);
            
             //close the socket after processing the data.
             if(close(sockfd) < 0) {
                std::cout<<"UNABLE TO CLOSE THE SOCKET: "<<sockfd<<std::endl;
                exit(EXIT_FAILURE);
             }
             
             FD_CLR(sockfd, &allset);
             client[i] = -1;
         
             if(--nready <= 0){
              break;
             } 
              
          } // end of if condition.     
      }// end of for loop
     
   }// end of endless-for loop
   
   if(close(tcpsockfd) < 0) {
    std::cout<<"UNABLE TO CLOSE THE SOCKET: "<<tcpsockfd<<std::endl;
    exit(EXIT_FAILURE);
   }
   
   if(close(udpsockfd) < 0) {
    std::cout<<"UNABLE TO CLOSE THE SOCKET: "<<udpsockfd<<std::endl;
    exit(EXIT_FAILURE);
   }

return 0;
}
