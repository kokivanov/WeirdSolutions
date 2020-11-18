#include <iostream>
#include <cmath>

int main() {

	float x = 0, y = 0;	// init x

	std::cin >> x;
	std::cout << "\n";
	std::cin >> y;
	std::cout << "\n";

	if (x > 1) 
		std::cout << "true";
	else if ((((x <= 1) && (x >= 0)) && ((y <= 1) && (y >= 0))) || (((x >= -1) && (x <= 0)) && ((y >= -1) && (y <= 0)))) {
		if (sqrt(x * x + y * y) <= 1)
			std::cout << "true";
	} 
	else
		std::cout << "false";
}








