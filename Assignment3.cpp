/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Assignment3.cpp
// SPECIFICATION: A small calculator that takes two operands from the user
//                then asks them for an operation. The user may enter the operation's
//		  name (e.g. "add" or "ADD") or symbol (e.g, "+"). The calculator
//		  then performs the operation on the two operands, then outputs 
//		  the result.
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 110- homework 3 - MWF 10:45-11:35
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/ 
#include <iostream>
using namespace std;

/* Part 1: Written Exercises:
	1a) 8 + 1 + 2 - 1 + 1 = 11, since there is no break statement in case 5.
	1b) 4, since there is a break statement.
	2a) 0 + 3 = 3
	2b) 0 + 2 = 2
	3) 128
	4a) 0 10
	    1 9
	    2 8
	    3 7
	    4 6
	4b) *=====
	    *====
	    *===
	    *==
	    *=
*/

int main() {
	double firstOperand, secondOperand, result;
	string operation, operationLower = "";
	int opValue = 0; //assigns a value to the user's preferred operation to be used in a switch statement
	char opLetter; //holder for each character when converting operation to lower case
	
	//get operands from user
	cout << "Welcome to the calculator\n";
	cout << "Enter the first operand: ";
	cin >> firstOperand;
	cout << "Enter the second operand: ";
	cin >> secondOperand;
	cout << "\n";
	
	//get desired operation from user
	cout << "Operations are:\n"
		<< "ADD or + for addition\n"
		<< "SUBTRACT or - for subtraction\n"
		<< "MULTIPLY or * for multiplication\n"
		<< "DIVIDE or / for division\n";
	cout << "Enter your selection: ";
	cin >> operation;
	
	//format 'operation' into all lowercase so we can properly 
	//determine the operation the user wants more easily
	if(operation != "+" && operation != "-" && operation != "*" && operation != "/") {
		//go character by character in the string, convert to its lowercase equivalent, and put back into a string
		//to be copied into operation.
		
		for(int i = 0; i < operation.length(); i++) {
			opLetter = operation[i];
			opLetter = static_cast<char>(tolower(opLetter));
			operationLower += opLetter;
		}

		operation = operationLower;
	} else {
		//handle symbols
		if(operation == "+")
			operation = "add";
		if(operation == "-") 
			operation = "subtract";
		if(operation == "*")
			operation = "multiply";
		if(operation == "/")
			operation = "divide";
	}

	//convert the user's operation selection to an int to be used in our switch block
	if(operation == "add")
		opValue = 1;
	else if(operation == "subtract")
		opValue = 2;
	else if(operation == "multiply")
		opValue = 3;
	else if(operation == "divide")
		opValue = 4;
	
	//run the operation
	switch(opValue) {
		case 1:
			result = firstOperand + secondOperand;
			cout << "The sum is " << result << "\n";
			break;
		case 2:
			result = firstOperand - secondOperand;
			cout << "The difference is " << result << "\n";
			break;
		case 3:
			result = firstOperand * secondOperand;
			cout << "The product is " << result << "\n";
			break;
		case 4:
			result = firstOperand/secondOperand;
			cout << "The quotient is " << result << "\n";
			break;
		default:
			cout << "Not a valid operation" << '\n';
	}
	
	return 0;
}