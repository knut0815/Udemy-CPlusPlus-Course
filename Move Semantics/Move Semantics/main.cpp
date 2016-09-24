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
		m_buffer = t_other.m_buffer;

		/*
		
		Without this line, the destruction of the temporary rvalue named t_other
		would de-allocate its buffer, which 'this' now points to. Obviously,
		this is not what we want, so we set t_other's pointer to nullptr.
		
		*/
		t_other.m_buffer = nullptr;
	}

	Test& operator=(Test &&t_other)
	{
		std::cout << "Move assignment operator.\n";
		if (this != &t_other)
		{
			delete[] m_buffer;
			m_buffer = t_other.m_buffer;
			t_other.m_buffer = nullptr;
		}
		return *this;
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
	int *m_buffer{ nullptr };
};

Test get_test_object()
{
	return {};
}

int main()
{
	// move constructor
	std::vector<Test> test_objects;
	test_objects.push_back(Test{});

	// move assignment
	Test test;
	test = get_test_object();

	return 0;
}