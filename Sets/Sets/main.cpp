#include <iostream>
#include <set>
#include <string>

int main()
{
	/*

	A std::set only stores unique elements. If you try to insert an element that already exists in the 
	std::set, nothing will happen.

	*/

	std::set<int> numbers = { 0, 1, 2, 3 };
	
	// does nothing
	numbers.insert(0);
	
	for (const auto e : numbers)
	{
		std::cout << e << std::endl;
	}

	const int look_for = 2;

	std::cout << "Search using find method:" << std::endl;
	if (numbers.find(look_for) != numbers.end())
	{
		std::cout << "Found element " << look_for << std::endl;
	}

	std::cout << "Search using count method:" << std::endl;
	if (numbers.count(look_for))
	{
		std::cout << "Found one or more occurrences of " << look_for << " in the set." << std::endl;
	}

	return 0;
}