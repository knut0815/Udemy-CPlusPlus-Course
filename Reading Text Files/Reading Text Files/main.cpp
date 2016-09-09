#include <iostream>
#include <string>
#include <fstream>

int main()
{
	/*
	
	Reading from files in C++ is very similar to writing to files. We simply declare a std::ifstream
	object and call open. Alternatively, we can use the more generic std::fstream class with ios::in
	as the second parameter of the constructor.

	Using the input operator >> on a std::ifstream object will let you read the text file word by word.
	Calling std::getline lets you parse entire lines of the file at once. Note that the std::ifstream
	class overloads the bool operator, so the condition in our while loop is equivalent to the more
	verbose:

			while(!input_file.eof()) { ... }

	Generally, you should not mix calls to operator >> with calls to std::getline. This is because
	token-based parsing does not consume newline characters, so you may end up with spurious empty
	lines if you subsequently call std::getline after token-based extraction got you to the end of a
	line already.
	
	*/
	
	const std::string input_file_name = "text.txt";
	
	std::ifstream input_file;
	input_file.open(input_file_name);
	
	if (input_file.is_open())
	{
		std::string line;
		
		while (input_file) 
		{
			std::getline(input_file, line);
			std::cout << line << std::endl;
		}
		input_file.close();
	}
	else
	{
		std::cout << "Cannot open file: " << input_file_name << std::endl;
	}

	return 0;
}