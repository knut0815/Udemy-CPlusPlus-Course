#include <iostream>
#include <map>
#include <string>

class Person
{
public:

	Person() 
	{
		std::cout << "Default constructor called." << std::endl;
	}

	Person(const std::string &t_name, int t_age) :
		m_name(t_name),
		m_age(t_age)
	{
		std::cout << "Constructor with two parameters called." << std::endl;
	}

	Person(const Person &t_other) :
		m_name(t_other.m_name),
		m_age(t_other.m_age)
	{
		std::cout << "Copy constructor called." << std::endl;
	}

	bool operator<(const Person &t_other) const
	{
		// use std::string's less-than operator
		if (m_name == t_other.m_name)
		{
			return m_age < t_other.m_age;
		}
		return m_name < t_other.m_name;
	}

	friend std::ostream& operator<<(std::ostream &t_stream, const Person &t_person)
	{
		t_stream << t_person.m_name << ": " << t_person.m_age;
		return t_stream;
	}
		
private:

	std::string m_name = "name";
	int m_age = 0;

};

int main()
{
	/*

	By default, a std::map will always sort elements by key. Here, we use C++11's list initialization
	syntax to construct a std::map from integers to Person objects.

	When iterating over a std::map, keys are treating as const. 

	In order to use custom objects as keys, we need to overload operator < so that the map can properly
	sort its keys.

	*/

	Person p;
	std::cout << p << std::endl;

	std::map<int, Person> num_to_people = {
		{ 0, { "Mike", 40 } },
		{ 1, { "Vicky", 30 } },
		{ 2, { "Raj", 20 } }
	};

	std::map<Person, int> people_to_num = {
		{ { "Mike", 40 }, 0 },
		{ { "Vicky", 30 }, 1 },
		{ { "Raj", 20 }, 2 }
	};

	// If we did not check for string equality in the Person class' operator <, this line of 
	// code would simply update the value associated with this person in the std::map, even though
	// this "Mike" appears to be different (in age) from the other "Mike". However, since we are
	// checking for equality, this will actually add a new key-value pair to the std::map.
	people_to_num[{"Mike", 80}] = 30;

	for (const auto &p : people_to_num)
	{
		std::cout << "Key: " << p.first << ", Value: " << p.second << std::endl;
	}

	return 0;
}