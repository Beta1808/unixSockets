#ifndef CLIENT_H
#define CLIENT_H


#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <mutex>

class Client {
public:
    Client(int domain, int type, int port);

    Client(const Client &client) = delete;
    Client& operator=(const Client &client) = delete;

    Client(Client &&client) = default;
    Client& operator=(Client&& client) = default;

    ~Client();

    int createSocket();

    void sendMessage(const char *data);

    bool Bind();

    bool isConnected();

    sockaddr_in getAddress() const;
    int getSocket() const;
    int getDomain() const;
    int getType() const;
    int getPort() const;
private:
    std::mutex data_mutex;

    sockaddr_in address_{};
    int listener_{};
    int client_socket_{};
    int domain_;
    int type_;
    int port_;
};



#endif //CLIENT_H