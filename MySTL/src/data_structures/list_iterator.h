#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "node.h"

///////////////////////////////////////////////////////////////////////////////////////
/// list_iterator class																///
///																					///
/// This class is a templated list iterator class meant to mimic the C++			///
/// STL list iterators. The iterators take in a class/type. Note that there is no	///
/// error/bounds checking. There are four iterators that are implemented: const,	///
/// mutable, const reverse, mutable reverse.										///
///																					///
///////////////////////////////////////////////////////////////////////////////////////

// list_const_iterator
namespace mystl
{
	template<class C>
	class list_const_iterator
	{
		// typedefs
	public:
		using		value_type = typename C::value_type;
		using		const_pointer_type = const value_type*;
		using		const_reference_type = const value_type&;

		using		const_node_ptr = const node<value_type>*;

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
		constexpr	list_const_iterator& operator++();
		constexpr	list_const_iterator		operator++(int);

		constexpr	list_const_iterator& operator+=(const size_t& offset);
		constexpr	list_const_iterator& operator+(const size_t& offset) const;

		// modifier functions: decrement
	public:
		constexpr	list_const_iterator& operator--();
		constexpr	list_const_iterator		operator--(int);

		constexpr	list_const_iterator& operator-=(const size_t& offset);
		constexpr	list_const_iterator& operator-(const size_t& offset) const;

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
		using		value_type = typename C::value_type;
		using		pointer_type = value_type*;
		using		reference_type = value_type&;

		using		node_ptr = node<value_type>*;

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
		constexpr	list_iterator& operator++();
		constexpr	list_iterator	operator++(int);
		constexpr	list_iterator& operator+=(const size_t& offset);
		constexpr	list_iterator	operator+(const size_t& offset) const;

		// modifier functions: decrement
	public:
		constexpr	list_iterator& operator--();
		constexpr	list_iterator	operator--(int);

		constexpr	list_iterator& operator-=(const size_t& offset);
		constexpr	list_iterator& operator-(const size_t& offset) const;
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
		using		value_type = typename C::value_type;
		using		const_pointer_type = const value_type*;
		using		const_reference_type = const value_type&;

		using		const_node_ptr = const node<value_type>*;

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
		constexpr	list_const_reverse_iterator& operator++();
		constexpr	list_const_reverse_iterator		operator++(int);

		constexpr	list_const_reverse_iterator& operator+=(const size_t& offset);
		constexpr	list_const_reverse_iterator& operator+(const size_t& offset) const;

		// modifier functions: decrement
	public:
		constexpr	list_const_reverse_iterator& operator--();
		constexpr	list_const_reverse_iterator		operator--(int);

		constexpr	list_const_reverse_iterator& operator-=(const size_t& offset);
		constexpr	list_const_reverse_iterator& operator-(const size_t& offset) const;

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
		using		base_class = list_const_reverse_iterator<C>;

		// typedefs
	public:
		using		value_type = typename C::value_type;
		using		pointer_type = value_type*;
		using		reference_type = value_type&;

		using		node_ptr = node<value_type>*;

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
		constexpr	list_reverse_iterator& operator++();
		constexpr	list_reverse_iterator	operator++(int);

		constexpr	list_reverse_iterator& operator+=(const size_t& offset);
		constexpr	list_reverse_iterator	operator+(const size_t& offset) const;

		// modifier functions: decrement
	public:
		constexpr	list_reverse_iterator& operator--();
		constexpr	list_reverse_iterator	operator--(int);

		constexpr	list_reverse_iterator& operator-=(const size_t& offset);
		constexpr	list_reverse_iterator& operator-(const size_t& offset) const;
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

#endif
