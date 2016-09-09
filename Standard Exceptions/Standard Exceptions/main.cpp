#include <iostream>

class CanGoWrong
{
public:
	CanGoWrong()
	{
		char* p_memory = new char[1024];
		delete [] p_memory;
	}
};

int main()
{
	/*
	
	In Visual Studio, the constructor above will never throw an exception. The point is, if we 
	tried to allocate too much memory or the memory allocation failed, the constructor would
	throw a std::bad_alloc exception, which we could subsequently catch.

	All exceptions in C++ are derived from the std::exception base class and override the virtual
	method what(), which gives us a printable string that describes the nature of the exception.
	
	*/
	
	try 
	{
		CanGoWrong wrong;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "Still running." << std::endl;

	return 0;
}