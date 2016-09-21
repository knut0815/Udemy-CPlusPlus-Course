#include <iostream>
#include <string>

class Test
{
public:
	// By declaring a constructor that takes one argument, we would normally lose our default constructor.
	Test() = default;
	Test(uint32_t t_id) : m_id(t_id) {}
	Test(const Test &t_other) = default;
	Test& operator=(const Test &t_other) = default;

	friend std::ostream& operator<<(std::ostream &t_stream, const Test &t_test)
	{
		t_stream << t_test.m_name << " : " << t_test.m_id;
		return t_stream;
	}

private:
	// in-class initializers
	uint32_t m_id{ 0 };
	std::string m_name{ "Default" };
};

class Noncopyable
{
public:
	Noncopyable() = default;
	Noncopyable(uint32_t t_id) : m_id(t_id) {}

	// delete the copy constructor and copy assignment operator
	Noncopyable(const Noncopyable &t_other) = delete;
	Noncopyable& operator=(const Noncopyable &t_other) = delete;
private:
	uint32_t m_id{ 0 };
};

int main()
{
	Test test_0;
	std::cout << test_0 << '\n';

	Test test_1{ 10 };
	std::cout << test_1 << '\n';

	Test test_2 = test_0;
	std::cout << test_2 << '\n';

	Noncopyable nc_0;
	Noncopyable nc_1{ 10 };
	// error: Noncopyable nc_2{ nc_0 };

	return 0;
}