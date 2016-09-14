#include <string>

#include "Test.h"

int main()
{
	Test<std::string> test{ "Hello" };
	
	auto param = test.get();

	std::cout << test << std::endl;
	std::cout << param << std::endl;

	return 0;
}