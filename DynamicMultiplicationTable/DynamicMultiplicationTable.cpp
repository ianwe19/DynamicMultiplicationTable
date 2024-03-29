// DynamicMultiplicationTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include <conio.h>


// prototype functions
int getInput();
void populateTable(int** ppRootPointer, int rows, int cols);
void printTable(int** ppRootPointer, int rows, int cols);


// constants
const int MAX_NUM = int(10); // values higher than 10 will work
const int MIN_NUM = int(0);


int main()
{
	int rows = int(0);
	int cols = int(0);

	std::cout << "Enter number of rows (1-10): ";
	rows = getInput();

	std::cout << "Enter number of columns (1-10): ";
	cols = getInput();

	int** ppRootPointer = NULL;
	ppRootPointer = new(int* [rows]); // create array of ptrs

	for (int i = 0; i < rows; i++) {
		ppRootPointer[i] = new(int[cols]); // create array for each ptr in aforementioned array of ptrs (to make 2d array)
	}

	populateTable(ppRootPointer, rows, cols);

	printTable(ppRootPointer, rows, cols);

	for (int i = 0; i < rows; i++) { // dealloc memory from each array in ptr array
		delete[] ppRootPointer[i];
	}
	delete[] ppRootPointer; // dealloc ptr array

	_getche;
}


int getInput() {
	int num = int(0);

	std::cin >> num;
	rewind(stdin); // clear potential extras from buffer

	while (!(std::cin) || num < MIN_NUM || num > MAX_NUM) { // for input sanitization
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Must be integer between 1-10: ";
		std::cin >> num;
	}
	return int(num); 
}


void populateTable(int** ppRootPointer, int rows, int cols) { // populate array with multiplication table values
	int colCounter = int(1);
	int rowCounter = int(1);

	for (int i = 0; i < rows; i++) { 
		for (int j = 0; j < cols; j++) {
			ppRootPointer[i][j] = colCounter * rowCounter;
			colCounter++;
		}
		rowCounter++;
		colCounter = 1; // reset after the end of each row before returning to leftmost cell
	}
}


void printTable(int** ppRootPointer, int rows, int cols) { // format and print the table, does not write to array
	
	std::cout << "   "; // print empty space in top left

	for (int i = 0; i < cols; i++) {
		std::cout << "|" << std::setw(3) << i + 1; // print top row of numbers, i + 1 because indexing at 0
	}

	std::cout << "\n";

	for (int i = 0; i <= cols; i++) {
		if (!i) {
			std::cout << "---"; // print divider under top row of numbers and omit leftmost "+" for leftmost cell
		}
		else {
			std::cout << "+---";
		}
	}

	std::cout << "\n";

	std::cout << std::right;

	for (int i = 0; i < rows; i++) {
		std::cout << std::setw(3) << i + 1; // hard coded way to print leftmost cell because of the space in top left

		for (int j = 0; j < cols; j++) {
			std::cout << "|" << std::setw(3) << *(*(ppRootPointer + i) + j); // print each value formatted like |___
		}

		std::cout << "\n";

		for (int j = 0; j <= cols; j++) {
			if (i == rows - 1) {
				break;
			}
			else if (!j) {
				std::cout << "---"; // print divider between each row after first row (which is done on line 92)
			}
			else {
				std::cout << "+---"; // and omit leftmost "+" for leftmost cell, again
			}
		}
		std::cout << "\n";
	}
}
