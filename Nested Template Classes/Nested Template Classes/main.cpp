#include <iostream>
#include <string>

#include "RingBuffer.h"

int main()
{
	const std::string line_break(20, '-');

	ms::RingBuffer<std::string> buffer{ 3 };
	buffer.push_back("one");
	buffer.push_back("two");
	buffer.push_back("three");
	buffer.push_back("four");

	for (size_t i = 0; i < buffer.size(); ++i)
	{
		std::cout << buffer[i] << '\n';
	}

	std::cout << line_break << '\n';

	for (auto it = buffer.begin(); it != buffer.end(); ++it)
	{
		std::cout << *it << '\n';
	}

	std::cout << line_break << '\n';

	for (const auto &e : buffer)
	{
		std::cout << e << '\n';
	}

	return 0;
}