#pragma once

#include <iostream>

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