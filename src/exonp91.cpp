#include "headers/Header.h"

void exonp91();

unsigned short hackermode = 0, hbuff = 1;

void hk() { // heh HACKERMAN! https://www.youtube.com/watch?v=V4MF2s6MLxY https://www.youtube.com/watch?v=_DWBMxFjebc
	hackermode ^= hbuff;
	hbuff ^= hackermode;
	hackermode ^= hbuff;
}

int findIndex(int* arr, int elem, int size) {	// Find index of element by simplest way
	for (int i = 0; i < size; i++)
	{
		if (elem == arr[i])
			return i;
	}

	return -1;
}

void swap_(int* a, int* b) { // swapper ¯\_(ツ)_/¯
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int findBinary(int * arr, int elem, int a, int b/*size - 1*/) { // find element bi binary search algorythm
	if (b - a >= 1) {
		if (b - a == 1) {
			if (arr[a] == elem) return a;
			if (arr[b] == elem) return b;
			return -1;
		}

		int mid = ceil(((b - a) / 2) + a);

		if (arr[mid] == elem) return mid;

		if (elem < arr[mid]) return findBinary(arr, elem, mid, b);
		if (elem > arr[mid]) return findBinary(arr, elem, a, mid);
	}

	return -1;
}

void printSmile() { // oh shit
	// ======= It's a fucking hell
	


	int row = 0, col = 0;
	printf("Enten mount of rows\n");
	scanf_s("%d", &row);
	printf("Enten mount of columns\n");
	scanf_s("%d", &col);

	int** smile = new int* [row];
	for (int i = 0; i < row; i++)
		smile[i] = new int[col];

	int last_row = 0;
	int last_col = 0;

	int fl = 0, sl = 1;

	// upper
	for (int i = last_row; i < last_row + ceil(1 * (row / 10)); i++) {
		last_col = 0;
		for (int j = last_col; j < last_col + ceil(10 * (col / 10)); j++)
			smile[i][j] = sl;
	}
	last_row = last_row + ceil(1 * (row / 10));


	// space
	for (int i = last_row; i < last_row + ceil(2 * (row / 10)); i++) {
		last_col = 0;

		for (int j = last_col; j < last_col + ceil(1 * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(1 * (col / 10));

		for (int j = last_col; j < last_col + ceil(8 * (col / 10)); j++)
			smile[i][j] = fl;
		last_col = last_col + ceil(8 * (col / 10));

		for (int j = last_col; j < last_col + ceil(1 * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(1 * (col / 10));
	}
	last_row = last_row + ceil(2 * (row / 10));


	// eyes
	for (int i = last_row; i < last_row + ceil(2 * (row / 10)); i++) {
		last_col = 0;
		int tmp = 0;

		tmp = 1;
		for (int j = last_col; j < last_col + ceil(tmp * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(tmp * (col / 10));

		tmp = 1;
		for (int j = last_col; j < last_col + ceil(tmp * (col / 10)); j++)
			smile[i][j] = fl;
		last_col = last_col + ceil(tmp * (col / 10));

		tmp = 2;
		for (int j = last_col; j < last_col + ceil(tmp * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(tmp * (col / 10));

		tmp = 2;
		for (int j = last_col; j < last_col + ceil(tmp * (col / 10)); j++)
			smile[i][j] = fl;
		last_col = last_col + ceil(tmp * (col / 10));

		tmp = 2;
		for (int j = last_col; j < last_col + ceil(tmp * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(tmp * (col / 10));

		tmp = 1;
		for (int j = last_col; j < last_col + ceil(tmp * (col / 10)); j++)
			smile[i][j] = fl;
		last_col = last_col + ceil(tmp * (col / 10));

		tmp = 1;
		for (int j = last_col; j < last_col + ceil(tmp * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(tmp * (col / 10));
	}
	last_row = last_row + ceil(2 * (row / 10));

	//space
	for (int i = last_row; i < last_row + ceil(1 * (row / 10)); i++) {
		last_col = 0;

		for (int j = last_col; j < last_col + ceil(1 * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(1 * (col / 10));

		for (int j = last_col; j < last_col + ceil(8 * (col / 10)); j++)
			smile[i][j] = fl;
		last_col = last_col + ceil(8 * (col / 10));

		for (int j = last_col; j < last_col + ceil(1 * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(8 * (col / 10));
	}
	last_row = last_row + ceil(1 * (row / 10));

	// mouth
	for (int i = last_row; i < last_row + ceil(2 * (row / 10)); i++) {
		last_col = 0;

		for (int j = last_col; j < last_col + ceil(1 * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(1 * (col / 10));

		for (int j = last_col; j < last_col + ceil(2 * (col / 10)); j++)
			smile[i][j] = fl;
		last_col = last_col + ceil(2 * (col / 10));

		for (int j = last_col; j < last_col + ceil(4 * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(4 * (col / 10));

		for (int j = last_col; j < last_col + ceil(2 * (col / 10)); j++)
			smile[i][j] = fl;
		last_col = last_col + ceil(2 * (col / 10));

		for (int j = last_col; j < last_col + ceil(1 * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(1 * (col / 10));
	}
	last_row = last_row + ceil(2 * (row / 10));

	// space
	for (int i = last_row; i < last_row + ceil(1 * (row / 10)); i++) {
		last_col = 0;

		for (int j = last_col; j < last_col + ceil(1 * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(1 * (col / 10));

		for (int j = last_col; j < last_col + ceil(8 * (col / 10)); j++)
			smile[i][j] = fl;
		last_col = last_col + ceil(8 * (col / 10));

		for (int j = last_col; j < last_col + ceil(1 * (col / 10)); j++)
			smile[i][j] = sl;
		last_col = last_col + ceil(1 * (col / 10));
	}
	last_row = last_row + ceil(1 * (row / 10));

	// lower
	for (int i = last_row; i < last_row + ceil(1 * (row / 10)); i++) {
		last_col = 0;
		for (int j = last_col; j < last_col + ceil(10 * (col / 10)); j++)
			smile[i][j] = sl;
	}

	last_row = last_row + ceil(1 * (row / 10));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (smile[i][j] > -5600) printf("%i", smile[i][j]);
		}
		printf("\n");
	}

	
	std::cin.get();
	system("pause");
	exonp91();
}

void array1d() { // Functions with 1d array
	srand(time(nullptr));

	//Init
	int size = rand() % 100 + 100;
	int* arr = new int[size];
	
	//Fill
	for (int i = 0; i < size; i++)
		arr[i] = (rand() % 3000) - 1000;

	//Print
	for (int i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	auto start = std::chrono::steady_clock::now(); // get time of start program
	
	int serNeg;
	printf("Enten element to seek lower than\n");
	scanf_s("%d", &serNeg);
	int counter = 0;
	for (int i = 0; i < size; i++)
		if ((arr[i] < serNeg) && (arr[i] < 0))
			counter++;
	printf("Count of elements lower than %i is %i\n", serNeg, counter);

	auto end = std::chrono::steady_clock::now(); // get time of end program 

	auto elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);

	start = std::chrono::steady_clock::now(); // get time of start program
	
	//Count normale
	int norm = 0;
	for (int i = 0; i < size; i++)
		norm += arr[i] * arr[i];
	printf("norm is %d\n", norm);

	end = std::chrono::steady_clock::now(); // get time of end program 

	elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);

	start = std::chrono::steady_clock::now(); // get time of start program

	//Find min (Simple)
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}

	//Find max (Simple)
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	printf("Minimum is %i, maximum is %i", min, max);

	end = std::chrono::steady_clock::now(); // get time of end program 

	elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);

	// Find index of element by simple algorythm
	int elem;
	printf("Enten element to seek for\n");
	scanf_s("%d", &elem);
	start = std::chrono::steady_clock::now(); // get time of start program
	int index = findIndex(arr, elem, size);
	if (index == -1) {
		printf("Can't find mstch element\n");
	}
	else {
		printf("Index is %i\n", index);
	}
	printf("\n");
	end = std::chrono::steady_clock::now(); // get time of end program 

	elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);

	start = std::chrono::steady_clock::now(); // get time of start program
	
	//Bubble sort array
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (arr[j] < arr[j + 1])
				swap_(&arr[j], &arr[j + 1]);

	end = std::chrono::steady_clock::now(); // get time of end program 

	elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("\nSorting elapsed time (ms): %.3f \n", elasped_time / 1e6);

	//Print array
	for (int i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	
	
	//Binary search
	int tfel;
	printf("Enten element to seek for\n");
	scanf_s("%d", &tfel);

	start = std::chrono::steady_clock::now(); // get time of start program
	printf("Position: %i \n", findBinary(arr, tfel, 0, size - 1));

	end = std::chrono::steady_clock::now(); // get time of end program 

	elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);
	//Deinit
	delete[size] arr;

	std::cin.get();
	system("pause");
	exonp91();
}

void array2d() { // Functions with 2d array
	int row = 0, col = 0;
	printf("Enten mount of rows\n");
	scanf_s("%d", &row);
	printf("Enten mount of columns\n");
	scanf_s("%d", &col);

	// init
	int** matr = new int* [row];
	for (int i = 0; i < row; i++)
		matr[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			matr[i][j] = (rand() % 10000) - 5000;

	auto start = std::chrono::steady_clock::now(); // get time of start program
	// Pair for inex of minimum element 
	std::pair<int, int> minin = std::make_pair(0, 0);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (matr[i][j] < matr[minin.first][minin.second])
				minin = std::make_pair(i, j);
	
	

	// Pair for inex of maximum element 
	std::pair<int, int> maxin = std::make_pair(0, 0);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (matr[i][j] > matr[maxin.first][maxin.second])
				maxin = std::make_pair(i, j);

	auto end = std::chrono::steady_clock::now(); // get time of end program 

	auto elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

	

	// Print 〜(￣▽￣〜)
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%i\t", matr[i][j]);
		printf("\n");
	}

	printf("Min index is %i %i, max is %i %i", minin.second, minin.first, maxin.first, maxin.second);
	printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);

	// Deinit
	for (int i = 0; i < row; i++)
		delete[col] matr[i];
	delete[row] matr;

	std::cin.get();
	system("pause");
	exonp91();
}

void exonp91() // main function
{	
	system("CLS");

	if (hackermode == 1)
		setColor(10);
	else setColor(7);

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char inp = 'n';
	printf("Практичні завдання\n[1] Операції з одномірним масивом \n[2] Операції з двомірним масивом \n[3] Роздрукувати смайлик\n[h/H] ???????\n[q/Q] Quit\n");
	if (scanf_s("%c", &inp, 1) != 1) {
		printf("Error");
		std::cin.get();
		exonp91;
	}

	switch (tolower(inp))
	{
	case '1':
		array1d();

	case '2':
		array2d();

	case '3':
		printSmile();

	case 'q':
		return;

	case 'h':
		hk();
		std::cin.get();
		exonp91();

	default:
		printf("Error\n");
		std::cin.get();
		system("pause");
		exonp91();
	}

	std::cin.get();
	exonp91();
}