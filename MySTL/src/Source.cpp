#include <iostream>
#include "data_structures/array.h"
#include "data_structures/vector.h"
#include "data_structures/list.h"
#include "data_structures/deque.h"
#include "data_structures/stack.h"
#include "data_structures/queue.h"
#include "data_structures/binary_search_tree.h"

#define LOG(x) std::cout << x << std::endl
#define LOGIL(x) std::cout << x 

int main() {

	std::cout << std::boolalpha;

	LOG("ARRAY");
	mystl::array<int, 5> arr{};
	arr.fill(21);

	LOG("array of size 5 filled with 2");
	LOG("printed using for-loop");
	for (size_t i = 0; i < arr.size(); i++)
		LOG(arr[i]);
	

	std::cout << std::endl;
	LOG("array being incremented");
	LOG("manipulated/printed using for-each loop");
	for (auto& x : arr)
		LOG(++x);

	LOG("\n\nVECTOR");
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
		LOG(x);

	LOG("\n\nLIST");
	mystl::list<int> list{};

	LOG("initialized empty list");
	LOG("list size: " << list.size());
	
	list.push_back(1);
	LOG("\npush back 1: " << list.front());
	LOG("list size: " << list.size());

	list.push_front(2);
	LOG("\npush front 2: " << list.front());
	LOG("list size: " << list.size());
	
	list.emplace_front(3);
	LOG("\nemplace front 3: " << list.front());
	LOG("list size: " << list.size());

	list.emplace_back(0);
	LOG("\nemplace back 0: " << list.back());
	LOG("list size: " << list.size());

	LOG("\nprint list using for-each loop");
	for (const auto& x : list)
		LOGIL(x << "->");

	std::cout << std::endl;

	LOG("pop front: " << list.pop_front());
	LOG("pop back: " << list.pop_back());

	for (const auto& x : list)
		LOGIL(x << "->");
	
	std::cout << std::endl;

	LOG("list at index 1: " << list[1]);

	LOG("\n\nDEQUE");
	mystl::deque<int> deque{};

	LOG("initialized empty deque");
	LOG("deque size: " << deque.size());

	deque.push_back(3);
	LOG("\npush back 3: " << deque.front());
	LOG("deque size: " << deque.size());

	deque.push_front(2);
	LOG("\npush front 2: " << deque.front());
	LOG("deque size: " << deque.size());

	deque.push_front(1);
	LOG("\npush front 1: " << deque.front());
	LOG("deque size: " << deque.size());

	deque.push_front(0);
	LOG("\npush front 0: " << deque.front());
	LOG("deque size: " << deque.size());

	LOG("\nprint deque using for-each loop");
	for (const auto& x : deque)
		LOGIL(x << " ");

	std::cout << std::endl;

	LOG("pop front: " << deque.pop_front());
	LOG("pop back: " << deque.pop_back());

	for (const auto& x : deque)
		LOGIL(x << " ");

	std::cout << std::endl;

	LOG("deque at index 1: " << deque[1]);

	LOG("\n\nSTACK");
	mystl::stack<int> stack{};

	LOG("initialized empty stack");
	LOG("stack size: " << stack.size());
	LOG("stack empty: " << stack.empty());

	stack.push(1);
	LOG("\npush 1 to stack");
	
	stack.push(2);
	LOG("push 2 to stack");

	stack.push(3);
	LOG("push 3 to stack");

	stack.emplace(4);
	LOG("emplace 4 to stack");

	LOG("\nstack top: " << stack.top());

	LOG("stack pop top: " << stack.pop());

	LOG("\nprinting stack");
	while (!stack.empty())
	{
		LOGIL(stack.top() << " ");
		stack.pop();
	}

	std::cout << std::endl;

	LOG("\n\nQUEUE");
	mystl::queue<int> queue{};

	LOG("initialized empty queue");
	LOG("queue size: " << queue.size());
	LOG("queue empty: " << queue.empty());

	queue.push(1);
	LOG("\npush 1 to queue");

	queue.push(2);
	LOG("push 2 to queue");

	queue.push(3);
	LOG("push 3 to queue");

	queue.emplace(4);
	LOG("emplace 4 to queue");

	LOG("\nqueue front: " << queue.front());
	LOG("\nqueue back: " << queue.back());

	LOG("queue pop front: " << queue.pop());

	LOG("\nprinting queue");
	while (!queue.empty())
	{
		LOGIL(queue.front() << " ");
		queue.pop();
	}

	std::cout << std::endl;

	LOG("\n\nBINARY SEARCH TREE (BST)");
	mystl::binary_search_tree<int> bst{};

	LOG("initialized empty BST");
	LOG("BST size: " << bst.size());
	LOG("BST empty: " << bst.empty());

	LOG("\npush 50 to BST");
	bst.push(50);
	
	LOG("\nemplace 20 to BST");
	bst.emplace(20);

	LOG("\npush 70 to BST");
	bst.push(70);

	LOG("\npush 25 to BST");
	bst.push(25);

	LOG("\nemplace 80 to BST");
	bst.emplace(80);

	LOG("\nemplace 65 to BST");
	bst.emplace(65);

	LOG("\nprint BST preorder");
	for (const auto& x : bst.preorder())
		LOGIL(x << " ");

	LOG("\n\nprint BST inorder");
	for (const auto& x : bst.inorder())
		LOGIL(x << " ");

	LOG("\n\nprint BST postorder");
	for (const auto& x : bst.postorder())
		LOGIL(x << " ");

	LOG("\n\nprint BST breadth-first");
	for (auto x : bst.breadth_first())
	{
		LOGIL("{ ");

		for (auto y : x)
			LOGIL(y << " ");

		LOGIL("} ");
	}

	LOG("\n\nprint BST level-order");
	for (auto x : bst.level_order())
	{
		LOGIL("{ ");

		for (auto y : x)
			LOGIL(y << " ");

		LOGIL("} ");
	}

	return 0;
}