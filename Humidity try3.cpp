
#include "pch.h"
#include "Values.h"
#include "Middle.h"
#include <fstream>

/*pressToConts function is to clear the screen after the data has been showed,
to then return to main menu.*/
void pressToCont()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Press Enter to Continue";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("CLS");
}

/*binary_search calculates the middle of the vector then compares the inputted date to the one higher or lower
if the user inputs an date that has not been registered or a jibberish long int the program will let the
user know if the input from searchMedel has been between two registered dates. */
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

/*searchMedel will, before calling the binary_search method let the user know if
the date inputted by the user is bigger than or smaller than the first element of 
the vector and the last, if the input is in between the binary_search will be called.
If the inputted date is the same as the first or lowest it will print that date out.*/
void searchMedel(std::vector <Middle*> v_medel)
{
	bool b_Medel;
	do
	{
		long int high, date;
		high = v_medel.size() - 1;
		std::cout << "Return To Main Menu(0)\nEnter date to search(yyyymmdd): ";
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
			b_Medel = true;
		}
	} while (b_Medel);
}

/*mergeMold,mergeTemperature and mergeHumidity is the same method, but it prints out
depending on what the user wants sorted, it takes in a pointer pointer of Middle
and initiates a temporary array of Middle to store the sorted elements inside.*/
void mergeMold(Middle** medium, int leftLow, int leftHigh, int rightHigh)
{
	int rightLow = leftHigh + 1;
	int length = rightHigh - leftLow + 1;
	Middle** temp = new Middle*[length];
	int i = 0;
	int left = leftLow;
	int right = rightLow;
	while (left <= leftHigh && right <= rightHigh)
	{
		if (medium[left]->get_mold() < medium[right]->get_mold())
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
	delete[] temp;
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
	delete[] temp;
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

/*mergeSortMold, mergeSortTemperature, mergeSortHumidity are all the same methods
but calls the correct sort. it splits the array that is sent in until it is only
1 element left, then calls the merging method, then calls it again with more elements
until it is sorted.*/
void mergeSortMold(Middle** medium, int low, int high)
{
	bool hit = false;
	int mid;
	if (low < high)
	{
		mid = (high + low) / 2;
		mergeSortMold(medium, low, mid);
		mergeSortMold(medium, mid + 1, high);
		mergeMold(medium, low, mid, high);
	}
}
void mergeSortTemperature(Middle** medium, int low, int high)
{
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

/*meteorologicalDAtes checks when the "official" date for autumn and winter happens
which is for autumn when the temperature has been below 10°C for 5 days
and for winter when it has been below 0°C for 5 days.*/
void meteorologicalDates(std::vector <Middle*> medium)
{
	bool searching = true;
	do
	{
		int i = 0;
		int answer;
		int lengthCounter=0;
		std::cout << "do you want to search for meteorological autumn(1) or winter(2)?\nReturn to main menu(0)" << std::endl;
		std::cin >> answer;
		switch (answer)
		{
		case(1):
			do
			{
				if (medium[i]->get_temp() < 10.f && medium[i + 1]->get_temp() < 10.f && medium[i + 2]->get_temp() < 10.f && medium[i + 3]->get_temp() < 10.f && medium[i+4]->get_temp() < 10.f)
				{
					medium[i]->printout();
					searching = false;
				}
				else
				{
					i++;
				}
				if (i == medium.size() - 1)
				{
					std::cout << "No meteorological autumn was found." << std::endl;
					searching = false;
				}
			} while (searching);
			break;
		case(2):
			do
			{
				if (medium[i]->get_temp() < 0 && medium[i + 1]->get_temp() < 0 && medium[i + 2]->get_temp() < 0 && medium[i + 3]->get_temp() < 0 && medium[i + 4]->get_temp() < 0)
				{
					medium[i]->printout();
					searching = false;
				}
				else
				{
					i++;
				}
				if (i == medium.size() - 1)
				{
					std::cout << "No meteorological winter was found." << std::endl;
					searching = false;
				}
			} while (searching);
			break;
		case(0):
			searching = false;
			break;
		default:
			std::cout << "That option is not available." << std::endl;
		}
	} while (searching);
}


int main()
{
	std::vector <Values*> worthIn;
	std::vector <Values*> worthOut;
	std::vector <Middle*> medelIn;
	std::vector <Middle*> medelOut;
	Middle** SortingArray;
	bool readIn=true, texteof=false;
	double tempusIn=0.0,tempusOut=0.0,tempTempIn=0.0, tempTempOut=0.0, moldIn=0.0, tempMoldIn=0.0, moldOut=0.0, tempMoldOut=0.0,temporaryMoldIn=0.0, temporaryMoldOut=0.0;
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
				tempTempIn = std::stof(s_temperature);
				tempTempOut = std::stof(s_temperature);
				tempHumidOut = std::stoi(s_humidity);
				tempHumidIn = std::stoi(s_humidity);
				//tempMoldIn = (pow(tempTempIn, 3)*-0.0015) + (pow(tempTempIn, 2)*0.1193) - (tempTempIn*2.9878) + 102.69;
				//tempMoldOut = (pow(tempTempOut, 3)*-0.0015) + (pow(tempTempOut, 2)*0.1193) - (tempTempOut*2.9878) + 102.69;
			}
			if (s_inOut == "Inne")
			{
				worthIn.push_back(new Values(s_day, s_time, std::stof(s_temperature), std::stoi(s_humidity)));
				if (tempDayIn == std::stol(test))
				{
					tempTempIn = std::stof(s_temperature);
					tempHumidIn = std::stoi(s_humidity);
					temporaryMoldIn = -0.0015*(pow(tempTempIn, 3)) + 0.1193*(pow(tempTempIn, 2)) - (2.9878*tempTempIn) + 102.69;
					tempusIn = tempusIn + tempTempIn;
					humidIn = humidIn + tempHumidIn;
					tempMoldIn = tempMoldIn + temporaryMoldIn;
					++counterIn;					
				}
				else
				{
					tempusIn = tempusIn / counterIn;
					humidIn = humidIn / counterIn;
					moldIn = tempMoldIn / counterIn;
					moldIn = humidIn - moldIn;
					medelIn.push_back(new Middle(tempusIn, humidIn, tempDayIn, moldIn));
					tempusIn = std::stof(s_temperature);
					humidIn = std::stoi(s_humidity);
					counterIn = 1;
					tempTempIn = std::stof(s_temperature);
					tempHumidIn = std::stoi(s_humidity);
					tempDayIn = std::stol(test);
					tempMoldIn = -0.0015*(pow(tempTempIn, 3)) + 0.1193*(pow(tempTempIn, 2)) - (2.9878*tempTempIn) + 102.69;
				}
			}
			else
			{
				worthOut.push_back(new Values(s_day, s_time, std::stof(s_temperature), std::stoi(s_humidity)));
				if (tempDayOut == std::stol(test))
				{
					tempTempOut = std::stof(s_temperature);
					tempHumidOut = std::stoi(s_humidity);
					temporaryMoldOut = ((pow(tempTempOut, 3)*-0.0015) + (pow(tempTempOut, 2)*0.1193) - (tempTempOut*2.9878) + 102.69);
					tempusOut = tempusOut + tempTempOut;
					humidOut = humidOut + tempHumidOut;
					tempMoldOut = tempMoldOut + temporaryMoldOut;
					counterOut++;
				}
				else
				{
					tempusOut = tempusOut/counterOut;
					humidOut = humidOut/counterOut;
					moldOut = tempMoldOut / counterOut;
					moldOut = humidOut - moldOut;
					medelOut.push_back(new Middle(tempusOut, humidOut, tempDayOut,moldOut));
					tempDayOut = std::stol(test);
					tempTempOut = std::stod(s_temperature);
					tempHumidOut = std::stoi(s_humidity);
					humidOut = std::stoi(s_humidity);
					tempusOut = std::stod(s_temperature);
					tempMoldOut = ((pow(tempTempOut, 3)*-0.0015) + (pow(tempTempOut, 2)*0.1193) - (tempTempOut*2.9878) + 102.69);
					counterOut = 1;
				}
			}
		}

		if (counterIn == 0) counterIn = 1;
		tempusIn = tempusIn / counterIn;
		humidIn = humidIn / counterIn;
		moldIn = tempMoldIn / counterIn;
		moldIn = humidIn - moldIn;
		medelIn.push_back(new Middle(tempusIn, humidIn, tempDayIn,moldIn));
		tempusIn = 0;
		humidIn = 0;
		counterIn = 0;
		if (counterOut == 0) counterOut = 1;
		tempusOut = tempusOut / counterOut;
		humidOut = humidOut / counterOut;
		moldOut = tempMoldOut / counterOut;
		moldOut = humidOut - moldOut;
		medelOut.push_back(new Middle(tempusOut, humidOut, tempDayOut, moldOut));
		humidOut = 0;
		tempusOut = 0;
		counterOut = 0;
	}
	else
	{
		std::cout << "ePiC fAiL Xdddd"<< std::endl;
	}
	text.close();
	int choice;
	bool gameOn = true;
	//this switch is the UI
	do
	{
		std::cout << "What do you want to do? \n1. Search average values inside\n2. Search average values outside\n3. Sort humidity inside\n4. Sort temperature inside\n5. Sort by risk of mold inside\n6. Sort humidity outside\n7. Sort temperature outside\n8. Sort by risk of mold outside\n9. Check when meteorological dates happen\n0. exit" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case(1):
			searchMedel(medelIn);
			pressToCont();
			break;
		case(2):
			searchMedel(medelOut);
			pressToCont();
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
			pressToCont();
			delete[] SortingArray;
			break;
		case(4):
			//MergeSort the temperature inside according to average temperature
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
			pressToCont();
			delete[] SortingArray;
			break;
		case(5):
			//MergeSort the risk of mold inside according to average risk of mold.
			SortingArray = new Middle*[medelIn.size()];
			for (int i = 0; i < medelIn.size(); i++)
			{
				SortingArray[i] = medelIn[i];
			}
			mergeSortMold(SortingArray, 0, medelIn.size() - 1);
			for (int i = 0; i < medelIn.size(); i++)
			{
				SortingArray[i]->printout();
			}
			pressToCont();
			delete[] SortingArray;
			break;
		case(6):
			//MergeSort the humidity outside according to average humidity
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
			pressToCont();
			delete[] SortingArray;
			break;
		case(7):
			//MergeSort the temperature outside according to average temperature
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
			pressToCont();
			delete[] SortingArray;
			break;
		case(8):
			//MergeSort the risk of mold outside according to average risk of mold
			SortingArray = new Middle*[medelOut.size()];
			for (int i = 0; i < medelOut.size(); i++)
			{
				SortingArray[i] = medelOut[i];
			}
			mergeSortMold(SortingArray, 0, medelOut.size() - 1);
			for (int i = 0; i < medelOut.size(); i++)
			{
				SortingArray[i]->printout();
			}
			pressToCont();
			delete[] SortingArray;
			break;
		case(9):
			meteorologicalDates(medelOut);
			pressToCont();
			break;
		case(0):
			gameOn = false;
			for (int i = 0; i < worthIn.size(); i++)
			{
				delete worthIn[i];
			}
			for (int i = 0; i < worthOut.size(); i++)
			{
				delete worthOut[i];
			}
			for (int i = 0; i < medelIn.size(); i++)
			{
				delete medelIn[i];
			}
			for (int i = 0; i < medelOut.size(); i++)
			{
				delete medelOut[i];
			}
			break;
		default:
			std::cout << "That option is not available" << std::endl;
			pressToCont();
			break;
		}
	} while (gameOn);

}