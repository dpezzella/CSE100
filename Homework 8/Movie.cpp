/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Movie.cpp
// SPECIFICATION: Definition file for the Movie class.
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 100- homework #8 - MWF 10:45-11:35am
// TIME SPENT: 5 hours
//----------------------------------------------------------------------*/ 

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Movie.h"
using namespace std;

//to control the output for testing purposes
//#define TEST

/*===============================================
Movie()
Load files 'seatAvailability.txt' and 'seatPrices.txt'
to initialize the seats[][] and price[] variables, respectively.
Also, intialize seatsSold and totalRevenue to 0.
=================================================*/
Movie::Movie() {
	//load seatAvailility.txt and initialize seats variable
	ifstream seatsFile;
	string seatsLine;
	int i = 0;

	seatsFile.open("seatAvailability.txt");

	if(seatsFile) {
		for(int h = 0; h < NUMROWS; h++) {
			for(int i = 0; i < NUMCOLUMNS; i++) {
				seatsFile >> seats[h][i];
			}
		}
	} else {
		cout << "Cannot open seatAvailability.txt\n";
	}
	
	seatsFile.close();

	//load seatPrices.txt and initialize seats variable
	ifstream priceFile;
	string priceLine;

	priceFile.open("seatPrices.txt");

	if(priceFile) {
		for(int j = 0; j < NUMROWS; j++) {
			priceFile >> price[j];
#ifdef TEST
	cout << "\033[1;31m" << "Row " << j + 1 << ": " << price[j] <<  "\033[0m\n";
#endif

		}
	} else {
		cout << "Cannot open seatPrices.txt\n";
	}

	priceFile.close();

	//set seatsSold and totalRevenue to 0
	seatsSold = 0;
	totalRevenue = 0;
}

/*===============================================
requestTickets(int seatNum, int requestedRow, int startingSeatNum)
Checks to see if the indicated seats are available
by seeing if they are marked '#' (available) or '*' (not available).
=================================================*/
bool Movie::requestTickets(int seatNum, int requestedRow, int startingSeatNum) {
	bool seatsAvailable = true;

	for(int i = 0; i < seatNum; i++) {
		if(seatsAvailable) { 
			if(getSeat(requestedRow, startingSeatNum + i) == '#') {
#ifdef TEST
				cout << "\033[1;31m" << "Seat row: " << requestedRow << " seat: " << startingSeatNum + i <<  "\033[0m\n";
				cout << "\033[1;31m" << "Seat status: " << getSeat(requestedRow, startingSeatNum + i) <<  "\033[0m\n";
#endif
			} else {
				seatsAvailable = false;
			}
		} 
	}

	return seatsAvailable;
}

/*==========================
purchaseTickets(int seatNum, int requestedRow, int startingSeatNum)
Buy the specified number of tickets, starting with startingSeatNum at requestedRow
============================*/
void Movie::purchaseTickets(int seatNum, int requestedRow, int startingSeatNum) {
	char purchaseTickets;
	double amtPaid;

	cout << fixed << setprecision(2); 
	cout << "The total purchase price is " << seatNum << " X $" << getPrice(requestedRow) << " = $" << getPrice(requestedRow) * seatNum << '\n';
	cout << "Do you wish to purchase these tickets (Y/N)? ";
	cin >> purchaseTickets;

	if(purchaseTickets == 'Y' || purchaseTickets == 'y') {
		cout << "Num Seats: " << seatNum << '\n';
		cout << fixed << setprecision(2);
		cout << "The price for the requested tickets is $" << getPrice(requestedRow) * seatNum << "\n\n";
		cout << "Please input amount paid: $";
		cin >> amtPaid;

		//not adjusting the startingSeaNum because it should have already
		//been substracted by 1 in the function that calls it
		for(int i = 0; i < seatNum; i++) {
			seats[requestedRow-1][startingSeatNum - 1 + i] = '*';

#ifdef TEST
		cout << "\033[1;31m" << "Seat row: " << requestedRow << " seat: " << startingSeatNum + i <<  "\033[0m\n";
		cout << "\033[1;31m" << "Seat status: " << getSeat(requestedRow, startingSeatNum + i) <<  "\033[0m\n";
#endif

		}

		printTickets(seatNum, requestedRow, startingSeatNum);
		cout << '\n';

		cout << setw(25) << left << "Tickets purchased" << ": " << seatNum << '\n';
		cout << fixed << setprecision(2);
		cout << setw(25) << left << "Payment" << ": $" << amtPaid << '\n';
		cout << setw(25) << left << "Total ticket price" << ": $" << getPrice(requestedRow) * seatNum << '\n';
		cout << setw(25) << left << "Change due" << ": $" << amtPaid - (getPrice(requestedRow) * seatNum) << '\n';
		cout << '\n';

		seatsSold += seatNum;
		totalRevenue += getPrice(requestedRow) * seatNum;
	}
}

