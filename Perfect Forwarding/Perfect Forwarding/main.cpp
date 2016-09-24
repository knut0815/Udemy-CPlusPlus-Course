#include <iostream>

class Test
{

};

template<class T>
void call(T &&arg)
{
	/*
	
	This template function can be called with either an lvalue or rvalue.
	We want to forward this argument to another function (in this case 'check') in
	such a way that its lvalue-ness or rvalue-ness is preserved. We do this with
	perfect forwarding.

	*/
	check(std::forward<T>(arg));
}

void check(const Test &t_test)
{
	std::cout << "lvalue\n";
}

void check(Test &&t_test)
{
	std::cout << "rvalue\n";
}

int main()
{
	/*
	
	When using auto with rvalue / lvalue references, we sometimes observe "reference
	collapsing." In the example below, an rvalue reference is bound to an lvalue, and
	as a result, the entire declaration collapses to an lvalue reference.
	
	*/
	Test test;
	auto &&rvalue = test;
	
	// without perfect forwarding, this will always call the lvalue version of 'check'
	call(Test{});

	return 0;
}