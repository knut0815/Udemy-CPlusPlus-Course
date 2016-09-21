#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

class Test
{
public:
	inline void run()
	{
		int value_2{ 2 };
		int value_3{ 3 };

		// to use member variables, we need to capture 'this'
		auto capture_this = [&, this]() 
		{ 
			// using 'this' in the capture section will always capture member variables by reference
			value_0 += value_2;
			value_1 += value_3;
		};
		capture_this();

		std::cout << "Member variables after function call:\n";
		std::cout << value_0 << " " << value_1 << '\n';
	}
private:
	int value_0{ 0 };
	int value_1{ 1 };
};

void call_function(const std::function<bool(std::string)> &t_func)
{
	std::string text{"test"};
	t_func(text);
}

template<typename T>
void call_lambda(const std::function<void(T)> &t_func, const T &t_param)
{
	t_func(t_param);
}

int main()
{
	std::string text{ "Hello" };
	auto lambda = [](const std::string &t_text) { std::cout << t_text << '\n'; };
	
	// call the lambda expression directly
	lambda(text);

	// call the lambda expression indirectly
	call_lambda<std::string>(lambda, text);

	// trailing return type
	auto divide = [](double a, double b) -> double
	{ 
		if (b == 0.0)
		{
			return 0; // int
		}
		return a / b; // double
	};
	
	std::cout << divide(10.0, 5.0) << '\n';
	std::cout << divide(10.0, 0.0) << '\n';

	// lambda captures
	int value_0{ 0 };
	int value_1{ 1 };
	int value_2{ 2 };

	auto capture_by_value = [=]() { std::cout << value_0 << value_1 << value_2 << '\n'; };
	capture_by_value();

	auto capture_by_reference = [&]() 
	{
		value_0 = 1;
		value_1 = 2;
		value_2 = 3;
	};
	capture_by_reference();
	std::cout << value_0 << value_1 << value_2 << '\n';

	// capturing 'this' with lambdas
	Test test;
	test.run();

	std::vector<std::string> lines_of_text{ "zero", "one", "two", "three" };
	size_t size = 3;

	// many of the standard algorithms take an optional predicate that is of type std::function
	// the predicate can be a lamdba, a functor class, or a function pointer
	auto count_lambda = [=](const std::string &t_text) { return t_text.size() == size; };
	auto num_matches = std::count_if(lines_of_text.begin(), lines_of_text.end(), count_lambda);
	std::cout << num_matches << '\n';

	call_function(count_lambda);

	std::function<int(int, int)> add = [](int t_0, int t_1) { return t_0 + t_1; };
	std::cout << add(7, 3) << '\n';

	// mutable lambdas let you modify any variables that are captured by value
	int some_value{ 5 };
	auto some_lambda = [some_value]() mutable 
	{ 
		some_value += 5; 
		std::cout << "Value inside mutable lambda: " << some_value << '\n';
	};
	some_lambda();
	
	std::cout << "Value after calling mutable lambda: " << some_value << '\n';

	return 0;
}