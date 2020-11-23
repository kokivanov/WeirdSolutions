#include "headers/Header.h"

// ============ All about using arrays in structs you can see there: 
// ============ Part 1: https://youtu.be/-xOo_MEw7w4
// ============ Part 1: https://youtu.be/wNzojpcFMK0

struct arr // just a tool to work with array
{
	int size;
	int* arr;
};

struct arr initArray(int a) { // array initialization 
	arr mass;
	mass.size = a;
	mass.arr = new int[a];
	return mass;
}

// =========================================================================================================

void fill_arr(arr* mass) {   // filling array with random numbers 
	for (int i = 0; i < mass->size; i++)
		mass->arr[i] = (rand() % 100) - 50;
}

void print_arr(arr* mass) {  // prints array, lol what else (ʘ ͜ʖ ʘ)
	for (int i = 0; i < mass->size; i++)
		std::cout << mass->arr[i] << "\t";
	std::cout << "\n";
}

void swap_a(arr* mass, int a, int b) { // XOR swap function
	if (a != b) {
		mass->arr[a] ^= mass->arr[b];
		mass->arr[b] ^= mass->arr[a];
		mass->arr[a] ^= mass->arr[b];
	}
}

// Algorythm is based on separate and conquer algorythm where we take sny number that will be our pillar (number that will be compared)
// Then we will do the same with every next part of arra till array size is lower than 3

int part(arr* mass, int left, int right) {  //  separate array and get separation index
	int wall = left - 1;
	int pivo = mass->arr[right];
	
	for (int i = left; i < right; i++) {
		if (mass->arr[i] < pivo) {
			swap_a(mass, i, wall+1);
			wall++;
		}
	}

	swap_a(mass, wall+1, right);

	return wall;

}

void sort(arr* mass, int left, int right, int iter) { // main function of sorting
	if (left == right) return;

	if (right-left <= 1) { // checks is amount of elements lower that or equal to 2
			if (mass->arr[left] > mass->arr[right])
				swap_a(mass, 0, 1);
			printf("still working on it...\n"); // just a message to be sure that algorythm works
	}
	else {
		int prt = part(mass, left, right); // get partition index
		sort(mass, 0, prt, iter+1); // do the same with the left part of array in recursion
		sort(mass, prt+2, right, iter+1); // do the same with the right part of array in recursion
	}

	// so array will be divided many times till avery part has size of 2 or 1 elements

	if ((mass->arr[left] > mass->arr[left+1])&&(left+1 <= mass->size-1)) // sometimes first two elements 
		swap_a(mass, left, left+1);

	
}

bool checkarray(arr* mass) { // checks is srray sorted correctly 
	for (int i = 0; i < mass->size - 2; i++) {
		if (mass->arr[i] > mass->arr[i + 1])
			return false;
	}

	return true;
}

int q_sort() {

	printf("Input array size ");
	int sz;
	if (scanf_s("%d", &sz) != 1) {
		std::cin.get();
		q_sort(); // start again in case of wrong input
	}

	srand(time(NULL));

	auto start = std::chrono::steady_clock::now(); // get time of start program

	arr mass = initArray(sz); // init array
	fill_arr(&mass);
	print_arr(&mass);

	sort(&mass, 0, mass.size-1, 0);
	print_arr(&mass);

	auto end = std::chrono::steady_clock::now(); // get time of end program 

	double elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("Elapsed time (ms): %.3f \n", elasped_time / 1e6);
	
	setColor(12);
	printf("\nIs array sorted correctly (1 - true, 0 - false): %i\n", checkarray(&mass)); // checks is srray sorted correctly 
	setColor(7);

	std::cin.get();

	return 1;
}