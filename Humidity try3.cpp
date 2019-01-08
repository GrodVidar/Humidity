
#include "pch.h"
#include "Values.h"
#include <fstream>

void search_day(std::vector <Values*> worth)
{
	int year, day, month;
	bool b_year=false, b_month=false, b_day=false;
	do
	{
		std::cout << "Enter year: ";
		std::cin >> year;
		for (int i = 0; i < worth.size(); i++)
		{
			if (year == worth[i]->get_year())
			{
				b_year = true;
				do
				{
					std::cout << "Enter month: ";
					std::cin >> month;
					for (int j = i; j < worth.size(); j++)
					{
						if (year == worth[i]->get_year() && month == worth[j]->get_month())
						{
							b_month = true;
							do
							{
								if(!b_day)std::cout << "Enter day: ";
								if(!b_day)std::cin >> day;
								for (int k = j; k < worth.size(); k++)
								{
									if (year == worth[i]->get_year() && month == worth[j]->get_month() && day == worth[i]->get_day())
									{
										b_day = true;
										worth[k]->printout();
									}
									else
									{
										if(k==worth.size()-1)std::cout << "That day isn't registered." << std::endl;
									}
								}
							} while (b_day == false);
						}
						else
						{
							if(j==worth.size()-1)std::cout << "That month isn't registered." << std::endl;
						}
					}
				} while (b_month == false);
			}
			else
			{
				if(i==worth.size()-1)std::cout << "That year isn't registered" << std::endl;
			}
		}
	} while (b_year == false);
}

void binary_searchDay(std::vector <Values*> worth, int high, int low, int day)
{
	int temp = (high + low) / 2;
	if (day < worth[temp]->get_day())
	{
		high = temp;
		binary_searchDay(worth, high, low, day);	
	}
	else if (day > worth[temp]->get_day())
	{
		low = temp;
		if (low == temp)low = high;
		binary_searchDay(worth, high, low, day);
	}
	else if (day == worth[temp]->get_day())
	{
			worth[temp]->printout();
	}
}

void binary_searchMonth(std::vector <Values*> worth, int high, int low, int month)
{
	int temp = (high+low)/2;
	int day;
	if (month < worth[temp]->get_month())
	{
		high = temp;
		binary_searchMonth(worth, high, low, month);
	}
	else if (month > worth[temp]->get_month())
	{
		low = temp;
		if (low == temp)low = high;
		binary_searchMonth(worth, high, low, month);
	}
	else if (month == worth[temp]->get_month())
	{
		std::cout << "Enter day: ";
		std::cin >> day;
		if (day >= worth[low]->get_day() && day <= worth[high]->get_day())
		{
			binary_searchDay(worth, high, low, day);
		}
		else
		{
			std::cout << "Day not registered.";
		}
	}
}

void binary_searchYear(std::vector <Values*> worth, int high, int low, int year)
{
	int temp = (high+low)/2;
	int month;	
	if (year < worth[temp]->get_year())
	{
		high = temp;
		binary_searchYear(worth, high, low, year);
	}
	else if(year > worth[temp]->get_year())
	{
		low = temp;
		if (low == temp)low = high;
		binary_searchYear(worth, high, low, year);
	}
	else if (year == worth[temp]->get_year())
	{	
		std::cout << "Enter month: ";
		std::cin >> month;
		if (month >= worth[low]->get_month() && month <= worth[high]->get_month())
		{
			binary_searchMonth(worth, high, low, month);
		}
		else
		{
			std::cout << "Month not registered.";
		}
	}
}

int main()
{
	std::vector <Values*> worthIn;
	std::vector <Values*> worthOut;
	Values vals;
	long int big;
	std::string s_year, s_month, s_day, s_time, s_inOut, s_temperature, s_humidity;
	std::ifstream text("TempFuktDataSemi.txt");
	bool texteof=false;
	bool b_inOut;
	int year, month, day;
	if (text.is_open())
	{
		while(!text.eof())
		{
			std::getline(text, s_year, '-');
			std::getline(text, s_month, '-');
			std::getline(text, s_day, ' ');
			std::getline(text, s_time, ';');
			std::getline(text, s_inOut, ';');
			std::getline(text, s_temperature, ';');
			std::getline(text, s_humidity);
			if (s_inOut == "Inne")
			{
				worthIn.push_back(new Values(std::stoi(s_year), std::stoi(s_month), std::stoi(s_day), s_time, std::stof(s_temperature), std::stoi(s_humidity)));
			}
			else
			{
				worthOut.push_back(new Values(std::stoi(s_year), std::stoi(s_month), std::stoi(s_day), s_time, std::stof(s_temperature), std::stoi(s_humidity)));
			}
		}
	}
	else
	{
		std::cout << "ePiC fAiL Xdddd"<< std::endl;
	}

	//search_day(worth);


	//std::cout << "--------Inside---------" << std::endl << std::endl;
	//for (int i = 0; i < worth.size(); i++)
	//{
	//	if (worth[i]->get_inOut() == true)
	//	{
	//		worth[i]->printout();
	//	}
	//	
	//}
	//std::cout << "----------Outside-----------" << std::endl << std::endl;
	//for (int i = 0; i < worth.size(); i++)
	//{
	//	if (worth[i]->get_inOut() == false)
	//	{
	//		worth[i]->printout();
	//	}
	//}
	/*for (int i = 0; i < worth.size(); i++)
	{
		printout_outside();
	}*/
	/*for (int i = 0; i < worth.size(); i++)
	{
		worth[i]->printout();
	}*/
	big = worthIn.size()-1;
	std::cout << "Enter year: ";
	std::cin >> year;
	if (year >= worthIn[0]->get_year() && year <= worthIn[big]->get_year())
	{
		binary_searchYear(worthIn, big, 0, year);
	}
	else
	{
		std::cout << "That year is not registered." << std::endl;
	}
}