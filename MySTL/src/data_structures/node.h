#ifndef NODE_H
#define NODE_H

// simple node struct
namespace mystl
{
	template<typename T>
	struct node
	{
		using value_type = T;

		T		data = T();
		node* next = nullptr;
		node* prev = nullptr;

		node() : data(T()), next(nullptr), prev(nullptr) { }

		node(const T& data) : data(data), next(nullptr), prev(nullptr) { }
		~node() = default;
	};
}

#endif