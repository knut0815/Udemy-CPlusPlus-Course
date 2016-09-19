#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Animal
{
public:
	virtual void speak() const = 0;
	virtual void run() const = 0;
};

class Dog : public Animal
{
public:
	void speak() const override { std::cout << "Woof!" << std::endl; }
};

class Labrador : public Dog
{
public:
	Labrador() = default;
	Labrador(const std::string &t_name) : m_name(t_name) {}
	void run() const override { std::cout << m_name << " is starting to run..." << std::endl; };
private:
	std::string m_name;
};

void test(const Animal &t_animal)
{
	t_animal.run();
}

int main()
{
	// error (cannot instantiate abstract class):
	// Animal animal;

	// error (cannot instantiate abstract class):
	// Dog dog;

	// This finally works since Labrador implements all pure virtual functions. Note that the
	// implementation of speak is provided by its direct parent, Dog.
	Labrador lab{ "Rufus" };

	test(lab);

	// We can't create an array of Animal objects. However, we can create a container that 
	// holds pointers to Animal objects.
	std::vector<std::shared_ptr<Animal>> animals;

	animals.push_back(std::make_shared<Labrador>("Max"));
	animals.push_back(std::make_shared<Labrador>("Sadie"));
	animals.push_back(std::make_shared<Labrador>("Zoey"));

	for (const auto &e : animals)
	{
		e->run();
	}

	return 0;
}