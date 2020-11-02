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
void swap(int arr[], int a, int b) {

	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
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
bool isSimple(int n) {

	if (n == 2)
		return true;

	for (int i = 2; i < sqrt(abs(n))+1; i++)
		if (abs(n) % i == 0)
			return false;

	return true;
}

// ========================================	prints array, all simple numbers will be colored in red =============================================
void markSimpleNumber(int arr[], int n) {

	printf("\n Sorted array, simple numbers is marked by red color:\n ");

	for (int i = 0; i < n; i++) {

		if (isSimple(arr[i])) {

			setColor(12);
			printf("%i \t", arr[i]);
			setColor(7);
		} else 

			printf("%i \t", arr[i]);
	}
}

// ========================================	this function will be called in main.cpp =============================================
int exonp85() {
	// creates console window
	AllocConsole();
	SetConsoleTitleA("Simpliest task scince last month");

	system("CLS"); // clear console


	printf("Enter array size:\n");
	int n;
	if (scanf_s("%d", &n) != 1) { // checks for valid input
		printf("Input error\n");
		system("pause");
		return 0;
	}

	int* table = new int[n]; // Init array

	srand(time(NULL)); // Make rand() more random

	for (int i = 0; i < n; i++)
		table[i] = (rand() % 200) - 100; // fills array with random numbers from -99 to 99

	printf("Current array: \n");
	printArr(table, n); // prints current generated array
	printf("\n");

	sortByDescending(table, n); // sorts arry by descending (from higest tot lowest)

	printf("\n");
	markSimpleNumber(table, n); // prints array, all simple numbers will be colored in red
	printf("\n");

	system("pause");
	return 1;
}