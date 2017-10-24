#ifndef SIP_h
#include "SIP.h"
#endif

#ifndef SIPHEADERPARSER_H
#include "SIPHeaderPArser.h"
#endif

using namespace sip_utils;

int main() {
 string tmp1("120 (I’m in a meeting);duration=3600");
 string tmp2("120;duration=3600");
 string tmp3("120 (I’m in a meeting)");
 string tmp4("120");
 /*
 //string  tmp("  123456   INVITE  ");
 string tmp("zip;q = 10, abc;q=, nbv , , gunzip;,datta;q=12.567");
 //string tmp("   iabc24795bcd wo;eo ");
 //string tmp("INVITE, ACK, OPTIONS, CANCEL, BYE");

 string tmp("The Operator <sip:operator@cs.columbia.edu>;tag=287447");
 string tmp("zip, abc, nbv , , gunzip");
 HeaderBase *h = new AcceptEncoding();
 h->ParseHeader(tmp);
 h->Print();

 HeaderBase *h = new AcceptLanguage();
 h->ParseHeader(tmp);
 h->Print();
 HeaderBase *h = new Accept();
 h->ParseHeader(tmp);
 h->Print();
 HeaderBase *h = new CallID();
 h->ParseHeader(tmp);
 h->Print();

 HeaderBase *h = new Allow();
 h->ParseHeader(tmp);
 h->Print();
 HeaderBase *h = new ContentLength();
 h->ParseHeader(tmp);
 h->Print();
 HeaderBase *h = new CSeq();
 h->ParseHeader(tmp);
 h->Print();
 HeaderBase *h1 = new RetryAfter();
 h1->ParseHeader(tmp1);
 h1->Print();
 HeaderBase *h2 = new RetryAfter();
 h2->ParseHeader(tmp2);
 h2->Print();
 HeaderBase *h3 = new RetryAfter();
 h3->ParseHeader(tmp3);
 h3->Print();
 HeaderBase *h4 = new RetryAfter();
 h4->ParseHeader(tmp4);
 h4->Print();


        KeyValue kv;
        string sep1 = ";";
        string sep2 = "=";

        GetKeyValuePair(tmp, sep1, kv);
        //string tmp1 = kv->value;
        std::cout<<"DATTA: "<<kv->value<<std::endl;
        GetKeyValuePair(kv->value, sep2, kv);
        string t = "     ";
        string t1 = "   abcd  ";
        string t2 = "   abcd";
        string t3 = "   abcd uhruhe   ";
        string t4 = "";

        lstrip(t);
        lstrip(t1);
        lstrip(t2);
        lstrip(t3);
        lstrip(t4);

        std::cout<<t<<"END"<<std::endl;
        std::cout<<t1<<"END"<<std::endl;
        std::cout<<t2<<"END"<<std::endl;
        std::cout<<t3<<"END"<<std::endl;
        std::cout<<t4<<"END"<<std::endl;
        rstrip(t);
        rstrip(t1);
        rstrip(t2);
        rstrip(t3);
        rstrip(t4);

        std::cout<<t<<"END"<<std::endl;
        std::cout<<t1<<"END"<<std::endl;
        std::cout<<t2<<"END"<<std::endl;
        std::cout<<t3<<"END"<<std::endl;
        std::cout<<t4<<"END"<<std::endl;

        strip(t);
        strip(t1);
        strip(t2);
        strip(t3);
        strip(t4);

        std::cout<<t<<"END"<<std::endl;
        std::cout<<t1<<"END"<<std::endl;
        std::cout<<t2<<"END"<<std::endl;
        std::cout<<t3<<"END"<<std::endl;
        std::cout<<t4<<"END"<<std::endl;



        //string t = "zip;abc ; pqr; sdf ;any_str%; ";
        string t = "zip abc  pqr df any_str%   ";
        //string t = " a ";
        string tokenizer = " %;_";
        set<string> res;
        tokenize(t,tokenizer, res);

        set<string>::iterator it;

        for(it = res.begin(); it != res.end(); it++){
          std::cout<<*it<<"END"<<std::endl;

         }

        free(kv);
        //string tmp =" The Operator <sip:operator@cs.columbia.edu>;tag=287447";
        string tmp ="  < sip:operator@cs.columbia.edu  >  ";
        string addr;
        GetAddress(tmp, addr);
        std::cout<<"ADDR: "<<addr<<std::endl;
 string tmp7 = "<sip:bigbox3.site3.atlanta.com;lr>, < sip:server10.biloxi.com;lr>, <sip:bigbox4.site3.atlanta.com;lr>, <sip:server11.biloxi.com;lr>";

 HeaderBase *h4 = new Route();
 h4->ParseHeader(tmp7);
 h4->Print();
*/
   string t = """Digest username= 'Alice', realm='atlanta.com', nonce= 'c60f3082ee1212b402a21831ae', response='245f23415f11432b3434341c022' """;
 HeaderBase *h4 = new ProxyAuthorization();
 h4->ParseHeader(t);
 h4->Print();

}
