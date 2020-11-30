#include "headers/Header.h"

const double e = 2.718; // math const e

// ========================= Utility element ================================
namespace elas {
	struct elem {
		int x;
		int y;
		double value;
	};

	struct elem mkelem_xy(int j, int i) {
		elem tmp;
		tmp.x = j;
		tmp.y = i;
 		return tmp;
	}

}

// ================================ fills array
void fillArray(double* arr, int a) {
	for (int i = 0; i < a; i++) {
		arr[i] = (rand() % 10000);
		arr[i] = arr[i] / 100;
	}
}

// ================================ prints array
void printArray(double* arr, int a) {
	for (int i = 0; i < a; i++) {
		printf("%6.3f \t", arr[i]);
	}
	printf("\n");
}

// ============================ fills array with matching elements of another array calculeted by given function
void fillWith(double* arr, double* arr2, int a, double (*func)(double, int)) {
	for (int i = 0; i < a; i++) {
		arr[i] = func(arr2[i], a);
	}
}

// ============================= Function to calculate elements of array
double func(double arr, int a) {
	return log10(arr)/atan(e * a / 10);
}

// ============================= Checks does element belongs array 
bool isIn(int a, elas::elem* COD, elas::elem tmp) {
	for (int i = 0; i < a; i++) {
		if ((COD[i].x == tmp.x) && (COD[i].y == tmp.y)) return true;
	}

	return false;
}

// ================================ Main function
void exonp95() {

	srand(time(nullptr)); // random

	setColor(2);

	int n;
	printf("Enter 1d array size: ");
	if (scanf_s("%d", &n) != 1) {
		printf("\nerror\n");
		std::cin.get();
	}
	printf("\n");

	auto start = std::chrono::steady_clock::now(); // get time of start program
	// allocate arrays using malloc()
	double* arr = (double*)malloc((size_t)(n*sizeof(double)));
	double* arr2 = (double*)malloc((size_t)(n*sizeof(double)));

	fillArray(arr, n); // fills array with random numbers
	fillWith(arr2, arr, n, &func); // fills array using function
	printf("a array: \n");
	printArray(arr, n); // lol rly?
	printf("f(a[n]) array: \n");
	printArray(arr2, n); // same

	// free allocated arrays
	free(arr);
	free(arr2);

	auto end = std::chrono::steady_clock::now(); // get time of end program 

	double elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);


	int nx, ny, nc;
	printf("\nElnter amount of rows: ");
	if (scanf_s("%d", &ny) != 1) {
		printf("\nerror\n");
		std::cin.get();
	} printf("\n");
	printf("Elnter amount of columns: ");
	if (scanf_s("%d", &nx) != 1) {
		printf("\nerror\n");
		std::cin.get();
	} printf("\n");
	printf("Elnter amount of list of biggest numbers that is needed to be printed: ");
	if (scanf_s("%d", &nc) != 1) {
		printf("\nerror\n");
		std::cin.get();
	} printf("\n");
	printf("\n");

	if (nc < 1) {
		printf("Warning: only array will be printed!\n");
		std::cin.get();
		std::cin.get();
	}

	start = std::chrono::steady_clock::now(); // get time of start program


	elas::elem* coords = new elas::elem[nc]; // array with biggest elements

	// allocating array using new
	double** arr_2d = new double* [ny];
	for (int i = 0; i < ny; i++) {
		arr_2d[i] = new double[nx];
	}

	for (int i = 0; i < ny; i++) {
		for (int j = 0; j < nx; j++) {
			arr_2d[i][j] = (rand() % 10000);
			arr_2d[i][j] = arr_2d[i][j] / 100;
		}
	}

	if ((nx * ny >= nc) && ((nx != 0) && (ny != 0))) {
		printf("Source array: \n");
		for (int i = 0; i < ny; i++) {
			printArray(arr_2d[i], nx);
			printf("\n");
		}
		if (nc > 0) {
			for (int c = 0; (c < nc); c++) {
				int ttpr = (ceil(sqrt(c - (c / 2))));
				coords[c].value = arr_2d[ny - ttpr-1][nx - ttpr - 1];
				coords[c].x = ny - c;
				coords[c].y = nx - c;

				for (int i = 0; i < ny; i++) {
					for (int j = 0; j < nx; j++) {
						if ((coords[c].value < arr_2d[i][j]) && (!isIn(c, coords, elas::mkelem_xy(j, i)))) {
							coords[c].value = arr_2d[i][j];
							coords[c].x = j;
							coords[c].y = i;
						}
					}
				}

				printf("%0.3f >> a: %i, b: %i\n", coords[c].value, coords[c].x, coords[c].y);
			}
		}
	} else printf("Amount of biggest elements can't be higher than total amount of elements");

	// free allocated arrays
	delete[] coords;

	for (int i = 0; i < ny; i++) {
		delete[] arr_2d[i];
	}
	delete[] arr_2d;

	end = std::chrono::steady_clock::now(); // get time of end program 

	elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);

	// prevent application from  closing
	system("pause");
}