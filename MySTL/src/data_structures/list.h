#ifndef LIST_H
#define LIST_H

#include "iterator.h"
#include <list>

namespace mystl
{
	template<typename T>
	class list
	{
	// struct
	private:
		struct node
		{
			friend class list;

			T		data = T();
			node*	next = nullptr;
			node*	prev = nullptr;

			node() : data(T()), next(nullptr), prev(nullptr) { }

			node(const T& data) : data(T()), next(nullptr), prev(nullptr) { }

			~node() = default;

		};
	// typedefs
	public:
		using		value_type = T;

		using		reference_type = value_type&;
		using		pointer_type = value_type*;

		using		const_reference_type = const value_type&;
		using		const_pointer_type = const value_type*;

		using		iterator = iterator<list<T>>;
		using		const_iterator = const_iterator<list<T>>;

		using		reverse_iterator = reverse_iterator<iterator>;
		using		const_reverse_iterator = const_reverse_iterator<const_iterator>;

		using		node_ptr = node*;

	// iterator functions
	public:

		CONSTEXPR	const_iterator			cbegin() const;
		CONSTEXPR	const_iterator			cend() const;

		CONSTEXPR	iterator				begin();
		CONSTEXPR	iterator				end();

		CONSTEXPR	const_reverse_iterator	crbegin() const;
		CONSTEXPR	const_reverse_iterator	crend() const;

		CONSTEXPR	reverse_iterator		rbegin();
		CONSTEXPR	reverse_iterator		rend();

	// size functions
	public:
		CONSTEXPR	bool					empty() const;
		CONSTEXPR	size_t					size() const;

	// access functions
	public:
		CONSTEXPR	reference_type			front();
		CONSTEXPR	reference_type			back();

		CONSTEXPR	const_reference_type	front() const;
		CONSTEXPR	const_reference_type	back() const;

	// mutators
	public:
		CONSTEXPR	void					assign(const size_t& size, const_reference_type fillElement);
		CONSTEXPR	void					assign(iterator first, iterator last);
		CONSTEXPR	void					assign(pointer_type first, pointer_type second);

		CONSTEXPR	reference_type			push_front(T&& element);
		CONSTEXPR	reference_type			push_front(const_reference_type element);

		CONSTEXPR	reference_type			push_back(T&& element);
		CONSTEXPR	reference_type			push_back(const_reference_type element);

		template<typename... Args>
		CONSTEXPR	reference_type			emplace_front(Args&&... args);

		template<typename... Args>
		CONSTEXPR	reference_type			emplace_back(Args&&... args);

		template<typename... Args>
		CONSTEXPR	iterator				emplace(iterator position, Args&&... args);

		CONSTEXPR	reference_type			pop_front();
		CONSTEXPR	reference_type			pop_back();

		CONSTEXPR	reference_type			insert(iterator position, T&& element);

	// mutators
	public:
		CONSTEXPR	void					clear();
		CONSTEXPR	void					swap(list& other);
		CONSTEXPR	void					resize(const size_t& size);

	// mutators
	public:
		
		CONSTEXPR	iterator				erase(iterator position);
		CONSTEXPR	iterator				erase(iterator first, iterator last);

		CONSTEXPR	reference_type			remove(T&& element);
		CONSTEXPR	reference_type			remove(const_reference_type element);

		template<class Predicate>
		CONSTEXPR	void					remove_if(const Predicate& predicate);

		CONSTEXPR	void					sort();
		template<class Compare>
		CONSTEXPR	void					sort(const Compare& comparator);

		CONSTEXPR	void					merge(list& other);
		template<class Compare>
		CONSTEXPR	void					merge(list& other, const Compare& comparator);

		CONSTEXPR	void					reverse();

	// constructor/destructor
	public:
		CONSTEXPR list();
		CONSTEXPR list(const size_t& size);
		CONSTEXPR list(const size_t& size, const_reference_type fillElement);

	private:
					node_ptr				m_Head	= nullptr;
					node_ptr				m_Tail	= nullptr;
					size_t					m_Size	= 0;
	};

	template<typename T>
	CONSTEXPR typename list<T>::const_iterator list<T>::cbegin() const
	{
		return const_iterator();
	}

	template<typename T>
	CONSTEXPR typename list<T>::const_iterator list<T>::cend() const
	{
		return const_iterator();
	}

	template<typename T>
	CONSTEXPR typename list<T>::iterator list<T>::begin()
	{
		return iterator();
	}

