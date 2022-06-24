#ifndef LIST_H
#define LIST_H
#include "iterator.h"
#include <list>

// TODO:
// reorder function declarations and defintions
// write sort algorithms
//
namespace mystl
{
	template<typename T>
	struct node
	{
		using value_type = T;

		T		data = T();
		node*	next = nullptr;
		node*	prev = nullptr;

		node() : data(T()), next(nullptr), prev(nullptr) { }

		node(const T& data) : data(data), next(nullptr), prev(nullptr) { }
		~node() = default;
	};
}

// list_const_iterator
namespace mystl
{
	template<class C>
	class list_const_iterator
	{
	// typedefs
	public:
		using		value_type				= typename C::value_type;
		using		const_pointer_type		= const value_type*;
		using		const_reference_type	= const value_type&;

		using		const_node_ptr			= const node<value_type>*;

	// constructors
	public:
		constexpr							list_const_iterator(const_node_ptr ptr);
											~list_const_iterator() = default;

	// element access
	public:
		constexpr	const_reference_type	operator[](const size_t& offset) const;
		constexpr	const_reference_type	operator*() const;
		constexpr	const_pointer_type		operator->() const;

	// modifier functions: increment
	public:
		constexpr	list_const_iterator&	operator++();
		constexpr	list_const_iterator		operator++(int);

		constexpr	list_const_iterator&	operator+=(const size_t& offset);
		constexpr	list_const_iterator&	operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		constexpr	list_const_iterator&	operator--();
		constexpr	list_const_iterator		operator--(int);

		constexpr	list_const_iterator&	operator-=(const size_t& offset);
		constexpr	list_const_iterator&	operator-(const size_t& offset) const;

	// equality operators
	public:
		constexpr	bool					operator==(const list_const_iterator& other) const;
		constexpr	bool					operator!=(const list_const_iterator& other) const;

	// variables
	protected:
					const_node_ptr			m_Ptr = nullptr;
	};

	template<class C>
	constexpr list_const_iterator<C>::list_const_iterator(const_node_ptr ptr) : m_Ptr(ptr)
	{ }

	template<class C>
	constexpr typename list_const_iterator<C>::const_reference_type
		list_const_iterator<C>::operator[](const size_t& offset) const
	{
		for (size_t i = 0; i < offset; i++)
		{
			m_Ptr = m_Ptr->next;
		}
		return m_Ptr->data;
	}

	template<class C>
	constexpr typename list_const_iterator<C>::const_reference_type
		list_const_iterator<C>::operator*() const
	{
		return m_Ptr->data;
	}

	template<class C>
	constexpr typename list_const_iterator<C>::const_pointer_type
		list_const_iterator<C>::operator->() const
	{
		return m_Ptr;
	}

	template<class C>
	constexpr list_const_iterator<C>&
		list_const_iterator<C>::operator++()
	{
		m_Ptr = m_Ptr->next;
		return *this;
	}

	template<class C>
	constexpr list_const_iterator<C>
		list_const_iterator<C>::operator++(int)
	{
		list_const_iterator it = *this;
		++(*this);
		return it;
	}

	template<class C>
	constexpr list_const_iterator<C>&
		list_const_iterator<C>::operator+=(const size_t& offset)
	{
		for (size_t i = 0; i < offset; i++)
		{
			m_Ptr = m_Ptr->next;
		}
		return *this;
	}

	template<class C>
	constexpr list_const_iterator<C>&
		list_const_iterator<C>::operator+(const size_t& offset) const
	{
		list_const_iterator it = *this;
		it += offset;
		return *this;
	}

	template<class C>
	constexpr list_const_iterator<C>&
		list_const_iterator<C>::operator--()
	{
		m_Ptr = m_Ptr->prev;
		return *this;
	}

	template<class C>
	constexpr list_const_iterator<C>
		list_const_iterator<C>::operator--(int)
	{
		list_const_iterator it = *this;
		--(*this);
		return it;
	}

	template<class C>
	constexpr list_const_iterator<C>&
		list_const_iterator<C>::operator-=(const size_t& offset)
	{
		for (size_t i = 0; i < offset; i++)
		{
			m_Ptr = m_Ptr->prev;
		}
		return *this;
	}

	template<class C>
	constexpr list_const_iterator<C>&
		list_const_iterator<C>::operator-(const size_t& offset) const
	{
		list_const_iterator it = *this;
		it -= offset;
		return it;
	}

