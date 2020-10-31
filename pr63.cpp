#include "Header.h"

#define LOG(x) std::cout << x;  

#define e 2.71828

#define fun1(x) x*x - 1
#define fun3(x) pow(x, 3) - x + 1
#define fun2(x) x * pow(e, -1 * pow(x, 2))

#define cond1(x) i <= -2
#define cond2(x) (i > -2) && (i <= 2)

#define GetRes(x) cond1(x) ? fun1(x) : (cond2(x) ?  fun2(x) : fun3(x))

float func1(float x) {
	return x * x - 1;
}

float func2(float x) {
	return x * pow(e, -1 * pow(x, 2));
}

float func3(float x) {
	return pow(x, 3) - x + 1;
}


void pr63() {

	AllocConsole();
	SetConsoleTitleA("WeirdSolutions");
	/*
	for (float i = -3; i <= 3; i += 0.1) {
		if (i <= -2) {
			printf("%6.3f", func1(i));
		}
		if ((i > -2) && (i <= 2)) {
			printf_s("%6.3f", func2(i));
		}
		if ((i < 2)) {
			printf_s("%6.3f", func2(i));
		}
	}
	*/

	//LOG('n'); // std::cout << 'n'


	/*printf("x : \n");
	for (float i = -3; i <= 3; i += 0.1) {
		printf("%6.2f", i);
	}

	printf("\n y : \n");
	for (float i = -3; i <= 3; i += 0.1) {
		printf("%6.2f", GetRes(i));
	}*/

	for (float x = -2; x <= 2; x += 0.1) {
		printf("\n x = %3.2f \n y: ", x);
		for (float y = -4; y <= 4; y += 0.2) {
			printf("%6.2f", y);
		}
		printf("\n z: ");
		for (float y = -4; y <= 4; y += 0.2) {
			printf("%6.2f", x * y * (x - y));
		}
	}

	for (float x = -2; x <= 2; x += 1) {
		printf("\n x = %3.2f \n y: ", x);
		for (float y = -4; y <= 4; y += 1) {
			printf("%6.2f", y);
		}
		printf("\n z: ");
		for (float y = -4; y <= 4; y += 1) {
			printf("%6.2f", x * y * (x - y));
		}
	}

	getchar();

}
