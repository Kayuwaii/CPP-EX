/**
* @file EJ 2.cpp
* @author Alex Coronas Altemir (AKA. Seraphire)
* @date 16/10/2017
* @brief C++ Learning Documentation 2.
*
* @see https://github.com/Kayuwaii/EJERCICIOS-CPP
*/

/*
EXCERCISE 2:
1)
a-Get temperature and the temperature scale used. [INPUT]
b-Print the the temperature in Kelvin, Celsius & Fahrenheit. [OUTPUT]

2)
a-Get name surname and height(in Meters or cm. [INPUT]
b-Print the data from above and change the height into feets and inches[OUTPUT]

c)
a- Ask the name, surname and city of the user and ask the distance in km of his city with respect to Barcelona. [INPUT]
b- Displays user data and distance in yard and miles. [OUTPUT]

d)
a- Request the name, surname and the DNi of the user and their weight in kg [INPUT]
b-Visualize their data in pounds [OUTPUT]

e)
Inventado
*/

//Include the precompiled headers
#include "stdafx.h"

//Include the "libraries" needed (HEADERS)
#include <iostream> // Header that defines the standard input/output stream objects
#include <string>	// This header introduces string types, character traits and a set of converting functions
#include <vector>	// Header that defines the vector container class. (ArrayList)
#include <sstream>
#include <Windows.h>
#include <io.h>
#include <locale>
#include <fcntl.h>

using namespace std;

//The following region contains the declarations of every method
#pragma region Method and Class Declaration
void menu();
void temperatureConverter();
void heightConverter();
void lengthConverter();
void wheightConverter();
void eurConverter();
#pragma endregion

#undef max

int main()
{
	CONSOLE_FONT_INFOEX cfi;
	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	bool right_in = false; //Boolean to manage the menu repettition
	int sel; //Declare an empty integer. It will hold the user selection later.
	menu(); //Execute the menu method. It prints every option that the menu has.

	while (!right_in) //While the input is not valid repeat the block. 
	{
		cout << "\n\n Select an Option:\t"; //Print text and stay in the same line. \t is a TAB
		cin >> sel; //Read the input. 
		if (cin) //If the intput type is a  valid proceed with the following code
		{
			right_in = true; //Set the boolean to true, so the code doesn't repeat.
			switch (sel) //Switch Statement, used to specify what to do for each posible case
			{
			case 1: //If the input equals 1
				temperatureConverter(); //Call case1 method
				break;
			case 2: //If the input equals 2
				heightConverter(); //Call case2 method
				break;
			case 3: //If the input equals 3
				lengthConverter(); //Call case3 Method
				break;
			case 4:
				wheightConverter();
				break;
			case 5:
				eurConverter();
				break;
			default: //If the input is anythhing else
				cout << "Such option does not exist. Please select a valid one." << endl;
				//Print text and jump to the next line. 

				right_in = false; //Change the bool to repeat the code.
				break;
			}
		}
		else //If the intput type is a NOT valid proceed with the following code
		{
			right_in = false; //Change the bool to repeat the code.
			cout << "\n Wrong Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			/*Every time the loop repeats remove any "\n"(newline) characters trailing in the cin stream to avoid
			any future getline() fail.*/
		}
	}

	system("pause");
	return 0;
}


/**
* \brief Displays the menu options
*/
void menu()
{
	// We store each menu option as a String in an Array
	wstring menu_options[] = {
		L"Convert Temperature",
		L"Convert Heights",
		L"Convert Length",
		L"Convert Wheight",
		L"Convert € to $",
	};
	int tmp_count = 1; // This variable is used to print a number before each option

	cout << "Select an Option:" << endl;
	_setmode(_fileno(stdout), _O_U16TEXT);
	for (wstring s : menu_options) // Foreach loop. For each ite
	{
		wcout << "\t " << tmp_count << ". " << s << endl;
		tmp_count++;
	}
	_setmode(_fileno(stdout), _O_TEXT);
	cout << "\n0. Exit Application" << endl;
}

