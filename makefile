CC=g++

CFLAGS=-I. -I./se  -I./os -I./tr -I./tn -I./tr -I./ua -I./el -std=c++11 -DELPP_THREAD_SAFE
CXXFLAGS=-I. -I./el -std=c++11 -DELPP_DEFAULT_LOG_FILE='"logs/sip.log"' -DELPP_UTC_DATETIME=ON -DELPP_THREAD_SAFE 
#-DELPP_DISABLE_LOGS

LDFLAGS=-lpthread -lrt

sip: se/SIPUtils.o se/SIPHeaderParser.o se/SIPRawDataParser.o se/SIPServerSE.o os/SIPSocket.o se/SIPServerRequest.o se/SIPServerResponse.o tn/SIPServerTn.o tr/SIPServerTr.o os/SIPTimer.o ua/SIPUA.o el/easylogging++.o os/main.o
	$(CC) -o sip SIPUtils.o SIPHeaderParser.o SIPSocket.o  SIPRawDataParser.o SIPServerSE.o SIPServerRequest.o SIPServerResponse.o SIPServerTn.o SIPServerTr.o SIPUA.o SIPTimer.o el/easylogging++.o main.o $(LDFLAGS)
	
se/SIPHeaderParser.o:  se/SIPHeaderParser.cpp 
	$(CC) $(CFLAGS) -c se/SIPHeaderParser.cpp

se/SIPRawDataParser.o:  se/SIPRawDataParser.cpp 
	$(CC) $(CFLAGS) -c se/SIPRawDataParser.cpp
	
se/SIPUtils.o:  se/SIPUtils.cpp 
	$(CC) $(CFLAGS) -c se/SIPUtils.cpp

se/SIPServerRequest.o: se/SIPServerRequest.cpp
	$(CC) $(CFLAGS) -c se/SIPServerRequest.cpp
	 
se/SIPServerResponse.o: se/SIPServerResponse.cpp
	$(CC) $(CFLAGS) -c se/SIPServerResponse.cpp
	
se/SIPServerSE.o: se/SIPServerSE.cpp
	$(CC) $(CFLAGS) -c se/SIPServerSE.cpp
	
tn/SIPServerTn.o: tn/SIPServerTn.cpp
	$(CC) $(CFLAGS) -c tn/SIPServerTn.cpp
	
tr/SIPServerTr.o: tr/SIPServerTr.cpp
	$(CC) $(CFLAGS) -c tr/SIPServerTr.cpp
	
ua/SIPUA.o: ua/SIPUA.cpp
	$(CC) $(CFLAGS) -c ua/SIPUA.cpp
	
os/SIPSocket.o:  os/SIPSocket.cpp 
	$(CC) $(CFLAGS) -c os/SIPSocket.cpp
	
os/SIPTimer.o: os/SIPTimer.cpp
	$(CC) $(CFLAGS) -c os/SIPTimer.cpp
	
el/easylogging.o: el/easylogging.cpp
	$(CC) $(CXXFLAGS) -c el/easylogging.cpp

os/main.o: os/main.cpp
	$(CC) $(CFLAGS) -c os/main.cpp 

clean :
	rm -f *.o
	rm -f el/*.o
	rm -f logs/*
	rm -f sip