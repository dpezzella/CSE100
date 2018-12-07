/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Movie.h
// SPECIFICATION: Movie class declaration
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 100- homework #8 - MWF 10:45-11:35am
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/ 

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
	private:
		static const int NUMROWS = 15;
		static const int NUMCOLUMNS = 30;

		char seats[NUMROWS][NUMCOLUMNS];
		double price[NUMROWS];
		int seatsSold;
		double totalRevenue;
	public:
		Movie();

		bool requestTickets(int seatNum, int requestedRow, int startingSeatNum);
		void purchaseTickets(int seatNum, int requestedRow, int startingSeatNum);
		double getTotalRevenue();
		int getSeatsSold();
		double getPrice(int row);
		char getSeat(int row, int column);
		void printTickets(int seatNum, int requestedRow, int startingSeatNum);
		void displaySeats();
		void displaySalesReport();
};

#endif