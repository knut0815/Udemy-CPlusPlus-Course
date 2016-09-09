#include <iostream>
#include <string>
#include <fstream>

int main()
{
	/*
	
	Streams in C++ are objects that we can write to. Here, we use the std::ofstream class
	to create a basic text file. You could also use the more generic std::fstream class, 
	in which case you would need to specify the read-write mode in the constructor:

			std::fstream output_file(output_file_name, ios::out);

	*/

	const std::string output_file_name = "text.txt";

	std::ofstream output_file;
	output_file.open(output_file_name);

	if (output_file.is_open())
	{
		output_file << "Hello there." << std::endl;
		output_file << "Let's write a few lines of text to the file " << output_file_name << ":" << std::endl;

		const size_t num_lines = 10;
		for (size_t line_no = 0; line_no < num_lines; ++line_no)
		{
			output_file << line_no << " A wonderful line of text." << std::endl;
		}
		output_file << "End of file." << std::endl;
		output_file.close();
	}
	else
	{
		std::cout << "Could not create file: " << std::endl;
	}
	return 0;
}