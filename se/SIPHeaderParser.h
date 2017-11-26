#pragma once

#ifndef SIP_H
#include "SIP.h"
#endif

#ifndef SIPHEADERPARSER_H
#define SIPHEADERPARSER_H

class HeaderBase {
    public:
        virtual void ParseHeader(string& hdr);
        virtual void Print();
        virtual string GetHeader();
};

class AcceptEncoding : public HeaderBase {
   vector<string> encoders;
   vector<string>::iterator it;
public:
   AcceptEncoding(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class AcceptLanguage : public HeaderBase {
   vector<string> languages;
   vector<string>::iterator it;
public:
   AcceptLanguage(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class Accept : public HeaderBase {
   map<string, float> params;
   map<string, float>::iterator it;
public:
   Accept(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class CallID : public HeaderBase {
   string callid;
public:
   CallID(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class AlertInfo : public HeaderBase {
   string ringtone;
public:
   AlertInfo(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class Allow : public HeaderBase {
   vector<string> methods;
   vector<string>::iterator it;
public:
   Allow(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class ContentEncoding : public HeaderBase {
   vector<string> encoders;
   vector<string>::iterator it;
public:
   ContentEncoding(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class ContentLanguage : public HeaderBase {
   vector<string> languages;
   vector<string>::iterator it;
public:
   ContentLanguage(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class ContentLength : public HeaderBase {
   unsigned long content_length;
public:
   ContentLength(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class MaxForwards : public HeaderBase {
   unsigned long maxforwards;
public:
   MaxForwards(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class Expires : public HeaderBase {
   unsigned int expires;
public:
   Expires(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class CSeq : public HeaderBase {
   unsigned int seq_no;
   string method;
public:
   CSeq(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class MinExpires : public HeaderBase {
   unsigned int minexpires;
public:
   MinExpires(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class Subject : public HeaderBase {
   string subject;
public:
   Subject(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class To : public HeaderBase {
   string address_spec;
   string display_name;
   map<string, string> params;
public:
   To(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class From : public HeaderBase {
   string address_spec;
   string display_name;
   map<string, string> params;
public:
   From(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class Timestamp : public HeaderBase {
   unsigned int timestamp;
public:
   Timestamp(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class Supported : public HeaderBase {
   vector<string> supported;
   vector<string>::iterator it;
public:
   Supported(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Unsupported : public HeaderBase {
   vector<string> unsupported;
   vector<string>::iterator it;
public:
   Unsupported(){};
   void ParseHeader(string& hdr);
   void Print();
};

class RetryAfter : public HeaderBase {
   unsigned long duration;
   unsigned long retryafter;
   string comment;
public:
   RetryAfter():duration(0){};
   void ParseHeader(string& hdr);
   void Print();
};

class ProxyRequire : public HeaderBase {
   vector<string> require;
   vector<string>::iterator it;
public:
   ProxyRequire(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Require : public HeaderBase {
   vector<string> require;
   vector<string>::iterator it;
public:
   Require(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class Route : public HeaderBase {
   set<pair<string, string> > routes;
   set<pair<string, string> >::iterator it;
public:
   Route(){};
   void ParseHeader(string& hdr);
   void Print();
};

class ProxyAuthorization : public HeaderBase {
   map<string, string> credentials;
   map<string, string>::iterator it;
public:
   ProxyAuthorization(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Via : public HeaderBase {
   struct via_param {
      string sip_type;
      string sip_version;
      string sip_transport;
      string sip_host;
      string sip_port;
      map<string, string> params;
   };
   
   vector<via_param> vparam;
   vector<via_param>::iterator it;
public:
   Via(){};
   void ParseHeader(string& hdr);
   void Print();
   string GetHeader();
};

class Contact : public HeaderBase {
   struct contacts {
      string addr_spec;
      map<string, string> params;
   };
   
   vector<contacts> cparams;
  public:
    Contact(){};
    void ParseHeader(string& hdr);
    void Print();
    string GetHeader();
};


class Content_Type : public HeaderBase {
   string content_type;
   public:
    Content_Type(){};
    void ParseHeader(string& hdr);
    void Print();
    string GetHeader();
};

#endif

/*
// Rule names are case-insensitive
message - header = (
	/ Authentication - Info 
	/ Authorization 
	/ Call - Info 
	/ Contact 
	/ Content - Disposition 
	/ Content - Type 
	/ Date 
	/ Error - Info 
	/ In - Reply - To 
	/ MIME - Version 
	/ Organization 
	/ Priority 
	/ Proxy - Authenticate 
	/ Record - Route 
	/ Reply - To
	/ Server 
	/ User - Agent 
	/ Warning 
	/ WWW - Authenticate 
	/ extension - header) 
*/
