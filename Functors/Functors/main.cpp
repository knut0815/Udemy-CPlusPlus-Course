#include <iostream>
#include <string>

struct Test
{
	virtual bool operator()(const std::string &t_text) const = 0;
};

struct MatchTest : public Test
{
	bool operator()(const std::string &t_text) const override { return t_text == "Lion"; }
};

bool check(const std::string &t_test, const Test &t_predicate) 
{
	return t_predicate(t_test);
}

int main()
{
	std::string text{ "Lion" };
	MatchTest predicate;

	std::cout << std::boolalpha << check(text, predicate) << std::endl;

	return 0;
}