#include "pch.h"
#include "Values.h"

void Values::printout()
{
	std::cout << "Date: " << this->year << "-" << this->month << "-" << this->day << std::endl;
	std::cout << "Time: " << this->time << std::endl;
	std::cout << "Temperature and humidity: " << this->temperature << " Celcius, " << this->humidity <<"%"<< std::endl<<std::endl;
}

Values::~Values()
{
}
