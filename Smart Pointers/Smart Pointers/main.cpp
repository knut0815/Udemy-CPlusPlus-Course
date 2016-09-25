#include <iostream>
#include <memory>
#include <string>

struct MyStruct
{
	std::string m_name;
	uint32_t m_id;
	float m_balance;
	
	MyStruct(const std::string &t_name, uint32_t t_id, float t_balance) :
		m_name{ t_name },
		m_id{ t_id },
		m_balance{ t_balance }
	{
	}

	~MyStruct() { std::cout << "destructor\n"; }
};

int main()
{
	{
		auto basic_ptr = std::make_unique<MyStruct>("Bill", 0, 0.0f);
	}
	
	std::cout << "the unique pointer above will automatically be destroyed...\n";

	auto unique_ptr = std::make_unique<MyStruct>("Mike", 1, 0.0f);
	auto shared_ptr = std::make_shared<MyStruct>("John", 2, 0.0f);

	std::cout << unique_ptr->m_name << '\n';
	std::cout << shared_ptr->m_name << '\n';

	{
		auto another_shared_ptr = shared_ptr;
		std::cout << "reference count: " << another_shared_ptr.use_count() << '\n';
	}

	std::cout << "reference count: " << shared_ptr.use_count() << '\n';

	return 0;
}