#ifndef LIST_H
#define LIST_H
#include "iterator.h"

// TODO:
// reorder function declarations and defintions
// write an iterator class for list to overload the ++/--, +/-
// write sort algorithms
//

namespace mystl
{
	template<typename T>
	class list
	{
	// node struct
	private:
		struct node
		{
			friend class list;

			T		data = T();
			node*	next = nullptr;
			node*	prev = nullptr;

			node() : data(T()), next(nullptr), prev(nullptr) { }

			node(const T& data) : data(data), next(nullptr), prev(nullptr) { }

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

	// constructor/destructor
	public:
		CONSTEXPR	list();
		CONSTEXPR	list(const size_t& size);
		CONSTEXPR	list(const size_t& size, const_reference_type fillElement);

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

		vector<T>* print() const
		{
			vector<T>* data = new vector<T>();
			node_ptr temp = m_Head;
			while (temp)
			{
				data->push_back(temp->data);
				temp = temp->next;
			}

			return data;
		}

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

	private:
					node_ptr				m_Head	= nullptr;
					node_ptr				m_Tail	= nullptr;
					size_t					m_Size	= 0;
	};

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
		for (size_t i = 0; i < size; i++)
		{
			emplace_front(fillElement);
		}
	}

	template<typename T>
	CONSTEXPR void list<T>::assign(iterator first, iterator last)
	{

	}

	template<typename T>
	CONSTEXPR void list<T>::assign(pointer_type first, pointer_type second)
	{
		while (first != second)
		{
			emplace_front(*(first++));
		}
	}

	template<typename T>
	template<typename ...Args>
	CONSTEXPR typename list<T>::reference_type list<T>::emplace_front(Args && ...args)
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
		m_Head = temp;
		m_Size++;

		return m_Head->data;
	}

	template<typename T>
	template<typename ...Args>
	CONSTEXPR typename list<T>::reference_type list<T>::emplace_back(Args && ...args)
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
	CONSTEXPR typename list<T>::iterator list<T>::emplace(iterator position, Args && ...args)
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
	CONSTEXPR typename list<T>::reference_type list<T>::push_front(T&& element)
	{
		return emplace_front(element);
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::push_front(const_reference_type element)
	{
		return emplace_front(element);
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::push_back(T&& element)
	{
		return emplace_back(element);
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::push_back(const_reference_type element)
	{
		return emplace_back(element);
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::pop_front()
	{
		if (!m_Head)
		{
			return reference_type();
		}

		node_ptr temp = m_Head;
		reference_type data = temp->data;

		m_Head = m_Head->next;

		delete temp;
		m_Size--;

		return data;
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::pop_back()
	{
		if (!m_Head)
		{
			return reference_type();
		}

		node_ptr temp = m_Tail;
		reference_type data = temp->data;

		m_Tail = m_Tail->prev;
		m_Tail->next = nullptr;

		delete temp;
		m_Size--;

		return data;
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::insert(iterator position, T&& element)
	{
		emplace(position, element);
	}

	template<typename T>
	CONSTEXPR void list<T>::clear()
	{
		while (m_Head)
		{
			pop_front();
		}
	}

	
	template<typename T>
	CONSTEXPR void list<T>::swap(list& other)
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
	CONSTEXPR void list<T>::resize(const size_t& size)
	{
		while (m_Size > size)
		{
			pop_back();
		}
	}

	template<typename T>
	CONSTEXPR typename list<T>::reference_type list<T>::remove(T&& element)
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
	CONSTEXPR typename list<T>::reference_type list<T>::remove(const_reference_type element)
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
	CONSTEXPR typename list<T>::iterator list<T>::erase(iterator position)
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
	CONSTEXPR typename list<T>::iterator list<T>::erase(iterator first, iterator last)
	{
		iterator temp = first;
		while (first != last)
		{
			erase(first++);
		}

		return temp;
	}

	template<typename T>
	CONSTEXPR void list<T>::sort()
	{
		// implemented later using merge sort
	}

	template<typename T>
	CONSTEXPR void list<T>::merge(list& other)
	{
		m_Tail->next = other.m_Head;
	}

	template<typename T>
	template<class Compare>
	CONSTEXPR void list<T>::merge(list& other, const Compare& comparator)
	{
		// implemented later using merge sort
	}

	template<typename T>
	CONSTEXPR void list<T>::reverse()
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
	CONSTEXPR void list<T>::remove_if(const Predicate& predicate)
	{
		// implement later
	}

	template<typename T>
	template<class Compare>
	CONSTEXPR void list<T>::sort(const Compare& comparator)
	{
		// implement using merge sort later
	}

	// iterator functions will be implemented when i stop being lazy and refactor the iterator
	// class to be a base class that can be used for inheritance to override the ++/-- and +/-
	// functions.
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
		return iterator(*m_Head);
	}

	template<typename T>
	CONSTEXPR typename list<T>::iterator list<T>::end()
	{
		return iterator(*m_Tail);
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
}

#endif