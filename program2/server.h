#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

class Server
{
public:
    Server(int domain, int type, int port);
    ~Server();
    
    void start();
    void createSocket();
    bool bindSocket();
    void listenForClient();
    void acceptClient();
    void receiveData();
    void handleData();

private:
    sockaddr_in address_;
    socklen_t clientAddrLen_;
    int port_;
    int serverSocket_;
    int clientSocket_;
    int domain_;
    int type_;
};



#endif // SERVER_H