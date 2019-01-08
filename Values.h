#pragma once
class Values
{
	std::string time;
	float temperature;
	int humidity, year, month, day;
public:
	Values(int year, int month, int day , std::string time, float temperature, int humidity) : year(year), month(month), day(day), time(time), temperature(temperature), humidity(humidity) {}
	Values(){}
	void printout();
	int get_year() { return this->year; }
	int get_month() { return this->month; }
	int get_day() { return this->day; }
	//void averageTemp();
	~Values();
};

