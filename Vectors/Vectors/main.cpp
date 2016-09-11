#include <iostream>
#include <vector>
#include <string>

int main()
{
	/*

	A std::vector's capacity is the size of its internal array that contains "reserved" memory. In
	contrast, its size is the actual number of elements that have been added to the std::vector.
	When adding an element to a std::vector that is already at capacity, the std::vector will resize
	itself so that its internal capacity far exceeds the current size of the std::vector.

	*/

	std::vector<std::string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	std::cout << "Using iterators: " << std::endl;
	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "Using range-based for-loop: " << std::endl;
	for (const auto &s : strings)
	{
		std::cout << s << std::endl;
	}

	// pre-size our vector
	std::vector<double> numbers(20);
	const size_t num_to_add = 10000;
	size_t capacity = numbers.capacity();

	std::cout << "Vector with " << numbers.size() << " elements." << std::endl;
	std::cout << "Vector with " << capacity << " capacity." << std::endl;
	
	for (size_t i = 0; i < num_to_add; ++i)
	{	
		if (numbers.capacity() != capacity)
		{
			capacity = numbers.capacity();
			std::cout << "New capacity: " << capacity << std::endl;
		}
		numbers.push_back(i);
	}

	// note that clearing (or resizing) the vector does not change the capacity of the std::vector's internal array
	numbers.clear();
	std::cout << "Size: " << numbers.size() << std::endl;
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	return 0;
}