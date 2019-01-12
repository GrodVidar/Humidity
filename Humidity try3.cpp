
#include "pch.h"
#include "Values.h"
#include "Middle.h"
#include <fstream>

void binary_search(std::vector <Middle*> worth, int high, int low, long int year)
{
	int temp = (high+low)/2;
	//std::cout << worth[temp]->get_date();
	if (year < worth[temp]->get_date())
	{
		high = temp;
		binary_search(worth, high, low, year);
	}
	else if(year > worth[temp]->get_date())
	{
		low = temp;
		//if (low == temp)low = high;
		binary_search(worth, high, low, year);
	}
	else if (year == worth[temp]->get_date())
	{	
		worth[temp]->printout();
	}
}

void searchMedel(std::vector <Middle*> v_medel)
{
	bool b_Medel;
	do
	{
		long int high, date;
		high = v_medel.size() - 1;
		std::cout << "Enter date to search(yyyymmdd): ";
		std::cin >> date;
		if (date == v_medel[0]->get_date())
		{
			v_medel[0]->printout();
			b_Medel = false;
		}
		else if (date == v_medel[high]->get_date())
		{
			v_medel[high]->printout();
			b_Medel = false;
		}

		else if (date > v_medel[0]->get_date() && date < v_medel[high]->get_date())
		{
			binary_search(v_medel, high, 0, date);
			b_Medel = false;
		}
		else if (date == 0)
		{
			b_Medel = false;
		}
		else
		{
			std::cout << "That date is not registered." << std::endl;
		}
	} while (b_Medel);
}
int main()
{
	std::vector <Values*> worthIn;
	std::vector <Values*> worthOut;
	std::vector <Middle*> medelIn;
	std::vector <Middle*> medelOut;
	bool readIn=true;
	Values vals;
	double tempusIn=0.0,tempusOut=0.0,tempTempIn=0.0, tempTempOut=0.0;
	int humidIn=0,humidOut=0, tempHumidIn=0, tempHumidOut=0;
	std::string test;
	int counterIn = 0,counterOut=0;
	long int highIn,highOut, tempDayIn = 0, tempDayOut = 0;
	std::string s_year, s_month, s_day, s_time, s_inOut, s_temperature, s_humidity;
	std::ifstream text("tempdata4.txt");
	bool texteof=false;
	long int date;
	if (text.is_open())
	{
		while(!text.eof())
		{
			std::getline(text, s_day, ' ');
			test = s_day.substr(0, 4);
			test.append(s_day.substr(5, 2));
			test.append(s_day.substr(8, 2));
			std::getline(text, s_time, ',');
			std::getline(text, s_inOut, ',');
			std::getline(text, s_temperature, ',');
			std::getline(text, s_humidity);
			if (tempDayIn == 0)
			{
				tempDayIn = std::stol(test);
				tempDayOut = std::stol(test);
				tempTempIn = std::stod(s_temperature);
				tempTempOut = std::stod(s_temperature);
				tempHumidOut = std::stoi(s_humidity);
				tempHumidIn = std::stoi(s_humidity);
			}
			if (s_inOut == "Inne")
			{
				worthIn.push_back(new Values(s_day, s_time, std::stof(s_temperature), std::stoi(s_humidity)));
				if (tempDayIn == std::stol(test))
				{
					tempusIn = tempusIn + tempTempIn;
					humidIn = humidIn + tempHumidIn;
					++counterIn;					
				}
				else
				{
					if (counterIn == 0) counterIn = 1;
					tempusIn = tempusIn / counterIn;
					humidIn = humidIn / counterIn;
					medelIn.push_back(new Middle(tempusIn, humidIn, tempDayIn));
					tempusIn = 0;
					humidIn = 0;
					counterIn = 0;
					tempTempIn = std::stod(s_temperature);
					tempHumidIn = std::stoi(s_humidity);
					tempDayIn = std::stol(test);
				}
			}
			else
			{
				worthOut.push_back(new Values(s_day, s_time, std::stof(s_temperature), std::stoi(s_humidity)));
				if (tempDayOut == std::stol(test))
				{
					tempusOut = tempusOut + tempTempOut;
					humidOut = humidOut + tempHumidOut;
					counterOut++;
				}
				else
				{
					if (counterOut == 0) counterOut = 1;
					tempusOut = tempusOut/counterOut;
					humidOut = humidOut/counterOut;
					medelOut.push_back(new Middle(tempusOut, humidOut, tempDayOut));
					tempDayOut = std::stol(test);
					tempTempOut = std::stod(s_temperature);
					tempHumidOut = std::stoi(s_humidity);
					humidOut = 0;
					tempusOut = 0;
					counterOut = 0;
				}
			}
		}
		if (counterIn == 0) counterIn = 1;
		tempusIn = tempusIn / counterIn;
		humidIn = humidIn / counterIn;
		medelIn.push_back(new Middle(tempusIn, humidIn, tempDayIn));
		tempusIn = 0;
		humidIn = 0;
		counterIn = 0;
		if (counterOut == 0) counterOut = 1;
		tempusOut = tempusOut / counterOut;
		humidOut = humidOut / counterOut;
		medelOut.push_back(new Middle(tempusOut, humidOut, tempDayOut));
		humidOut = 0;
		tempusOut = 0;
		counterOut = 0;
	}
	else
	{
		std::cout << "ePiC fAiL Xdddd"<< std::endl;
	}
	text.close();
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

	/*for (int i = 0; i < medelIn.size(); i++)
	{
		medelIn[i]->set_date();
		medelIn[i]->printout();
	}*/

	/*for (int i = 0; i < medelIn.size(); i++)
	{
		medelIn[i]->printout();
	}*/
		//std::cout << medelOut[0]->get_date() << "\n" << medelOut[highOut]->get_date() << std::endl;
	
	int a;
	bool gameOn = true;
	//this switch is the UI
	do
	{
		std::cout << "what do you want to do? \n1.search middle values inside 2. search middle values outside 3. exit" << std::endl;
		std::cin >> a;
		switch (a)
		{
		case(1):
			searchMedel(medelIn);
			break;
		case(2):
			searchMedel(medelOut);
			break;
		case(3):
			gameOn = false;
			break;
		default:
			std::cout << "That option is not available" << std::endl;
			break;
		}
	} while (gameOn);

}