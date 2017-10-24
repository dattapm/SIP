
#ifndef SIPHEADERPARSER_H
#include "SIPHeaderParser.h"
#endif

#ifndef SIP_H
#include "SIP.h"
#endif

using namespace sip_utils;

void AcceptEncoding::ParseHeader(string& hdr) {
  //values are comma seperated.
  sip_utils::tokenize(hdr, COMMA, encoders);
}

void AcceptEncoding::Print() {
  for(it = encoders.begin(); it != encoders.end(); it++){
    std::cout<<*it<<"END"<<std::endl; 
  }
}

void AcceptLanguage::ParseHeader(string& hdr) {
  //values are comma seperated.

  sip_utils::tokenize(hdr, COMMA, languages);
}

void AcceptLanguage::Print() {
  for(it = languages.begin(); it != languages.end(); it++){
    std::cout<<*it<<"END"<<std::endl; 
  }
}

void Accept::ParseHeader(string& hdr) {
  //values are comma seperated.
  // params and q values are ; seperated
  set<string> lparams;
  set<string>::iterator lit;
  tokenize(hdr, COMMA, lparams);
 
  //iterate the lparams and get the param and q value.
  for(lit = lparams.begin();lit != lparams.end();lit++) {
    string local = *lit;
    strip(local);
    KeyValue kv; 

    float q = -1.0;
    string tparam;

    GetKeyValuePair(local, SEMICOLON, kv);
    strip(kv.key);
    tparam = kv.key;

    //Get the q parameter
    GetKeyValuePair(kv.value, EQUAL, kv);
    if(!kv.value.empty()){
      q = stof(kv.value);
    }
    params.insert(make_pair(tparam, q));
  }

    return;
}

void Accept::Print() {
  for(it = params.begin(); it != params.end(); it++){
    std::cout<<it->first<<" "<<it->second<<std::endl; 
  }

return;
}

void CallID::ParseHeader(string& hdr) {
   strip(hdr);
   callid = hdr;
}

void CallID::Print() {
   std::cout<<callid<<std::endl;
}

void AlertInfo::ParseHeader(string& hdr) {
   strip(hdr);
   ringtone = hdr;
}

void AlertInfo::Print() {
   std::cout<<ringtone<<std::endl;
}

void Allow::ParseHeader(string& hdr) {
  //values are comma seperated.

  sip_utils::tokenize(hdr, COMMA, methods);
}

void Allow::Print() {
  for(it = methods.begin(); it != methods.end(); it++){
    std::cout<<*it<<"END"<<std::endl; 
  }
}

void ContentEncoding::ParseHeader(string& hdr) {
  //values are comma seperated.
  sip_utils::tokenize(hdr, COMMA, encoders);
}

void ContentEncoding::Print() {
  for(it = encoders.begin(); it != encoders.end(); it++){
    std::cout<<*it<<"END"<<std::endl; 
  }
}

void ContentLanguage::ParseHeader(string& hdr) {
  //values are comma seperated.

  sip_utils::tokenize(hdr, COMMA, languages);
}

void ContentLanguage::Print() {
  for(it = languages.begin(); it != languages.end(); it++){
    std::cout<<*it<<"END"<<std::endl; 
  }
}

void ContentLength::ParseHeader(string& hdr) {
  strip(hdr);
  content_length = stoi(hdr);
}

void ContentLength::Print() {
  std::cout<<content_length<<"END"<<std::endl; 
}

void MaxForwards::ParseHeader(string& hdr) {
  strip(hdr);
  maxforwards = stoi(hdr);
}

void MaxForwards::Print() {
  std::cout<<maxforwards<<"END"<<std::endl; 
}

void Expires::ParseHeader(string& hdr) {
  strip(hdr);
  expires = stoi(hdr);
}

void Expires::Print() {
  std::cout<<expires<<"END"<<std::endl; 
}

void CSeq::ParseHeader(string& hdr) {
  strip(hdr);
  KeyValue kv;
  GetKeyValuePair(hdr, SPACE, kv);

  seq_no = stoi(kv.key);
  method = kv.value;
}

void CSeq::Print() {
  std::cout<<seq_no<<" "<<method<<"END"<<std::endl; 
}

void MinExpires::ParseHeader(string& hdr) {
  strip(hdr);
  minexpires = stoi(hdr);
}

void MinExpires::Print() {
  std::cout<<minexpires<<"END"<<std::endl; 
}

void Subject::ParseHeader(string& hdr) {
  strip(hdr);
  subject = hdr;
}

void Subject::Print() {
  std::cout<<subject<<"END"<<std::endl; 
}

void Timestamp::ParseHeader(string& hdr) {
  strip(hdr);
  timestamp = stoi(hdr);
}

