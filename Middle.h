#pragma once
class Middle
{	
	long double temp;
	int result, humidity;
	long int date;
public:
	Middle(long double temp, int humidity, long int date) : temp(temp),humidity(humidity), date(date){}
	~Middle();
	void printout();
	long int get_date() { return this->date; }
	
};

