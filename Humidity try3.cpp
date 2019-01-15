
#include "pch.h"
#include "Values.h"
#include "Middle.h"
#include <fstream>

void binary_search(std::vector <Middle*> worth, int high, int low, long int date)
{
	if (low<=high)
	{
		int temp = (high + low) / 2;

		if (date < worth[temp]->get_date())
		{
			high = temp - 1;
			binary_search(worth, high, low, date);
		}
		else if (date > worth[temp]->get_date())
		{
			low = temp + 1;
			binary_search(worth, high, low, date);
		}
		else if (date == worth[temp]->get_date())
		{
			worth[temp]->printout();
		}
	}
	else
	{
		std::cout << "That date is not registered!" << std::endl;
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
			b_Medel = false;
		}
	} while (b_Medel);
}
void mergeTemperature(Middle** medium, int leftLow, int leftHigh, int rightHigh)
{
	int rightLow = leftHigh + 1;
	int length = rightHigh - leftLow + 1;
	Middle** temp = new Middle*[length];
	int i = 0;
	int left = leftLow;
	int right = rightLow;
	while (left <= leftHigh && right <= rightHigh)
	{
		if (medium[left]->get_temp() < medium[right]->get_temp())
		{
			temp[i] = medium[left];
			left++;
			i++;
		}
		else
		{
			temp[i] = medium[right];
			right++;
			i++;
		}
	}

	while (left <= leftHigh)
	{
		temp[i] = medium[left];
		left++;
		i++;
	}
	while (right <= rightHigh)
	{
		temp[i] = medium[right];
		right++;
		i++;
	}

	for (int j = leftLow; j <= rightHigh; j++)
	{
		medium[j] = temp[j - leftLow];
	}

}
void mergeHumidity(Middle** medium, int leftLow, int leftHigh, int rightHigh)
{
	int rightLow = leftHigh + 1;
	int length = rightHigh - leftLow + 1;
	Middle** temp = new Middle*[length];
	int i = 0;
	int left = leftLow;
	int right = rightLow;
	while (left <= leftHigh && right <= rightHigh)
	{
		if (medium[left]->get_humidity() < medium[right]->get_humidity())
		{
			temp[i] = medium[left];
			left++;
			i++;
		}
		else
		{
			temp[i] = medium[right];
			right++;
			i++;
		}
	}

	while (left <= leftHigh)
	{
		temp[i] = medium[left];
		left++;
		i++;
	}
	while (right <= rightHigh)
	{
		temp[i] = medium[right];
		right++;
		i++;
	}
	
	for (int j = leftLow; j <= rightHigh; j++)
	{
		medium[j] = temp[j - leftLow];
	}
	delete[]temp;
}

void mergeSortTemperature(Middle** medium, int low, int high)
{
	int choice;
	bool hit = false;
	int mid;
	if (low < high)
	{
		mid = (high + low) / 2;
		mergeSortTemperature(medium, low, mid);
		mergeSortTemperature(medium, mid + 1, high);
		mergeTemperature(medium, low, mid, high);
	}
}

void mergeSortHumidity(Middle** medium, int low, int high)
{
	int choice;
	bool hit=false;
	int mid;
	if (low < high)
	{
		mid = (high + low) / 2;
		mergeSortHumidity(medium, low, mid);
		mergeSortHumidity(medium, mid + 1, high);
		mergeHumidity(medium, low, mid, high);
	}
}

