#ifndef BINARY_NODE_H
#define BINARY_NODE_H

namespace mystl
{
	template<typename T>
	struct binary_node
	{
	// typedefs
	public:
		using	value_type				= T;
		using	const_reference_type	= const T&;

	public:
				value_type		data	= value_type();
				binary_node*	left	= nullptr;
				binary_node*	right	= nullptr;

	public:
		constexpr				binary_node() : data(value_type()), left(nullptr), right(nullptr) { }
		constexpr				binary_node(const_reference_type data) : data(data), left(nullptr), right(nullptr) { }
								~binary_node() = default;
	};
}

#endif