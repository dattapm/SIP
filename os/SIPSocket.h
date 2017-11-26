
#ifndef SIPSOCKET_H
#define SIPSOCKET_H

#ifndef LOGGER_H
#include "easylogging++.h"
#endif

#include<iostream>
using namespace std;

#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#include<unistd.h>
#include<string.h>
#include<netdb.h>
#include<errno.h>

#define MAXLINE 1024
#define QUEUE 1024

#ifndef HAVE_BZERO
#define bzero(ptr, n) memset(ptr, 0, n)
#endif


int CreateTCPSocket(const char*);
int CreateUDPSocket(const char*);
int ReadSIPDataFromSocket(int, char* );

#endif