#pragma once

#include <iostream>

// example of a template class
template<class T>
class Test
{
public:

	Test(T t_object) :
		m_object(t_object)
	{
	}

	inline T get() const { return m_object; }

	friend std::ostream& operator<<(std::ostream &t_stream, const Test &t_test)
	{
		t_stream << t_test.m_object;
		return t_stream;
	}

private:

	T m_object;

};

// example of a template function
template<typename T>
void print(T t)
{
	std::cout << "Calling template print function." << std::endl;
	std::cout << t << std::endl;
}

// non-template version
void print(int t)
{
	std::cout << "Calling non-template print function." << std::endl;
	std::cout << t << std::endl;
}

// example of a template function with no arguments
template<typename T>
void show()
{
	std::cout << "Calling template show function." << std::endl;
	std::cout << T() << std::endl;
}