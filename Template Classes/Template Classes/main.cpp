#include <string>

#include "Test.h"

int main()
{
	Test<std::string> test{ "Hello" };
	
	auto param = test.get();

	std::cout << test << std::endl;
	std::cout << param << std::endl;

	// explicit type in template parameters
	print<std::string>("Printing from a template function.");
	
	// automatic type inference doesn't work because the non-template print function hides the template version
	print(10);

	// if we want to use the template version, we need to be explicit in this case
	print<>(10);

	// because show has no arguments, type inference will never work - we always need to supply diamond brackets
	show<double>();

	return 0;
}