void Timestamp::Print() {
  std::cout<<timestamp<<"END"<<std::endl; 
}

void To::ParseHeader(string& hdr) {
  size_t index = 0;

  

  //display name
  size_t foundd = hdr.find_first_of(LABRACKET);

  if(foundd != string::npos){
    display_name = hdr.substr(0, foundd);
    strip(display_name);
     
    //Get the address here
      
  
  } else {
     //no < in the header.
     // mostly the header has address.
     //nothing to do here.
  }




  //params
  size_t found = hdr.find_first_of(SEMICOLON);

  if(found != string::npos) {
    string param = hdr.substr(found + 1);
    size_t foundp = param.find_first_of(EQUAL);

    if(foundp != string::npos) { 
        tg_param = param.substr(foundp + 1);
        strip(tg_param);
    } else {
      //set param type to NONE here
    }   

  } else {
   //no params
   //set param type to NONE here

  }

return;

}

void To::Print() {
  std::cout<<tg_param<<" "<<display_name<<" "<<address<<"END"<<std::endl; 
}


void Supported::ParseHeader(string& hdr) {
  //values are comma seperated.
  tokenize(hdr, COMMA, supported);
}

void Supported::Print() {
  for(it = supported.begin(); it != supported.end(); it++){
    std::cout<<*it<<"END"<<std::endl; 
  }
}


void Unsupported::ParseHeader(string& hdr) {
  //values are comma seperated.
  tokenize(hdr, COMMA, unsupported);
}

void Unsupported::Print() {
  for(it = unsupported.begin(); it != unsupported.end(); it++){
    std::cout<<*it<<"END"<<std::endl; 
  }
}

void RetryAfter::ParseHeader(string& hdr) {
  // params and generic values are ; seperated

  strip(hdr);
  KeyValue kv;
  GetKeyValuePair(hdr, SEMICOLON, kv);

  string lrparam = kv.key;
  string ldparam = kv.value;
  //get the comment
  GetKeyValuePair(lrparam, SPACE, kv);
  if(!kv.key.empty()){
    retryafter = stoi(kv.key);
  }
  if(!kv.value.empty()){
    comment = kv.value;
  }

  //get the duration
  GetKeyValuePair(ldparam, EQUAL, kv);
  if(!kv.value.empty()){
    duration = stoi(kv.value);
  }
  return;
}

void RetryAfter::Print(){
  std::cout<<retryafter<<" "<<comment<<" "<<duration<<std::endl;
}

void ProxyRequire::ParseHeader(string& hdr) {
  //values are comma seperated.
  tokenize(hdr, COMMA, require);
}

void ProxyRequire::Print() {
  for(it = require.begin(); it != require.end(); it++){
    std::cout<<*it<<"END"<<std::endl; 
  }
}

void Require::ParseHeader(string& hdr) {
  //values are comma seperated.
  tokenize(hdr, COMMA, require);
}

void Require::Print() {
  for(it = require.begin(); it != require.end(); it++){
    std::cout<<*it<<"END"<<std::endl; 
  }
}

void Route::ParseHeader(string& hdr) {
  //values are comma seperated.
  // params and q values are ; seperated
  set<string> lparams;
  set<string>::iterator lit;
  tokenize(hdr, COMMA, lparams);
 
  //iterate the lparams and get the param and q value.
  for(lit = lparams.begin();lit != lparams.end();lit++) {
    string local = *lit;
    strip(local);
    string tparam;

    GetAddress(local, tparam); 

    KeyValue kv; 

    GetKeyValuePair(tparam, SEMICOLON, kv);

    strip(kv.key);
    strip(kv.value);
    routes.insert(make_pair(kv.key, kv.value));
  }

    return;
}

void Route::Print() {
  for(it = routes.begin(); it != routes.end(); it++){
    std::cout<<it->first<<" "<<it->second<<std::endl; 
  }

return;
}

void ProxyAuthorization::ParseHeader(string& hdr) {
  //values are comma seperated.
  // params and q values are ; seperated
  set<string> lparams;
  set<string>::iterator lit;
  tokenize(hdr, COMMA, lparams);
 
  //iterate the lparams and get the param and q value.
  for(lit = lparams.begin();lit != lparams.end();lit++) {
    string local = *lit;
    strip(local);

    KeyValue kv; 
    GetKeyValuePair(local, EQUAL, kv);

    strip(kv.key);
    strip(kv.value);
    credentials.insert(make_pair(kv.key, kv.value));
  }

    return;
}

void ProxyAuthorization::Print() {
  for(it = credentials.begin(); it != credentials.end(); it++){
    std::cout<<it->first<<" "<<it->second<<std::endl; 
  }

return;
}
