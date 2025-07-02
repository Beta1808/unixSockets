#pragma once

#ifndef CLIENT_H
#define CLIENT_H


#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

class Client {
public:
    Client(int domain, int type, int port);

    Client(const Client &client) = delete;
    Client& operator=(const Client &client) = delete;

    Client(Client &&client) = default;
    Client& operator=(Client&& client) = default;

    ~Client();

    int CreateSocket();

    void SendMessage(const char *data);

    bool ConnectToAddress();
    bool ConnectToAddress(sockaddr_in &address);

    sockaddr_in GetAddress() const;
    int GetSocket() const;
    int GetDomain() const;
    int GetType() const;
    int GetPort() const;
private:
    sockaddr_in _address{};
    int _listener{};
    int _client_socket{};
    int _domain;
    int _type;
    int _port;
};



#endif //CLIENTSERVER_SERVER_H