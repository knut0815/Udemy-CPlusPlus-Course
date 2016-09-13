#include <iostream>
#include <stack>
#include <queue>
#include <string>

class Test
{
public:

	Test() = default;
	
	Test(int t_id, const std::string &t_name) :
		m_id(t_id),
		m_name(t_name)
	{
	}

	Test(const Test &t_other) :
		m_id(t_other.m_id),
		m_name(t_other.m_name)
	{
		std::cout << "Copy constructor called." << std::endl;
	}

	const Test& operator=(const Test &t_other)
	{
		m_id = t_other.m_id;
		m_name = t_other.m_name;
		std::cout << "Assignment operator called." << std::endl;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream &t_stream, const Test &t_test)
	{
		t_stream << "name: " << t_test.m_name << ", id: " << t_test.m_id;
		return t_stream;
	}

private:

	// C++11 in-class initializers
	int m_id = 0;
	std::string m_name = "";

};

int main()
{
	Test test_0{ 16, "Mike" };
	Test test_1; // uninitialized
	Test test_2; // uninitialized

	test_2 = test_1 = test_0;

	// On the other hand, this will not call operator =. Rather, this calls the copy constructor.
	Test test_3 = test_0;

	std::cout << "Test 0 | " << test_0 << std::endl;
	std::cout << "Test 1 | " << test_1 << std::endl;
	std::cout << "Test 2 | " << test_2 << std::endl;
	std::cout << "Test 3 | " << test_3 << std::endl;

	return 0;
}