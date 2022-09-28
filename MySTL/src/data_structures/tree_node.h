#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "vector.h"

namespace mystl
{
	template<typename T>
	struct tree_node
	{
		using value_type = T;
		
		value_type data = T();
		tree_node* parent = nullptr;
		vector<tree_node*> children{};

		tree_node() : data(T()), next(nullptr), children() { }
		tree_node(const value_type& data) : data(data), next(nullptr), children() { }
		~tree_node()
		{
			for (size_t i = 0; i < children.size(); i++)
			{
				delete children[i];
			}
		}
	};
}

#endif