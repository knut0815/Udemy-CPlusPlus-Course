#include <iostream>

class Parent 
{
public:
	Parent() = default;
	Parent(const Parent& t_other) 
	{ 
		m_pvariable = t_other.m_pvariable;
		std::cout << "Calling Parent copy constructor."; 
	}
	virtual ~Parent() = default;
	virtual void print() { std::cout << "Parent" << std::endl; }
private:
	int m_pvariable = 0;
};

class Child : public Parent
{
public:
	void print() override { std::cout << "Child" << std::endl; }
private:
	int m_cvariable = 1;
};

int main()
{
	Child child;

	Parent &parent_polymorphic = child;
	parent_polymorphic.print();

	// we lose the Child member variable m_cvariable here
	Parent parent_sliced = Child();
	parent_sliced.print();

	return 0;
}