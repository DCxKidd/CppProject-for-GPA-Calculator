/*
* Author: Burke Stachurski
* Course: IT-312
* Date: 3/9 - 15/2026
* Assignment: GPA Calculator
* 
* This program allows us to take 4 letters as input (A, B, C, D, F) and calculate the GPA based on the standard 4.0 scale.
* Then use that GPA to determine the honors level of the student (Summa Cum Laude, Magna Cum Laude, Cum Laude, or No Honors).
*/

#include <iostream>
#include "GPA.h"

using std::cout;
using std::cin;
using std::endl;


void getInput(std::vector<char>& grades) {

	/* 
	* Function: getInput
	* Parameters: A reference to a vector of characters (grades) will hold the letter grades input by the user.
	* Logic: This function prompts user to enter a letter grade for each 4 courses.
	* Also, it forces the user to enter valid letter grades (A, B, C, D, F) through a simple validation loop.
	* With each letter grade input, the function converts it to uppercase to ensure case-insensitive input handling.
	* 
	*/
	cout << "Enter letter grades (A, B, C, D, F):\n";

	for (int i = 0; i < grades.size(); ++i) {
		bool isValid = false;

		// Simple validation loop for input
		while (!isValid) {
			cout << "Grade " << (i + 1) << ": ";
			cin >> grades[i];

			// Convert to uppercase to avoid unneccessary bugs
			grades[i] = toupper(grades[i]);

			// Basic conditional to check for valid input
			if (grades[i] == 'A'
				|| grades[i] == 'B'
				|| grades[i] == 'C'
				|| grades[i] == 'D'
				|| grades[i] == 'F'
				)
				isValid = true;
			else {
				cout << "Invalid input please try again with letter values (A, B, C, D, F) \n";
			}
		}
	}
	
}

/*
* Function: calculateGPA
* Parameters: A constant reference to a vector of characters (grades) that contains the letter grades input by the user.
* Logic: This function takes a vector of letter grades as input and calculates the GPA based on the standard 4.0 scale.
* Additonally, the for loop is a simple character by charater iteration to determine GPA (through totalPoints).
* Then by using a switch statement to assign point values to each letter grade (A=4.0, B=3.0, C=2.0, D=1.0, F=0.0).
* 
*/


double calculateGPA(const std::vector<char>& grades) {
	double totalPoints = 0.0;

	for (char grade : grades) {

		switch (toupper(grade)) {
		case 'A':
			totalPoints += 4.0;
			break;
		case 'B':
			totalPoints += 3.0;
			break;
		case 'C':
			totalPoints += 2.0;
			break;
		case 'D':
			totalPoints += 1.0;
			break;
		case 'F':
			totalPoints += 0.0;
			break;
		default:
			cout << "Invalid grade input please enter a valid letter grade (A, B, C, D, F)" << grade << endl;
			break;
		}
	}
	// This allows your courses GPA to be calculated by dividing the total courses size (4) by the total GPA value based off user input.
	double coursesGPA = totalPoints / grades.size();

	return coursesGPA;
}
/*
* Function : convertToHonors
* Parameters: A double value (coursesGPA) that represents the calculated GPA based on the user's input letter grades.
* Logic: This function uses conditional statements to change the coursesGPA to
* boolean values on the honors level of the student based on the following criteria :
* Summa Cum Laude : 3.9 - 4.0
* Magna Cum Laude : 3.7 - 3.89
* Cum Laude : 3.5 - 3.69
* No Honors : Below 3.5
*
*/

void convertToHonors(double coursesGPA) {
	
	if (coursesGPA >= 3.9) {
		cout << "Summa Cum Laude is True\n";
		cout << "Magna Cum Laude is false\n";
		cout << "Cum Laude is false\n";
		cout << "No Honors is false\n";
	}

	else if (coursesGPA >= 3.7) {
		cout << "Summa Cum Laude is false\n";
		cout << "Magna Cum Laude is True\n";
		cout << "Cum Laude is false\n";
		cout << "No Honors is false\n";
	}

	else if (coursesGPA >= 3.5) {
		cout << "Summa Cum Laude is false\n";
		cout << "Magna Cum Laude is false\n";
		cout << "Cum Laude is True\n";
		cout << "No Honors is false\n";
	}

	else if (coursesGPA < 3.5) {
		cout << "Summa Cum Laude is false\n";
		cout << "Magna Cum Laude is false\n";
		cout << "Cum Laude is false\n";
		cout << "No Honors is True\n";
	}
}
