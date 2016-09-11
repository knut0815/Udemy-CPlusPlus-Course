#include <iostream>
#include <string>
#include <fstream>

#pragma pack(push, 1)
struct Person
{
	char m_name[50];	// 50 bytes
	int m_age;			// 4 bytes
	double m_height;	// 8 bytes
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream& t_stream, const Person &t_person)
{
	t_stream << "Person | name: " << t_person.m_name << ", age: " << t_person.m_age << ", height: " << t_person.m_height << std::endl;
	return t_stream;
}

int main()
{
	/*

	If we attempt to write a struct that contains heap-allocated memory to a binary file, only the 
	pointer to that data will be written. Because std::string stores its data internally as a char*,
	we will not get correct results by trying to write a Person struct to a binary file. Instead,  
	the member variable m_name needs to be a stack-allocated char array.

	By default, C++ will pad structs. When we print the size of the Person struct, we get 64, which
	is obviously larger than the expected 50 + 4 + 8 = 62 bytes that we'd expect. If we want to write
	a Person struct to a file, we need to turn off this padding.

	The pre-processor directive above the Person struct tells the compiler to align Person on single
	byte boundaries, thus avoiding any unwanted padding. We want to 'pop' this directive off the 
	stack when we are done using it.

	When we open a file with the intention of writing binary data, it is important to include the
	second parameter std::ios::binary. This tells the std::ofstream object to treat newline
	characters as regular, raw data.

	In order to write a struct to a binary file, we need to convert it to a char*. To do this, we 
	can grab a pointer to our struct by using the address-of operator. Then, we can use a 
	reinterpret_cast to cast the raw bytes to a char*.

	*/

	std::cout << "The size of a char is: " << sizeof(char) << std::endl;
	std::cout << "The size of an int is: " << sizeof(int) << std::endl;
	std::cout << "The size of a double is: " << sizeof(double) << std::endl;
	std::cout << "The size of a Person is: " << sizeof(Person) << std::endl;

	Person someone{ "Frodo", 220, 0.8 };

	const std::string file_name = "test.bin";
	
	// write binary file
	std::ofstream output_file;
	output_file.open(file_name, std::ios::binary);

	if (output_file.is_open())
	{
		output_file.write(reinterpret_cast<char*>(&someone), sizeof(Person));
		output_file.close();
	}
	else
	{
		std::cout << "Could not create file " + file_name << std::endl;
	}

	// read binary file
	Person someone_else{};

	std::ifstream input_file;
	input_file.open(file_name, std::ios::binary);

	if (input_file.is_open())
	{
		input_file.read(reinterpret_cast<char*>(&someone_else), sizeof(Person));
		input_file.close();
	}
	else
	{
		std::cout << "Could not open file " + file_name << std::endl;
	}

	std::cout << someone_else << std::endl;

	return 0;
}