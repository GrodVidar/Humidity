#include "pch.h"
#include "Middle.h"



/*printout is used both in this class and in Values, it gives the user information
about the data they have requested.*/
void Middle::printout()
{
	std::cout << "The average temperature of:" << this->date << ", is: " << this->temp  << " Celcius"<< std::endl;
	std::cout << "The average humidity is: " << this->humidity << std::endl;
	std::cout << "The risk of mold this day was: " << this->mold << std::endl << std::endl;
}


Middle::~Middle()
{
}