	template<class C>
	constexpr bool
		list_const_iterator<C>::operator==(const list_const_iterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	template<class C>
	constexpr bool
		list_const_iterator<C>::operator!=(const list_const_iterator& other) const
	{
		return !(*this == other);
	}
}

// list_iterator
namespace mystl
{
	template<class C>
	class list_iterator : public list_const_iterator<C>
	{
	// base class typedef
	public:
		using		base_class = list_const_iterator<C>;

	// typedefs
	public:
		using		value_type		= typename C::value_type;
		using		pointer_type	= value_type*;
		using		reference_type	= value_type&;

		using		node_ptr		= node<value_type>*;

	// constructors
	public:
		constexpr					list_iterator(node_ptr ptr);
									~list_iterator() = default;

	// element access
	public:
		constexpr	reference_type	operator[](const size_t& offset) const;
		constexpr	reference_type	operator*() const;
		constexpr	pointer_type	operator->() const;

	// modifier functions: increment
	public:
		constexpr	list_iterator&	operator++();
		constexpr	list_iterator	operator++(int);
		constexpr	list_iterator&	operator+=(const size_t& offset);
		constexpr	list_iterator	operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		constexpr	list_iterator&	operator--();
		constexpr	list_iterator	operator--(int);

		constexpr	list_iterator&	operator-=(const size_t& offset);
		constexpr	list_iterator&	operator-(const size_t& offset) const;
	};

	template<class C>
	constexpr list_iterator<C>::list_iterator(node_ptr ptr) : list_const_iterator<C>(ptr)
	{ }

	template<class C>
	constexpr typename list_iterator<C>::reference_type
		list_iterator<C>::operator[](const size_t& offset) const
	{
		return const_cast<reference_type>(base_class::operator[](offset));
	}

	template<class C>
	constexpr typename list_iterator<C>::reference_type
		list_iterator<C>::operator*() const
	{
		return const_cast<reference_type>(base_class::operator*());
	}

	template<class C>
	constexpr typename list_iterator<C>::pointer_type
		list_iterator<C>::operator->() const
	{
		return this->m_Ptr;
	}

	template<class C>
	constexpr list_iterator<C>&
		list_iterator<C>::operator++()
	{
		base_class::operator++();
		return *this;
	}

	template<class C>
	constexpr list_iterator<C>&
		list_iterator<C>::operator+=(const size_t& offset)
	{
		base_class::operator+=(offset);
		return *this;
	}

	template<class C>
	constexpr list_iterator<C>
		list_iterator<C>::operator+(const size_t& offset) const
	{
		list_iterator it = *this;
		it += offset;
		return it;
	}

	template<class C>
	constexpr list_iterator<C>
		list_iterator<C>::operator++(int)
	{
		list_iterator it = *this;
		base_class::operator++();
		return it;
	}

	template<class C>
	constexpr list_iterator<C>&
		list_iterator<C>::operator--()
	{
		base_class::operator--();
		return *this;
	}

	template<class C>
	constexpr list_iterator<C>
		list_iterator<C>::operator--(int)
	{
		list_iterator it = *this;
		base_class::operator--();
		return it;
	}

	template<class C>
	constexpr list_iterator<C>&
		list_iterator<C>::operator-=(const size_t& offset)
	{
		base_class::operator-=(offset);
		return *this;
	}

	template<class C>
	constexpr list_iterator<C>&
		list_iterator<C>::operator-(const size_t& offset) const
	{
		list_iterator it = *this;
		it -= offset;
		return *this;
	}
}

// list_const_reverse_iterator
namespace mystl
{
	template<class C>
	class list_const_reverse_iterator
	{
	// typedefs
	public:
		using		value_type						= typename C::value_type;
		using		const_pointer_type				= const value_type*;
		using		const_reference_type			= const value_type&;

		using		const_node_ptr					= const node<value_type>*;

	// constructors
	public:
		constexpr									list_const_reverse_iterator(const_node_ptr ptr);
													~list_const_reverse_iterator() = default;

	// element access
	public:
		constexpr	const_reference_type			operator[](const size_t& offset) const;
		constexpr	const_reference_type			operator*() const;
		constexpr	const_pointer_type				operator->() const;

	// modifier functions: increment
	public:
		constexpr	list_const_reverse_iterator&	operator++();
		constexpr	list_const_reverse_iterator		operator++(int);

