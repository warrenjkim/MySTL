#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "binary_search_tree.h"

namespace mystl
{
	template<typename T>
	class avl_tree : public binary_search_tree<T>
	{
	// base class
	public:
		using base_class = binary_search_tree<T>;

	// typedefs
	public:
		using value_type = base_class::value_type;

		using reference_type = base_class::reference_type;
		using pointer_type = base_class::pointer_type;

		using const_reference_type = base_class::const_reference_type;
		using const_pointer_type = base_class::const_pointer_type;

		using binary_node = base_class::binary_node;
		using binary_node_ptr = base_class::binary_node_ptr;

	// mutators
	public:
		template<typename... Args>
		constexpr binary_node_ptr emplace(Args&&... args);

		constexpr binary_node_ptr push(const_reference_type element);
	
	//private mutators
	private:
		template<typename... Args>
		constexpr binary_node_ptr emplace(binary_node_ptr& root, Args&&... args);

		constexpr void restructure(binary_node_ptr& root);
		constexpr void left_rotate(binary_node_ptr& x);
		constexpr void right_rotate(binary_node_ptr& x);

		constexpr size_t left_height(binary_node_ptr root);
		constexpr size_t right_height(binary_node_ptr root);
		constexpr size_t height_diff(binary_node_ptr root);
	};

	template<typename T>
	template<typename ...Args>
	constexpr typename avl_tree<T>::binary_node_ptr avl_tree<T>::emplace(Args && ...args)
	{
		auto temp = base_class::emplace(std::forward<Args>(args)...);

		restructure(m_Root);
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename avl_tree<T>::binary_node_ptr avl_tree<T>::emplace(binary_node_ptr& root, Args && ...args)
	{
		return binary_node_ptr();
	}

	template<typename T>
	constexpr typename avl_tree<T>::binary_node_ptr avl_tree<T>::push(const_reference_type element)
	{
		return binary_node_ptr();
	}

	template<typename T>
	constexpr void avl_tree<T>::restructure(binary_node_ptr& root)
	{

	}

	//
	// left rotations:
	//	- right right:
	//		  z							 y
	//		 / \					   /   \
	//		T1  y			==>		  z     x
	//	       / \					 / \   / \
	//		  T2  x					T1 T2 T3 T4
	//			 / \	
	//		    T3 T4
	//
	// left rotate:
	//	- right left:
	//		  z							 x
	//		 / \					   /   \
	//		T1  y			==>		  z	    y
	//		   / \				 	 / \   / \
	//		  x  T4	 			    T1 T2 T3 T4
	//		 / \	
	//		T2 T3
	//
	template<typename T>
	constexpr void avl_tree<T>::left_rotate(binary_node_ptr& z)
	{
		binary_node_ptr y = z->right;
		binary_node_ptr t2 = y->left;

		y->left = z;
		z->right = t2;
		y->parent = z->parent;
		z->parent = y;
	}

	//
	// right rotations:
	//	- left left:
	//		  z							 y
	//		 / \					   /   \
	//		y  T4			==>		  x     z
	//	   / \						 / \   / \
	//    x	 T3						T1 T2 T3 T4
	//	 / \	
	//  T1 T2
	//
	// left rotate:
	//	- left right:
	//		  z							 x
	//		 / \					   /   \
	//		y  T4			==>		  y	    z
	//	   / \					 	 / \   / \
	//    T1  x					    T1 T2 T3 T4
	//		 / \	
	//		T2 T3
	//
	template<typename T>
	constexpr void avl_tree<T>::right_rotate(binary_node_ptr& z)
	{
		binary_node_ptr y = z->left;
		binary_node_ptr t3 = y->right;

		y->right = z;
		z->left = t3;
		y->parent = z->parent;
		z->parent = y;
	}

	template<typename T>
	constexpr size_t avl_tree<T>::left_height(binary_node_ptr root)
	{
		return height(root->left);
	}

	template<typename T>
	constexpr size_t avl_tree<T>::right_height(binary_node_ptr root)
	{
		return height(root->right);
	}

	template<typename T>
	constexpr size_t avl_tree<T>::height_diff(binary_node_ptr root)
	{
		return left_height(root) - right_height(root);
	}

}

#endif
