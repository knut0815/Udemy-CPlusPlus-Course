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

	// Addition operators
	Complex complex_3 = complex_0 + complex_1 + complex_2;
	Complex complex_4 = complex_3 + 5.0;
	Complex complex_5 = 10.0 + complex_4;
	
	// Equality operators
	if (complex_0 == complex_1)
	{
		std::cout << "They are equal!" << std::endl;
	}
	else
	{
		std::cout << "They are not equal." << std::endl;
	}

	if (complex_0 != complex_3)
	{
		std::cout << "They are not equal." << std::endl;
	}
	else
	{
		std::cout << "They are equal!" << std::endl;
	}

	std::cout << complex_0 << std::endl;
	std::cout << complex_1 << std::endl;
	std::cout << complex_2 << std::endl;
	std::cout << complex_3 << std::endl;
	std::cout << complex_4 << std::endl;
	std::cout << complex_5 << std::endl;

	return 0;
}