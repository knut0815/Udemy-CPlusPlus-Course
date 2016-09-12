#include <iostream>
#include <map>
#include <string>

int main()
{
	/*

	A std::multimap lets you store values with duplicate keys. If possible, you want to avoid using this
	data structure and instead use a regular std::map with custom objects as keys. Note that a std::multimap
	does not overload operator [], so you must use the insert method to add new pairs to the map.

	Similar to std::map, std::multimap orders its elements by key.

	*/

	std::multimap<int, std::string> lookup;
	lookup.insert(std::make_pair(30, "Mike"));
	lookup.insert(std::make_pair(10, "Vicky"));
	lookup.insert(std::make_pair(20, "Raj"));
	lookup.insert(std::make_pair(30, "Bob"));

	for (auto it = lookup.begin(); it != lookup.end(); ++it)
	{
		std::cout << "First: " << it->first << ", Second: " << it->second << std::endl;
	}

	for (const auto &p : lookup)
	{
		std::cout << "First: " << p.first << ", Second: " << p.second << std::endl;
	}

	const int look_for = 10;
	if (lookup.find(look_for) != lookup.end())
	{
		std::cout << "Found element with value " << look_for << std::endl;
	}

	std::cout << "Equal range: " << std::endl;
	auto its = lookup.equal_range(30);
	for (auto it = its.first; it != its.second; ++it)
	{
		std::cout << "First: " << it->first << ", Second: " << it->second << std::endl;
	}

	return 0;
}