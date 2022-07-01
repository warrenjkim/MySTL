#ifndef LIST_H
#define LIST_H

#include "node.h"
#include "list_iterator.h"

// TODO:
// write sort algorithms
//

// list class
namespace mystl
{
	template<typename T>
	class list
	{
	// typedefs
	public:
		using		value_type				= T;

		using		reference_type			= value_type&;
		using		pointer_type			= value_type*;

		using		node					= node<T>;
		using		node_ptr				= node*;

		using		const_reference_type	= const value_type&;
		using		const_pointer_type		= const value_type*;

		using		const_iterator			= list_const_iterator<list<T>>;
		using		iterator				= list_iterator<list<T>>;

		using		const_reverse_iterator	= list_const_reverse_iterator<const_iterator>;
		using		reverse_iterator		= list_reverse_iterator<iterator>;

	// constructor/destructor
	public:
		constexpr							list();
		constexpr							list(const size_t& size);
		constexpr							list(const size_t& size, const_reference_type fillElement);
											~list();

	// size functions
	public:
		constexpr	bool					empty() const;
		constexpr	size_t					size() const;

	// element access
	public:
		constexpr	reference_type			operator[](const size_t& offset);
		constexpr	reference_type			front();
		constexpr	reference_type			back();

		constexpr	const_reference_type	front() const;
		constexpr	const_reference_type	back() const;

	// mutators
	public:
		constexpr	void					assign(const size_t& size, const_reference_type fillElement);
		constexpr	void					assign(iterator first, iterator last);
		constexpr	void					assign(pointer_type first, pointer_type second);

		constexpr	reference_type			push_front(T&& element);
		constexpr	reference_type			push_front(const_reference_type element);

		constexpr	reference_type			push_back(T&& element);
		constexpr	reference_type			push_back(const_reference_type element);

		template<typename... Args>
		constexpr	reference_type			emplace_front(Args&&... args);

		template<typename... Args>
		constexpr	reference_type			emplace_back(Args&&... args);

		template<typename... Args>
		constexpr	iterator				emplace(iterator position, Args&&... args);

		constexpr	value_type				pop_front();
		constexpr	value_type				pop_back();

		constexpr	reference_type			insert(iterator position, T&& element);

	// mutators
	public:
					[[noreturn]] void		clear();
					[[noreturn]] void		swap(list& other);
					[[noreturn]] void		resize(const size_t& size);

	// mutators
	public:
		
		constexpr	iterator				erase(iterator position);
		constexpr	iterator				erase(iterator first, iterator last);

		constexpr	reference_type			remove(T&& element);
		constexpr	reference_type			remove(const_reference_type element);

		template<class Predicate>
		constexpr	void					remove_if(const Predicate& predicate);

		constexpr	void					sort();
		template<class Compare>
		constexpr	void					sort(const Compare& comparator);

		constexpr	void					merge(list& other);
		template<class Compare>
		constexpr	void					merge(list& other, const Compare& comparator);

		constexpr	void					reverse();

	// iterator functions
	public:

		constexpr	const_iterator			cbegin() const;
		constexpr	const_iterator			cend() const;

		constexpr	iterator				begin();
		constexpr	iterator				end();

		constexpr	const_reverse_iterator	crbegin() const;
		constexpr	const_reverse_iterator	crend() const;

		constexpr	reverse_iterator		rbegin();
		constexpr	reverse_iterator		rend();

	private:
					node_ptr				m_Head	= nullptr;
					node_ptr				m_Tail	= nullptr;
					size_t					m_Size	= 0;
	};

	template<typename T>
	constexpr list<T>::list() : m_Head(nullptr), m_Tail(nullptr), m_Size(0)
	{

	}

	template<typename T>
	constexpr list<T>::list(const size_t& size) : m_Head(nullptr), m_Tail(nullptr), m_Size(size)
	{

	}

	template<typename T>
	constexpr list<T>::list(const size_t& size, const_reference_type fillElement) : m_Head(nullptr), m_Tail(nullptr), m_Size(size)
	{
		for (size_t i = 0; i < size; i++)
		{
			emplace_front(fillElement);
		}
	}

