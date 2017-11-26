//Util for right-strip

#ifndef SIP_H
#include "SIP.h"
#endif

#ifndef SIPREQUEST_H
#include "SIPRequest.h"
#endif

namespace sip_utils {

	void lstrip(string& str, const string splitter) {
	    size_t found = str.find_first_not_of(splitter);

	    if(found != string::npos){
	      str = str.substr(found); 
	    } else {
	      str.clear();
	    }

	    return;
	}

	void rstrip(string& str, const string splitter) {
	    size_t found = str.find_last_not_of(splitter);

	    if(found != string::npos){
	      str.erase(found + 1); 
	    } else {
	      str.clear();
	    }
	    
	    return;
	}

	void strip(string& str){
	   lstrip(str);
	   rstrip(str);

	   return;
	}

	void tokenize(string& str, const string tokenizer, vector<string>& items) {
		
	  set<string> ltokens;	
	  
	  size_t index = 0;
	  string local;

	  while(index < str.size()){
	     size_t found = str.find_first_of(tokenizer, index);

	     if(found != string::npos){
			local = str.substr(index, found - index);
			index = found + 1;
			
			strip(local);
			if(!local.empty()) {
				if(ltokens.find(local) == ltokens.end()){
					ltokens.insert(local);
					items.push_back(local);
					
				}
				
			}
	     } else {
	     	local = str.substr(index);
	     	
	     	strip(local);
	     	if(!local.empty()) {
	     		if(ltokens.find(local) == ltokens.end()){
	     			ltokens.insert(local);
	     			items.push_back(local);
	     			
	     		}
	     		
	     	}
	     	break; //otherwise it will loop infinitely.
	     }
	  } // end of while
	  return;
		
	}

	void GetKeyValuePair(string str, string separator, KeyValue& res) {
	    res.key.clear();
	    res.value.clear();

	    size_t found = str.find_first_of(separator);
	    if(found != string::npos) {
	      res.key = str.substr(0, found);
	      res.value = str.substr(found + 1);
	    } else {
	      res.key = str;
	    }

	    strip(res.key);
	    strip(res.value);

	return;

	}

	void GetAddress(string& hdr, string& addr) {
	   // Remove the < and > and return only the adddress.
        strip(hdr);
        lstrip(hdr, LABRACKET);
        rstrip(hdr, RABRACKET);

	    KeyValue kv;
        GetKeyValuePair(hdr, COLON, kv);
        strip(kv.value);
     
        addr = kv.value;
	}

}
string HdrToStringConverter(SIPHEADER hdr){
  
  switch(hdr){
    
    case VIA:
       return "Via";
    case FROM:
       return "From";
    case TO:
       return "To";
    case CALL_ID:
       return "Call-ID";
    case CSEQ:
       return "CSeq";
    case CONTACT:
       return "Contact";
    case MAX_FORWARDS:
       return "Max-Forwards";
    case SUBJECT:
       return "Subject";
    case CONTENT_TYPE:
       return "Content-Type";
    case CONTENT_LENGTH:
       return "Content-Length";
    default:
       LOG(ERROR)<<"Unknown Header";
    
  }
}

//}//end of namespace
