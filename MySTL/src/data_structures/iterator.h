#ifndef ITERATOR_H
#define ITERATOR_H

///////////////////////////////////////////////////////////////////////////////////////
/// iterator class																	///
///																					///
/// This class is a templated iterator class meant to mimic the C++					///
/// STL iterators. The iterators take in a class/type. Note that there is no		///
/// error/bounds checking. There are four iterators that are implemented: const,	///
/// mutable, const reverse, mutable reverse.										///
///																					///
///////////////////////////////////////////////////////////////////////////////////////
// const_iterator			(19  - 221) ///
// iterator					(220 - 363) ///
// const_reverse_iterator	(366 - 558) ///
// reverse_iterator			(561 - 697) ///
///////////////////////////////////////////

// const_iterator			(19 - 221)
namespace mystl
{	
	template<class C>
	class const_iterator
	{
	// typedefs
	public:
		using		value_type				= typename C::value_type;
		using		const_pointer_type		= const value_type*;
		using		const_reference_type	= const value_type&;
		using		ptrdiff_t				= int;

	// constructors
	public:
		constexpr							const_iterator(const_pointer_type ptr);
											~const_iterator() = default;

	// element access
	public:
		constexpr	const_reference_type	operator[](const size_t& offset) const;
		constexpr	const_reference_type	operator*() const;
		constexpr	const_pointer_type		operator->() const;

	// modifier functions: increment
	public:
		constexpr	const_iterator&			operator++();
		constexpr	const_iterator			operator++(int);

		constexpr	const_iterator&			operator+=(const size_t& offset);
		constexpr	const_iterator&			operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		constexpr	const_iterator&			operator--();
		constexpr	const_iterator			operator--(int);

		constexpr	const_iterator&			operator-=(const size_t& offset);
		constexpr	const_iterator&			operator-(const size_t& offset) const;

	// pointer difference
	public:
		constexpr	ptrdiff_t				operator-(const const_iterator& other) const;

	// equality operators
	public:
		constexpr	bool					operator==(const const_iterator& other) const;
		constexpr	bool					operator!=(const const_iterator& other) const;
		constexpr	bool					operator<(const const_iterator& other) const;
		constexpr	bool					operator>(const const_iterator& other) const;
		constexpr	bool					operator<=(const const_iterator& other) const;
		constexpr	bool					operator>=(const const_iterator& other) const;

	// variables
	protected:
					const_pointer_type		m_Ptr = nullptr;
	};

	template<class C>
	constexpr const_iterator<C>::const_iterator(const_pointer_type ptr) : m_Ptr(ptr)
	{ }
	
	template<class C>
	constexpr typename const_iterator<C>::const_reference_type 
		const_iterator<C>::operator[](const size_t& offset) const
	{
		return *(m_Ptr + offset);
	}

	template<class C>
	constexpr typename const_iterator<C>::const_reference_type 
		const_iterator<C>::operator*() const
	{
		return *m_Ptr;
	}

	template<class C>
	constexpr typename const_iterator<C>::const_pointer_type 
		const_iterator<C>::operator->() const
	{
		return m_Ptr;
	}

	template<class C>
	constexpr const_iterator<C>& 
		const_iterator<C>::operator++()
	{
		m_Ptr++;
		return *this;
	}

	template<class C>
	constexpr const_iterator<C> 
		const_iterator<C>::operator++(int)
	{
		const_iterator it = *this;
		++(*this);
		return it;
	}

	template<class C>
	constexpr const_iterator<C>&
		const_iterator<C>::operator+=(const size_t& offset)
	{
		m_Ptr += offset;
		return *this;
	}

	template<class C>
	constexpr const_iterator<C>&
		const_iterator<C>::operator+(const size_t& offset) const
	{
		const_iterator it = *this;
		it += offset;
		return *this;
	}

	template<class C>
	constexpr const_iterator<C>& 
		const_iterator<C>::operator--()
	{
		m_Ptr--;
		return *this;
	}

	template<class C>
	constexpr const_iterator<C>
		const_iterator<C>::operator--(int)
	{
		const_iterator it = *this;
		--(*this);
		return it;
	}

	template<class C>
	constexpr const_iterator<C>&
		const_iterator<C>::operator-=(const size_t& offset)
	{
		return *this += -offset;
	}

	template<class C>
	constexpr const_iterator<C>& 
		const_iterator<C>::operator-(const size_t& offset) const
	{
		const_iterator it = *this;
		it -= offset;
		return it;
	}

