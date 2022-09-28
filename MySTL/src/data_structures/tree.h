#ifndef TREE_H
#define TREE_H

#include "vector.h"
#include "tree_node.h"

namespace mystl
{
	template<typename T>
	class tree
	{
	// typedefs
	public:
		using		value_type				= T;
											
		using		reference_type			= value_type&;
		using		pointer_type			= value_type*;
											
		using		tree_node				= tree_node<T>;
		using		tree_node_ptr			= tree_node*;
											
		using		const_reference_type	= const value_type&;
		using		const_pointer_type		= const value_type*;

	// constructor/destructor
		constexpr tree();
		constexpr tree(const_reference_type root);
		~tree();

	// size functions
	public:
		constexpr size_t size() const;
		constexpr size_t height() const;
		constexpr size_t depth() const;
		constexpr bool empty() const;

	// element access
	public:
		constexpr tree_node_ptr root();
		constexpr tree_node_ptr root() const;

	// traversals
	public:
		constexpr [[noreturn]] void preorder() const;
		constexpr [[noreturn]] void inorder() const;
		constexpr [[noreturn]] void postorder() const;
		constexpr [[noreturn]] void breadth_first() const;
		constexpr [[noreturn]] void level_order() const;
	
	// mutator functions
	public:
		constexpr tree_node_ptr push(const size_t level, const_reference_type element);


	private:
		size_t max_height(tree_node_ptr root);
	// variables
	private:
		tree_node_ptr m_Root;
		size_t m_Size;
	};

	template<typename T>
	constexpr tree<T>::tree()
	{
		m_Root = new tree_node();
	}

	template<typename T>
	constexpr tree<T>::tree(const_reference_type root)
	{
		m_Root = new tree_node(root);
	}

	template<typename T>
	tree<T>::~tree()
	{
		delete m_Root;
	}

	template<typename T>
	constexpr size_t tree<T>::size() const
	{
		return m_Size;
	}

	template<typename T>
	constexpr size_t tree<T>::height() const
	{

	}

	template<typename T>
	constexpr size_t tree<T>::depth() const
	{
		return m_Height + 1;
	}

	template<typename T>
	constexpr bool tree<T>::empty() const
	{
		return !m_Root;
	}

	template<typename T>
	constexpr typename tree<T>::tree_node_ptr tree<T>::root()
	{
		return m_Root;
	}

	template<typename T>
	constexpr typename tree<T>::tree_node_ptr tree<T>::root() const
	{
		return m_Root;
	}

	template<typename T>
	constexpr typename tree<T>::tree_node_ptr tree<T>::push(const size_t level, const_reference_type element)
	{
		tree_node_ptr temp = new tree_node(element);

		m_Root->children[level].push_back(element);
	}

	template<typename T>
	inline size_t tree<T>::max_height(tree_node_ptr root)
	{
		if (!root)
		{
			return 0;
		}
		else
		{
			size_t left_height = max_height(root->left);
			size_t right_height = max_height(root->right);
		}

		return left_height > right_height ? left_height : right_height;
	}


}

#endif