#pragma once
class Middle
{	
	double temp;
	int result, humidity;
	long int date;
public:
	Middle(double temp, int humidity, long int date) : temp(temp),humidity(humidity), date(date){}
	~Middle();
	void printout();
	long int get_date() { return this->date; }
	double get_temp() { return this->temp; }
	int get_humidity() { return this->humidity; }

};

