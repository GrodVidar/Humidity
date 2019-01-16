#include "pch.h"
#include "Values.h"
/*printout is used both in this class and in Middle, it gives the user information
about the data they have requested.*/
void Values::printout()
{
	separate_values();
	std::cout << "Date: " << this->year << "-" << this->month << "-" << this->day << std::endl;
	std::cout << "Time: " << this->time << std::endl;
	std::cout << "Temperature and humidity: " << this->temperature << " Celcius, " << this->humidity <<"%"<< std::endl<<std::endl;
}

/*The separate_values method uses substring to separate the date into year, month, day
instead of having it all in a long int, mostly used for decoring the printout method.*/
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
