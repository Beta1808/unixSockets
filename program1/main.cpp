#include <iostream>
#include <string>

#include "client.h"
#include "buffer.h"



void inputData()
{
    while(true)
    {
        std::string str;
        getline(std::cin, str);
        if (str.size() > 64 || str.empty())
        {
            std::cerr << "Error: Ошибка ввода!" << std::endl;
        }
    

    	bool valid = true;
		for (const auto& ch : str) {
			if (!(ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)) {
				std::cout << "Неправильно введённые данные.\n";
				valid = false;
				break;
			}
        }
        if (!valid)
            continue;
        
    }
}


int main()
{
    std::cout << "------------ Программа 1 -------------"<< std::endl;
    // inputData();

    return 0;
}