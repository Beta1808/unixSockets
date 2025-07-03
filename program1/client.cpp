#include "client.h"

Client::Client(int domain, int type, int port):
            domain_(domain),
            type_(type),
            port_(port)
{
}

Client::~Client()
{
	if (shutdown(client_socket_, SHUT_RDWR) == -1)
		std::cout << "Ошибка при закрытии соединения.\n";
	if (close(client_socket_) == -1)
		std::cout << "Ошибка при закрытии сокета.\n";
}

int Client::createSocket()
{
    client_socket_ = socket(domain_, type_, port_);
    if(client_socket_ < 0)
    {
        std::cerr << "Error: clientSocket" << std::endl;
        return 1;
    }
    return client_socket_;
}

void Client::sendMessage(const char *data)
{
    send(client_socket_, data, strlen(data), 0);
}

sockaddr_in Client::getAddress() const
{
    return address_;
}

int Client::getSocket() const
{
    return client_socket_;
}

bool Client::Bind()
{
    address_.sin_family = domain_;
    address_.sin_port = htons(port_); 
    address_.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if(connect(client_socket_, (sockaddr *)&address_, sizeof(address_)) < 0) {
        std::cerr << "Error: connect" << std::endl;
        return false;
    }
    return true;
}

bool Client::isConnected() // проверка подключения
{
    if(connect(client_socket_, (sockaddr *)&address_, sizeof(address_)) < 0)
    {}
    return false;
}

int Client::getDomain() const
{
    return domain_;
}

int Client::getType() const
{
    return type_;
}

int Client::getPort() const
{
    return port_;
}


