
#ifndef SIPHEADERPARSER_H
#include "SIPHeaderParser.h"
#endif

#ifndef SIP_H
#include "SIP.h"
#endif

using namespace sip_utils;

void HeaderBase::ParseHeader(string& hdr){
   return;
}

void HeaderBase::Print(){
  return;
}

string HeaderBase::GetHeader(){
  string str("Hello World");
  return str;
}

void AcceptEncoding::ParseHeader(string& hdr) {
  
  LOG(DEBUG)<<"In AcceptEncoding parser";
  //values are comma seperated.
  
  sip_utils::tokenize(hdr, COMMA, encoders);
}

void AcceptEncoding::Print() {
  LOG(DEBUG)<<"In AcceptEncoding print";
  
  for(it = encoders.begin(); it != encoders.end(); it++){
    LOG(DEBUG)<<*it; 
  }
}

string AcceptEncoding::GetHeader(){
  string hdr;
  
  for(it = encoders.begin(); it != encoders.end(); it++){
    hdr += (*it) + COLON; 
  }
  
  return hdr;
}

void AcceptLanguage::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In AcceptLanguage parser";
  
  //values are comma seperated.

  sip_utils::tokenize(hdr, COMMA, languages);
}

void AcceptLanguage::Print() {
  LOG(DEBUG)<<"In AcceptLanguage print";
  
  for(it = languages.begin(); it != languages.end(); it++){
    LOG(DEBUG)<<*it; 
  }
}

string AcceptLanguage::GetHeader(){
  string hdr;
  
  for(it = languages.begin(); it != languages.end(); it++){
    hdr += (*it) + COMMA; 
  }
  
  return hdr;
}


void Accept::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In Accept parser";
  //values are comma seperated.
  //params and q values are ; seperated.
  vector<string> lparams;
  vector<string>::iterator lit;
  tokenize(hdr, COMMA, lparams);
 
  //iterate the lparams and get the param and q value.
  for(lit = lparams.begin();lit != lparams.end();lit++) {
    string local = *lit;
    strip(local);
    KeyValue kv; 

    float q = -1.0;
    string tparam;

    GetKeyValuePair(local, SEMICOLON, kv);
   
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
  LOG(DEBUG)<<"In Accept print";
  
  for(it = params.begin(); it != params.end(); it++){
    LOG(DEBUG)<<it->first<<" "<<it->second; 
  }

return;
}

string Accept::GetHeader(){
  
  return "Hello";
}

void CallID::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In CallID parser";

  strip(hdr);
  callid = hdr;
}

void CallID::Print() {
  LOG(DEBUG)<<"In CallID print";
  LOG(DEBUG)<<callid;
}

string CallID::GetHeader(){
  return callid;
}

void AlertInfo::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In AlertInfo parser";
  
  strip(hdr);
  ringtone = hdr;
}

void AlertInfo::Print() {
  LOG(DEBUG)<<"In AlertInfo print";
  
   LOG(DEBUG)<<ringtone;
}

string AlertInfo::GetHeader(){
  return ringtone;
}

void Allow::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In Allow parser";
  //values are comma seperated.

  sip_utils::tokenize(hdr, COMMA, methods);
}

void Allow::Print() {
  LOG(DEBUG)<<"In Allow print";
  for(it = methods.begin(); it != methods.end(); it++){
    LOG(DEBUG)<<*it; 
  }
}

string Allow::GetHeader(){
  string hdr;
  
  for(it = methods.begin(); it != methods.end(); it++){
    hdr += (*it) + COMMA; 
  }
  return hdr;
}

void ContentEncoding::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In ContentEncoding parser";
  //values are comma seperated.
  sip_utils::tokenize(hdr, COMMA, encoders);
}

void ContentEncoding::Print() {
  LOG(DEBUG)<<"In ContentEncoding print";
  for(it = encoders.begin(); it != encoders.end(); it++){
    LOG(DEBUG)<<*it; 
  }
}

string ContentEncoding::GetHeader(){
  string hdr;
  
  for(it = encoders.begin(); it != encoders.end(); it++){
    hdr += (*it) + COMMA; 
  }
  return hdr;
}

void ContentLanguage::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In ContentLanguage parser";
  //values are comma seperated.

  sip_utils::tokenize(hdr, COMMA, languages);
}

void ContentLanguage::Print() {
  LOG(DEBUG)<<"In ContentLanguage print";
  for(it = languages.begin(); it != languages.end(); it++){
    LOG(DEBUG)<<*it; 
  }
}

string ContentLanguage::GetHeader(){
  string hdr;
  
  for(it = languages.begin(); it != languages.end(); it++){
    hdr += (*it) + COMMA; 
  }
  return hdr;
}

void ContentLength::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In ContentLength parser";
  strip(hdr);
  content_length = stoi(hdr);
}