	template<typename T>
	CONSTEXPR typename list<T>::iterator list<T>::end()
	{		  
		return iterator();
	}		  
			  
	template<typename T>
	CONSTEXPR typename list<T>::const_reverse_iterator list<T>::crbegin() const
	{
		return const_reverse_iterator();
	}

	template<typename T>
	CONSTEXPR typename list<T>::const_reverse_iterator list<T>::crend() const
	{
		return const_reverse_iterator();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reverse_iterator list<T>::rbegin()
	{
		return reverse_iterator();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reverse_iterator list<T>::rend()
	{
		return reverse_iterator();
	}

	template<typename T>
	CONSTEXPR bool list<T>::empty() const
	{
		return !m_Head;
	}

	template<typename T>
	CONSTEXPR size_t list<T>::size() const
	{
		return m_Size;
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::front()
	{
		return m_Head->data;
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::back()
	{
		return m_Tail->data;
	}

	template<typename T>
	CONSTEXPR typename list<T>::const_reference_type list<T>::front() const
	{
		return m_Head->data;
	}

	template<typename T>
	CONSTEXPR typename list<T>::const_reference_type list<T>::back() const
	{
		return m_Tail->data;
	}

	template<typename T>
	CONSTEXPR void list<T>::assign(const size_t& size, const_reference_type fillElement)
	{

	}

	template<typename T>
	CONSTEXPR void list<T>::assign(iterator first, iterator last)
	{
	}

	template<typename T>
	CONSTEXPR void list<T>::assign(pointer_type first, pointer_type second)
	{
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::push_front(T&& element)
	{
		return reference_type();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::push_front(const_reference_type element)
	{
		return reference_type();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::push_back(T&& element)
	{
		return reference_type();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::push_back(const_reference_type element)
	{
		return reference_type();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::pop_front()
	{
		return reference_type();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::pop_back()
	{
		return reference_type();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::insert(iterator position, T&& element)
	{
		return reference_type();
	}

	template<typename T>
	CONSTEXPR void list<T>::clear()
	{
	}

	
	template<typename T>
	CONSTEXPR void list<T>::swap(list& other)
	{
	}

	template<typename T>
	CONSTEXPR void list<T>::resize(const size_t& size)
	{
	}

	template<typename T>
	CONSTEXPR typename list<T>::iterator list<T>::erase(iterator position)
	{
		return iterator();
	}

	template<typename T>
	CONSTEXPR typename list<T>::iterator list<T>::erase(iterator first, iterator last)
	{
		return iterator();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::remove(T&& element)
	{
		return reference_type();
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::remove(const_reference_type element)
	{
		return reference_type();
	}

	template<typename T>
	CONSTEXPR void list<T>::sort()
	{
	}

	template<typename T>
	CONSTEXPR void list<T>::merge(list& other)
	{
	}

	template<typename T>
	CONSTEXPR void list<T>::reverse()
	{
	}

	template<typename T>
	CONSTEXPR list<T>::list() : m_Head(nullptr), m_Tail(nullptr), m_Size(0)
	{
	}

	template<typename T>
	CONSTEXPR list<T>::list(const size_t& size) : m_Head(nullptr), m_Tail(nullptr), m_Size(size)
	{
	}

	template<typename T>
	CONSTEXPR list<T>::list(const size_t& size, const_reference_type fillElement) : m_Head(nullptr), m_Tail(nullptr), m_Size(size)
	{
		for (size_t i = 0; i < size; i++)
		{
			emplace_front(fillElement);
		}
	}

	template<typename T>
	template<typename ...Args>
	CONSTEXPR typename list<T>::reference_type list<T>::emplace_front(Args && ...args)
	{
		return reference_type();
	}

	template<typename T>
	template<typename ...Args>
	CONSTEXPR typename list<T>::reference_type list<T>::emplace_back(Args && ...args)
	{
		return reference_type();
	}

	template<typename T>
	template<typename ...Args>
	CONSTEXPR typename list<T>::iterator list<T>::emplace(iterator position, Args && ...args)
	{
		return iterator();
	}

	template<typename T>
	template<class Predicate>
	CONSTEXPR void list<T>::remove_if(const Predicate& predicate)
	{
	}

	template<typename T>
	template<class Compare>
	CONSTEXPR void list<T>::sort(const Compare& comparator)
	{
	}

	template<typename T>
	template<class Compare>
	CONSTEXPR void list<T>::merge(list& other, const Compare& comparator)
	{
	}

}

#endif