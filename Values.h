#pragma once
class Values
{
	std::string time;
	bool inOut;
	float temperature;
	int humidity,year, month, day;
public:
	Values(int year,int month,int day, std::string time, bool inOut, float temperature, int humidity) : year(year), month(month), day(day), time(time), inOut(inOut), temperature(temperature), humidity(humidity) {}
	Values(){}
	void printout();
	~Values();
};

