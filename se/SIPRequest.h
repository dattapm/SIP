#ifndef SIPREQUEST_H
#define SIPREQUEST_H

#ifndef SIPHEADERPARSER_H
#include "SIPHeaderParser.h"
#endif

#ifndef SIP_H
#include "SIP.h"
#endif

#ifndef SIPSOCKET_H
#include "SIPSocket.h"
#endif

using namespace sip_utils;

enum SIPMETHODS {
  INVITE,
  ACK,
  OPTIONS,
  CANCEL,
  REGISTER
};

enum SIPHEADER {
  VIA,
  FROM,
  TO,
  CALL_ID,
  CSEQ,
  CONTACT,
  MAX_FORWARDS,
  SUBJECT,
  CONTENT_TYPE,
  CONTENT_LENGTH
};

enum INVITE_SERVER_STATE{
   PROCEEDING,
   COMPLETED,
   CONFIRMED,
   TERMINATED,
   NONE
};

class SIPRequest {
    
    string method;
    string url;
    string version;
    
    SocketParams sp;
    map<SIPHEADER, HeaderBase*> reqhdrs;
    
  public:
    void ParseSIPRequest(char* sipreq);
    void GetHeaderMap(KeyValue);
    string GetMethod();
    string GetSIPVersion();
    string GetURL();
    
    //set/ get socket params.
    void SetSockType(SOCK_TYPE);
    SOCK_TYPE GetSockType();
    void SetSockFd(int);
    int GetSockFd();
    void SetThreadId(pthread_t);
    pthread_t GetThreadId();
    
    map<SIPHEADER, HeaderBase*>& GetHeaders();
};


class SIPResponse {
  int code;
  string version;
  string display_phrase;

  SocketParams sp;
  map<SIPHEADER, HeaderBase*> rsphdrs;
 

  public:
    map<SIPHEADER, HeaderBase*>& GetHeaders();
    void PrintResponse();
    void SetRspCode(int);
    int GetRspCode();
    void SetSIPVersion(string);
    string GetSIPVersion();
    void SetPhrase(string);
    string GetPhrase();
    
    
    //set/ get socket params.
    void SetSockType(SOCK_TYPE);
    SOCK_TYPE GetSockType();
    void SetSockFd(int);
    int GetSockFd();
    void SetThreadId(pthread_t);
    pthread_t GetThreadId();
    
    void SetHeaders(map<SIPHEADER, HeaderBase*>);
    HeaderBase* GetHeaderValue(SIPHEADER);
    void SetHeaderValue(SIPHEADER, HeaderBase*);
  
};

void SendReqToTransport(SIPRequest);
void SendReqToTransaction(SIPRequest);
int SendReqToUA(SIPRequest);
void SendReqToSE(char*, SOCK_TYPE, int);

void SendRspToTransaction(int, SIPRequest);
void SendRspToTransport(SIPResponse);
void SendRspToSE(SIPResponse);

string HdrToStringConverter(SIPHEADER);
//extern queue<SIPRequest> queuereqs;
//extern queue<SIPRequest> queuersps;

extern map<int, string> rsp_display_name;

#endif