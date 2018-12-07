//***********************************************************
// Name: Derek Pezzella
// Title: Assignment1.cpp
// Description: The first part of the program, 
//		labeled "Part 1" in a block comment, answers
//		questions from the hw1 PDF. The second part
//		asks the user their name and height in feet
//		and inches, then converts it to metric.
// Time & dates of your lab: Th 1:30-2:20
// Time spent: 1 hour
// Date: 8/24/2018
//**************************************************************

//*************
//Part 1
//*************

/*
1. a. The program will print out "In 2007 February had 28 days."
   b. The program will print out the following:
	The value of number is number
	The value of number is 5
	Now the value of number is 7
2. a. cin >> description;
   b. getline(cin, description);
3. a. d1 = d2 - 8.5;
   b. d2 = d1*3.14;
   c. c = 70;
   d. i += 1;
*/

//*************
//Part 2
//*************

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	//create variables
	string name; 
	int feet, inches;
	double heightMeters;
	const double amerToMeters = 2.54/100;

	//get input from user on their name and height in feet and inches
	cout << "What is your name? ";
	cin >> name; 
	
	cout << "What is your height?" << endl;
	cout << "Feet: ";
	cin >> feet;
	cout << "Inches: ";
	cin >> inches;

	//convert the user's height from American measurements to meters
	heightMeters = ((feet * 12) + inches) * amerToMeters;

	//display the user's height in meters
	cout << setprecision(3);
	cout << name << ", " << "your height in meters is " << heightMeters << endl;

	return 0;
}



	