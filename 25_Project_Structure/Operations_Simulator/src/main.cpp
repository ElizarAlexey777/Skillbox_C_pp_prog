#include "funcTools.h"
#include "dots.h"
#include <iostream>

bool isCorrectInstrument (std::string &);

std::string instruments[] {"scalpel", "hemostat", "tweezers", "suture"};


int main()
{
	std::string chosenInstrument {""};
	std::cout << "To start operation enter \"scalpel\"" << std::endl;
	do
		std::cin >> chosenInstrument;
	while (chosenInstrument != "scalpel");

	Dot cutS, cutF;
	std::cout << "Enter the coordinates of the beginning of the cut (x1, y1):" << std::endl;
	std::cin >> cutS.x >> cutS.y;
	std::cout << "Enter the coordinates of the end of the cut (x2, y2):" << std::endl;
	std::cin >> cutF.x >> cutF.y;
	scalpel(cutS, cutF);

	if (cutF.x < cutS.x)
		std::swap (cutS, cutF);

	Dot sutureS, sutureF;
	do
	{
		std::cout << "Choose instrument: " << std::endl;
		std::cout << " - " << instruments[0] << ";" << std::endl;
		std::cout << " - " << instruments[1] << ";" << std::endl;
		std::cout << " - " << instruments[2] << ";" << std::endl;
		std::cout << " - " << instruments[3] << ";" << std::endl;
		
		do
			std::cin >> chosenInstrument;
		while (!isCorrectInstrument(chosenInstrument));

		int n_chosen {0};
		while (chosenInstrument != instruments[n_chosen])
			++n_chosen;

		switch (n_chosen)
		{
		case 0 : scalpel(inpDot(), inpDot()); break;
		case 1 : hemostat(inpDot()); break;
		case 2 : tweezers(inpDot()); break;
		case 3 :
		{
			sutureS = inpDot();
			sutureF = inpDot();
			suture(sutureS, sutureF); 

			if (sutureF.x < sutureS.x)
				std::swap (sutureS, sutureF);
			break;
		}
		}
	}
	while (!(compareDots(cutS, sutureS) && compareDots(cutF, sutureF)));

	std::cout << std::endl << "Operation completed successfully!" << std::endl;
}



bool isCorrectInstrument (std::string &instrument)
{
	for (int i = 0; i < instrument.size (); ++i)
		instrument[i] = tolower (instrument[i]);

	for (const auto &available : instruments)
		if (instrument == available) return true;

	return false;
}