#include "ConnectedClient.h"

ConnectedClient::ConnectedClient(TCPServer* server, int connected_socket, uint32_t ip, uint16_t port)
{
    this->server = server;
    this->connected_socket = connected_socket;
    this->ip = ip;
    this->port = port;
	this->start();
    pthread_create(&thread_id, NULL, run, (void*)this);
}


vector<Command*> ConnectedClient::listCommands() 
{ 
	return server->listCommands(); 
}

void ConnectedClient::putline(string str)
{
    send(connected_socket, str.c_str(), str.length(), 0);
}

ConnectedClient::~ConnectedClient()
{
    disconnect();
}

void ConnectedClient::disconnect()
{
    shutdown(connected_socket, SHUT_RDWR);
}

string ConnectedClient::getline(bool asterisks)
{
    string line("");
    char c;
    size_t rxbytes;
    do {
        rxbytes = recv(connected_socket, &c, 1, 0);
        if(rxbytes == 1 && c>=32)
        {
            line += c;
            if(asterisks) c = '*';
            send(connected_socket, &c, 1, 0); //echo
        }
		if (rxbytes == -1) { this->stop(); throw ::exception("client disconnected"); }
    } while (rxbytes==1 && c!='\r');
    return line;
}

void* ConnectedClient::run(void* arg)
{
    ConnectedClient * client = (ConnectedClient*)arg;

    client->putline("User: ");
    client->user = client->getline(false);
    cout << client->user << endl;

    client->putline(Common::EOLN + "Pass: ");
    client->pass = client->getline(true);
    cout << client->pass << endl;

    string c("");
    do 
	{
        client->putline(Common::EOLN + "Cmd: ");
		try {
			c = client->getline();
		} 
		catch(exception e)
		{
			client->putline(Common::EOLN + e.what());
			break;
		}

        cout << client->user << ": " << c << endl;

		try 
		{
			client->server->cmdEngine->exec(client, c);
		} 
		catch(exception e)
		{
			client->putline(Common::EOLN + e.what());
		}
    } while(client->is_running());

    client->disconnect();
    client->server->removeClient(client);
    return NULL;
}
