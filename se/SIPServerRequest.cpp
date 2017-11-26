
#ifndef SIPREQUEST_H
#include "SIPRequest.h"
#endif

using namespace sip_utils;

void SIPRequest::ParseSIPRequest(char* sipreq){
     
    string sipmsg(sipreq);
    strip(sipmsg);
    string line;
    
    //parse the request.
    std::istringstream ss(sipmsg);
    
    //First line should be the method line.
    getline(ss, line);
        
    vector<string> toks;
        
    tokenize(line, SPACE, toks);
        
    if(toks.size() != 3) {
      LOG(DEBUG)<<"SIP Request line has less than required data to process";
      // send back 400 Bad Request error
      exit(EXIT_FAILURE);
    }
    
    method = toks[0];
    url = toks[1];
    version = toks[2];
    
    
    //parse the headers.
    while(getline(ss, line)){
      //split the line at ":".
      KeyValue kv;
      GetKeyValuePair(line, COLON, kv);
      
      //Fill the header map for the request in hand.
      GetHeaderMap(kv);
      
    } //end of while.
    
    /*
    map<SIPHEADER, HeaderBase*>::iterator it;
    for(it = GetHeaders().begin();it != GetHeaders().end();it++){
          string t = typeid(it->second).name();
          std::cout<<"DATTA IN MPARSE REQ: "<<it->first<<" "<<it->second<<std::endl;
          //it->second->Print();
    }
    */
  
    
}// end of ParseSIPRequest.

string SIPRequest::GetMethod(){
    return method;
}

string SIPRequest::GetSIPVersion(){
    return version;
}

string SIPRequest::GetURL(){
    return url;
}

map<SIPHEADER, HeaderBase*>& SIPRequest::GetHeaders(){
   return reqhdrs;
}

void SIPRequest::SetSockType(SOCK_TYPE s_type){
  sp.sock_type = s_type;
}
 
SOCK_TYPE SIPRequest::GetSockType(){
  return sp.sock_type;
}

void SIPRequest::SetSockFd(int socketfd){
  sp.sockfd = socketfd;
}

int SIPRequest::GetSockFd(){
  return sp.sockfd;
}
    
void SIPRequest::SetThreadId(pthread_t tid){
 tid = tid;
}

pthread_t SIPRequest::GetThreadId(){
 return sp.tid;
}

void SIPRequest::GetHeaderMap(KeyValue kv){
    string in_hdr;
    std::transform(kv.key.begin(), kv.key.end(), in_hdr.begin(), ::tolower);
    
    
    //header fields are case-insensitive.
    
    if(in_hdr == "via"){
        Via* hdr = new Via();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = VIA;
        reqhdrs.insert(make_pair(v_hdr, hdr));
         
        return;
    }
    
    if(in_hdr == "to"){
        To* hdr = new To();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = TO;
        reqhdrs.insert(make_pair(v_hdr, hdr));
        
        return;
    }
    
    if(in_hdr == "from"){
        From* hdr = new From();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = FROM;
        reqhdrs.insert(make_pair(v_hdr, hdr));
        
        return;
         
    }
    
    if(in_hdr == "call-id"){
        CallID* hdr = new CallID();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = CALL_ID;
        reqhdrs.insert(make_pair(v_hdr, hdr));
        
        return;
    }
    
    if(in_hdr == "cseq"){
        CSeq* hdr = new CSeq();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = CSEQ;
        reqhdrs.insert(make_pair(v_hdr, hdr));
        
        return;
    }
    
    if(in_hdr == "content-length"){
        ContentLength* hdr = new ContentLength();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = CONTENT_LENGTH;
        reqhdrs.insert(make_pair(v_hdr, hdr));
        
        return;
    }
    
    if(in_hdr == "max-forwards"){
        MaxForwards* hdr = new MaxForwards();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = MAX_FORWARDS;
        reqhdrs.insert(make_pair(v_hdr, hdr));
        
        return;
    }
    
    if(in_hdr == "subject"){
        Subject* hdr = new Subject();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = SUBJECT;
        reqhdrs.insert(make_pair(v_hdr, hdr));
        
        return;
    }
    
    if(in_hdr == "contact"){
        Contact* hdr = new Contact();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = CONTACT;
        reqhdrs.insert(make_pair(v_hdr, hdr));
        
        return;
    }
    
    if(in_hdr == "content-type"){
        Content_Type* hdr = new Content_Type();
        hdr->ParseHeader(kv.value);
        
        // Add the header object to map for future reference.
        SIPHEADER v_hdr = CONTENT_TYPE;
        reqhdrs.insert(make_pair(v_hdr, hdr));
         
        return;
    }
}
