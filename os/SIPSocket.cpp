#ifndef SIPSOCKET_H
#include "SIPSocket.h"
#endif

int CreateTCPSocket(const char* PORT) {
    struct addrinfo hints, *res, *ressave;
    int n, listenfd;

    bzero(&hints, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // resolve the domain name into a list of addresses.
    if((n = getaddrinfo(NULL, PORT, &hints, &res)) != 0){
       LOG(ERROR)<<"Error in getaddrinfo: %s"<<gai_strerror(n);
       exit(EXIT_FAILURE);
    }
    ressave = res;

    do {
       listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
       
       LOG(DEBUG)<<"TCP Socket created: "<<listenfd<<" "<<res->ai_family<<" "<<res->ai_socktype<<" "<<res->ai_protocol;
       
       if(listenfd < 0)
         continue;

       // Set socket to reuse address
       int flag = 1;
       if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag)) < 0){
         LOG(ERROR)<<"TCP set socket option SO_REUSEADDR failed on socket id: "<<listenfd;
         exit(EXIT_FAILURE);
       }
       
       if(bind(listenfd, res->ai_addr, res->ai_addrlen) == 0) {
         LOG(DEBUG)<<"TCP bind successful on socket id: "<<listenfd;
         break;
       }

       if(close(listenfd) < 0) {
         LOG(ERROR)<<"Unable to close the TCP socket: "<<listenfd;
         exit(EXIT_FAILURE);
       }

    } while((res = res->ai_next) != NULL);

    if(res == NULL) {
     LOG(ERROR)<<"Unable to create a TCP socket";
     exit(EXIT_FAILURE);
    }

    if(listen(listenfd, QUEUE) < 0) {
      LOG(ERROR)<<"TCP socket listen failed on : "<<listenfd;
      exit(EXIT_FAILURE);
    }
    
    LOG(DEBUG)<<"TCP socket listen successful on : "<<listenfd;
     
    freeaddrinfo(ressave);

    return listenfd;
}

int CreateUDPSocket(const char* PORT) {
    struct addrinfo hints, *res, *ressave;
    int n, listenfd;

    bzero(&hints, sizeof(struct addrinfo));

    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    // resolve the domain name into a list of addresses.
    if((n = getaddrinfo(NULL, PORT, &hints, &res)) != 0){
       LOG(ERROR)<<"Error in getaddrinfo: %s"<<gai_strerror(n);
       exit(EXIT_FAILURE);
    }
    ressave = res;

    do {
       listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
       LOG(DEBUG)<<"UDP socket created: "<<listenfd<<" "<<res->ai_family<<" "<<res->ai_socktype<<" "<<res->ai_protocol;
       
       if(listenfd < 0 )
         continue;

       if(bind(listenfd, res->ai_addr, res->ai_addrlen) == 0) {
         LOG(DEBUG)<<"UDP bind successful on socket id: "<<listenfd;
         break;
       }

       if(close(listenfd) < 0) {
         LOG(ERROR)<<"Unable to close the UDP socket: "<<listenfd;
         exit(EXIT_FAILURE);
       }

    } while((res = res->ai_next) != NULL);

    if(res == NULL) {
     LOG(ERROR)<<"Unable to create a UDP socket"<<std::endl;
    }
    
    LOG(DEBUG)<<"UDP socket created  successfully with socket id: "<<listenfd;
    
    freeaddrinfo(ressave);

    return listenfd;
}