void temperatureConverter()
{
	cout << "\nEnter the temperature: \t";
	double tempIn;
	cin >> tempIn;
	double temp1 = 0;
	double temp2 = 0;
	string temp1Scale;
	string temp2Scale;
	string tempInScale;
	cout << "Celsius, Fahrenheight or Kelvin (C, F or K): \t";
	char option;
	cin >> option;
	switch (toupper(option))
	{
	case 'K':
		temp1 = tempIn - 273.15; // Kelvin to Celsius
		temp1Scale = "\370 Celsius";
		temp2 = (temp1 * 9 / 5.0) + 32; //Celsius to Farenheight
		temp2Scale = "\370 Farenheight";
		tempInScale = "\370 Kelvin";
		break;
	case 'C':
		temp1 = tempIn + 273.15; //Celsius to Kelvin
		temp1Scale = "\370 Kelvin";
		temp2 = (tempIn * 9 / 5.0) + 32; //Celsius  to Farenheight
		temp2Scale = "\370 Farenheight";
		tempInScale = "\370 Celsius";
		break;
	case 'F':
		temp1 = (tempIn - 32) * 5 / 9; //Farenheight to Celsius
		temp1Scale = "\370 Celsius";
		temp2 = (tempIn + 459.67) * 5 / 9; //Farenheight to Kelvin
		temp2Scale = "\370 Kelvin";
		tempInScale = "\370 Farenheight";
		break;
	}
	cout << "\t" << tempIn << tempInScale << " are " << temp1 << temp1Scale << " and " <<
		temp2 << temp2Scale << endl;
}

void heightConverter()
{
	cout << "\nHow tall are you? (In cm) \t";
	int cm;
	cin >> cm;
	double feet = cm / 30.48;
	double inches = (cm / 2.54) - (static_cast<int>(feet) * 12);
	cout << "\tYour height in feets and inches is: " << static_cast<int>(feet) << " feet and " << inches << " inches"
		<< endl;
}

void lengthConverter()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//Remove any "\n" (newline) characters trailing in the cin stream to avoid any future getline() to fail.
	cout << "\nWhere are you from? \t";
	string city;
	getline(cin, city);
	cout << "How many kilometers from Barcelona is it? \t";
	double distanceKM;
	cin >> distanceKM;
	double distanceYards = distanceKM * 1093.6F;
	double distanceMiles = distanceKM * 0.62137119F;
	cout << "\tThe distance between Barcelona and " << city << " is " << distanceYards <<
		" yards, or " << distanceMiles << " miles." << endl;
}

void wheightConverter()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//Remove any "\n" (newline) characters trailing in the cin stream to avoid any future getline() to fail.
	cout << "\nIntroduce your name and surname: \t";
	string fullName[2];
	string temp;
	string word;
	getline(cin, temp);
	stringstream ss(temp);
	int count = 0;
	while (getline(ss, word, ' ') && count < 2)
	{
		fullName[count++] = word;
	}
	double wheight;
	cout << "What is your wheight? (In kg) \t";
	cin >> wheight;
	double wheightIbs = wheight / 0.45359237F;

	printf("%-15s %15s %2s", "\tName: ", fullName[0].c_str(), "\n");
	printf("%-15s %15s %2s", "\tSurname: ", fullName[1].c_str(), "\n");
	printf("%-15s %15.2f %2s", "\tWheight (kg): ", wheight, "\n");
	printf("%-15s %15.2f %2s", "\tWheight (Ibs):", wheightIbs, "\n");
}

void eurConverter()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"\nHow many € would you like to convert? \t";
	double eur;
	cin >> eur;
	double doll = eur * 1.1950001195F;
	wcout << L"\t " << eur << L"€ equal to " << doll << L"$" << endl;
	_setmode(_fileno(stdout), _O_TEXT);
}
