#include <iostream>
#include <string>

struct my_error_object
{
	std::string m_message;
	int m_error_code;
};

void might_go_wrong()
{
	bool error_0 = false;
	bool error_1 = false;
	bool error_2 = true;

	if (error_0)
	{
		throw "Something went wrong.";
	}
	if (error_1)
	{
		throw std::string{ "Something else went wrong." };
	}
	if (error_2)
	{
		throw my_error_object{ "Something went wrong again", 404 };
	}
}

void uses_might_go_wrong()
{
	might_go_wrong();
}

int main()
{
	/*

	In general, we want to use exceptions for things that our program can't recover from. Imagine that
	the boolean 'error' was set to true due to some severe error in our program.

	You can throw pretty much anything - even objects. Note that the type of the object thrown must match
	one of the types in a subsequent catch statement if the exception is to be handled properly. In
	general, it's best to catch any thrown objects by reference.

	Also note that a throw statement will terminate the currently executing function.

	Exceptions get thrown all the way up the call stack until they are handled or the program exits.

	*/

	try
	{
		uses_might_go_wrong();
	}
	catch (int e)
	{
		std::cout << "Error code (int): " << e << std::endl;
	}
	catch (const char* e)
	{
		std::cout << "Error code (const char*): " << e << std::endl;
	}
	catch (std::string &e)
	{
		std::cout << "Error code (string): " << e << std::endl;
	}
	catch (my_error_object &e)
	{
		std::cout << "Error code (my_error_object): " << e.m_message << std::endl;
	}

	std::cout << "We successfully handled all exceptions." << std::endl;

	return 0;
}