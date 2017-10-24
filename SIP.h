#ifndef SIP_H
#define SIP_H


#include<string>
#include<set>
#include<iostream>
#include<map>

using namespace std;

namespace sip_utils {

   const string COMMA(",");
   const string SEMICOLON(";");
   const string COLON(":");
   const string EQUAL("=");
   const string SPACE(" ");
   const string LABRACKET("<");
   const string RABRACKET(">");
   const string WHITESPACES (" \t\f\v\n\r");

   class KeyValue {
      public:
        string key;
        string value;
   };

   void lstrip(string& str, const string splitter = SPACE);
   void rstrip(string& str, const string splitter = WHITESPACES);
   void strip(string& str);
   void tokenize(string& str, const string tokenizer, set<string>& items);
   void GetKeyValuePair(string str, string separator, KeyValue& kv);
   void GetAddress(string& str, string& addr);


}

#endif
