#ifndef NODE_H
#define NODE_H

// simple node struct
namespace mystl
{
	template<typename T>
	struct node
	{
	public:
		using value_type = T;
		using const_reference_type = const T&;

	public:
		value_type	data = value_type();
		node*		next = nullptr;
		node*		prev = nullptr;

	public:
		constexpr node() : data(value_type()), next(nullptr), prev(nullptr) { }
		constexpr node(const_reference_type& data) : data(data), next(nullptr), prev(nullptr) { }
		~node() = default;
	};
}

#endif