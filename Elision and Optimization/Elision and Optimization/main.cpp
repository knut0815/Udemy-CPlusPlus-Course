#include <iostream>
#include <vector>

class Test
{
public:
	Test()
	{
		std::cout << "Default constructor.\n";
		m_buffer = new int[m_size] {};
	}

	Test(int t_value)
	{
		std::cout << "Constructor with one argument.\n";
		m_buffer = new int[m_size] { t_value };
	}

	Test(const Test &t_other)
	{
		std::cout << "Copy constructor.\n";
		m_buffer = new int[m_size] {};
		memcpy(m_buffer, t_other.m_buffer, sizeof(int) * m_size);
	}

	Test& operator=(const Test &t_other)
	{
		std::cout << "Assignment operator.\n";

		// handling self-assignment https://isocpp.org/wiki/faq/assignment-operators
		if (this != &t_other) 
		{
			delete[] m_buffer;
			m_buffer = new int[m_size] {};
			memcpy(m_buffer, t_other.m_buffer, sizeof(int) * m_size);
		}
		return *this;
	}

	Test(Test &&t_other)
	{
		std::cout << "Move constructor.\n";
	}

	Test& operator=(Test &&t_other)
	{
		std::cout << "Move assignment operator.\n";
	}
	
	~Test()
	{
		std::cout << "Destructor.\n";
		delete[] m_buffer;
	}

	friend std::ostream& operator<<(std::ostream &t_stream, const Test &t_test)
	{
		t_stream << "Output operator.";
		return t_stream;
	}
private:
	static const size_t m_size{ 100 };
	int *m_buffer;
};

Test get_test_object()
{
	return {};
}

void check(const Test &t_test)
{
	std::cout << "lvalue reference.\n";
}

void check(Test &&t_test)
{
	std::cout << "rvalue reference.\n";
}

int main()
{
	/*

	First, in the get_test_object function, we construct a Test object. Then, we copy that
	object into a temporary return value. Then, we destruct the local variable Test object.
	Then, we copy construct our object below from the temporary return value object.

	RVO (return value optimization) is enabled by default in Visual Studio 2015. This will
	elide ("optimize away") many of these unnecessary copies.

	In C++11, an lvalue is anything that you can take the address of. In contrast, rvalues
	are temporary. For example, our function get_test_object returns an rvalue. Literals
	are rvalues. The result of simple expressions like:
			
			Test test_sum = test_0 + test_1;

	are rvalues. We cannot take the address of rvalues.

	We can, however, bind a const reference to an rvalue. This will "extend" the 
	lifetime of the temporary rvalue.

	*/
	Test test = get_test_object();

	std::vector<Test> test_objects;
	test_objects.push_back(Test{});

	int lvalue{ 0 };
	int* ptr_to_lvalue = &lvalue;
	// error: int* ptr_to_rvalue = &5;

	Test* ptr_to_ltest = &test;
	// error: Test* ptr_to_rtest = &get_test_object();

	// basic (C++98) lvalue reference
	Test &ltest_0 = test;

	// const lvalue references can bind to rvalues
	const Test &ltest_1 = get_test_object();

	// this is what lets us use the copy constructor with rvalues
	Test copied_test{ Test{ 10 } };
	std::cout << copied_test << '\n';

	// basic (C++11) rvalue references
	Test &&rtest_0 = Test{};
	Test &&rtest_1 = get_test_object();

	check(test);
	check(Test{});

	return 0;
}