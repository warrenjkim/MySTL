#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binary_node.h"
#include "vector.h"
#include "queue.h"

namespace mystl
{
	template<typename T>
	class binary_search_tree
	{
	// typedefs
	public:
		using value_type = T;

		using reference_type = T&;
		using pointer_type = T*;
		
		using const_reference_type = const T&;
		using const_pointer_type = const T*;

		using binary_node = binary_node<T>;
		using binary_node_ptr = binary_node*;

	// constructor/destructor
	public:
		constexpr binary_search_tree();
		~binary_search_tree();

	// element access
	public:
		constexpr binary_node_ptr search(const_reference_type element) const;
		constexpr bool contains(const_reference_type element) const;

		constexpr binary_node_ptr root();
		constexpr binary_node_ptr root() const;

	// size functions
	public:
		constexpr size_t height(binary_node_ptr root) const;
		constexpr size_t depth(binary_node_ptr root) const;
		constexpr size_t size() const;
		constexpr bool empty() const;

	// mutator functions
	public:
		template<typename... Args>
		constexpr binary_node_ptr emplace(Args&&... args);
		
		constexpr binary_node_ptr push(const_reference_type element);
		
	// mutator functions
	public:
		constexpr void erase(const_reference_type element);

	// conversion functions
	public:
		constexpr vector<value_type> to_vector() const;

	// traversals
	public:
		constexpr vector<T> preorder() const;
		constexpr vector<T> inorder() const;
		constexpr vector<T> postorder() const;
		constexpr vector<vector<T>> level_order() const;
		constexpr vector<vector<T>> breadth_first() const;

	// traversals
	protected:
		constexpr void preorder(binary_node_ptr root, vector<T>& order) const;
		constexpr void inorder(binary_node_ptr root, vector<T>& order) const;
		constexpr void postorder(binary_node_ptr root, vector<T>& order) const;
		constexpr void level_order(binary_node_ptr root, vector<vector<T>>& order) const;
		constexpr void breadth_first(binary_node_ptr root, vector<vector<T>>& order) const;

	// private helper functions
	protected:
		template<typename... Args>
		constexpr binary_node_ptr emplace(binary_node_ptr& root, binary_node_ptr parent, Args&&... args);
		constexpr binary_node_ptr search(const_reference_type element, binary_node_ptr root) const;
		constexpr size_t max_height(binary_node_ptr root);
		constexpr void delete_tree(binary_node_ptr root);
		constexpr bool find(const_reference_type element, binary_node_ptr root);
		constexpr binary_node_ptr erase(binary_node_ptr root, const_reference_type element);

	// variables
	protected:
		binary_node_ptr m_Root = nullptr;
		size_t m_Size = 0;
	};

	template<typename T>
	constexpr binary_search_tree<T>::binary_search_tree() : m_Root(nullptr), m_Size(0) { }

	template<typename T>
	inline binary_search_tree<T>::~binary_search_tree()
	{
		delete_tree(m_Root);
	}

	template<typename T>
	constexpr typename binary_search_tree<T>::binary_node_ptr 
		binary_search_tree<T>::search(const_reference_type element) const
	{
		return search(element, m_Root);
	}

	template<typename T>
	constexpr bool 
		binary_search_tree<T>::contains(const_reference_type element) const
	{
		return find(element, m_Root);
	}

	template<typename T>
	constexpr typename binary_search_tree<T>::binary_node_ptr
		binary_search_tree<T>::root()
	{
		return m_Root;
	}

	template<typename T>
	constexpr typename binary_search_tree<T>::binary_node_ptr 
		binary_search_tree<T>::root() const
	{
		return m_Root;
	}

	template<typename T>
	constexpr size_t 
		binary_search_tree<T>::height(binary_node_ptr root) const
	{
		return max_height(root);
	}

	template<typename T>
	constexpr size_t 
		binary_search_tree<T>::depth(binary_node_ptr root) const
	{
		return max_height(m_Root) - max_height(root);
	}

	template<typename T>
	constexpr size_t 
		binary_search_tree<T>::size() const
	{
		return m_Size;
	}

