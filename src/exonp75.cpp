#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

int exonp75();

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

	double step = ceil(((findMax(arr, a) - findMin(arr, a)) / 20)*100)/100; // count step (one symbol = (max - min)/amount_of_symbols 
	//and roud up tp hundred)
	
	for (int i = 0; i < *a; i++) {
		setColor(11); //you can ignore it
		printf("\n \t Day %i \t ", i); //напичатать номер дня
		setColor(10); //you can ignore it
		for (int j = 0; j < (ceil(arr[i] - fmod(arr[i], step)) / step)+1 /*count amount of iterations (divide measure by step)*/; j++) { 
			printf("%c", point);
		}
	}
	setColor(15); //you can ignore it

	printf("\n \t \t \t \t Step is %f  ", step); // print step

	printf("\n");
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
	//AllocConsole();
	//SetConsoleTitleA("WeirdSolutions");

	//sets localization
	//setlocale(LC_ALL, "ru");

	//sets color to white
	//setColor(15);

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