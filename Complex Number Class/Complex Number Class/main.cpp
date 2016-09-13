#include <iostream>

#include "Complex.h"

int main()
{
	using namespace tutorial;

	// Regular constructor
	Complex complex_0{ 9.0, 10.0 };

	// Copy constructor
	Complex complex_1{ complex_0 };

	// Assignment operator
	Complex complex_2;
	complex_2 = complex_0;

	std::cout << complex_0 << std::endl;
	std::cout << complex_1 << std::endl;
	std::cout << complex_2 << std::endl;

	return 0;
}