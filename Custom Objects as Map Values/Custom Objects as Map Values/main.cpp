#include <iostream>
#include <map>
#include <string>

class Person
{
public:

	Person() 
	{
	}

	Person(const std::string &t_name, int t_age) :
		m_name(t_name),
		m_age(t_age)
	{
	}

	Person(const Person &t_other) :
		m_name(t_other.m_name),
		m_age(t_other.m_age)
	{
		std::cout << "Copy constructor called." << std::endl;
	}

	friend std::ostream& operator<<(std::ostream &t_stream, const Person &t_person)
	{
		t_stream << t_person.m_name << ": " << t_person.m_age;
		return t_stream;
	}
		
private:

	std::string m_name = "empty";
	int m_age = 0;

};

int main()
{
	/*

	While the elements of a std::vector are stored in one, contiguous block of memory, the elements
	
	By default, a std::map will always sort elements by key.

	*/

	Person p;
	std::cout << p << std::endl;

	std::map<int, Person> people = { 
		{0, {"Mike", 40}}, 
		{1, {"Vicky", 30}}, 
		{2, {"Raj", 20}} 
	};

	return 0;
}