#include "common.h"
#include <string>

Common common;

class exception
{
protected:
	std::string s;
public:
	exception(std::string s) : s(s) { }
	std::string what() { return s; }
};

 void Common::sleep(uint32_t s) 
{ 
	#ifdef WIN32
	Sleep(1000*s);
	#else
	::sleep(s);
	#endif
}

Common::Common()
{
	#ifdef WIN32
	WORD wVersionRequested = MAKEWORD(2, 2);
	WSADATA wsaData;
	if(0 != WSAStartup(wVersionRequested, &wsaData))
	{
		cerr << "problem: WSAStartup" << endl;
		throw ::exception("WSAStartup");
	}
	#endif
}

Common::~Common()
{
	#ifdef WIN32
	WSACleanup();
	#endif
}


std::string Common::EOLN = "\r\n";