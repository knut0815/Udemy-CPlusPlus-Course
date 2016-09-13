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

	Test(const Test &&t_other) noexcept :
		m_name(std::move(t_other.m_name))
	{
		std::cout << "Move constructor called." << std::endl;
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

	In constrast, a std::queue is a FIFO structure (first-in, first-out).

	*/

	std::stack<Test> test_stack;
	test_stack.push({ "Mike" });
	test_stack.push({ "Vicky" });
	test_stack.push({ "Raj" });

	while (test_stack.size() > 0)
	{
		Test &top_of_stack = test_stack.top();
		std::cout << "Printing and popping an element off the top of the stack: " << top_of_stack << std::endl;
		test_stack.pop();
	}

	std::queue<Test> test_queue;
	test_queue.push({ "Mike" });
	test_queue.push({ "Vicky" });
	test_queue.push({ "Raj" });

	std::cout << "Back of the queue: " << test_queue.back() << std::endl;

	while (test_queue.size() > 0)
	{
		Test &front_of_queue = test_queue.front();
		std::cout << "Printing and popping an element off the front of the queue: " << front_of_queue << std::endl;
		test_queue.pop();
	}

	return 0;
}