int main()
{
	std::vector <Values*> worthIn;
	std::vector <Values*> worthOut;
	std::vector <Middle*> medelIn;
	std::vector <Middle*> medelOut;
	Middle** SortingArray;
	bool readIn=true, texteof=false;
	double tempusIn=0.0,tempusOut=0.0,tempTempIn=0.0, tempTempOut=0.0;
	int humidIn=0,humidOut=0, tempHumidIn=0, tempHumidOut=0, counterIn = 1,counterOut=1;
	std::string test;
	long int highIn,highOut, tempDayIn = 0, tempDayOut = 0;
	std::string s_year, s_month, s_day, s_time, s_inOut, s_temperature, s_humidity;
	std::ifstream text("tempdata4.txt");
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
				worthIn.push_back(new Values(s_day, s_time, std::stod(s_temperature), std::stoi(s_humidity)));
				if (tempDayIn == std::stol(test))
				{
					tempTempIn = std::stod(s_temperature);
					tempHumidIn = std::stoi(s_humidity);
					tempusIn = tempusIn + tempTempIn;
					humidIn = humidIn + tempHumidIn;
					++counterIn;					
				}
				else
				{
					tempusIn = tempusIn / counterIn;
					humidIn = humidIn / counterIn;
					medelIn.push_back(new Middle(tempusIn, humidIn, tempDayIn));
					tempusIn = std::stod(s_temperature);
					humidIn = std::stoi(s_humidity);
					counterIn = 1;
					tempTempIn = std::stod(s_temperature);
					tempHumidIn = std::stoi(s_humidity);
					tempDayIn = std::stol(test);
				}
			}
			else
			{
				worthOut.push_back(new Values(s_day, s_time, std::stod(s_temperature), std::stoi(s_humidity)));
				if (tempDayOut == std::stol(test))
				{
					tempTempOut = std::stod(s_temperature);
					tempHumidOut = std::stoi(s_humidity);
					tempusOut = tempusOut + tempTempOut;
					humidOut = humidOut + tempHumidOut;
					counterOut++;
				}
				else
				{
					tempusOut = tempusOut/counterOut;
					humidOut = humidOut/counterOut;
					medelOut.push_back(new Middle(tempusOut, humidOut, tempDayOut));
					tempDayOut = std::stol(test);
					tempTempOut = std::stod(s_temperature);
					tempHumidOut = std::stoi(s_humidity);
					humidOut = std::stoi(s_humidity);
					tempusOut = std::stod(s_temperature);
					counterOut = 1;
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
	int a;
	bool gameOn = true;
	//this switch is the UI
	do
	{
		std::cout << "what do you want to do? \n1. Search average values inside\n2. Search average values outside\n3. Sort humidity inside\n4. Sort temperature inside\n5. Sort humidity outside\n6. Sort temperature outside\n0. exit" << std::endl;
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
			//MergeSort the humidity inside according to average humidity
			SortingArray = new Middle*[medelIn.size()];
			for (int i = 0; i < medelIn.size(); i++)
			{
				SortingArray[i] = medelIn[i];
			}
			mergeSortHumidity(SortingArray, 0, medelIn.size()-1);
			for (int i = 0; i < medelIn.size(); i++)
			{
				SortingArray[i]->printout();
			}
			delete[] SortingArray;
			break;
		case(4):
			SortingArray = new Middle*[medelIn.size()];
			for (int i = 0; i < medelIn.size(); i++)
			{
				SortingArray[i] = medelIn[i];
			}
			mergeSortTemperature(SortingArray, 0, medelIn.size() - 1);
			for (int i = 0; i < medelIn.size(); i++)
			{
				SortingArray[i]->printout();
			}
			delete[] SortingArray;
			break;
		case(5):
			SortingArray = new Middle*[medelOut.size()];
			for (int i = 0; i < medelOut.size(); i++)
			{
				SortingArray[i] = medelOut[i];
			}
			mergeSortHumidity(SortingArray, 0, medelOut.size() - 1);
			for (int i = 0; i < medelOut.size(); i++)
			{
				SortingArray[i]->printout();
			}
			delete[] SortingArray;
			break;
		case(6):
			SortingArray = new Middle*[medelOut.size()];
			for (int i = 0; i < medelOut.size(); i++)
			{
				SortingArray[i] = medelOut[i];
			}
			mergeSortTemperature(SortingArray, 0, medelOut.size() - 1);
			for (int i = 0; i < medelOut.size(); i++)
			{
				SortingArray[i]->printout();
			}
			delete[] SortingArray;
			break;

		case(0):
			gameOn = false;
			break;
		default:
			std::cout << "That option is not available" << std::endl;
			break;
		}
	} while (gameOn);

}