/*===============================================
getTotalRevenue
Returns the total revenue generated
=================================================*/
double Movie::getTotalRevenue() {
	return totalRevenue;
}

/*===============================================
seatsSold()
Returns the number of seats sold (private variable)
=================================================*/
int Movie::getSeatsSold() {
	return seatsSold;
}

/*===============================================
getPrice(int row)
Given the row, returns the price as given by
the 'seatPrices.txt' file.
=================================================*/
double Movie::getPrice(int row) {
	/*
	double seatPrice;

	switch(row) {
		case 1:
		case 2:
		case 3:
		case 4: seatPrice = 12.50; 
			break;
		case 5:
		case 6:
		case 7:
		case 8: seatPrice = 10.00;
			break;
		case 9:
		case 10:
		case 11:
		case 12: seatPrice = 8.00;
			break;
		case 13:
		case 14:
		case 15: seatPrice = 5.00;
			break;
	}*/

	return price[row-1];
}

/*===============================================
getSeat(int row, int column)
Returns the value of the seat. In other words,
is the seat marked '#' or '*'?
=================================================*/
char Movie::getSeat(int row, int column) {
	return seats[row-1][column-1];
}

/*===============================================
printTickets(int seatNum, int requestedRow, int startingSeatNum)
Shows the seat row and number, and price for a ticket
=================================================*/
void Movie::printTickets(int seatNum, int requestedRow, int startingSeatNum) {
	double rowPrice = getPrice(requestedRow);

	for(int i = 0; i < seatNum; i++) {
		cout << "***********************************************\n";
		cout << "*\tMovie Theather                             \n";
		cout << "*\tRow " << requestedRow << " Seat " << startingSeatNum + i << "\n";
		cout << fixed << setprecision(2);
		cout << "*\tPrice: $ " << rowPrice << "                 \n";
		cout << "***********************************************\n";
	}
}

/*===============================================
displaySeats()
Shows the entire theather's seats and their availability
=================================================*/
void Movie::displaySeats() {
	cout << setw(25) << right << "Seats\n";
	cout << setw(39) << right << "123456789012345678901234567890\n\n";

	for(int i = 0; i < NUMROWS; i++) {
		cout << left << "Row " << setw(2) << right << (i + 1);
		cout << setw(2);
		for(int j = 0; j < NUMCOLUMNS; j++) {
			cout << seats[i][j];
		}
		cout << '\n';
	}
	
	cout << "\n\n";
	cout << setw(24) << right << "Legend: * = Sold\n";
	cout << setw(31) << "# = Available\n\n\n";
}

/*===============================================
displaySalesReport()
Displays the amount of seats sold, the amout remaining,
and the total revenue generated.
=================================================*/
void Movie::displaySalesReport() {
	cout << "\n\n";
	cout << "Theater Sales Report\n";
	cout << "____________________\n\n";
	cout << "Seats sold: " << setw(15) << right << seatsSold << '\n';
	cout << "Seats available: " << setw(12) << right << (NUMROWS * NUMCOLUMNS) - seatsSold << '\n';
	cout << fixed << setprecision(2);
	cout << "Total revenue to date: " << setw(4) << right << "$" << totalRevenue << '\n'; 
	cout << "\n\n";
}
