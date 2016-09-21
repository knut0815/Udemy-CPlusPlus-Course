#include <iostream>
#include <string>
#include <vector>

struct ExampleStruct
{
	std::string m_name;
	uint32_t m_id;
};

template <class T>
class ExampleClass
{
public:
	ExampleClass(const std::initializer_list<T> &t_list) :
		m_elements(t_list)
	{
	}

	friend std::ostream& operator<<(std::ostream &t_stream, const ExampleClass &t_class)
	{
		for (const auto &e : t_class.m_elements)
		{
			t_stream << e << ' ';
		}
		return t_stream;
	}
private:
	std::vector<T> m_elements;
};

template <typename T>
void test(const std::initializer_list<T> &t_list)
{
	for (const auto &e : t_list)
	{
		std::cout << e << ' ';
	}
	std::cout << '\n';
}

int main()
{
	std::string text{ "Hello" };
	
	double default_init{}; // will be 0.0
	int value{ 5 };
	int values[]{ 0, 1, 2, 3, 4, 5 };

	int* p_null{}; // will be nullptr
	int* p_value{ &value };
	int* p_values = new int[6] { 0, 1, 2, 3, 4, 5 };
	
	std::vector<std::string> lines_of_text{ "One", "Two", "Three" };

	for (const auto &e : lines_of_text)
	{
		std::cout << e << '\n';
	}

	ExampleStruct my_struct{ "Mike", 25 };

	ExampleClass<std::string> my_class{ "Hi", "my", "name", "is", "Mike." };
	
	std::cout << my_class << '\n';

	test({ 0, 1, 2, 3, 4, 5 });

	return 0;
}