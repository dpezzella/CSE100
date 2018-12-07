/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Triangle.h
// SPECIFICATION: Class for the triangle
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 100- homework #5 - MWF 10:45-11:35am
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/ 

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
	private:
		int side1, side2, side3;
		int largest();
		int smallest();
	
	public:
		Triangle(int s1, int s2, int s3) {
			side1 = s1;
			side2 = s2;
			side3 = s3;
		}

		Triangle() {
			side1 = 0;
			side2 = 0;
			side3 = 0;
		}
	
		bool isRight();	
		bool isEquilateral();
		bool isIsosceles();
		bool isScalene();
		void print();
};

#endif

		