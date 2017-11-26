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

int SendReqToUA(SIPRequest req){
    //return either 100 or 180
    LOG(DEBUG)<<"UA: Sending 100 Trying response back to the client.";
    
    int rspcode = 100;
    SendRspToTransaction(rspcode, req);
}

