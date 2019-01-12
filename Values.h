#pragma once
class Values
{
	std::string time, date;
	float temperature;
	int humidity, year, month, day;
	long int i_date;
public:
	Values(std::string date , std::string time, float temperature, int humidity) : date(date), time(time), temperature(temperature), humidity(humidity) {}
	Values(){}
	void printout();
	void separate_values();
	int get_year() { return this->year; }
	int get_month() { return this->month; }
	int get_day() { return this->day; }
	long int get_date()
	{

		return this->i_date;
	}

	//void averageTemp();
	~Values();

};