void ContentLength::Print() {
  LOG(DEBUG)<<"In ContentLength print";
  LOG(DEBUG)<<content_length; 
}

string ContentLength::GetHeader(){
  return to_string(content_length);
}

void MaxForwards::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In MaxForwards parser";
  strip(hdr);
  maxforwards = stoi(hdr);
}

void MaxForwards::Print() {
  LOG(DEBUG)<<"In MaxForwards print";
  LOG(DEBUG)<<maxforwards; 
}

string MaxForwards::GetHeader(){
  return to_string(maxforwards);
}

void Expires::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In Expires parser";
  strip(hdr);
  expires = stoi(hdr);
}

void Expires::Print() {
  LOG(DEBUG)<<"In Expires print";
  LOG(DEBUG)<<expires; 
}

string Expires::GetHeader(){
  return to_string(expires);
}

void CSeq::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In CSeq parser";
  
  strip(hdr);
  KeyValue kv;
  GetKeyValuePair(hdr, SPACE, kv);

  seq_no = stoi(kv.key);
  method = kv.value;
}

void CSeq::Print() {
  LOG(DEBUG)<<"In CSeq print";
  LOG(DEBUG)<<seq_no<<" "<<method; 
}

string CSeq::GetHeader(){
  return to_string(seq_no) + SPACE + method;
}

void MinExpires::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In MinExpires parser";
  strip(hdr);
  minexpires = stoi(hdr);
}

void MinExpires::Print() {
  LOG(DEBUG)<<"In MinExpires print";
  LOG(DEBUG)<<minexpires; 
}

string MinExpires::GetHeader(){
  return to_string(minexpires);
}

void Subject::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In Subject parser";
  strip(hdr);
  subject = hdr;
}

void Subject::Print() {
  LOG(DEBUG)<<"In Subject print";
  LOG(DEBUG)<<subject; 
}

string Subject::GetHeader(){
  return subject;
}

void Timestamp::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In Timestamp parser";
  strip(hdr);
  timestamp = stoi(hdr);
}

void Timestamp::Print() {
  LOG(DEBUG)<<"In Timestamp parser";
  LOG(DEBUG)<<timestamp; 
}

string Timestamp::GetHeader(){
  return to_string(timestamp);
}

void To::ParseHeader(string& hdr) {
  
  LOG(DEBUG)<<"In To parser";
  //values are comma seperated.
  // params and q values are ; seperated
  vector<string> lparams;
  vector<string>::iterator lit;
  
  tokenize(hdr, SEMICOLON, lparams);
 
  address_spec = lparams[0];
  
  for(lit = lparams.begin() + 1; lit != lparams.end();lit++){
    //Second entry to end are key=value parameters.
    KeyValue kv; 
    GetKeyValuePair(*lit, EQUAL, kv);

    params.insert(make_pair(kv.key, kv.value));
    
  }//end of for loop.
    
  return;
}

void To::Print() {
  LOG(DEBUG)<<"In To print";
  
  LOG(DEBUG)<<address_spec;
  
  map<string, string>::iterator it;
  for(it = params.begin();it != params.end();it++){
    LOG(DEBUG)<<it->first<<SPACE<<it->second;
  }
}


string To::GetHeader(){
  string hdr;
  
  hdr += display_name + address_spec;
  
  map<string, string>::iterator it;
  for(it = params.begin();it != params.end();it++){
    hdr += COLON;
    hdr += it->first + EQUAL + it->second;
  }
  
  return hdr;
}

void From::ParseHeader(string& hdr) {
  
  LOG(DEBUG)<<"In From parser";
  //values are ; seperated.
 
  vector<string> lparams;
  vector<string>::iterator lit;
  
  tokenize(hdr, SEMICOLON, lparams);
 
  address_spec = lparams[0];
  
  for(lit = lparams.begin() + 1; lit != lparams.end();lit++){
    //Second entry to end are key=value parameters.
    KeyValue kv; 
    GetKeyValuePair(*lit, EQUAL, kv);

    params.insert(make_pair(kv.key, kv.value));
    
  }//end of for loop.
    
  return;
}

void From::Print() {
  LOG(DEBUG)<<"In From print";
  LOG(DEBUG)<<address_spec; 
  map<string, string>::iterator it;
  for(it = params.begin();it != params.end();it++){
    LOG(DEBUG)<<it->first<<SPACE<<it->second;
  }
}

string From::GetHeader(){
  string hdr;
  
  hdr += display_name + address_spec;
  
  map<string, string>::iterator it;
  for(it = params.begin();it != params.end();it++){
    hdr += COLON;
    hdr += it->first + EQUAL + it->second;
  }
  
  return hdr;
}

void Supported::ParseHeader(string& hdr) {
  
  LOG(DEBUG)<<"In Supported parser";
  
  //values are comma seperated.
  tokenize(hdr, COMMA, supported);
}

