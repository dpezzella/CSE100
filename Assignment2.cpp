/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Assignment2.cpp
// SPECIFICATION: This program calculates the net profit of a movie theater.
//		  It takes the movie name and number of adult and child tickets sold from the user,
//		  calculates the gross, then deducts 80% of the earnings, leaving the 20% as profit.
//		  Finally,it outputs the inputted data and the calculations.
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 100- homework #2- MWF 10:45-11:35
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/ 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Part 1: Written exercises
/* -----------------------------
1) cout << setprecision(3) << showpoint << setw(8) << divSales << endl;
2) a) cmath
   b) iostream
   c) iomanip
   d) string
--------------------------------*/

//Part 2: Programming

int main() {
	const double PROFIT_PCT = 0.2; //percentage that the theater gets
	const int TICKET_ADULT = 6, TICKET_CHILD = 3; //prices of tickets
	double gross, net;
	int adultSold, childSold; //amount of adult and tickets sold
	double adultGross, childGross; //gross amount generated from adult and child tickets
	string movieName;
	
	//get movie name, and amount of adult and child tickets sold
	cout << "Please enter in the name of the movie: ";
	getline(cin, movieName);
	
	cout << "Please enter the total amount of adult tickets sold: ";
	cin >> adultSold;

	cout << "Please enter the total amount of child tickets sold: ";
	cin >> childSold;

	//calculate the gross and net amounts taken in by the theater
	//the net calculates the 20% profit 
	adultGross = TICKET_ADULT * adultSold;
	childGross = TICKET_CHILD * childSold;
	gross = adultGross + childGross;
	net = gross * PROFIT_PCT;

	//format and output data
	cout << "\n";
	cout << "Revenue Report" << endl;
	cout << "\n";

	cout << left << setw(35) << "Movie Name:" << right << "\"" << movieName << "\"" << endl;
	cout << left << setw(35) << "Adult Tickets Sold:" << right << adultSold << endl;
	cout << left << setw(35) << "Child Tickets Sold:" << right << childSold << endl;
	cout << setprecision(5);
	cout << showpoint; //all numbers in the program are integers, but we want two decimal places shown
	cout << left << setw(33) << "Gross Box Office Profit:" << left << setw(2) << "$" << right << setw(2) << gross << endl;
	cout << left << setw(32) << "Amount Paid to Distributor:" << left << setw(3) << "-$" << right << setw(2) << gross - net << endl;
	cout << left << setw(33) << "Net Box Office Profit:" << left << setw(2) << "$" << right << setw(2) << net << endl;
	
	//prompt the user to end the program
	cout << "\n";
	cout << "Press any key to continue...\n"; 
	cout << "\n";
	
	cin.get();

	return 0;
}