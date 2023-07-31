#include <iostream>
#include <string>
#include "ram.h"
#include "const.h"



bool isNumber(const std::string& str)
{
    for (const char& c : str)
        if (!std::isdigit(c))
            return false;

    return true;
}



void enterNumbers()
{
    int* tmp = new int[g_size];
    std::string str;
    std::cout << "Enter " << g_size << " numbers: ";

    for (int i = 0; i < g_size;)
    {
        std::cin >> str;
        if (isNumber(str))
        {
            *(tmp + i) = std::stoi(str);
            ++i;
            std::cout << g_size - i << " numbers left to enter" << std::endl;
        }
    }
    ramWrite(tmp);
    system("cls");
    std::cout << "~ Data was written on RAM ~" << std::endl << std::endl;

    delete[] tmp;
    tmp = nullptr;
}