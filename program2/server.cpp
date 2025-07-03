#include "server.h"

Server::Server(int domain, int type, int port):
               domain_(domain),
               type_(type),
               port_(port)
{
}

Server::~Server()
{
	if (close(serverSocket_) == -1)
		std::cout << "Ошибка при закрытии сокета сервера.\n";
}


// void Server::start()
// {
//     acceptClient();
// }

void Server::createSocket()
{
    serverSocket_ = socket(domain_, type_, port_);

    if (serverSocket_ < 0 )
    {
        std::cerr << "Error: Ошибка создания сокета!" << std::endl;
    }
}

bool Server::bindSocket()
{
    address_.sin_family = domain_;
    address_.sin_port = htons(port_); 
    address_.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        
    int listen(serverSocket_);

    if (connect(serverSocket_, (sockaddr *)& address_, sizeof(address_)) < 0)
    {
        std::cerr << "Error: Не удалось связать сокет!" << std::endl;
        return false;
    }

    return true;
}


// void Server::acceptClient()
// {
//     	fcntl(serverSocket_, F_SETFL, O_NONBLOCK); // операции чтения и записи не блокируют выполнение программы, если данные в данный момент недоступны
	
// 	while (true) {
// 		clientSocket_ = accept(serverSocket_, (struct sockaddr*)&clientAddr_, &clientAddrLen_);
// 		if (clientSocket_ == -1) {
// 			if (errno == EWOULDBLOCK || errno == EAGAIN) { // сокет маркирован как неблокирующий, но нет ни одного соединения, которое можно было бы принять
// 				usleep(100000);
// 				continue;
// 			}
// 			throw std::runtime_error("Ошибка принятия соединения на сокете.");
// 		}
// 		std::cout << "Клиент успешно соединён.\n";
		
// 		receiveData();
// 	}
// }

void Server::receiveData()
{
    	char buffer[1024];
	while (true) {
		int bytesReceived = recv(clientSocket_, buffer, sizeof(buffer) - 1, 0);
		if (bytesReceived <= 0) {
			std::cout << "Клиент отключился.\n";
			break;
		}
		buffer[bytesReceived] = '\0';
		// handleData(buffer);
	}
	
	if (close(clientSocket_) == -1)
		std::cout << "Ошибка при закрытии сокета клиента.\n";
}

void Server::handleData()
{
	// nlohmann::json j = nlohmann::json::parse(buf);
	// std::map data = j.get<std::map<char, unsigned>>();
	// std::string newstr = "";
	// std::vector<std::pair<char, unsigned>> v(data.begin(), data.end());
	// std::sort(v.begin(), v.end(), [](const auto& left, const auto& right) {
	// 	return left.second < right.second;
	// });
	// for (const auto& [first, second] : v) {
	// 	for (unsigned i = 0; i < second; i++) {
	// 		newstr += first;
	// 	}
	// }
    std::cout << "Получено: " /*<< newstr */ << std::endl;
}