	template<class C>
	constexpr typename const_iterator<C>::ptrdiff_t 
		const_iterator<C>::operator-(const const_iterator& other) const
	{
		return m_Ptr - other.m_Ptr;
	}

	template<class C>
	constexpr bool 
		const_iterator<C>::operator==(const const_iterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	template<class C>
	constexpr bool 
		const_iterator<C>::operator!=(const const_iterator& other) const
	{
		return !(*this == other);
	}

	template<class C>
	constexpr bool 
		const_iterator<C>::operator<(const const_iterator& other) const
	{
		return m_Ptr < other.m_Ptr;
	}

	template<class C>
	constexpr bool 
		const_iterator<C>::operator>(const const_iterator& other) const
	{
		return other < *this;
	}

	template<class C>
	constexpr bool 
		const_iterator<C>::operator<=(const const_iterator& other) const
	{
		return !(other < *this);
	}

	template<class C>
	constexpr bool 
		const_iterator<C>::operator>=(const const_iterator& other) const
	{
		return !(*this < other);
	}
}

// iterator					(220 - 363)
namespace mystl
{
	template<class C>
	class iterator : public const_iterator<C>
	{
	// base class typedef
	public:
		using		base_class		= const_iterator<C>;

	// typedefs
	public:
		using		value_type		= typename C::value_type;
		using		pointer_type	= value_type*;
		using		reference_type	= value_type&;
		using		ptrdiff_t		= int;

	// constructors
	public:
		constexpr					iterator(pointer_type ptr);
									~iterator() = default;

	// element access
	public:
		constexpr	reference_type	operator[](const size_t& offset) const;
		constexpr	reference_type	operator*() const;
		constexpr	pointer_type	operator->() const;

	// modifier functions: increment
	public:
		 constexpr	iterator&		operator++();
		 constexpr	iterator		operator++(int);
		 constexpr	iterator&		operator+=(const size_t& offset);
		 constexpr	iterator		operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		 constexpr	iterator&		operator--();
		 constexpr	iterator		operator--(int);

		 constexpr	iterator&		operator-=(const size_t& offset);
		 constexpr	iterator&		operator-(const size_t& offset) const;
		 constexpr	ptrdiff_t		operator-(const iterator& other) const;
	};

	template<class C>
	constexpr iterator<C>::iterator(pointer_type ptr) : const_iterator<C>(ptr)
	{ }

	template<class C>
	constexpr typename iterator<C>::reference_type 
		iterator<C>::operator[](const size_t& offset) const
	{
		return const_cast<reference_type>(base_class::operator[](offset));
	}

	template<class C>
	constexpr typename iterator<C>::reference_type 
		iterator<C>::operator*() const
	{
		return const_cast<reference_type>(base_class::operator*());
	}

	template<class C>
	constexpr typename iterator<C>::pointer_type 
		iterator<C>::operator->() const
	{
		return this->m_Ptr;
	}

	template<class C>
	constexpr iterator<C>& 
		iterator<C>::operator++()
	{
		base_class::operator++();
		return *this;
	}

	template<class C>
	constexpr iterator<C>& 
		iterator<C>::operator+=(const size_t& offset)
	{
		base_class::operator+=(offset);
		return *this;
	}

	template<class C>
	constexpr iterator<C> 
		iterator<C>::operator+(const size_t& offset) const
	{
		iterator it = *this;
		it += offset;
		return it;
	}

	template<class C>
	constexpr iterator<C> 
		iterator<C>::operator++(int)
	{
		iterator it = *this;
		base_class::operator++();
		return it;
	}

	template<class C>
	constexpr iterator<C>& 
		iterator<C>::operator--()
	{
		base_class::operator--();
		return *this;
	}

	template<class C>
	constexpr iterator<C> 
		iterator<C>::operator--(int)
	{
		iterator it = *this;
		base_class::operator--();
		return it;
	}

	template<class C>
	constexpr iterator<C>& 
		iterator<C>::operator-=(const size_t& offset)
	{
		base_class::operator-=(offset);
		return *this;
	}

	template<class C>
	constexpr iterator<C>& 
		iterator<C>::operator-(const size_t& offset) const
	{
		iterator it = *this;
		it -= offset;
		return *this;
	}

