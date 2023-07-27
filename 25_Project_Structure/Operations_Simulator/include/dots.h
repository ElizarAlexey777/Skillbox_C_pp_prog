#pragma once
#include <iostream>


struct Dot
{
	double x = 0.0;
	double y = 0.0;
};


Dot inpDot()
{
	Dot dot;
	std::cout << "Enter two coordinate of dot:" << std::endl;
	std::cin >> dot.x >> dot.y;

	return dot;
}


bool compareDots (Dot &dot1, Dot &dot2)
{
	return (dot1.x == dot2.x && dot1.y == dot2.y);
}