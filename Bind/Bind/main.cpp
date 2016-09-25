#include <iostream>
#include <functional>

int add(int a, int b, int c)
{
	std::cout << a << ", " << b << ", " << c << '\n';
	return a + b + c;
}

void run(std::function<int(int, int)> func)
{
	func(10, 20);
}

class Test
{
public:
	int multiply(int a, int b, int c)
	{
		std::cout << a << ", " << b << ", " << c << '\n';
		return a * b * c;
	}
};

int main()
{
	auto result = add(1, 2, 3);
	std::cout << result << '\n';

	auto normal_add = std::bind(add, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
	auto reverse_add = std::bind(add, std::placeholders::_3, std::placeholders::_2, std::placeholders::_1);
	std::cout << normal_add(4, 5, 6) << '\n';
	std::cout << reverse_add(4, 5, 6) << '\n';

	// we can use the placeholders namespace
	using namespace std::placeholders;

	auto custom_add = std::bind(add, _2, 100, _1);
	std::cout << custom_add(4, 5) << '\n';

	// passing the bound function to another function
	run(custom_add);

	// binding a member function requires a class instance
	Test test;
	auto cube = std::bind(&Test::multiply, test, _1, _1, _1);
	std::cout << cube(4) << '\n';

	return 0;
}