void Supported::Print() {
  LOG(DEBUG)<<"In Supported print";
  
  for(it = supported.begin(); it != supported.end(); it++){
    LOG(DEBUG)<<*it; 
  }
}


void Unsupported::ParseHeader(string& hdr) {
  
  LOG(DEBUG)<<"In Unsupported parser";
  
  //values are comma seperated.
  tokenize(hdr, COMMA, unsupported);
}

void Unsupported::Print() {
  LOG(DEBUG)<<"In Unsupported print";
  
  for(it = unsupported.begin(); it != unsupported.end(); it++){
    LOG(DEBUG)<<*it; 
  }
}

void RetryAfter::ParseHeader(string& hdr) {
  // params and generic values are ; seperated

  LOG(DEBUG)<<"In RetryAfter parser";

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
  LOG(DEBUG)<<"In RetryAfter print";
  LOG(DEBUG)<<retryafter<<SPACE<<comment<<SPACE<<duration;
}

void ProxyRequire::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In ProxyRequire parser";
  
  //values are comma seperated.
  tokenize(hdr, COMMA, require);
}

void ProxyRequire::Print() {
  LOG(DEBUG)<<"In ProxyRequire print";
  
  for(it = require.begin(); it != require.end(); it++){
    LOG(DEBUG)<<*it; 
  }
}

void Require::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In Require parser";
  
  //values are comma seperated.
  tokenize(hdr, COMMA, require);
}

void Require::Print() {
  LOG(DEBUG)<<"In Require print";
  
  for(it = require.begin(); it != require.end(); it++){
    LOG(DEBUG)<<*it; 
  }
}

string Require::GetHeader(){
  string hdr;
  
  for(it = require.begin(); it != require.end(); it++){
    hdr += (*it) + COMMA; 
  }
  
  return hdr;
}

void Route::ParseHeader(string& hdr) {
  
  LOG(DEBUG)<<"In Route parser";
  
  //values are comma seperated.
  // params and q values are ; seperated
  vector<string> lparams;
  vector<string>::iterator lit;
  tokenize(hdr, COMMA, lparams);
 
  //iterate the lparams and get the param and q value.
  for(lit = lparams.begin();lit != lparams.end();lit++) {
    string local = *lit;
    strip(local);
    string tparam;

    GetAddress(local, tparam); 

    KeyValue kv; 

    GetKeyValuePair(tparam, SEMICOLON, kv);
    routes.insert(make_pair(kv.key, kv.value));
  }

    return;
}

void Route::Print() {
  LOG(DEBUG)<<"In Route print";
  
  for(it = routes.begin(); it != routes.end(); it++){
    LOG(DEBUG)<<it->first<<SPACE<<it->second; 
  }

return;
}

void ProxyAuthorization::ParseHeader(string& hdr) {
  
  LOG(DEBUG)<<"In ProxyAuthorization parser";
  
  //values are comma seperated.
  // params and q values are ; seperated
  vector<string> lparams;
  vector<string>::iterator lit;
  tokenize(hdr, COMMA, lparams);
 
  //iterate the lparams and get the param and q value.
  for(lit = lparams.begin();lit != lparams.end();lit++) {
    string local = *lit;
    strip(local);

    KeyValue kv; 
    GetKeyValuePair(local, EQUAL, kv);

   
    credentials.insert(make_pair(kv.key, kv.value));
  }

    return;
}

void ProxyAuthorization::Print() {
  LOG(DEBUG)<<"In ProxyAuthorization print";
  
  for(it = credentials.begin(); it != credentials.end(); it++){
    LOG(DEBUG)<<it->first<<SPACE<<it->second; 
  }

return;
}

void Via::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In Via parser";
  
  //values are comma seperated.
  vector<string> lparams;
  vector<string>::iterator lit;
  
  tokenize(hdr, COMMA, lparams);
 
  //iterate the lparams and get the param and q value.
  for(lit = lparams.begin();lit != lparams.end();lit++) {
    string local = *lit;
    strip(local);

    struct via_param lviaparam;
    
    vector<string> ltoks;
    vector<string>::iterator it;
    
    tokenize(local, SEMICOLON, ltoks);
    
    //first one is sent-by details.
    KeyValue kv; 
    GetKeyValuePair(ltoks[0], SPACE, kv);

    string sent_protocol = kv.key;
    string sent_by = kv.value;
    
    //Get sent-protocol details.
    vector<string> lsentprotocol;
    tokenize(sent_protocol, FORWARDSLASH, lsentprotocol);
    
    if(lsentprotocol.size() == 3){
      lviaparam.sip_type = lsentprotocol[0];
      lviaparam.sip_version = lsentprotocol[1];
      lviaparam.sip_transport = lsentprotocol[2];
    } else {
      //send back 400 BAD REQUEST RESPONSE
    }
    
    // Get sent_by details.    
    GetKeyValuePair(sent_by, COLON, kv);
    
    lviaparam.sip_host = kv.key;
    lviaparam.sip_port = kv.value;
    
    for(it = ltoks.begin() + 1; it != ltoks.end();it++){
      //Second entry to end are key=value parameters.
      KeyValue kv; 
      GetKeyValuePair(*it, EQUAL, kv);

      lviaparam.params.insert(make_pair(kv.key, kv.value));
    
    }//end of inner for loop.
    
    vparam.push_back(lviaparam);
    
  }//end of outer for-loop.

    return;
}

