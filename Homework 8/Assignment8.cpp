/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Assignment8.cpp
// SPECIFICATION: A ticket-reservation system for a movie theather.
//		  A user can reserve and purchase tickets,
//		  see revenue and remaining seats,and 
//		  check for availability.
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 100- homework #5 - MWF 10:45-11:35am
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/ 

#include <iostream>
#include <iomanip>
#include "Movie.h"
using namespace std;

void printMenu();

int main() {
	int menuChoice, seatsDesired, rowDesired, startingSeat;
	bool seatsReserved;
	Movie movie;

	do { 
		printMenu();

		cin >> menuChoice;

		switch(menuChoice) {
			case 1:
				//show seat availability
				movie.displaySeats();
				break;
			case 2:
				//get tickets for user
				cout << "Number of seats desired (1-30): ";
				cin >> seatsDesired;

				cout << "Desired row (1-15): ";
				cin >> rowDesired;

				cout << "Desired starting seat number in the row (1-30): ";
				cin >> startingSeat;
				
				seatsReserved = movie.requestTickets(seatsDesired, rowDesired, startingSeat);
				if(!seatsReserved)
					cout << "\n\nThe seats you have requested are not available for purchase.\n";
				else {
					cout << "\n\nThe seats you have requested are available for purchase.\n";
					movie.purchaseTickets(seatsDesired, rowDesired, startingSeat);
				}

				break;
			case 3:
				//show theater sales stats
				movie.displaySalesReport();
				break;
		}
	} while(menuChoice != 4);

	return 0;
}

void printMenu() {
	cout << setw(35) << right << "Movie Theater\n\n";
	cout << setw(15) << right << "1. " << setw(15) << left << "View Available Seats\n";
	cout << setw(15) << right << "2. " << setw(15) << left << "Request Tickets\n";
	cout << setw(15) << right << "3. " << setw(15) << left << "Display Theater Sales Report\n";
	cout << setw(15) << right << "4. " << setw(15) << left << "Exit the Program\n";
}