	template<typename T>
	inline list<T>::~list()
	{
		while (!empty())
		{
			pop_front();
		}
	}

	template<typename T>
	constexpr bool list<T>::empty() const
	{
		return !m_Head;
	}

	template<typename T>
	constexpr size_t list<T>::size() const
	{
		return m_Size;
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::operator[](const size_t& offset)
	{
		node_ptr temp = m_Head;
		
		for (size_t i = 0; i < offset; i++)
		{
			temp = temp->next;
		}

		return temp->data;
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::front()
	{
		return m_Head->data;
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::back()
	{
		return m_Tail->data;
	}

	template<typename T>
	constexpr typename list<T>::const_reference_type list<T>::front() const
	{
		return m_Head->data;
	}

	template<typename T>
	constexpr typename list<T>::const_reference_type list<T>::back() const
	{
		return m_Tail->data;
	}

	template<typename T>
	constexpr void list<T>::assign(const size_t& size, const_reference_type fillElement)
	{
		for (size_t i = 0; i < size; i++)
		{
			emplace_front(fillElement);
		}
	}

	template<typename T>
	constexpr void list<T>::assign(iterator first, iterator last)
	{

	}

	template<typename T>
	constexpr void list<T>::assign(pointer_type first, pointer_type second)
	{
		while (first != second)
		{
			emplace_front(*(first++));
		}
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename list<T>::reference_type list<T>::emplace_front(Args && ...args)
	{
		node_ptr temp = new node(std::forward<Args>(args)...);

		if (!m_Head)
		{
			m_Head = temp;
			m_Tail = temp;
			m_Size++;
			return m_Head->data;
		}

		temp->next = m_Head;
		m_Head->prev = temp;
		m_Head = temp;
		m_Size++;

		return m_Head->data;
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename list<T>::reference_type list<T>::emplace_back(Args && ...args)
	{
		node_ptr temp = new node(std::forward<Args>(args)...);

		if (!m_Head)
		{
			m_Head = temp;
			m_Tail = temp;
			m_Size++;
			return m_Tail->data;
		}

		temp->prev = m_Tail;
		m_Tail->next = temp;
		m_Tail = temp;
		m_Size++;
		
		return m_Tail->data;
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename list<T>::iterator list<T>::emplace(iterator position, Args && ...args)
	{
		node_ptr temp = new node(std::forward<Args>(args)...);

		if (!m_Head)
		{
			emplace_front(args);
			return begin();
		}

		node_ptr tempHead = m_Head;
		node_ptr tempSecondHalf = m_Head->next;
		while (tempHead->next != *position)
		{
			tempHead = tempHead->next;
			tempSecondHalf = tempSecondHalf->next;
		}

		temp->prev = tempHead;
		tempHead->next = temp;

		temp->next = tempSecondHalf;
		tempSecondHalf->prev = temp;
		m_Size++;

		return position;
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::push_front(T&& element)
	{
		return emplace_front(element);
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::push_front(const_reference_type element)
	{
		return emplace_front(element);
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::push_back(T&& element)
	{
		return emplace_back(element);
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::push_back(const_reference_type element)
	{
		return emplace_back(element);
	}

	template<typename T>
	constexpr typename list<T>::value_type list<T>::pop_front()
	{
		if (!m_Head)
		{
			return value_type();
		}

		node_ptr temp = m_Head;
		m_Head = m_Head->next;
		value_type val = temp->data;

		delete temp;
		m_Size--;

		return val;
	}

	template<typename T>
	constexpr typename list<T>::value_type list<T>::pop_back()
	{
		if (!m_Head)
		{
			return value_type();
		}

		node_ptr temp = m_Tail;
		m_Tail = m_Tail->prev;
		m_Tail->next = nullptr;
		value_type val = temp->data;

		delete temp;
		m_Size--;

		return val;
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::insert(iterator position, T&& element)
	{
		emplace(position, element);
	}

	template<typename T>
	inline void list<T>::clear()
	{
		while (m_Head)
		{
			pop_front();
		}
	}

	
	template<typename T>
	inline void list<T>::swap(list& other)
	{
		node_ptr tempHead = m_Head;
		node_ptr tempTail = m_Tail;
		size_t tempSize = m_Size;

		m_Head = other.m_Head;
		m_Tail = other.m_Tail;
		m_Size = other.m_Size;

		other.m_Head = tempHead;
		other.m_Tail = tempTail;
		other.m_Size = tempSize;
	}

	template<typename T>
	inline void list<T>::resize(const size_t& size)
	{
		while (m_Size > size)
		{
			pop_back();
		}
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::remove(T&& element)
	{
		node_ptr temp = m_Head;

		while (temp->data != element)
		{
			if (!temp->next)
			{
				return reference_type();
			}

			temp = temp->next;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		
		reference_type data = temp->data;

		delete temp;
		m_Size--;

		return data;
	}

	template<typename T>
	constexpr typename list<T>::reference_type list<T>::remove(const_reference_type element)
	{
		node_ptr temp = m_Head;

		while (temp->data != element)
		{
			if (!temp->next)
			{
				return reference_type();
			}

			temp = temp->next;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		reference_type data = temp->data;

		delete temp;
		m_Size--;

		return data;
	}

	template<typename T>
	constexpr typename list<T>::iterator list<T>::erase(iterator position)
	{
		node_ptr temp = m_Head;

		while (temp != *position)
		{
			temp = temp->next;
		}

		remove(temp->data);

		return position;
	}

	template<typename T>
	constexpr typename list<T>::iterator list<T>::erase(iterator first, iterator last)
	{
		iterator temp = first;
		while (first != last)
		{
			erase(first++);
		}

		return temp;
	}

	template<typename T>
	constexpr void list<T>::sort()
	{
		// implemented later using merge sort
	}

	template<typename T>
	constexpr void list<T>::merge(list& other)
	{
		m_Tail->next = other.m_Head;
	}

	template<typename T>
	template<class Compare>
	constexpr void list<T>::merge(list& other, const Compare& comparator)
	{
		// implemented later using merge sort
	}

	template<typename T>
	constexpr void list<T>::reverse()
	{
		if (!m_Head)
		{
			return;
		}

		node_ptr curr = m_Head;
		m_Tail = curr;
		node_ptr prev = nullptr;
		node_ptr next = nullptr;

		while (curr)
		{
			next = curr->next;
			curr->next = prev;
			curr->prev = next;
			prev = curr;
			curr = next;
		}

		m_Head = prev;
	}

	template<typename T>
	template<class Predicate>
	constexpr void list<T>::remove_if(const Predicate& predicate)
	{
		// implement later
	}

	template<typename T>
	template<class Compare>
	constexpr void list<T>::sort(const Compare& comparator)
	{
		// implement using merge sort later
	}

	template<typename T>
	constexpr typename list<T>::const_iterator list<T>::cbegin() const
	{
		return const_iterator(m_Head);
	}

	template<typename T>
	constexpr typename list<T>::const_iterator list<T>::cend() const
	{
		return const_iterator(m_Tail->next);
	}

	template<typename T>
	constexpr typename list<T>::iterator list<T>::begin()
	{
		return iterator(m_Head);
	}

	template<typename T>
	constexpr typename list<T>::iterator list<T>::end()
	{
		return iterator(m_Tail->next);
	}

	template<typename T>
	constexpr typename list<T>::const_reverse_iterator list<T>::crbegin() const
	{
		return const_reverse_iterator(cend());
	}

	template<typename T>
	constexpr typename list<T>::const_reverse_iterator list<T>::crend() const
	{
		return const_reverse_iterator(cbegin());
	}

	template<typename T>
	constexpr typename list<T>::reverse_iterator list<T>::rbegin()
	{
		return reverse_iterator(end());
	}

	template<typename T>
	constexpr typename list<T>::reverse_iterator list<T>::rend()
	{
		return reverse_iterator(begin());
	}
}

#endif