#include <iostream>

class Parent
{
public:
	virtual void say_something() const { std::cout << "Hello from Parent\n"; }
	virtual ~Parent() = default;
};

class Brother : public Parent
{
public:
	void say_something() const override { std::cout << "Hello from Brother\n"; }
};

class Sister : public Parent
{
public:
	void say_something() const override { std::cout << "Hello from Sister\n"; }
};

int main()
{
	Parent p;
	Brother b;
	Sister s;

	// cast a float to an int
	float f_value{ 3.14f };
	int i_value{ static_cast<int>(f_value) };

	// cast an lvalue to an rvalue reference
	Parent &&ref_p = static_cast<Parent&&>(p);
	ref_p.say_something();

	/*
	
	Static casts are compile-time only - they don't do run-time checking. This would
	let us do something like:
			
			Parent *ptr_p{ &b };
			Brother *ptr_b{ static_cast<Brother*>(ptr_p) };

	This makes sense in this case, since ptr_p is actually pointing to an object of
	type Brother via polymorphism. If instead it were pointing to an object of type
	Parent, we would likely run into issues when we attempted to call member functions
	of the Brother class via ptr_b.

	A dynamic cast implements the exact behavior we require. It uses RTTI (run-time 
	type information) to determine whether the specified cast is appropriate. If the
	cast fails, it will return nullptr.

	*/
	Parent *ptr_p{ &b };
	Brother *ptr_b{ dynamic_cast<Brother*>(ptr_p) };
	if (ptr_b == nullptr)
	{
		std::cout << "Invalid cast\n";
	}
	else
	{
		std::cout << "Valid cast - pointer address: " << ptr_b << '\n';
	}

	return 0;
}