#include <iostream>
#include "data_structures/array.h"


int main() {

	mystl::array<int, 5> arr{};
	arr.fill(21);

	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i] += i;
		std::cout << arr[i] << " ";
	}
	

	std::cout << std::endl;
	for (auto& x : arr)
	{
		std::cout << ++x << " ";
	}
	std::cin.get();

	//int x = arr[8];

	return 0;
}