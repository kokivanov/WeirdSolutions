#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

int exonp75();

// =========================== Just writes sybmol defined amount of times ========================================

void writeString(char a/*symbol*/, int b/*how many times to write*/) {
	for (int i = 0; i < b; i++) {
		printf("%c", a);
	}
}

// =========================== Finding maximum in double array ===================================================

double findMin(double* arr /*array where to look*/, int* n /*size of array*/) {
	double min = arr[0]; // begining point

	for (int i = 1;i < *n; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
		else continue;
	}

	return min;
}

 // ========================== Finding minimum in double array ===================================================

double findMax(double* arr /*array where to look*/, int* n /*size of array*/) {
	double max = arr[0]; // begining point

	for (int i = 1; i < *n; i++) {
		if (max <  arr[i]) {
			max = arr[i];
		}
		else continue;
	}

	return max;
}

 // ========================== Counts average in double array ===================================================

double average_(double* arr /*array where to look*/, int* n /*size of array*/) {
	double sum = 0;
	for (int i = 0; i < *n; i++) {
		sum += arr[i];
	}

	return sum / *n;
}

// ========================== Changes color of text in console =================================================
// you can ignore it
void setColor(int k) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, k);
}

 // ========================== Prints gistogram of given array =================================================

void printGistogramm(double* arr /*array where to look*/, int* a /*size of array*/) {
	const char point = '#'; // symbol of unit 
	
	double step;

	if (abs(findMax(arr, a)) < abs(findMin(arr, a)))
		step = abs(findMin(arr, a)) / 10;
	else
		step = abs(findMax(arr, a)) / 10;

	for (int i = 0; i < *a; i++) {
		int count = ceil((abs(arr[i]) - fmod(arr[i], step)) / step);
		setColor(11); //you can ignore it
		printf("\n \t Day %i \t ", i); //print number of day
		if (arr[i] > 0) { // if measure is lower than 0
			writeString(' ', 10); // put space
			setColor(15); 
			printf("|"); // print axis
			setColor(10);
			writeString(point, count); // print symbol
			setColor(13);
			printf("\t\t %6.2f ", arr[i]);//print value for day
		} 
		else if (arr[i] == 0) { //number equal to zero
			writeString(' ', 10); // put space
			setColor(15);
			printf("|"); // print axis
			setColor(13);
			printf("\t\t \t\t%6.2f ", arr[i]);//print value for day
		}
		else {
			setColor(12); 
			writeString(' ', 10 - count); // put free of symbols space
			writeString(point, count); // put symbols that left
			setColor(15);
			printf("|"); // print axis
			setColor(13);
			printf("\t\t \t\t%6.2f ", arr[i]);//print value for day
		}
	}

	setColor(15); //you can ignore it

	printf("\n Step: \t %.3f \n", abs(findMax(arr, a)/10)); // print step
}

// ========================== Prints commomn information (minimal, maximum and average temperature) =================================================

void showCommons(double* temp[] /*array where to look*/, int* countOfDays /*size of array*/) {
	printf("\t \t Minimal temperature is");
	setColor(12); // sets color to red
	printf("\t %.3f \n", findMin(*temp, countOfDays));
	setColor(15); //sets color to white
	printf("\t \t Average temrerature is");
	setColor(12); // sets color to red
	printf("\t %.3f \n", average_(*temp, countOfDays));
	setColor(15); //sets color to white
	printf("\t \t Maximal temperature is");
	setColor(12); // sets color to red
	printf("\t %.3f \n", findMax(*temp, countOfDays));
	setColor(15); //sets color to white
}
 // ========================== exonp75 FUNCTION ================================

int exonp75() {

	//creates console window
	AllocConsole();
	SetConsoleTitleA("WeirdSolutions");

	//sets localization
	setlocale(LC_ALL, "ru");

	//sets color to white
	setColor(15);

	// initialize variables
	int countOfDays = 0;
	double max = 0, min = 0, sum = 0, average = 0;
	
	// creating dynamic array ===========================================================================================================================
	
	printf("Enter amount of days \n");
	if (scanf_s("%i", &countOfDays) != 1) // checking is input valid
		exonp75();
	double* temp = new double[countOfDays]; // declaring array

	// ==================================================================================================================================================
	
	// Filling array
	for (int i = 0; i < countOfDays; i++) {
		printf("Enter a tamperature measure for day %i \n", i + 1);
		scanf_s("%lf", &temp[i]);
	}
	
	system("CLS"); // clear console

	showCommons(&temp, &countOfDays); // giving common information (minimal, maximum and average temperature)

	system("pause"); // wait before continue

	printGistogramm(temp, &countOfDays); // print gistogramm

	system("pause"); // wait before closing

	return 0;
}