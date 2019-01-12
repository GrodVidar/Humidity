#include "pch.h"
#include "Middle.h"




void Middle::printout()
{
	std::cout << "The average temperature of:" << this->date << ", is: " << this->temp  << " Celcius"<< std::endl;
	std::cout << "And the average humidity is: " << this->humidity << '%' << std::endl << std::endl;
}

//void Middle::set_date()
//{
//	std::string temp;
//	temp = date.substr(0, 4);
//	temp.append(date.substr(5, 2));
//	temp.append(date.substr(8, 2));
//	i_date = std::stoi(temp);
//}

Middle::~Middle()
{
}
