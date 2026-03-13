

/*
* Author: Burke Stachurski
* Course: IT-312
* Date: 3/9 - 15/2026
* Assignment: GPA Calculator
*
* Logic : This is driver program for the GPA Calculator.
* It initializes a vector to hold the letter grades, calls the getInput function to populate it.
* Then it calls calculate GPA to compute the GPA based on input grades and outputs the result.
* Finally, it calls convertToHonors to evaluate the GPA and output the corresponding honors classification.
* 
*/

#include <iostream>
#include <vector>
#include "GPA.h"

// Using declarations to avoid having to prefix std::before every standard library component.
using std::cout;
using std::endl;


int main() {
   
    std::vector<char> myGrades(4);

	getInput(myGrades);

    double coursesGPA = calculateGPA(myGrades);
    cout << "GPA: " << coursesGPA << "\n" << endl;


    convertToHonors(coursesGPA);

    return 0;
   
}