	template<class C>
	constexpr ptrdiff_t 
		iterator<C>::operator-(const iterator& other) const
	{
		return this->m_Ptr - other.m_Ptr;
	}
}

// const_reverse_iterator	(366 - 558)
namespace mystl
{
	template<class C>
	class const_reverse_iterator
	{
	// typedefs
	public:
		using		value_type					= typename C::value_type;
		using		const_pointer_type			= const value_type*;
		using		const_reference_type		= const value_type&;
		using		ptrdiff_t					= int;

	// constructors
	public:
		constexpr								const_reverse_iterator(const_pointer_type ptr);
		constexpr								const_reverse_iterator(const_pointer_type& ptr);
												~const_reverse_iterator() = default;

	// element access
	public:
		constexpr	const_reference_type		operator[](const size_t& offset) const;
		constexpr	const_reference_type		operator*() const;
		constexpr	const_pointer_type			operator->() const;

	// modifier functions: increment
	public:
		constexpr	const_reverse_iterator&		operator++();
		constexpr	const_reverse_iterator		operator++(int);

		constexpr	const_reverse_iterator&		operator+=(const size_t& offset);
		constexpr	const_reverse_iterator&		operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		constexpr	const_reverse_iterator&		operator--();
		constexpr	const_reverse_iterator		operator--(int);

		constexpr	const_reverse_iterator&		operator-=(const size_t& offset);
		constexpr	const_reverse_iterator&		operator-(const size_t& offset) const;

	// equality operators
	public:
		constexpr	bool						operator==(const const_reverse_iterator& other) const;
		constexpr	bool						operator!=(const const_reverse_iterator& other) const;
		constexpr	bool						operator<(const const_reverse_iterator& other) const;
		constexpr	bool						operator>(const const_reverse_iterator& other) const;
		constexpr	bool						operator<=(const const_reverse_iterator& other) const;
		constexpr	bool						operator>=(const const_reverse_iterator& other) const;

	// variables
	protected:
					const_pointer_type			m_Ptr = nullptr;
	};

	template<class C>
	constexpr const_reverse_iterator<C>::const_reverse_iterator(const_pointer_type ptr) : m_Ptr(ptr)
	{ }

	template<class C>
	constexpr const_reverse_iterator<C>::const_reverse_iterator(const_pointer_type& ptr) : m_Ptr(ptr)
	{ }

	template<class C>
	constexpr typename const_reverse_iterator<C>::const_reference_type 
		const_reverse_iterator<C>::operator[](const size_t& offset) const
	{
		return *(m_Ptr - offset);
	}

	template<class C>
	constexpr typename const_reverse_iterator<C>::const_reference_type 
		const_reverse_iterator<C>::operator*() const
	{
		return *m_Ptr;
	}

	template<class C>
	constexpr typename const_reverse_iterator<C>::const_pointer_type 
		const_reverse_iterator<C>::operator->() const
	{
		return m_Ptr;
	}

	template<class C>
	constexpr const_reverse_iterator<C>& 
		const_reverse_iterator<C>::operator++()
	{
		m_Ptr--;
		return *this;
	}

	template<class C>
	constexpr const_reverse_iterator<C>
		const_reverse_iterator<C>::operator++(int)
	{
		const_reverse_iterator it = *this;
		--(*this);
		return it;
	}

	template<class C>
	constexpr const_reverse_iterator<C>& 
		const_reverse_iterator<C>::operator+=(const size_t& offset)
	{
		m_Ptr -= offset;
		return *this;
	}

	template<class C>
	constexpr const_reverse_iterator<C>& 
		const_reverse_iterator<C>::operator+(const size_t& offset) const
	{
		const_reverse_iterator it = *this;
		it -= offset;
		return *this;
	}

	template<class C>
	constexpr const_reverse_iterator<C>& 
		const_reverse_iterator<C>::operator--()
	{
		m_Ptr++;
		return *this;
	}


	template<class C>
	constexpr const_reverse_iterator<C>& 
		const_reverse_iterator<C>::operator-=(const size_t& offset)
	{
		return *this += offset;
	}

	template<class C>
	constexpr const_reverse_iterator<C>& 
		const_reverse_iterator<C>::operator-(const size_t& offset) const
	{
		const_reverse_iterator it = *this;
		it += offset;
		return it;
	}

	template<class C>
	constexpr const_reverse_iterator<C> 
		const_reverse_iterator<C>::operator--(int)
	{
		const_reverse_iterator it = *this;
		++(*this);
		return it;
	}

