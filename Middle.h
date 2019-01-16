#pragma once
class Middle
{	
	float temp;
	double mold;
	int result, humidity;
	long int date;
public:
	Middle(float temp, int humidity, long int date, double mold) : temp(temp),humidity(humidity), date(date), mold(mold){}
	~Middle();
	void printout();
	long int get_date() { return this->date; }
	double get_temp() { return this->temp; }
	int get_humidity() { return this->humidity; }
	double get_mold() { return this->mold; }

};

