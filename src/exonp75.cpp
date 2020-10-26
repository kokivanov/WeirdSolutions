#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

#define MAX_TEMPERATURE 60
#define MIN_TEMPERATURE -90

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

		} else continue;

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

	// there is 10 symbols on left and right sides of axis and 1 symbol for axis
	// we find maximum not depended on sign and divide it by 10 to get step for 1 symbol unit 

	// по десять символов с каждой из сторон от оси + один для оси
	// находим максимально большое число в независимости от знака и делим его на 10, что бы найти шаг для одного символа
	if (abs(findMax(arr, a)) < abs(findMin(arr, a)))
		step = abs(findMin(arr, a)) / 10;

	else
		step = abs(findMax(arr, a)) / 10;

	//==============================================================================================================================================================

	// for each element of array
	for (int i = 0; i < *a; i++) {

		// кол-во символов считается как текущее значение поделить на шаг, однако что бы не потерять ничего и получить целое число мы отнимим от текущего числа остаток от деления еге самого на шаг и после этого сам результат уже поделим на шаг (ето нужно что бы в итоге получилось не дробное число) 
		// amount of symbols we count by dividing current number by step, but to get integer number we firstly subtract remainder of the division on step from current number then divide result by step (it's needed to get still (integer) number)
		int count = floor((abs(arr[i]) - fmod(arr[i], step)) / step); 

		setColor(11); //you can ignore it
		printf("\n \t Day %2i \t ", i); //print number of day

		if (arr[i] > 0) { // if measure is higher than 0

			writeString(' ', 10); // put space on left side of axis

			setColor(15); 
			printf("|"); // print axis

			setColor(10);
			writeString(point, count); // print symbols on right side

			setColor(13);
			writeString(' ', 10 - count); //  print symbols that left (total number(in this case 10) - printed)

			printf("\t %8.2f ", arr[i]);//print value for day
		} 

		else if (arr[i] == 0) { //number equal to zero

			writeString(' ', 10); // put space on left side of axis

			setColor(15);
			printf("|"); // print axis

			setColor(13);
			writeString(' ', 10); // put space on right

			printf("\t %8.2f ", arr[i]);//print value for day
		}

		else {

			setColor(12); 
			writeString(' ', 10 - count); // put symbols that are not sharps (subtrack amount of sharps from stotal number of symbols(10 in this case))
			writeString(point, count); // put symbols that left (sharps)

			setColor(15);
			printf("|"); // print axis

			setColor(13);
			writeString(' ', 10); // put space on right
			printf("\t %8.2f ", arr[i]);//print value for day

		}
	}

	setColor(15); //you can ignore it

	printf("\n \n \t \t Step: \t %.3f \n", abs(findMax(arr, a)/10)); // print step
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
	system("CLS"); // clear console
	printf("Press enter\n");
	while ((getchar()) != '\n'); // clear input buffer

	//creates console window
	AllocConsole();
	SetConsoleTitleA("Fucking gistogram");

	//sets localization
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//sets color to white
	setColor(15);

	// initialize variables
	int countOfDays = 0;
	double max = 0, min = 0, sum = 0, average = 0;
	
	// creating dynamic array ===========================================================================================================================
	
	printf("Enter amount of days \n");
	if ((scanf_s("%i", &countOfDays) != 1)||((countOfDays <= 0))) { // checking is input valid

		printf("Oops.. you did wrong, so CATCH AN ERRROR NOOB AND TRY AGAIN!!!!!\n");
		system("pause");
		exonp75();

	}

	fflush(stdin);

	double* temp = new double[countOfDays]; // declaring array

	// ==================================================================================================================================================
	
	// Filling array
	for (int i = 0; i < countOfDays; i++) {
		printf("Enter a tamperature measure for day %i \n", i + 1);
		if ((scanf_s("%lf", &temp[i]) != 1) || (temp[i] > MAX_TEMPERATURE) || (temp[i] < MIN_TEMPERATURE)) {

			printf("Oops.. looks like you aren't from eart, so CATCH AN ERRROR NOOB AND TRY AGAIN!!!!!\n");
			system("pause");
			exonp75();

		}
			
	}

	fflush(stdin);
	
	system("CLS"); // clear console

	showCommons(&temp, &countOfDays); // giving common information (minimal, maximum and average temperature)

	system("pause"); // wait before continue

	printGistogramm(temp, &countOfDays); // print gistogramm

	system("pause"); // wait before closing

	return 0;
}