	template<class C>
	constexpr bool 
		const_reverse_iterator<C>::operator==(const const_reverse_iterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	template<class C>
	constexpr bool 
		const_reverse_iterator<C>::operator!=(const const_reverse_iterator& other) const
	{
		return !(*this == other);
	}

	template<class C>
	constexpr bool 
		const_reverse_iterator<C>::operator<(const const_reverse_iterator& other) const
	{
		return other.m_Ptr < m_Ptr;
	}

	template<class C>
	constexpr bool 
		const_reverse_iterator<C>::operator>(const const_reverse_iterator& other) const
	{
		return *this < other;
	}

	template<class C>
	constexpr bool 
		const_reverse_iterator<C>::operator<=(const const_reverse_iterator& other) const
	{
		return !(*this< other);
	}

	template<class C>
	constexpr bool 
		const_reverse_iterator<C>::operator>=(const const_reverse_iterator& other) const
	{
		return !(other < *this);
	}
}

// reverse_iterator			(561 - 697)
namespace mystl
{
	template<class C>
	class reverse_iterator : public const_reverse_iterator<C>
	{
	// base class typedef
	public:
		using	base_class = const_reverse_iterator<C>;

	// typedefs
	public:
		using		value_type			= typename C::value_type;
		using		pointer_type		= value_type*;
		using		reference_type		= value_type&;
		using		ptrdiff_t			= int;

	// constructors
	public:
		constexpr						reverse_iterator(pointer_type ptr);
										~reverse_iterator() = default;

	// element access
	public:
		constexpr	reference_type		operator[](const size_t& offset) const;
		constexpr	reference_type		operator*() const;
		constexpr	pointer_type		operator->() const;

	// modifier functions: increment
	public:
		constexpr	reverse_iterator&	operator++();
		constexpr	reverse_iterator	operator++(int);

		constexpr	reverse_iterator&	operator+=(const size_t& offset);
		constexpr	reverse_iterator	operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		constexpr	reverse_iterator&	operator--();
		constexpr	reverse_iterator	operator--(int);

		constexpr	reverse_iterator&	operator-=(const size_t& offset);
		constexpr	reverse_iterator&	operator-(const size_t& offset) const;
	};

	template<class C>
	constexpr reverse_iterator<C>::reverse_iterator(pointer_type ptr) : const_reverse_iterator<C>(ptr)
	{ }

	template<class C>
	constexpr typename reverse_iterator<C>::reference_type 
		reverse_iterator<C>::operator[](const size_t& offset) const
	{
		return const_cast<reference_type>(base_class::operator[](offset));
	}

	template<class C>
	constexpr typename reverse_iterator<C>::reference_type 
		reverse_iterator<C>::operator*() const
	{
		return const_cast<reference_type>(base_class::operator*());
	}

	template<class C>
	constexpr typename reverse_iterator<C>::pointer_type 
		reverse_iterator<C>::operator->() const
	{
		return this->m_Ptr;
	}

	template<class C>
	constexpr reverse_iterator<C>& 
		reverse_iterator<C>::operator++()
	{
		base_class::operator++();
		return *this;
	}

	template<class C>
	constexpr reverse_iterator<C>
		reverse_iterator<C>::operator++(int)
	{
		reverse_iterator it = *this;
		base_class::operator++();
		return it;
	}

	template<class C>
	constexpr reverse_iterator<C>& 
		reverse_iterator<C>::operator+=(const size_t& offset)
	{
		base_class::operator+=(offset);
		return *this;
	}

	template<class C>
	constexpr reverse_iterator<C> 
		reverse_iterator<C>::operator+(const size_t& offset) const
	{
		reverse_iterator it = *this;
		it -= offset;
		return it;
	}

	template<class C>
	constexpr reverse_iterator<C>& 
		reverse_iterator<C>::operator--()
	{
		base_class::operator--();
		return *this;
	}

	template<class C>
	constexpr reverse_iterator<C> 
		reverse_iterator<C>::operator--(int)
	{
		reverse_iterator it = *this;
		base_class::operator--();
		return it;
	}

	template<class C>
	constexpr reverse_iterator<C>& 
		reverse_iterator<C>::operator-=(const size_t& offset)
	{
		base_class::operator-=(offset);
		return *this;
	}

	template<class C>
	constexpr reverse_iterator<C>& 
		reverse_iterator<C>::operator-(const size_t& offset) const
	{
		reverse_iterator it = *this;
		it += offset;
		return *this;
	}
}

#endif