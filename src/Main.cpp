#include <windows.h>
#include <stdio.h>
#include <iostream>

int main() {
	AllocConsole();
	SetConsoleTitleA("WeirdSolutions");
	
	std::cout << "Hello world!";

	getchar();
}