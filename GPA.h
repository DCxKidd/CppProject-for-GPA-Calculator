/* Author: Burke Stachurski
* Course : IT - 312
* Date : 3 / 9 - 15 / 2026
* Assignment : GPA Calculator
* 
* Logic: This header defines central interface for the GPA Calculator functionality.
* It declares the functions required to securely get user input,
* compute a GPA value, and evaluate
* that value to output honors classifications.
*/

#ifndef GPA_H
#define GPA_H

#include <vector>

// Delecaration of functions to be used in main.cpp and defined in GPA.cpp
void getInput(std::vector<char>& grades);
double calculateGPA(const std::vector<char>& grades);
void convertToHonors(double coursesGPA);

#endif // GPA_H 