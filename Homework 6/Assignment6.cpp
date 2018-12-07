/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Assignment6.cpp
// SPECIFICATION: Constructs a triangle based upon user-entered lengths,
		  then tests the triangle for the following properties:
		  right, isosceles, equilateral, and scalene.
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 100- homework #5 - MWF 10:45-11:35am
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/ 

#include <iostream>
#include "Triangle.h"
using namespace std;

int main() {
	int s1, s2, s3;
	char newTri;

	do {
		//get length inputs from user
		cout << "Enter the sides of the triangle:\n\n";

		cin >> s1;
		cin >> s2;
		cin >> s3;

		Triangle tri(s1,s2,s3);

		tri.print();

		cout << "Check another Triangle(y/n)? ";
		cin >> newTri;
	} while(newTri == 'y' || newTri == 'Y');

	return 0;
}