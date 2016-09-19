#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

void print()
{
	std::cout << "Calling a function with no parameters." << std::endl;
}

void test(int t_value)
{
	std::cout << "Calling a function with one parameter." << std::endl;
}

bool match(const std::string t_test)
{
	return t_test.size() == 3;
}

template<typename T>
size_t count_matches(const std::vector<T> &t_items, const std::function<bool(T)> &t_match_func)
{
	size_t count = 0;
	for (const auto &e : t_items)
	{
		if (t_match_func(e))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	/*
	
	In C++, the name of a function is actually a pointer to that function. That is why we do 
	not use to use the address-of operator below when we are declaring our function pointers.
	C++11 exposes the std::function class for managing function pointers.

	*/
	
	// C++98
	void(*func_ptr_0)() = print;
	func_ptr_0();

	// C++11
	std::function<void()> func_ptr_1 = print;
	func_ptr_1();

	// function pointers to functions with parameters
	void(*func_ptr_2)(int) = test;
	std::function<void(int)> func_ptr_3 = test;

	std::vector<std::string> items = { "one", "two", "three", "four", "five" };

	// we can use function pointers in many of the generic algorithms that C++ provides
	auto count_library = std::count_if(items.begin(), items.end(), match);
	std::cout << "Number of matching elements (library): " << count_library << std::endl;

	// our own version of count
	auto count_custom = count_matches<std::string>(items, match);
	std::cout << "Number of matching elements (custom): " << count_custom << std::endl;

	return 0;
}