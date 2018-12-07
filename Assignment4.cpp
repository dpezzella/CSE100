/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Assignment4.cpp
// SPECIFICATION: description of the program
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 100- homework #4- MWF 10:45-11:35am
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/ 

#include <iostream>
#include <iomanip>
using namespace std;

/*PART 1: WRITTEN EXERCISES
1a. i is: 5 i is: 4 i is: 3 i is:2 i is:1 i is:0
    (or more clearly 5 4 3 2 1 0)
1b. while(i >= 0) {
	cout << "i is: " << i;
	i--;
    }
2. *****#####*****#####
3. * * * * *
   * * * *
   * * *
   * *
c. while(x >= 0 && x <= 100) {
	...
	cin >> x;
   }
*/

//PART 2: PROGRAMMING
int main() {
	char option;
	int opInt = 0;

	//variables for choice 'a': gcd
	int x,y;
	int xGCD, yGCD;

	//variables for choice 'b': min, max, sum, and avg of set
	int sequence;
	int min = 1000000, max=-1000000, sum, elements;
	double average;

	cout << "Command Options\n"
	     << "---------------\n"
	     << "a. find gcd\n" 
	     << "b. find min, max & average\n"
	     << "c. display menu\n"
	     << "q. quit\n";

	cin >> option;

	do {
		//reset variables
		opInt = -1;
		x = 0, y = 0, xGCD = 0, yGCD = 0;
		sequence = 0, min = 1000000, max=-1000000, sum = 0, elements = 1, average = 0.0;
		
		//translate user option into integer to be used by switch statement
		if(option == 'a' || option == 'A') 
			opInt = 0;
		else if (option == 'b' || option == 'B')
			opInt = 1;
		else if (option == 'c' || option == 'C')
			opInt = 2;
		else if (option == 'q' || option == 'Q')
			opInt = 3;
		else
			//if the user didn't enter in a valid choice, set opInt to -1
			opInt = -1;

		//process user's option
		switch(opInt) {
			case 0:
				//get user input of the integers
				cout << "Enter the first integer: ";
				cin >> x;
				cout << "Enter the second integer: ";
				cin >> y;

				xGCD = x;
				yGCD = y;

				//Euclid's GCD algorithm
				//if x < y, then set y to be the difference of yGCD and xGCD
				//if x > y, then set x to be the difference of xGCD and yGCD
				//if x = y, then the previously smaller one is a multiple of the other?
				while(xGCD != 0) {
					if(xGCD < yGCD)
						yGCD = yGCD - xGCD;
					else if (xGCD > yGCD)
						xGCD = xGCD - yGCD;
					else
						xGCD = 0;
				}
			
				cout << "The gcd of " << x << " and " << y << " is " << yGCD << '\n';

				break;
			case 1:
				cout << "Enter in a sequence of integers, 0 to quit: ";
				
				do {
					cin >> sequence;
					
					if(sequence != 0) {
						if(max < sequence)
							max = sequence;
						
						if(min > sequence)
							min = sequence;

						sum += sequence;
						
						elements += 1;
						cout << elements << endl;
					}

				} while(sequence != 0);

				average = static_cast<double>(sum)/static_cast<double>(elements-1);

				cout << "Largest: " << max << '\n' 
				     << "Smallest: " << min << '\n'
				     << "Sum is: " << sum << '\n'
				     << setprecision(2) << fixed
				     << "Average is: " << average << '\n';

				break;
			case 2:
				//this actually does nothing, since the menu will be shown at the end of the switch block
				break;
			case 3: 
				//quit the program. I don't think this is good coding style though.
				return 0;
				break;
			case -1:
				cout << "Invalid input!" << endl;
				break;
			default:
				cout << "Invalid input!" << endl;
		}
	
		cout << '\n' 
	             << "Command Options\n"
	     	     << "---------------\n"
	     	     << "a. find gcd\n" 
	     	     << "b. find min, max & average\n"
	     	     << "c. display menu\n"
	     	     << "d. quit\n";

		cin >> option;
		cout << '\n';
	} while(opInt != 3);

	return 0;
}