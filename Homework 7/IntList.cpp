/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Assignment7
// SPECIFICATION: Member functions for the IntList class.
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/

#include <iostream>
#include "IntList.h"

using namespace std;

/*===============================================
int indexOf(int)
Find searchingNum (an integer) in the array. If not
found, the function returns -1. 
=================================================*/

int IntList::indexOf(int searchingNum) {
	int index = -1;

	for(int i = 0; i < size; i++) {
		if(numberArray[i] == searchingNum) {
			index = i;
		}
	} 

	return index;
}

/*===============================================
bool addNumber(int)
Adds a number to the lowest available index, 
on the conditions that the array isn't full and
the number doesn't already exist in the array.
If successfully added, the function returns true.
Otherwise, the function returns false.
=================================================*/

bool IntList::addNumber(int numberToAdd) {
	int found = indexOf(numberToAdd);
	bool added = false;

	if(found == -1 && count < size) {
		numberArray[count] = numberToAdd;
		count++;
		added = true;
	}
	
	return added;
}

/*===============================================
bool removeNumber(int)
If element exists, removes an element from the array, 
and shift all elements following the element are 
moved to the left. If the removal and shift are
successful, return true. 
=================================================*/

bool IntList::removeNumber(int numberToRemove) {
	int found = indexOf(numberToRemove);
	bool removed = false;

	if(found != -1) {
		numberArray[found] = 0;

		//move elements down
		for(int i = found; i < count; i++)
			numberArray[i] = numberArray[i+1];

		removed = true;

		count -= 1;
	}

	return removed;
}

/*===============================================
int findMin()
Find the smallest element of the array.
If the array is empty, it returns 0.
=================================================*/

int IntList::findMin() {
	int smallest = 100000;

	if(count != 0) {
		for(int i = 0; i < count; i++) {
			if(smallest > numberArray[i])
				smallest = numberArray[i];
		}
	} else {
		smallest = 0;
	}

	return smallest;

}

/*===============================================
int findMax()
Find the largest element of the array. 
If the array is empty, it returns 0.
=================================================*/

int IntList::findMax() {
	int largest = -100000;

	if(count != 0) {
		for(int i = 0; i < count; i++) {
			if(largest < numberArray[i])
				largest = numberArray[i];
		}
	} else {
		largest = 0;
	}

	return largest;

}

/*===============================================
double computeAverage()
Gives the average of the array elements.
If the array is empty, it returns 0.
=================================================*/

double IntList::computeAverage() {
	double average;
	int sum = 0;

	if(count != 0) {
		for(int i = 0; i < count; i++) {
			sum += numberArray[i];
		}

		average = static_cast<double>(sum)/static_cast<double>(count);
	} else {
		average = 0.0;
	}

	return average;
}

/*===============================================
void print()
Print the contents of the array.
=================================================*/

void IntList::print() {
	cout << "{";
	for(int i = 0; i < count; i++) {
		cout << numberArray[i];
		
		//if it isn't the last element in the array, add a comma and space
		if(i != count -1)
			cout << ", ";
	}

	cout << "}\n";
}