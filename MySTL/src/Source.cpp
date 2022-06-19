#include <iostream>
#include "data_structures/array.h"
#include "data_structures/vector.h"
#include "data_structures/list.h"

#define LOG(x) std::cout << x << std::endl

int main() {

	LOG("ARRAY");
	mystl::array<int, 5> arr{};
	arr.fill(21);

	LOG("array of size 5 filled with 2");
	LOG("printed using for-loop");
	for (size_t i = 0; i < arr.size(); i++)
	{
		LOG(arr[i]);
	}
	

	std::cout << std::endl;
	LOG("array being incremented");
	LOG("manipulated/printed using for-each loop");
	for (auto& x : arr)
	{
		LOG(++x);
	}

	LOG("\nVECTOR");
	mystl::vector<int> vec{};
	
	LOG("initialized empty vector");
	LOG("vector size: " << vec.size());
	LOG("vector capacity: " << vec.capacity());
	
	vec.push_back(1);
	LOG("\npush back " << vec[0]);
	LOG("vector size: " << vec.size());
	LOG("vector capacity: " << vec.capacity());

	vec.emplace_back(3);
	LOG("\nemplace back " << vec[1]);
	LOG("vector size: " << vec.size());
	LOG("vector capacity: " << vec.capacity());
	
	vec.emplace(vec.begin() + 1, 2);
	LOG("\nemplace at pos 2 (index 1) " << vec[1]);
	LOG("vector size: " << vec.size());
	LOG("vector capacity: " << vec.capacity());

	vec.shrink_to_fit();
	LOG("\nshrink to fit");
	LOG("vector size: " << vec.size());
	LOG("vector capacity: " << vec.capacity());


	LOG("\nvector printed using for-each loop");
	for (const auto& x : vec)
	{
		LOG(x);
	}

	LOG("\nLIST");
	mystl::list<int> l1;

	LOG("initialized empty list");
	LOG("list size: " << l1.size());
	
	l1.push_back(1);
	LOG("\npush back 1: " << l1.front());
	LOG("list size: " << l1.size());

	l1.push_front(2);
	LOG("\npush front 2: " << l1.front());
	LOG("list size: " << l1.size());
	
	l1.emplace_front(3);
	LOG("\nemplace front 3: " << l1.front());
	LOG("list size: " << l1.size());

	l1.emplace_back(0);
	LOG("\nemplace back 0: " << l1.back());
	LOG("list size: " << l1.size());

	auto lvec = l1.print();

	for (const auto& x : *lvec)
	{
		std::cout << x << "->";
	}
	std::cout << "nullptr" << std::endl;
	delete lvec;

	l1.reverse();
	LOG("\nreverse list");
	
	lvec = l1.print();

	for (const auto& x : *lvec)
	{
		std::cout << x << "->";
	}
	std::cout << "nullptr" << std::endl;

	
/*
	mystl::vector<int> vec;
	std::cout << vec.max_size();
*/
	return 0;
}