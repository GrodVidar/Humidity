#include "pch.h"
#include "Middle.h"




void Middle::printout()
{
	std::cout << "The average temperature of:" << this->date << ", is: " << this->temp  << " Celcius"<< std::endl;
	std::cout << "The average humidity is: " << this->humidity << std::endl;
	std::cout << "The risk of mold this day was: " << this->mold << std::endl << std::endl;
}


Middle::~Middle()
{
}