		constexpr	list_const_reverse_iterator&	operator+=(const size_t& offset);
		constexpr	list_const_reverse_iterator&	operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		constexpr	list_const_reverse_iterator&	operator--();
		constexpr	list_const_reverse_iterator		operator--(int);

		constexpr	list_const_reverse_iterator&	operator-=(const size_t& offset);
		constexpr	list_const_reverse_iterator&	operator-(const size_t& offset) const;

	// equality operators
	public:
		constexpr	bool						operator==(const list_const_reverse_iterator& other) const;
		constexpr	bool						operator!=(const list_const_reverse_iterator& other) const;

	// variables
	protected:
					const_node_ptr				m_Ptr = nullptr;
	};

	template<class C>
	constexpr list_const_reverse_iterator<C>::list_const_reverse_iterator(const_node_ptr ptr) : m_Ptr(ptr)
	{ }

	template<class C>
	constexpr typename list_const_reverse_iterator<C>::const_reference_type
		list_const_reverse_iterator<C>::operator[](const size_t& offset) const
	{
		for (size_t i = 0; i < offset; i++)
		{
			m_Ptr = m_Ptr->prev;
		}
		return m_Ptr->data;
	}

	template<class C>
	constexpr typename list_const_reverse_iterator<C>::const_reference_type
		list_const_reverse_iterator<C>::operator*() const
	{
		return m_Ptr->data;
	}

	template<class C>
	constexpr typename list_const_reverse_iterator<C>::const_pointer_type
		list_const_reverse_iterator<C>::operator->() const
	{
		return m_Ptr;
	}

	template<class C>
	constexpr list_const_reverse_iterator<C>&
		list_const_reverse_iterator<C>::operator++()
	{
		m_Ptr = m_Ptr->prev;
		return *this;
	}

	template<class C>
	constexpr list_const_reverse_iterator<C>
		list_const_reverse_iterator<C>::operator++(int)
	{
		list_const_reverse_iterator it = *this;
		++(*this);
		return it;
	}

	template<class C>
	constexpr list_const_reverse_iterator<C>&
		list_const_reverse_iterator<C>::operator+=(const size_t& offset)
	{
		for (size_t i = 0; i < offset; i++)
		{
			m_Ptr = m_Ptr->prev;
		}
		return *this;
	}

	template<class C>
	constexpr list_const_reverse_iterator<C>&
		list_const_reverse_iterator<C>::operator+(const size_t& offset) const
	{
		list_const_reverse_iterator it = *this;
		it += offset;
		return *this;
	}

	template<class C>
	constexpr list_const_reverse_iterator<C>&
		list_const_reverse_iterator<C>::operator--()
	{
		m_Ptr = m_Ptr->next;
		return *this;
	}

	template<class C>
	constexpr list_const_reverse_iterator<C>
		list_const_reverse_iterator<C>::operator--(int)
	{
		list_const_reverse_iterator it = *this;
		--(*this);
		return it;
	}

	template<class C>
	constexpr list_const_reverse_iterator<C>&
		list_const_reverse_iterator<C>::operator-=(const size_t& offset)
	{
		for (size_t i = 0; i < offset; i++)
		{
			m_Ptr = m_Ptr->next;
		}
		return *this;
	}

	template<class C>
	constexpr list_const_reverse_iterator<C>&
		list_const_reverse_iterator<C>::operator-(const size_t& offset) const
	{
		list_const_reverse_iterator it = *this;
		it -= offset;
		return it;
	}

	template<class C>
	constexpr bool
		list_const_reverse_iterator<C>::operator==(const list_const_reverse_iterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	template<class C>
	constexpr bool
		list_const_reverse_iterator<C>::operator!=(const list_const_reverse_iterator& other) const
	{
		return !(*this == other);
	}
}

// reverse_iterator
namespace mystl
{
	template<class C>
	class list_reverse_iterator : public list_const_reverse_iterator<C>
	{
	// base class typedef
	public:
		using		base_class				= list_const_reverse_iterator<C>;

	// typedefs
	public:
		using		value_type				= typename C::value_type;
		using		pointer_type			= value_type*;
		using		reference_type			= value_type&;

		using		node_ptr				= node<value_type>*;

	// constructors
	public:
		constexpr							list_reverse_iterator(pointer_type ptr);
											~list_reverse_iterator() = default;

	// element access
	public:
		constexpr	reference_type			operator[](const size_t& offset) const;
		constexpr	reference_type			operator*() const;
		constexpr	pointer_type			operator->() const;

