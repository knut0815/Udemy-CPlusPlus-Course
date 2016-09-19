#include <iostream>
#include <string>

// trailing return types
template<typename T>
auto test(T t_value) -> decltype(t_value)
{
	return t_value;
}

float get()
{
	return 0.0f;
}

auto test_get() -> decltype(get())
{
	return get();
}

int main()
{
	auto value = 5;
	auto text = "Hello";
	auto names = { "Mike", "Jordan", "Praul" };

	std::cout << test_get() << std::endl;

	return 0;
}