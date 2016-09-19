#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
	/*

	decltype extracts the type of a variable, which we can use to initialize new 
	variables of the same type.

	*/

	std::string value;
	
	std::cout << typeid(value).name() << std::endl;

	decltype(value) another_value{ "Hello" };

	std::cout << typeid(another_value).name() << std::endl;
	std::cout << another_value << std::endl;

	return 0;
}