/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Triangle.cpp
// SPECIFICATION: Function definitions for Triangle class.
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 100- homework #5 - MWF 10:45-11:35am
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/ 

#include <cmath>
#include <iostream>
#include "Triangle.h"
using namespace std;

/*===============================================
int largest()
returns the largest side of the triangle
=================================================*/
int Triangle::largest() {
	int largest;

	if(side1 > side2 && side1 > side3) {
		largest = side1;
	} else if(side1 < side2 && side2 > side3) {
		largest = side2;
	} else {
		largest = side3;
	}

	return largest;
}

/*===============================================
int smallest()
returns the smallest side of the triangle
=================================================*/
int Triangle::smallest() {
	int smallest;

	if(side1 < side2 && side1 < side3) {
		smallest = side1;
	} else if(side1 > side2 && side2 < side3) {
		smallest = side2;
	} else {
		smallest = side3;
	}

	return smallest;
}

/*===============================================
bool isRight()
determines if the triangle is a right triangle
right means an angle is 90 degrees
=================================================*/
bool Triangle::isRight() {
	bool right = false;
	int large = largest();
	int largeCase;

	if(large == side1)
		largeCase = 1;
	else if(large == side2)
		largeCase = 2;
	else if(large == side3)
		largeCase = 3;

	switch(largeCase) {
		case 1:
			//if(pow(side2,2) + pow(side3,2) == pow(side1,2))
			if((side2*side2) + (side3*side3) == (side1*side1))
				right = true;
			break;
		
		case 2:
			//if(pow(side1,2) + pow(side3,2) == pow(side2,2))
			if((side1*side1) + (side3*side3) == (side2*side2))
				right = true;
			break;
		
		case 3:
			//if(pow(side1,2) + pow(side2,2) == pow(side3,2))
			if((side1*side1) + (side2*side2) == (side3*side3))
				right = true;
			break;
	}

	return right;
}

/*===============================================
bool isEquilateral()
determines whether the triangle is equilateral
equilateral means longest side is equal to the shortest side
=================================================*/
bool Triangle::isEquilateral() {
	bool equal = false;
	int small, large;

	small = smallest();
	large = largest();

	if(small == large)
		equal = true;

	return equal;
}

/*===============================================
bool isIsosceles()
determines whether the triangle is isosceles
isosceles means at least two sides are the same length
=================================================*/
bool Triangle::isIsosceles() {
	bool iso = false;

	if(side1 == side2 || side1 == side3 || side2 == side3)
		iso = true;
	
	return iso;
}

/*===============================================
bool isScalene()
determines whether the triangle is scalene
scalene means no two sides are equal length
=================================================*/
bool Triangle::isScalene() {
	bool scal = false;

	if(side1 != side2 && side1 != side3 && side2 != side3)
		scal = true;

	return scal;
}

/*===============================================
void print()
print the results of the whether the triangle
is right, isosceles, equilateral, and scalene
=================================================*/
void Triangle::print() {
	cout << side1 << " " << side2 << " " << side3 << " triangle:\n";
	
	if(isRight())
		cout << "It is a right triangle\n";
	else
		cout << "It is not a right triangle\n";

	if(isIsosceles())
		cout << "It is isosceles\n";
	else	
		cout << "It is not isosceles\n";

	if(isEquilateral()) 
		cout << "It is equilateral\n";
	else
		cout << "It is not equilateral\n";

	if(isScalene())
		cout << "It is scalene\n";
	else
		cout << "It is not scalene\n";

}