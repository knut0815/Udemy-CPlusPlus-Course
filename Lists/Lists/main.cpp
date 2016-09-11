#include <iostream>
#include <list>
#include <string>

int main()
{
	/*

	While the elements of a std::vector are stored in one, contiguous block of memory, the elements 
	of a std::list are stored in nodes which are connected to each other via pointers. This is known
	as a doubly-linked list.

	Inserting or deleting elements from any part of a std::list is just as efficient as inserting
	elements at the end. Note that you cannot use operator [] to index into a std::list. Therefore,
	we must use iterators or range-based for-loops.

	*/

	std::list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	// insertion
	std::list<int>::iterator insert_it = numbers.begin();
	insert_it++;
	numbers.insert(insert_it, 100);

	// deletion
	std::list<int>::iterator erase_it = numbers.begin();
	erase_it++;

	// Note that at this point, the iterator erase_it would be invalid, but the erase method returns
	// a new iterator that points to one past the deleted element.
	erase_it = numbers.erase(erase_it);

	for (auto it = numbers.cbegin(); it != numbers.cend(); ++it)
	{
		std::cout << *it << std::endl;
	}

	for (auto it = numbers.begin(); it != numbers.end();)
	{
		if (*it == 1)
		{
			// Remember that erasing an element will invalidate the original iterator, so we need to set it equal
			// to the new iterator returned from erase. However, this will effectively increment our iterator 
			// twice! Once due to the erase operation and once due to the normal execution of the outer for-loop.
			it = numbers.erase(it);
		}
		else
		{
			// To account for this, we only increment the iterator if we didn't delete an element.
			it++;
		}
	}
	return 0;
}