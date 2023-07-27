#pragma once
#include <iostream>
#include "dots.h"


void scalpel(Dot & dot1, Dot & dot2) 
{
    std::cout << "A cut was made between (" << dot1.x << ", " << dot1.y << ") and (" << dot2.x << ", " << dot2.y << ") coordinates." << std::endl;
}

void hemostat(Dot & dot) 
{
    std::cout << "Clamped at a point with coordinates (" << dot.x << ", " << dot.y << ")." << std::endl;
}

void tweezers(Dot & dot) 
{
    std::cout << "Tweezers are used at a point with coordinates (" << dot.x << ", " << dot.y << ")." << std::endl;
}

void suture(Dot & dot1, Dot & dot2) {
    std::cout << "Stitched with a surgical needle between the (" << dot1.x << ", " << dot1.y << ") and (" << dot2.x << ", " << dot2.y << ") coordinates." << std::endl;
}