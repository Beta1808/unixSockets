#include "client.h"

Client::Client(int domain, int type, int port):
            _domain(domain),
            _type(type),
            _port(port)
{
}

Client::~Client()
{
    close(_client_socket);
}

int Client::CreateSocket()
{
    _client_socket = socket(_domain, _type, _port);
    if(_client_socket < 0)
    {
        std::cerr << "Error: clientSocket" << std::endl;
        return 1;
    }
    return _client_socket;
}

void Client::SendMessage(const char *data)
{
    send(_client_socket, data, strlen(data), 0);
}

sockaddr_in Client::GetAddress() const
{
    return _address;
}

int Client::GetSocket() const
{
    return _client_socket;
}

bool Client::ConnectToAddress()
{
    _address.sin_family = _domain;
    _address.sin_port = htons(_port); // или любой другой порт...
    _address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if(connect(_client_socket, (sockaddr *)&_address, sizeof(_address)) < 0) {
        std::cerr << "Error: connect" << std::endl;
        return false;
    }
    return true;
}

int Client::GetDomain() const
{
    return _domain;
}

int Client::GetType() const
{
    return _type;
}

int Client::GetPort() const
{
    return _port;
}


