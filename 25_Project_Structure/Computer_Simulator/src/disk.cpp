#include <iostream>
#include <fstream>
#include "const.h"
#include "ram.h"



void saveToFileFromRam()
{
    int* tmp = new int[g_size];
    ramRead(tmp);
    std::ofstream file("data.txt");
    for (int i = 0; i < g_size; ++i)
        file << *(tmp + i) << " ";
    file.close();
    std::cout << "~ RAM was saved on disk ~" << std::endl << std::endl;

    delete[] tmp;
    tmp = nullptr;
}



void loadFromFileToRam()
{
    int* tmp = new int[g_size];
    std::ifstream file("data.txt");
    if (file.is_open())
    {
        for (int i = 0; i < g_size; ++i)
            file >> *(tmp + i);

        ramWrite(tmp);
        std::cout << "~ Data was loaded on RAM ~" << std::endl << std::endl;
    }
    else
        std::cout << "! File not found !" << std::endl << std::endl;

    delete[] tmp;
    tmp = nullptr;
}