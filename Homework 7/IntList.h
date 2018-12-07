/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Assignment7
// SPECIFICATION: IntList class definition. 
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/

#ifndef INTLIST_H
#define INTLIST_H

#define SIZE 20

class IntList {
	private:
		int numberArray[SIZE];
		int count;
		int indexOf(int);
		int size;

	public:
		IntList() {
			//Initialize array with -527 for all elements
			for(int i = 0; i < SIZE; i++) {
				numberArray[i] = -527;	
			}

			size = SIZE;
			count = 0;
		}
		
		bool addNumber(int);
		bool removeNumber(int);
		int findMax();
		int findMin();
		double computeAverage();
		void print();
};

#endif