
#include "pch.h"
#include "Values.h"
#include <fstream>

int main()
{
	std::vector <Values*> worth;
	Values vals;
	std::string s_date, s_time, s_inOut, s_temperature, s_humidity;
	std::ifstream text("TempFuktDataSemi.txt");
	bool texteof=false;
	bool b_inOut;
	if (text.is_open())
	{
		while(!text.eof())
		{
			std::getline(text, s_date, ' ');
			std::getline(text, s_time, ';');
			std::getline(text, s_inOut, ';');
			std::getline(text, s_temperature, ';');
			std::getline(text, s_humidity);
			if (s_inOut == "Inne")
			{
				b_inOut = true;
			}
			else
			{
				b_inOut = false;
			}
			worth.push_back(new Values(s_date, s_time, b_inOut, std::stof(s_temperature), std::stoi(s_humidity)));
		}
	}
	else
	{
		std::cout << "ePiC fAiL Xdddd"<< std::endl;
	}
	
	/*for (int i = 0; i < worth.size(); i++)
	{
		worth[i]->printout();
	}*/

}