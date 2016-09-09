#include <iostream>
#include <exception>

void goes_wrong()
{
	bool error_0 = true;
	bool error_1 = false;

	if (error_0)
	{
		throw std::bad_alloc();
	}
	if (error_1)
	{
		throw std::exception();
	}
}

int main()
{
	/*
	
	The standard exceptions form an inheritance hierarchy. Therefore, the order in which
	we catch our exceptions matters. In the example below, we attempt to catch std::exception
	before std::bad_alloc, which is a subclass of std::exception. The function throwing
	std::bad_alloc will automatically be filtered into the first catch statement due to 
	polymorphism.

	The solution is to catch subclass exceptions first. In other words, we should swap the
	order of the two catch statements below.

	*/
	
	try
	{
		goes_wrong();
	}
	catch (std::exception &e)
	{
		std::cout << "Catching std::exception: " << e.what() << std::endl;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << "Catching std::bad_alloc: " << e.what() << std::endl;
	}
	
	return 0;
}