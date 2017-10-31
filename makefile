CC=g++
CFLAGS=-I. -I./se  -I./os -std=c++11

sip: se/SIPUtils.o se/SIPHeaderParser.o se/SIPMethodParser.o os/SIPSocket.o os/main.o
	$(CC) -o sip SIPUtils.o SIPHeaderParser.o SIPSocket.o SIPMethodParser.o main.o
	
os/SIPSocket.o:  os/SIPSocket.cpp 
	$(CC) $(CFLAGS) -c os/SIPSocket.cpp
	
se/SIPHeaderParser.o:  se/SIPHeaderParser.cpp 
	$(CC) $(CFLAGS) -c se/SIPHeaderParser.cpp

se/SIPMethodParser.o:  se/SIPMethodParser.cpp 
	$(CC) $(CFLAGS) -c se/SIPMethodParser.cpp
	
se/SIPUtils.o:  se/SIPUtils.cpp 
	$(CC) $(CFLAGS) -c se/SIPUtils.cpp
	
os/main.o: os/main.cpp
	$(CC) $(CFLAGS) -c os/main.cpp 
	
clean :
	rm -f *.o