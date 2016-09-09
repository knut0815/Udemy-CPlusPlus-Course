#include <iostream>
#include <exception>

class MyException : public std::exception
{
public:
	const char* what() const throw() override
	{
		return "Something bad happened.";
	}
};

class Test
{
public:
	void goes_wrong()
	{
		throw MyException();
	}
};

int main()
{
	/*
	
	You can create your own exception objects that are derived from std::exception.
	The function decorator throw() tells the compiler that this function won't throw a
	exception. Sometimes, this allows the compiler to make certain optimizations to
	your code.

	Throwing an exception from a function that is marked throw() will result in a run-
	time error. 

	*/
	
	Test test;

	try
	{
		test.goes_wrong();
	}
	catch (MyException &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}