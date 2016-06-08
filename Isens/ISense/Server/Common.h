#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include <ctime>
#include <exception> 
#include <cstdint> 

//#define WIN32 -- z automatu?

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN
	#include <WinSock2.h>
	#include <Ws2tcpip.h>
	#define SHUT_RDWR SD_BOTH
	typedef int	socklen_t;
	//void sleep(uint32_t s);
	#pragma comment(lib, "ws2_32.lib")
	#pragma comment(lib, "pthreadVC2.lib")
#else
	#include <arpa/inet.h>
	#include <sys/socket.h>
	#include <unistd.h>
#endif

class Common
{
public:
	Common();
	~Common();
	static void sleep(uint32_t s);
	static std::string EOLN;
};


using namespace std;


