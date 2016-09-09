#include <iostream>
#include <string>
#include <fstream>

int main()
{
	/*

	We can supply a delimiter to std::getline, which will cause the file to read up to the specified 
	delimiter. Then, we can call operator >> to get the integer that follows each colon. The problem is,
	operator >> will not consume the newline character that appears implicitly at the end of each line
	of text. Therefore, we need to call the std::ifstream's get method to consume that character.

	In C++11, we can call operator >> std::ws instead of get to read trailing whitespace.

	For more advanced parsing tasks, it is worth looking at C++11's regular expression classes.

	*/

	const std::string input_file_name = "population.txt";

	std::ifstream input_file;
	input_file.open(input_file_name);

	if (input_file.is_open())
	{
		while (input_file)
		{
			std::string line;
			std::getline(input_file, line, ':');

			int population;
			input_file >> population;
			input_file >> std::ws;

			// check for error state
			if (!input_file)
			{
				break;
			}

			std::cout << "'" << line << " -- " << population << "'" << std::endl;
		}
		input_file.close();
	}
	else
	{
		std::cout << "Cannot open file: " << input_file_name << std::endl;
	}

	return 0;
}