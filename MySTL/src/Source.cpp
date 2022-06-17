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

	mystl::list<int> l1;

	LOG(l1.size());

/*
	mystl::vector<int> vec;
	std::cout << vec.max_size();
*/
	return 0;
}