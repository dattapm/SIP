#ifndef SIPHEADERPARSER_H
#include "SIPHeaderParser.h"
#endif

#ifndef SIP_H
#include "SIP.h"
#endif

#ifndef SIPSOCKET_H
#include "SIPSocket.h"
#endif

#ifndef SIPREQUEST_H
#include "SIPRequest.h"
#endif

#ifndef SIPTIMER_H
#include "SIPTimer.h"
#endif

namespace sip_utils {
    

void* ProcessSIPData(void* arg){
    
    struct SocketParams* local = (struct SocketParams*)arg;
    char buf[MAXLINE];
    
    LOG(DEBUG)<<"Thread Information, Socket type is: "<<local->sock_type<<" Socked fd is: "<<local->sockfd<<" Thread Id. is: "<<local->tid;
    if(local->sock_type == TCP) {
        size_t nbytes;
        while((nbytes = read(local->sockfd, buf, MAXLINE)) > 0){
            if(nbytes < 0){
                if(errno != EINTR) {
                    break;
                }
            }
        }//end of while loop.

        LOG(DEBUG)<<"SIP message received: "<<buf;
        
        //send the request to SE.
        SendReqToSE(buf, local->sock_type, local->sockfd);
        
    } else if (local->sock_type == UDP){
        //process UDP data here
        struct sockaddr_in remaddr;     //remote address
        socklen_t addrlen = sizeof(remaddr);            //length of addresses
        int recvlen;                    /* # bytes received */
        
        
        if((recvlen = recvfrom(local->sockfd, buf, MAXLINE, 0, (struct sockaddr *)&remaddr, &addrlen)) < 0){
            LOG(ERROR)<<"Unable to read from UDP socket id: "<<local->sockfd;
            exit(EXIT_FAILURE);
        }
        buf[recvlen] = 0;
        
        LOG(DEBUG)<<"SIP message received: "<<buf;
        
        //send the request to SE.
        SendReqToSE(buf,local->sock_type, local->sockfd);
        
    }// end of UDP data receive
    
    /*
    //close the socket after processing the data.
    if(close(loc->sockfd) < 0) {
        LOG(ERROR)<<"Unable to close the socket with socket id: "<<loc->sockfd;
        exit(EXIT_FAILURE);
    }
    */
    
    
}//end of method.



}//end of namespace
