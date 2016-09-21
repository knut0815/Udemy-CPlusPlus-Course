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

private:
	static const size_t m_size{ 100 };
	int *m_buffer;
};

Test get_test_object()
{
	return {};
}

int main()
{
	/*
	
	First, in the get_test_object function, we construct a Test object. Then, we copy that
	object into a temporary return value. Then, we destruct the local variable Test object.
	Then, we copy construct our object below from the temporary return value object. 

	RVO (return value optimization) is enabled by default in Visual Studio 2015. This will
	elide ("optimize away") many of these unnecessary copies.

	*/
	Test test = get_test_object();

	std::vector<Test> test_objects;
	test_objects.push_back(Test{});

	return 0;
}