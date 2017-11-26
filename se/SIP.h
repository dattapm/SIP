#ifndef SIP_H
#define SIP_H

#ifndef LOGGER_H
#include "easylogging++.h"
#endif

#include<string>
#include<set>
#include<iostream>
#include<map>
#include<sstream>
#include<vector>
#include<typeinfo>
#include<queue>
#include<pthread.h>
#include <cctype>

//Timer related.
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

#ifndef SIPTIMER_H
#include "SIPTimer.h"
#endif

#include "easylogging++.h"

using namespace std;

namespace sip_utils {

   const string COMMA(",");
   const string SEMICOLON(";");
   const string COLON(":");
   const string EQUAL("=");
   const string SPACE(" ");
   const string LABRACKET("<");
   const string RABRACKET(">");
   const string FORWARDSLASH("/");
   //const string BACKSLASH("\");
   const string WHITESPACES (" \t\f\v\n\r");
   const string NEWLINE("\n");

   enum SOCK_TYPE {
     TCP,
     UDP,
     SCTP
   };
   
   class KeyValue {
      public:
        string key;
        string value;
   };

   struct SocketParams {
     pthread_t tid;
     long sockfd;
     SOCK_TYPE sock_type;
   };
    
   void lstrip(string& str, const string splitter = SPACE);
   void rstrip(string& str, const string splitter = WHITESPACES);
   void strip(string& str);
   void tokenize(string& str, const string tokenizer, vector<string>& items);
   void GetKeyValuePair(string str, string separator, KeyValue& kv);
   void GetAddress(string& str, string& addr);
   
   void* ProcessSIPData(void*);

};

#endif
