/**
* @file EJ 1.cpp
* @author Alex Coronas Altemir (AKA. Seraphire)
* @date 16/10/2017
* @brief C++ Learning Documentation 1.
*
* @see https://github.com/Kayuwaii/EJERCICIOS-CPP
*/

/*
EXCERCISE 1
1)
a-Get name and surname, group(class for example), school and age. [INPUT]
b-Print the the input and calculate the age in days(aprox.), months(aprox.) and years. [OUTPUT]

2)
a-Get 2 numbers (num1 y num2). [INPUT]
b-Print the 5 results of the operations *, + , - , / , %. [OUTPUT]

3) (ADVANCED SOLUTION)
a- Get the name and price without taxes of a product, the % of taxes and the % of discount.
b- Print the name, price, price with discount, taxes %, value of taxes, and final price(Format output as a chart). [OUTPUT]
z- This last part contains "advanced" code (such as classes and loop (Not really THAT advanced, but advanced indeed)).
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
class Item; //Used in the third part
void menu();
void case1_calc_age();
void case2_math_op();
void case3_item_chart();
//We are forward declaring the methods, so they are in scope everywere in the code. 
#pragma endregion

class Item //We need to define the class, as a preference I generally define classes before main and methods after.
{
public:
	string name = "";
	int price = 0;
	int discount = 0;
	int tax = 0;
	int finalPriceNoTax = 0;
	int finalPrice = 0;

	Item(string name, int price, int discount, int tax); //Constructor declaration

private:
	void getPrices();
};


int main()
{
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
				case1_calc_age(); //Call case1 method
				break;
			case 2: //If the input equals 2
				case2_math_op(); //Call case2 method
				break;
			case 3: //If the input equals 3
				case3_item_chart(); //Call case3 Method
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
	string menu_options[] = {
		"Personal Data",
		"Mathematical Operations",
		"Price Chart for product"
	};
	int tmp_count = 1; // This variable is used to print a number before each option

	cout << "Select an Option:" << endl;
	for (string s : menu_options) // Foreach loop. For each ite
	{
		cout << "\t " << tmp_count << ". " << s << endl;
		tmp_count++;
	}
}

void case1_calc_age()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//Remove any "\n" (newline) characters trailing in the cin stream to avoid any future getline() to fail.
	cout << "Hello, input your name:\t";
	string name;
	getline(cin, name);
	cout << "What is your group?\t";
	string group;
	getline(cin, group, '\n');
	cout << "And how old are you?:\t";
	int age;
	cin >> age;
	cout << "Welcome " << name << " from " << group << ". You are " << age << " years old, wich equivals to " << (age * 12)
		<< " months or " << (age * 365) << " days." << endl;
}

void case2_math_op()
{
	cout << "Select your first number:\t ";
	int num1;
	cin >> num1;
	cout << "Select your second number:\t ";
	int num2;
	cin >> num2;
	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
	cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
	cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
	cout << num1 << " % " << num2 << " = " << num1 % num2 << endl;
}

void case3_item_chart()
{
	cout << "How many Products will you buy? \t ";
	int n_items;
	cin >> n_items;
	vector<Item> item_array = vector<Item>();
	for (int i = 0; i < n_items; ++i)
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//Remove any "\n" (newline) characters trailing in the cin stream to avoid any future getline() to fail.
		cout << "Input the product name:\t";
		string name;
		getline(cin, name);
		cout << "Input the price:\t ";
		int price;
		cin >> price;
		cout << "Input discount %:\t ";
		int discount;
		cin >> discount;
		cout << "Input TAX %:\t ";
		int tax;
		cin >> tax;
		item_array.push_back(Item(name, price, discount, tax));
	}
	printf("\n %10s| %10s| %10s| %5s| %20s| %10s \n", "NAME", "BASE PRICE", "DISCOUNT %", "TAX %", "PRICE WITHOUT TAXES",
		"FINAL PRICE");
	for (Item item : item_array)
	{
		printf(" %10s| %9u$| %9u%%| %4u%%| %19u$| %9u$ \n", item.name.c_str(), item.price, item.discount, item.tax,
			item.finalPriceNoTax, item.finalPrice);
	}
}


Item::Item(string name, int price, int discount, int tax)
{
	this->name = name;
	this->price = price;
	this->discount = discount;
	this->tax = tax;
	getPrices();
}

void Item::getPrices()
{
	finalPriceNoTax = price - ((price / 100) * discount);
	finalPrice = finalPriceNoTax + ((price / 100) * tax);
}