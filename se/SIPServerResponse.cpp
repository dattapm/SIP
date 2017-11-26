#ifndef SIPREQUEST_H
#include "SIPRequest.h"
#endif

using namespace sip_utils;

map<SIPHEADER, HeaderBase*>& SIPResponse::GetHeaders(){
  return rsphdrs;
}

HeaderBase* SIPResponse::GetHeaderValue(SIPHEADER key){
  return rsphdrs[key];
}

void SIPResponse::SetHeaderValue(SIPHEADER key, HeaderBase* value){
  rsphdrs[key] = value;
}

void SIPResponse::PrintResponse(){
}

void SIPResponse::SetRspCode(int rsp_code){
    code = rsp_code;
}

int SIPResponse::GetRspCode(){
    return code;
}

void SIPResponse::SetSIPVersion(string s_version){
    version = s_version;
}

string SIPResponse::GetSIPVersion(){
    return version;
}

void SIPResponse::SetPhrase(string phrase){
    display_phrase = phrase;
}

string SIPResponse::GetPhrase(){
    return display_phrase;
}

void SIPResponse::SetHeaders(map<SIPHEADER, HeaderBase*> rhdrs){
    rsphdrs.insert(rhdrs.begin(), rhdrs.end());
}

void SIPResponse::SetSockType(SOCK_TYPE s_type){
  sp.sock_type = s_type;
}
 
SOCK_TYPE SIPResponse::GetSockType(){
  return sp.sock_type;
}

void SIPResponse::SetSockFd(int socketfd){
  sp.sockfd = socketfd;
}

int SIPResponse::GetSockFd(){
  return sp.sockfd;
}
    
void SIPResponse::SetThreadId(pthread_t tid){
  tid = tid;
}

pthread_t SIPResponse::GetThreadId(){
  return sp.tid;
}