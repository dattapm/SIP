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

using namespace sip_utils;

void SendReqToSE(char* sipbuf, SOCK_TYPE sock_type, int sockfd) {
    // Process the SIP message.
    SIPRequest sreq;
    
    sreq.SetSockType(sock_type);
    sreq.SetSockFd(sockfd);
    
    LOG(DEBUG)<<"DATTA: SOCK FD IS: "<<sockfd<<" "<<sreq.GetSockFd();
    
    sreq.ParseSIPRequest(sipbuf);
    
    LOG(INFO)<<"SIP request parsed successfully";
    
    
    //Check for errors with header fields.
    
    //Check if Accept hdr is present, if not set its value to 'application/sdp'.
    //Send to the transport layer.
    SendReqToTransport(sreq);
}

void SendRspToSE(SIPResponse rsp){
    
    //Convert rsp to a string and send it across to the sockfd 
    string response;
    
    LOG(INFO)<<"SE: SIP response created successfully: ";
    
    response += rsp.GetSIPVersion() + SPACE + to_string(rsp.GetRspCode()) + SPACE + rsp.GetPhrase();
    response += NEWLINE;
    
    
    //Swap the To and From header values here.
    HeaderBase* to_hdr = rsp.GetHeaderValue(TO);
    HeaderBase* from_hdr = rsp.GetHeaderValue(FROM);
    rsp.SetHeaderValue(TO, from_hdr);
    rsp.SetHeaderValue(FROM, to_hdr);
    
    //Iterate over all the headers from the request and create a response here.
    map<SIPHEADER, HeaderBase*>::iterator it;
    for(it = rsp.GetHeaders().begin();it != rsp.GetHeaders().end();it++){
          response += HdrToStringConverter(it->first) + COLON + SPACE;
          response += it->second->GetHeader();
          response += NEWLINE;
    }
    
    std::cout<<"DATTA IN RSP: "<<response<<std::endl;
    //send the response to the socket.
    LOG(DEBUG)<<"SE RSP: Sending the response to client: DATTA "<<rsp.GetSockType()<<" "<<rsp.GetSockFd();
    
    if(rsp.GetSockType() == TCP) {
        size_t nbytes;
        if((nbytes = write(rsp.GetSockFd(), response.c_str(), response.length())) < 0){
            LOG(ERROR)<<"Unable to write to the socket id: "<<rsp.GetSockFd();
            exit(EXIT_FAILURE);
        }//end of while loop.
        
        LOG(DEBUG)<<"TCP:  of bytes written: "<<nbytes;
        LOG(INFO)<<"SIP response sent on sock fd: "<<rsp.GetSockFd()<<" "<<response;
   } else if (rsp.GetSockType() == UDP){
       size_t nbytes;
       int clientlen;
       
       struct sockaddr_in clientaddr;
       
       clientlen = sizeof(clientaddr);
       if((nbytes = sendto(rsp.GetSockFd(), response.c_str(), response.length() + 1, 0, (struct sockaddr*)&clientaddr, clientlen)) < 0){
         LOG(ERROR)<<"Unable to write to UDP socket id: "<<rsp.GetSockFd();
         exit(EXIT_FAILURE);
       }
        
       LOG(DEBUG)<<"UDP: No of bytes written: "<<nbytes;
       LOG(INFO)<<"SIP response sent on sock fd: "<<rsp.GetSockFd()<<" "<<response;
       
   }
    
 }