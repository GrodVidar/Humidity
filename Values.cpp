#include "pch.h"
#include "Values.h"

void Values::printout()
{
	separate_values();
	std::cout << "Date: " << this->year << "-" << this->month << "-" << this->day << std::endl;
	std::cout << "Time: " << this->time << std::endl;
	std::cout << "Temperature and humidity: " << this->temperature << " Celcius, " << this->humidity <<"%"<< std::endl<<std::endl;
}


void Values::separate_values()
{
	std::string temp;
	temp = this->date.substr(0, 4);
	this->year = std::stoi(temp);
	temp = '\0';
	temp = this->date.substr(5, 2);
	this->month = std::stoi(temp);
	temp = '\0';
	temp = this->date.substr(8, 2);
	this->day = std::stoi(temp);
}

Values::~Values()
{
}
