#include <iostream>
#include "const.h"
#include "ram.h"



int compute()
{
    int* tmp = new int[g_size];
    ramRead(tmp);

    int sum = 0;
    for (int i = 0; i < g_size; ++i)
        sum += *(tmp + i);

    delete[] tmp;
    tmp == nullptr;

    return sum;
}