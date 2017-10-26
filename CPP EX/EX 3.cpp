/**
* @file EJ 13.cpp
* @author Alex Coronas Altemir (AKA. Seraphire)
* @date 16/10/2017
* @brief C++ Learning Documentation 3.
*
* @see https://github.com/Kayuwaii/CPP-EX
*/

/*
EXCERCISE 3
a) - Option 1 (Apt / Not Apt): Ask for the user's grade and say if he/she has passed or not.
b) - Option 2 (driver's license): Ask the age of the user and say if you can take the
driving or not.
c) - Option 3 (even / odd): Ask for a number and say if it is even or odd.
d) - Option 4 (divisible between 7): Ask for a number and say if divisible between 7 or not.
e) - Option 5 (triangle): Ask the 3 sides of a triangle and say if it is equilateral (the 3 sides
same
f) - Option 6 (winner): In a football match between 2 teams A and B, request the number of
goals scored by each team and say which team has won or if they have tied.
g) - Option 7 (major): Ask for two numbers and say which one is greater.
h) - Option 8 (Carnet Jove): Ask for the age and say if you can get the card or not.
The Fellows of the Carnet Jove are all young people between 12 and 30 years old, all inclusive.
I) - Option 9 (grades): Ask for a grade and say which letter corresponds:
grade <5: I;
grade> = 5 and grade <6: S;
grade> = 6 and grade <7: B;
grade> = 7 and grade <9: N;
grade> = 9: E;
*/

//Include the precompiled headers
#include "stdafx.h"

//Include the "libraries" needed (HEADERS)
#include <iostream> // Header that defines the standard input/output stream objects
#include <string>	// This header introduces string types, character traits and a set of converting functions
#include <vector>	// Header that defines the vector container class. (ArrayList)


using namespace std;

//The following region contains the declarations of every method
#pragma region Method and Class Declaration
void menu();
void case1_checkIfPassed();
void case2_driversLicense();
void case3_EvenOrOdd();
void case4_Divisible7();
void case5_equilater();
void cas6_matchwINNER();
//We are forward declaring the methods, so they are in scope everywere in the code. 
#pragma endregion

int main()
{
	bool right_in = false; //Boolean to manage the menu repettition
	int sel; //Declare an empty integer. It will hold the user selection later.

	while (!right_in) //While the input is not valid repeat the block. 
	{
		menu(); //Execute the menu method. It prints every option that the menu has.
		cout << "\nSelect an Option:\t";
		int sel;
		cin >> sel;
		switch (sel)
		{
		default:
			cout << "Such option does not exist. Select a proper one." << endl;
			break;
		case 0:
			break;
		case 1:
			case1_checkIfPassed();
			break;
		case 2:
			case2_driversLicense();
			break;
		case 3:
			case3_EvenOrOdd();
			break;
		case 4:
			case4_Divisible7();
			break;
		case 5:
			case5_equilater();
			break;
		case 6:
			cas6_matchwINNER();
			break;
		case 7:
		}
	}
	return 0;
}

/**
* \brief Displays the menu options
*/
void menu()
{
	// We store each menu option as a String in an Array
	string menu_options[] = {
		"Check if you have passed",
		"Check if you can have a drivers license:",
		"Check if a number is odd or even",
		"Check if a number is divisible by 7",
		"Check if a triangle is equilater",
		"Check who won a match",
		"Check which number is bigger",
		"Check if you can have the \"Young Carnet\"",
		"Convert numeric grade to letter"
	};
	int tmp_count = 1; // This variable is used to print a number before each option

	for (string s : menu_options) // Foreach loop. For each ite
	{
		cout << "\t " << tmp_count << ". " << s << endl;
		tmp_count++;
	}
	cout << "\t 0. Exit." << endl;
}

void case1_checkIfPassed()
{
	bool checker = true;
	do
	{
		cout << "\n\tInput your grade:\t";
		double grade;
		cin >> grade;
		if (grade >= 5 && grade <= 10)
		{
			cout << "Congratulations! You passed." << endl;
		}
		else if (grade < 5 && grade >= 0)
		{
			cout << "Sorry... you failed. Miserably if I must say." << endl;
		}
		else
		{
			cout << "That's not a proper grade." << endl;
			checker = false;
		}
	} while (!checker);
}

void case2_driversLicense()
{
	cout << "\n\tInput your age:\t";
	int age;
	cin >> age;
	if (age >= 18)
	{
		cout << "You can apply for a driving license." << endl;
	}
	else
	{
		cout << "You cannot have a driving license." << endl;
	}
}

void case3_EvenOrOdd()
{
	cout << "\n\tInput a number:\t";
	int num;
	cin >> num;
	if (num % 2 == 0)
	{
		cout << "It's even!" << endl;
	}
	else
	{
		cout << "It's odd!" << endl;
	}
}

void case4_Divisible7()
{
	cout << "\n\tInput a number:\t";
	int num;
	cin >> num;
	if (num % 7 == 0)
	{
		cout << "It's divisible by 7!" << endl;
	}
	else
	{
		cout << "It's not divisible by 7!" << endl;
	}
}

void case5_equilater()
{
	cout << "\n\tInput one side of the triangle:\t";
	int side1;
	cin >> side1;
	cout << "\n\tInput another side of the triangle:\t";
	int side2;
	cin >> side2;
	cout << "\n\tInput the last side of the triangle:\t";
	int side3;
	cin >> side3;
	if (side1 == side2 && side2 == side3)
	{
		cout << "It's equilater" << endl;
	}
	else
	{
		cout << "It's equilater" << endl;
	}
}

void cas6_matchwINNER()
{
	cout << "\n\tInput the score of the first team:\t";
	int team1Score;
	cin >> team1Score;
	cout << "\n\tInput the score of the second team:\t";
	int team2Score;
	cin >> team2Score;
	if (team1Score > team2Score)
	{
		cout << "The first team won!!!!!" << endl;
	}
	else if (team1Score < team2Score)
	{
		cout << "The second team won!!!!!" << endl;
	}else
	{
		cout << "The match ended in a draw" << endl;
	}
}
