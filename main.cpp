#include "common.h"
#include "Server.h"

int main()
{
    TCPServer server;
    server.start(1666);
    while(server.is_running()) 
	{ 
		Common::sleep(1);
	}
    return 0;
}
