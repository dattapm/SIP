#ifndef SIPSOCKET_H
#include "SIPSocket.h"
#endif

int CreateTCPSocket(const char* PORT) {
    struct addrinfo hints, *res, *ressave;
    int n, listenfd;

    bzero(&hints, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET6;
    hints.ai_socktype = SOCK_STREAM;

    /* resolve the domain name into a list of addresses */
    if((n = getaddrinfo(NULL, PORT, &hints, &res)) != 0){
       std::cout<<"error in getaddrinfo: %s"<<gai_strerror(n)<<std::endl;
       exit(EXIT_FAILURE);
    }
    ressave = res;

    do {
       listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
       std::cout<<"SOCKET CREATED: "<<listenfd<<" "<<res->ai_family<<" "<<res->ai_socktype<<" "<<res->ai_protocol<<std::endl;
       if(listenfd < 0 )
         continue;

       /* Set socket to reuse address */
       int flag = 1;
       if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag)) < 0){
         exit(EXIT_FAILURE);
       }
       
       if(bind(listenfd, res->ai_addr, res->ai_addrlen) == 0) {
         break;
       }

       if(close(listenfd) < 0) {
         std::cout<<"UNABLE TO CLOSE THE SOCKET: "<<listenfd<<std::endl;
         exit(EXIT_FAILURE);
       }

    } while((res = res->ai_next) != NULL);

    if(res == NULL) {
     std::cout<<"UNABLE TO CREATE A SOCKET"<<std::endl;
    }

    if(listen(listenfd, QUEUE) < 0) {
      std::cout<<"LISTEN FAILED ON SOCKET: "<<listenfd<<std::endl;
      exit(EXIT_FAILURE);
    } else {
      std::cout<<"LISTEN SUCCESSFUL: "<<listenfd<<std::endl;
    }
    freeaddrinfo(ressave);

    return listenfd;
}

int CreateUDPSocket(const char* PORT) {
    struct addrinfo hints, *res, *ressave;
    int n, listenfd;

    bzero(&hints, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET6;
    hints.ai_socktype = SOCK_DGRAM;

    /* resolve the domain name into a list of addresses */
    if((n = getaddrinfo(NULL, PORT, &hints, &res)) != 0){
       std::cout<<"error in getaddrinfo: %s"<<gai_strerror(n)<<std::endl;
       exit(EXIT_FAILURE);
    }
    ressave = res;

    do {
       listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
       std::cout<<"SOCKET CREATED: "<<listenfd<<" "<<res->ai_family<<" "<<res->ai_socktype<<" "<<res->ai_protocol<<std::endl;
       if(listenfd < 0 )
         continue;

       if(bind(listenfd, res->ai_addr, res->ai_addrlen) == 0) {
         break;
       }

       if(close(listenfd) < 0) {
         std::cout<<"UNABLE TO CLOSE THE SOCKET: "<<listenfd<<std::endl;
         exit(EXIT_FAILURE);
       }

    } while((res = res->ai_next) != NULL);

    if(res == NULL) {
     std::cout<<"UNABLE TO CREATE A SOCKET"<<std::endl;
    }
    freeaddrinfo(ressave);

    return listenfd;
}

