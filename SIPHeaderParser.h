#pragma once

#ifndef SIP_H
#include "SIP.h"
#endif

#ifndef SIPHEADERPARSER_H
#define SIPHEADERPARSER_H


class HeaderBase {

    public:
        virtual void ParseHeader(string& hdr) = 0;
        virtual void Print() = 0;
};

class AcceptEncoding : public HeaderBase {
   set<string> encoders;
   set<string>::iterator it;
public:
   AcceptEncoding(){};
   void ParseHeader(string& hdr);
   void Print();
};

class AcceptLanguage : public HeaderBase {
   set<string> languages;
   set<string>::iterator it;
public:
   AcceptLanguage(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Accept : public HeaderBase {
   map<string, float> params;
   map<string, float>::iterator it;
public:
   Accept(){};
   void ParseHeader(string& hdr);
   void Print();
};

class CallID : public HeaderBase {
   string callid;
public:
   CallID(){};
   void ParseHeader(string& hdr);
   void Print();
};

class AlertInfo : public HeaderBase {
   string ringtone;
public:
   AlertInfo(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Allow : public HeaderBase {
   set<string> methods;
   set<string>::iterator it;
public:
   Allow(){};
   void ParseHeader(string& hdr);
   void Print();
};

class ContentEncoding : public HeaderBase {
   set<string> encoders;
   set<string>::iterator it;
public:
   ContentEncoding(){};
   void ParseHeader(string& hdr);
   void Print();
};

class ContentLanguage : public HeaderBase {
   set<string> languages;
   set<string>::iterator it;
public:
   ContentLanguage(){};
   void ParseHeader(string& hdr);
   void Print();
};

class ContentLength : public HeaderBase {
   unsigned long content_length;
public:
   ContentLength(){};
   void ParseHeader(string& hdr);
   void Print();
};

class MaxForwards : public HeaderBase {
   unsigned long maxforwards;
public:
   MaxForwards(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Expires : public HeaderBase {
   unsigned int expires;
public:
   Expires(){};
   void ParseHeader(string& hdr);
   void Print();
};

class CSeq : public HeaderBase {
   unsigned int seq_no;
   string method;
public:
   CSeq(){};
   void ParseHeader(string& hdr);
   void Print();
};

class MinExpires : public HeaderBase {
   unsigned int minexpires;
public:
   MinExpires(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Subject : public HeaderBase {
   string subject;
public:
   Subject(){};
   void ParseHeader(string& hdr);
   void Print();
};

class To : public HeaderBase {
   string address;
   string display_name;
   string tg_param;
public:
   To(){};
   void ParseHeader(string& hdr);
   void Print();
};


class Timestamp : public HeaderBase {
   unsigned int timestamp;
public:
   Timestamp(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Supported : public HeaderBase {
   set<string> supported;
   set<string>::iterator it;
public:
   Supported(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Unsupported : public HeaderBase {
   set<string> unsupported;
   set<string>::iterator it;
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
   set<string> require;
   set<string>::iterator it;
public:
   ProxyRequire(){};
   void ParseHeader(string& hdr);
   void Print();
};

class Require : public HeaderBase {
   set<string> require;
   set<string>::iterator it;
public:
   Require(){};
   void ParseHeader(string& hdr);
   void Print();
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
	/ From 
	/ In - Reply - To 
	/ MIME - Version 
	/ Organization 
	/ Priority 
	/ Proxy - Authenticate 
	/ Record - Route 
	/ Reply - To
	/ Server 
	/ To 
	/ User - Agent 
	/ Via 
	/ Warning 
	/ WWW - Authenticate 
	/ extension - header) 
*/
