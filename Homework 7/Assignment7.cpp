/*-------------------------------------------------------------------------
// AUTHOR:
// FILENAME: Assignment7
// SPECIFICATION: This program prompts a user to enter a size for the array
//                and create an object. Then it displays
//                a menu to a user, and process a requested task accordingly.
// TIME SPENT: how long it took you to complete the assignment
//----------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include<string>

#include "IntList.h"
using namespace std;

//function prototype
void printMenu();

int main( )
{
			int number, size;
			char command;


			// instantiate a NumberCollection object
			IntList collection;
			// print the menu
			printMenu();

			do
			{
				// ask a user to choose a command
				cout << "\nPlease enter a command or type ?";
				cin >> command;
				switch (command)
				{
					case 'a': // add a number
						cout << "\nPlease enter an integer to add:";
						cin >> number;
						collection.addNumber(number);
						break;
					case 'b': // remove a number
						cout << "\nPlease enter an integer to remove:";
						cin >> number ;
						collection.removeNumber(number);
						break;
					case 'c': // display the array
						collection.print();
						break;
					case 'd': // compute and display the maximum
						cout << "\nThe maximum is: "  <<  collection.findMax();
						break;
					case 'e': // compute and display the minimum
						cout << "\nThe minimum is: " << collection.findMin();
						break;
					case 'f': // compute and display the average
						cout << "\nThe average is: " << collection.computeAverage();
						break;
					case '?':
						printMenu();
						break;
					case 'q':
						break;
					default: // wrong command
						cout << "Invalid command";
						break;
				}//end of switch

			} while (command != 'q');

		}  //end of the main method


		// this method prints out the menu to a user
		void printMenu()
		{
			          cout << "\nCommand Options\n";
					  cout  << "-----------------------------------\n";
					   cout << "a: add an integer in the array\n";
					   cout <<  "b: remove an integer from the array\n";
					   cout <<  "c: display the array\n";
					   cout << "d: compute and display the maximum\n";
					   cout << "e: compute and display the minimum\n";
					   cout << "f: compute and display the average\n";
					   cout << "?: display the menu again\n";
					   cout <<  "q: quit this program\n\n";

		} // end of the printMenu method
