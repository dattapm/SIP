#ifndef SIPHEADERPARSER_H
#include "SIPHeaderParser.h"
#endif

#ifndef SIP_H
#include "SIP.h"
#endif

#ifndef SIPSOCKET_H
#include "SIPSocket.h"
#endif

namespace sip_utils {
 

void ProcessSIPData(int sockfd){
 
 char buf[MAXLINE];
 size_t nbytes;
 
 while((nbytes = read(sockfd, buf, MAXLINE)) > 0){
    //std::cout<<"READING DATA FROM SOCKET"<<std::endl;	  
    std::cout<<buf<<std::endl;
    //std::cout<<"READ"<<n<<" "<<"BYTES"<<std::endl;
    if(nbytes < 0){
      if(errno != EINTR) {
        break;;
      }
   }

 }

 // Process the SIP message.
}

};