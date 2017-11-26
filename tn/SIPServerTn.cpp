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


static INVITE_SERVER_STATE FINITE_STATE = NONE;

map<int, string> rsp_display_name {
  {100, "Trying"},
  {180, "Ringing"},
};

void SendReqToTransaction(SIPRequest lreq){
   // if(queuereqs.size() != 0){
        
        //SIPRequest lreq = queuereqs.front();
        
        if(lreq.GetMethod() == "INVITE"){
            LOG(DEBUG)<<"TRANSACTION: INVITE method received. Creating the finite state for the request.";
            //Create INVITE FINITE STATE HERE.
            INVITE_SERVER_STATE server_state = PROCEEDING;
            
            //Send the req to UA
            int rsp_from_ua = SendReqToUA(lreq);

        } else {
            LOG(DEBUG)<<"TRANSACTION: NON-INVITE method received. Creating the finite state for the request.";
        }
        //Add to the rspqueue.
        
        
        //queuereqs.pop();
  //  }
    
}// end of method


void SendRspToTransaction(int rsp_code, SIPRequest req){
    // Create a response here.
    SIPResponse rsp;
    
    //Add rsp_code here.
    rsp.SetRspCode(rsp_code);
    rsp.SetSIPVersion(req.GetSIPVersion());
    rsp.SetPhrase(rsp_display_name[rsp_code]);
  
    // Set transport details here.
    rsp.SetSockType(req.GetSockType());
    LOG(DEBUG)<<"DATTA: REQ SOCK FD IS: "<<req.GetSockFd();
    
    rsp.SetSockFd(req.GetSockFd());
    
    LOG(DEBUG)<<"DATTA: RSP SOCK FD IS: "<<rsp.GetSockFd();
    
    // Set the list of headers here.
    rsp.SetHeaders(req.GetHeaders());
   
    // Change the STATE here.
    
    // Send the response to transport layer.
    SendRspToTransport(rsp);
    
}


