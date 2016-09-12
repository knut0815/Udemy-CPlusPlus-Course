#include <iostream>
#include <stack>
#include <queue>
#include <string>

class Test
{
public:

	Test(const std::string &t_name) :
		m_name(t_name)
	{
	}

	~Test()
	{
		std::cout << "Test object destroyed." << std::endl;
	}

	friend std::ostream& operator<<(std::ostream &t_stream, const Test &t_test)
	{
		t_stream << t_test.m_name;
		return t_stream;
	}

private:
	
	std::string m_name;

};

int main()
{
	/*

	A std::stack is a LIFO structure (last-in, first-out). You can add elements to the top of the stack
	or remove elements from the top of the stack. 

	*/

	std::stack<Test> test_stack;
	test_stack.push({ "Mike" });
	test_stack.push({ "Vicky" });
	test_stack.push({ "Raj" });

	Test top_of_stack = test_stack.top();
	std::cout << "Top of the stack: " << top_of_stack << std::endl;

	return 0;
}