	// modifier functions: increment
	public:
		constexpr	list_reverse_iterator&	operator++();
		constexpr	list_reverse_iterator	operator++(int);

		constexpr	list_reverse_iterator&	operator+=(const size_t& offset);
		constexpr	list_reverse_iterator	operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		constexpr	list_reverse_iterator&	operator--();
		constexpr	list_reverse_iterator	operator--(int);

		constexpr	list_reverse_iterator&	operator-=(const size_t& offset);
		constexpr	list_reverse_iterator&	operator-(const size_t& offset) const;
	};

	template<class C>
	constexpr list_reverse_iterator<C>::list_reverse_iterator(pointer_type ptr) : list_const_reverse_iterator<C>(ptr)
	{ }

	template<class C>
	constexpr typename list_reverse_iterator<C>::reference_type
		list_reverse_iterator<C>::operator[](const size_t& offset) const
	{
		return const_cast<reference_type>(base_class::operator[](offset));
	}

	template<class C>
	constexpr typename list_reverse_iterator<C>::reference_type
		list_reverse_iterator<C>::operator*() const
	{
		return const_cast<reference_type>(base_class::operator*());
	}

	template<class C>
	constexpr typename list_reverse_iterator<C>::pointer_type
		list_reverse_iterator<C>::operator->() const
	{
		return this->m_Ptr;
	}

	template<class C>
	constexpr list_reverse_iterator<C>&
		list_reverse_iterator<C>::operator++()
	{
		base_class::operator++();
		return *this;
	}

	template<class C>
	constexpr list_reverse_iterator<C>
		list_reverse_iterator<C>::operator++(int)
	{
		list_reverse_iterator it = *this;
		base_class::operator++();
		return it;
	}

	template<class C>
	constexpr list_reverse_iterator<C>&
		list_reverse_iterator<C>::operator+=(const size_t& offset)
	{
		base_class::operator+=(offset);
		return *this;
	}

	template<class C>
	constexpr list_reverse_iterator<C>
		list_reverse_iterator<C>::operator+(const size_t& offset) const
	{
		list_reverse_iterator it = *this;
		it += offset;
		return it;
	}

	template<class C>
	constexpr list_reverse_iterator<C>&
		list_reverse_iterator<C>::operator--()
	{
		base_class::operator--();
		return *this;
	}

	template<class C>
	constexpr list_reverse_iterator<C>
		list_reverse_iterator<C>::operator--(int)
	{
		list_reverse_iterator it = *this;
		base_class::operator--();
		return it;
	}

	template<class C>
	constexpr list_reverse_iterator<C>&
		list_reverse_iterator<C>::operator-=(const size_t& offset)
	{
		base_class::operator-=(offset);
		return *this;
	}

	template<class C>
	constexpr list_reverse_iterator<C>&
		list_reverse_iterator<C>::operator-(const size_t& offset) const
	{
		list_reverse_iterator it = *this;
		it -= offset;
		return *this;
	}
}

namespace mystl
{
	template<typename T>
	class list
	{
	// typedefs
	public:
		using		value_type = T;

		using		reference_type = value_type&;
		using		pointer_type = value_type*;

		using		node = node<T>;
		using		node_ptr = node*;

		using		const_reference_type = const value_type&;
		using		const_pointer_type = const value_type*;

		using		const_iterator = list_const_iterator<list<T>>;
		using		iterator = list_iterator<list<T>>;

		using		const_reverse_iterator = list_const_reverse_iterator<const_iterator>;
		using		reverse_iterator = list_reverse_iterator<iterator>;

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

	// access functions
	public:
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

		constexpr	void					pop_front();
		constexpr	void					pop_back();

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
	constexpr void list<T>::pop_front()
	{
		if (!m_Head)
		{
			return;
		}

		node_ptr temp = m_Head;
		m_Head = m_Head->next;

		delete temp;
		m_Size--;
	}

	template<typename T>
	constexpr void list<T>::pop_back()
	{
		if (!m_Head)
		{
			return;
		}

		node_ptr temp = m_Tail;
		m_Tail = m_Tail->prev;
		m_Tail->next = nullptr;

		delete temp;
		m_Size--;
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

	// iterator functions will be implemented when i stop being lazy and refactor the iterator
	// class to be a base class that can be used for inheritance to override the ++/-- and +/-
	// functions.
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