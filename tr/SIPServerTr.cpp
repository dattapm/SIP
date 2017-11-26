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

using namespace sip_utils;

queue<SIPRequest> queuereqs;

void SendReqToTransport(SIPRequest req) {
    //Create two queues here.
    // one for Requests and one for responses.
    
    //Additional transport processing will happen here.
    LOG(DEBUG)<<"TRANSPORT: Pushing the SIP request to the transaction layer for further processing.";
   
    SendReqToTransaction(req);
}


void SendRspToTransport(SIPResponse rsp){
  LOG(DEBUG)<<"TRANSPORT RSP: Sending the response to SE";
  
  SendRspToSE(rsp);
  
}
