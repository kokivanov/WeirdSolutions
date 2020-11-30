#include "headers/Header.h"


//	=========================================   Main() is defined in main.cpp Main function in this file is "exonp85()" read README.md in root directory for more information   ===================================================

void setColor(int k); // ===== Defined in consoleinterface.cpp =====

// ========================================	Prints array =============================================
void printArr(int arr[], int n) {

	printf("\n");

	for (int i = 0; i < n; i++)
		printf("\t %i", arr[i]);
}

// ========================================	Finds position of maximum element in array =============================================
int findMaxPos(int arr[], int a, int b) {

	int pos = a;

	for (int i = a; i < b; i++) {

		if (arr[i] > arr[pos])
			pos = i;
	}
	return pos;
}

// ========================================	Swaps two elements in array by position =============================================
void swap(int* arr, int a, int b) {

	/*int tmp = arr[a] = arr[b];
	arr[b] = tmp;*/

	if (arr[a] != arr[b])
	{
		arr[a] ^= arr[b];
		arr[b] ^= arr[a];
		arr[a] ^= arr[b];
	}
}

// ============================================ Sorts array from highest to lowest =====================================================
void sortByDescending(int arr[], int n) {

	for (int i = 0; i < n; i++) {

		int pos = findMaxPos(arr, i, n);

		if (pos == i)
			continue;
		else
			swap(arr, pos, i);
	}
}

// ========================================	Checks is number simple =============================================
bool isIdeal(int n) {

	int sum = 0;

	for (int j = 1; j < n; j++) {

		if (n % j == 0)
			sum += j;
	}

	if (sum == n)
		return true;

	return false;
}

// ========================================	prints array, all simple numbers will be colored in red =============================================
void markIdealNumber(int arr[], int n) {

	printf("\n Sorted array, simple numbers are marked by red color:\n ");

	for (int i = 0; i < n; i++) {

		if (isIdeal(arr[i])) {

			setColor(12);
			printf("%i \t", arr[i]);
			setColor(7);
		} else 

			printf("%i \t", arr[i]);
	}
}

// ========================================	this function will be called in main.cpp =============================================
void exonp85() {
	// creates console window
	AllocConsole();
	SetConsoleTitleA("Simpliest task scince last month");

	system("CLS"); // clear console


	printf("Enter array size:\n");
	int n;
	if (scanf_s("%d", &n) != 1) { // checks for valid input
		printf("Input error\n");
		system("pause");
	}

	auto start = std::chrono::steady_clock::now(); // get time of start program

	int* table = new int[n]; // Init array

	srand(time(NULL)); // Make rand() more random

	for (int i = 0; i < n; i++)
		table[i] = rand() % 100000;

	printf("Current array: \n");
	printArr(table, n); // prints current generated array
	printf("\n");

	sortByDescending(table, n); // sorts arry by descending (from higest tot lowest)

	printf("\n");
	markIdealNumber(table, n); // prints array, all simple numbers will be colored in red
	printf("\n");

	auto end = std::chrono::steady_clock::now(); // get time of end program 

	double elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);


	system("pause");
}