void Via::Print() {
  LOG(DEBUG)<<"In Via print";
  map<string, string>::iterator pit;
  
  for(it = vparam.begin(); it != vparam.end(); it++){
    LOG(DEBUG)<<"SIP TYPE: "<<it->sip_type;
    LOG(DEBUG)<<"SIP VERSION: "<<it->sip_version; 
    LOG(DEBUG)<<"SIP TRANSPORT: "<<it->sip_transport; 
    LOG(DEBUG)<<"SIP HOST: "<<it->sip_host; 
    LOG(DEBUG)<<"SIP PORT: "<<it->sip_port; 
  
    for(pit = it->params.begin(); pit != it->params.end();pit++){
      LOG(DEBUG)<<"SIP PARAM KEY: "<<pit->first;
      LOG(DEBUG)<<"SIP PARAM VALUE: "<<pit->second;
    }  
    
  }
  
return;
}

string Via::GetHeader(){
  
  string hdr;
  map<string, string>::iterator pit;
  
  for(it = vparam.begin(); it != vparam.end(); it++){
    hdr += it->sip_type + FORWARDSLASH + it->sip_version + FORWARDSLASH + it->sip_transport;
    hdr += SPACE + it->sip_host + COLON + it->sip_port;
    
    for(pit = it->params.begin(); pit != it->params.end();pit++){
      hdr += SEMICOLON;
      hdr += pit->first + EQUAL + pit->second;
    }
    
    hdr += COMMA;
  }
  
  //Remove the last extra character.
  return hdr.substr(0, hdr.length() - 1);
}

void Contact::ParseHeader(string& hdr) {
  
  LOG(DEBUG)<<"In Contact parser";
  
  //values are comma seperated.
  vector<string> lparams;
  vector<string>::iterator lit;
  
  tokenize(hdr, COMMA, lparams);
 
  //iterate the lparams and get the param and q value.
  for(lit = lparams.begin();lit != lparams.end();lit++) {
    string local = *lit;
    strip(local);

    struct contacts lcparam;
    
    vector<string> ltoks;
    vector<string>::iterator it;
    
    tokenize(local, SEMICOLON, ltoks);
    
    //first one is sent-by details.
    lcparam.addr_spec = local;
    
    for(it = ltoks.begin() + 1; it != ltoks.end();it++){
      //Second entry to end are key=value parameters.
      KeyValue kv; 
      GetKeyValuePair(*it, EQUAL, kv);

      lcparam.params.insert(make_pair(kv.key, kv.value));
    
    }//end of inner for loop.
    
    cparams.push_back(lcparam);
    
  }//end of outer for-loop.

    return;
}

void Contact::Print() {
  LOG(DEBUG)<<"In Contact print";

  vector<contacts>::iterator it;
  
  for(it = cparams.begin(); it != cparams.end();it++){
    LOG(DEBUG)<<"SIP ADDR: "<<(*it).addr_spec;
    map<string, string>::iterator pit;
    for(pit = (*it).params.begin(); pit != (*it).params.end();pit++){
      LOG(DEBUG)<<"SIP PARAM KEY: "<<pit->first;
      LOG(DEBUG)<<"SIP PARAM VALUE: "<<pit->second;
    }  
  }
return;
}

string Contact::GetHeader() {
  string hdr;
  
  vector<contacts>::iterator it;
  
  for(it = cparams.begin(); it != cparams.end();it++){
    hdr += it->addr_spec;
    
    map<string, string>::iterator pit;
    for(pit = (*it).params.begin(); pit != (*it).params.end();pit++){
      hdr += SEMICOLON;
      hdr += pit->first + EQUAL + pit->second;
     
    }
    hdr += COMMA;
  }
  
// last one should not get a comma.
return hdr.substr(0, hdr.length() - 1);
}

void Content_Type::ParseHeader(string& hdr) {
  LOG(DEBUG)<<"In Content_Type parser";

  strip(hdr);
  content_type = hdr;
}

void Content_Type::Print() {
  LOG(DEBUG)<<"In Content-Type print";
  LOG(DEBUG)<<content_type;
}

string Content_Type::GetHeader(){
  return content_type;
}