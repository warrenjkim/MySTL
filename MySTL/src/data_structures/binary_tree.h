#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "binary_node.h"

namespace mystl
{
	template<typename T>
	class binary_tree
	{
	// typedefs
	public:
		using		value_type = T;

		using		reference_type = T&;
		using		pointer_type = T*;

		using		const_reference_type = const T&;
		using		const_pointer_type = const T*;

		using		binary_node<T> = binary_node;
		using		binary_node_ptr = binary_node*;



	// constructor/destructor
	public:
		constexpr binary_tree();
		~binary_tree();

	// element access
	public:
		constexpr binary_node_ptr find(const_reference_type element);

	// mutator functions
	public:
		constexpr binary_node_ptr push_left(const_reference_type element);
		constexpr binary_node_ptr push_right(const_reference_type element);
		
	// mutator functions
	public:
		constexpr binary_node pop_leaf();
	// size functions
	public:
		constexpr size_t height() const;
		constexpr size_t depth() const;
		constexpr size_t size() const;

	// private helper functions
	private:
		constexpr binary_node_ptr find(const_reference_type element, binary_node_ptr node);
		[[noreturn]] void destroy_tree();
	private:
		binary_node_ptr m_Root = nullptr;
		size_t			m_Size = 0;
	};


	template<typename T>
	constexpr binary_tree<T>::binary_tree() : m_Root(nullptr), m_Size(0) { }

	template<typename T>
	inline binary_tree<T>::~binary_tree()
	{
		destroy_tree();
	}

	template<typename T>
	constexpr typename binary_tree<T>::binary_node_ptr 
		binary_tree<T>::find(const_reference_type element)
	{
		return find(element, root);
	}



	template<typename T>
	constexpr typename binary_tree<T>::binary_node_ptr 
		binary_tree<T>::find(const_reference_type element, binary_node_ptr node)
	{
		if (!node)
			return nullptr;
		else if (node->data == element)
			return node;
		else
			return find(element, node->left);
	}

}

#endif