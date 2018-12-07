/*-------------------------------------------------------------------------
// AUTHOR: Derek Pezzella
// FILENAME: Assignment5.cpp
// SPECIFICATION: Takes judges' scores from a talent competition, removes the 
		  highest and lowest scores, the aveages the middle three. The average
		  is the competitor's final score.
// LAB: Section B Th 1:30-2:20 with Batni
// FOR: CSE 100- homework #5 - MWF 10:45-11:35am
// TIME SPENT: 2 hours
//----------------------------------------------------------------------*/ 

#include <iostream>
#include <iomanip>
using namespace std;

/*PART 1: WRITTEN EXERCISES
1) Prototype: bool compareTwo(int, int, int)
   Header line: bool compareTwo(int max, int num1, int num2)
2) Prototype: double avg(int, int, int)
   Definition: 
	double avg(int num1, int num2, int num3) {
		double average = (num1 + num2 + num3)/3.0;
		double returnValue;

		if(average < 10) {
			cout << num1 << " " << num2 << " " << num3 << " " << average << '\n';
			returnValue = average;
		} else {
			cout << "Error: Average is less than ten." << '\n';
			returnValue = 0.0;
		}

		return returnValue;
	}
			
*/

//PART 2: PROGRAMMING

//function prototypes
void getJudgeData(double &);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

int main() {
	double score1, score2, score3, score4, score5, highestScore, lowestScore;
	char moreScores;

	//Get judge scores, find and throw out the lowest and highest scores, then calculate 
	//the final score by averaging the three remaining scores.
	//Continue until the user enters a letter other than 'y'
	do { 
		//get judges' scores from user
		getJudgeData(score1);
		getJudgeData(score2);
		getJudgeData(score3);
		getJudgeData(score4);
		getJudgeData(score5);

		//find the lowest and highest scores to drop
		highestScore = findHighest(score1, score2, score3, score4, score5);
		lowestScore = findLowest(score1, score2, score3, score4, score5);

		//find the score matching the highest score, and set it to zero
		//so it won't affect the final score average
		if(highestScore == score1)
			score1 = 0.0;
		else if(highestScore == score2)
			score2 = 0.0;
		else if(highestScore == score3)
			score3 = 0.0;
		else if(highestScore == score4)
			score4 = 0.0;
		else
			score5 = 0.0;

		//find the score matching the lowest score, and set it to zero
		//so it won't affect the final score average
		if(lowestScore == score1)
			score1 = 0.0;
		else if(lowestScore == score2)
			score2 = 0.0;
		else if(lowestScore == score3)
			score3 = 0.0;
		else if(lowestScore == score4)
			score4 = 0.0;
		else
			score5 = 0.0;

		//calculate the final score
		calcScore(score1, score2, score3, score4, score5);

		//ask the user if they want to enter in another contestant's scores
		//and repeat the process if they do
		cout << "Do you want to enter the score for another talent competition?" << '\n';
		cout << "Enter y or n: ";
		cin >> moreScores;

	} while(moreScores == 'y');

	return 0;
}

/*=======================================
getJudgeData
Gets the judge's score for each variable called in the main() function
=========================================*/
void getJudgeData(double &score) {
	cout << "Enter score between 0 and 10: ";
	cin >> score;

	//check if the user's entered score was between 0 and 10. if it isn't, keep looping
	//until the judge's score is
	while(score < 0 || score > 10) {
		cout << "Score must be in range 0 - 10. Please re-enter score: ";
		cin >> score;
	} 
}

/*=======================================
findLowest
Find the lowest judge's score by going through and comparing each variable
=========================================*/
double findLowest(double s1, double s2, double s3, double s4, double s5) {
	double lowest;

	if(s1 < s2 && s1 < s3 && s1 < s4 && s1 < s5)
		lowest = s1;

	if(s1 > s2 && s3 > s2 && s4 > s2 && s5 > s2) 
		lowest = s2;
	
	if(s1 > s3 && s2 > s3 && s4 > s3 && s5 > s3)
		lowest = s3;

	if(s1 > s4 && s2 > s4 && s3 > s4 && s5 < s4)
		lowest = s4;

	if(s1 > s5 && s2 > s5 && s3 > s5 && s4 > s5)
		lowest = s5;

	return lowest;
}

/*=======================================
findHighest
Find the highestjudge's score by going through and comparing each variable
=========================================*/
double findHighest(double s1, double s2, double s3, double s4, double s5) {
	//find the highest judge's score by comparing each score one at a time
	double highest;

	if(s1 > s2)
		highest = s1;
	else
		highest = s2;
	
	if(s3 > highest)
		highest = s3;

	if(s4 > highest)
		highest = s4;

	if(s5 > highest)
		highest = s5;

	return highest;
}

/*=======================================
calcScore
calculate the average, with the lowest and highest scores being set to 0
=========================================*/
void calcScore(double s1, double s2, double s3, double s4, double s5) {
	double finalScore = (s1 + s2 + s3 + s4 + s5)/3.0;

	cout << setprecision(2) << fixed;
	cout << '\n' << "The contestant's talent score is " << finalScore << '\n' << '\n';
}