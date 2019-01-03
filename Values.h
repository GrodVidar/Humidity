#pragma once
class Values
{
	std::string date, time;
	bool inOut;
	float temperature;
	int humidity,year, month, day;
public:
	Values(std::string date, std::string time, bool inOut, float temperature, int humidity) : date(date), time(time), inOut(inOut), temperature(temperature), humidity(humidity) {}
	Values(){}
	void printout();
	void separateDate(std::string);
	~Values();
};