	template<typename T>
	constexpr bool binary_search_tree<T>::empty() const
	{
		return !m_Root;
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename binary_search_tree<T>::binary_node_ptr
		binary_search_tree<T>::emplace(Args && ...args)
	{
		return emplace(m_Root, nullptr, std::forward<Args>(args)...);
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename binary_search_tree<T>::binary_node_ptr 
		binary_search_tree<T>::emplace(binary_node_ptr& root, binary_node_ptr parent, Args && ...args)
	{
		binary_node_ptr temp = new binary_node(std::forward<Args>(args)...);

		if (!root)
		{
			root = temp;
			root->parent = parent;
			m_Size++;
			return temp;
		}
		else if (temp->data < root->data)
			return emplace(root->left, std::forward<Args>(args)...);
		else if (temp->data > root->data)
			return emplace(root->right, std::forward<Args>(args)...);
		else
			return temp;
	}

	template<typename T>
	constexpr typename binary_search_tree<T>::binary_node_ptr 
		binary_search_tree<T>::push(const_reference_type element)
	{
		return emplace(element);
	}

	template<typename T>
	constexpr void 
		binary_search_tree<T>::erase(const_reference_type element)
	{
		m_Size--;
		erase(m_Root, element);
	}

	template<typename T>
	constexpr vector<T> 
		binary_search_tree<T>::to_vector() const
	{
		return;
	}

	template<typename T>
	constexpr vector<T>
		binary_search_tree<T>::preorder() const
	{
		vector<T> order(m_Size);

		preorder(m_Root, order);

		return order;
	}

	template<typename T>
	constexpr vector<T>
		binary_search_tree<T>::inorder() const
	{
		vector<T> order(m_Size);

		inorder(m_Root, order);
		
		return order;
	}

	template<typename T>
	constexpr vector<T> 
		binary_search_tree<T>::postorder() const
	{
		vector<T> order(m_Size);
		
		postorder(m_Root, order);

		return order;
	}

	template<typename T>
	constexpr vector<vector<T>> 
		binary_search_tree<T>::level_order() const
	{
		vector<vector<T>> order(m_Size);

		level_order(m_Root, order);

		return order;
	}

	template<typename T>
	constexpr vector<vector<T>> 
		binary_search_tree<T>::breadth_first() const
	{
		return level_order();
	}

	template<typename T>
	constexpr void 
		binary_search_tree<T>::preorder(binary_node_ptr root, vector<T>& order) const
	{
		if (!root)
			return;

		order.emplace_back(root->data);
		preorder(root->left, order);
		preorder(root->right, order);
	}

	template<typename T>
	constexpr void 
		binary_search_tree<T>::inorder(binary_node_ptr root, vector<T>& order) const
	{
		if (!root)
			return;

		inorder(root->left, order);
		order.emplace_back(root->data);
		inorder(root->right, order);
	}

	template<typename T>
	constexpr void 
		binary_search_tree<T>::postorder(binary_node_ptr root, vector<T>& order) const
	{
		if (!root)
			return;

		postorder(root->left, order);
		postorder(root->right, order);
		order.emplace_back(root->data);
	}

	template<typename T>
	constexpr void 
		binary_search_tree<T>::level_order(binary_node_ptr root, vector<vector<T>>& order) const
	{
		queue<binary_node_ptr> temp{};

		if (root)
			temp.emplace(root);

		while (!temp.empty())
		{
			size_t size = temp.size();

			vector<T> lvl{};

			for (size_t i = 0; i < size; i++)
			{
				lvl.emplace_back(temp.front()->data);

				if (temp.front()->left)
					temp.emplace(temp.front()->left);
				if (temp.front()->right)
					temp.emplace(temp.front()->right);

				temp.pop();
			}

			order.emplace_back(lvl);
		}
	}

	template<typename T>
	constexpr void 
		binary_search_tree<T>::breadth_first(binary_node_ptr root, vector<vector<T>>& order) const
	{
		level_order(root, order);
	}

	template<typename T>
	constexpr typename binary_search_tree<T>::binary_node_ptr 
		binary_search_tree<T>::search(const_reference_type element, binary_node_ptr root) const
	{
		if (!root)
			return nullptr;
		else if (root->data == element)
			return root;
		else if (element < root->data)
			return search(element, root->left);
		else if (element > root->data)
			return search(element, root->right);
	}

	template<typename T>
	constexpr size_t 
		binary_search_tree<T>::max_height(binary_node_ptr root)
	{
		if (!root)
			return 0;
		
		size_t left_height = max_height(root->left);
		size_t right_height = max_height(root->right);

		return left_height > right_height ? (left_height + 1) : (right_height + 1);
	}

	template<typename T>
	constexpr void 
		binary_search_tree<T>::delete_tree(binary_node_ptr root)
	{
		if (!root)
			return;
		
		delete_tree(root->right);
		delete_tree(root->left);

		delete root;
	}

	template<typename T>
	constexpr bool 
		binary_search_tree<T>::find(const_reference_type element, binary_node_ptr root)
	{
		if (!root)
			return false;
		else if (root->data == element)
			return true;
		else if (element < root->data)
			find(element, root->left);
		else if (element > root->data)
			find(element, root->right);

		return false;
	}

	template<typename T>
	constexpr typename binary_search_tree<T>::binary_node_ptr
		binary_search_tree<T>::erase(binary_node_ptr root, const_reference_type element)
	{
		if (!root)
			return nullptr;
		if (element < root->data)
			root->left = erase(root->left, element);
		else if (element > root->data)
			root->right = erase(root->right, element);
		else
		{
			if (!root->left && !root->right)
				return nullptr;
			else if (!root->left)
			{
				binary_node_ptr temp = root->right;
				delete root;
				return temp;
			}
			else if (!root->right)
			{
				binary_node_ptr temp = root->left;
				delete root;
				return temp;
			}
			
			binary_node_ptr target = [=](binary_node_ptr node)
			{
				while (node && node->left)
					node = node->left;

				return node;
			}(root->right);

			root->data = target->data;

			root->right = erase(root->right, target->data);
		}

		return root;
	}
}

#endif