
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
					for (int j = 0; j < worth.size(); j++)
					{
						if (year == worth[i]->get_year() && month == worth[j]->get_month())
						{
							b_month = true;
							do
							{
								if(!b_day)std::cout << "Enter day: ";
								if(!b_day)std::cin >> day;
								for (int k = 0; k < worth.size(); k++)
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
int main()
{
	std::vector <Values*> worth;
	Values vals;
	std::string s_year, s_month, s_day, s_time, s_inOut, s_temperature, s_humidity;
	std::ifstream text("TempFuktDataSemi.txt");
	bool texteof=false;
	bool b_inOut;
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
			b_inOut = (s_inOut == "Inne");
			//{
			//	b_inOut = true;
			//}
			//else
			//{
			//	b_inOut = false;
			//}
			worth.push_back(new Values(std::stoi(s_year), std::stoi(s_month), std::stoi(s_day), s_time, b_inOut, std::stof(s_temperature), std::stoi(s_humidity)));
		}
	}
	else
	{
		std::cout << "ePiC fAiL Xdddd"<< std::endl;
	}

	//search_day(worth);


	std::cout << "--------inside---------" << std::endl << std::endl;
	for (int i = 0; i < worth.size(); i++)
	{
		if (worth[i]->get_inOut() == true)
		{
			worth[i]->printout();
		}
		
	}
	std::cout << "----------Outside-----------" << std::endl << std::endl;
	for (int i = 0; i < worth.size(); i++)
	{
		if (worth[i]->get_inOut() == false)
		{
			worth[i]->printout();
		}
	}
	/*for (int i = 0; i < worth.size(); i++)
	{
		printout_outside();
	}*/
	/*for (int i = 0; i < worth.size(); i++)
	{
		worth[i]->printout();
	}*/

}