#include "pch.h"
#include "Values.h"


void Values::printout()
{
	std::cout << "Date: " << this->date << std::endl;
	std::cout << "Time: " << this->time << std::endl;
	std::cout << "Temperature and Humidity: " << this->temperature << ", " << this->humidity << std::endl;
}

void Values::separateDate(std::string date)
{

}

Values::~Values()
{
}
