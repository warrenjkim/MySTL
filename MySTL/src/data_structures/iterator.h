#ifndef ITERATOR_H
#define ITERATOR_H

#define CONSTEXPR inline constexpr

#include <vector>

// TODO: rearrange pre/postfix increment functions
//		 document line numbers.
namespace mystl
{
	///////////////////////////////////////////////////////////////////////////////////////
	/// const_iterator
	/// 
	/// This class is a templated const_iterator class meant to mimic the C++
	/// STL const_iterator. The const_iterator takes in a type. Note that there is no 
	/// error/bounds checking.
	/// 
	///////////////////////////////////////////////////////////////////////////////////////
	
	template<class C>
	class const_iterator
	{
	// typedefs
	public:
		using value_type = typename C::value_type;
		using const_pointer_type = const value_type*;
		using const_reference_type = const value_type&;
		using ptrdiff_t = int;

	// constructors
	public:
		CONSTEXPR const_iterator(const_pointer_type ptr);
		CONSTEXPR const_iterator(const_pointer_type& ptr);
		~const_iterator() = default;

	// element access
	public:
		 CONSTEXPR const_reference_type operator[](const size_t& offset) const;
		CONSTEXPR const_reference_type operator*() const;
		CONSTEXPR const_pointer_type operator->() const;

	// modifier functions: increment
	public:
		 CONSTEXPR const_iterator& operator++();
		 CONSTEXPR const_iterator operator++(int);

		 CONSTEXPR const_iterator& operator+=(const size_t& offset);
		 CONSTEXPR const_iterator& operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		 CONSTEXPR const_iterator& operator--();
		 CONSTEXPR const_iterator operator--(int);

		 CONSTEXPR const_iterator& operator-=(const size_t& offset);
		 CONSTEXPR const_iterator& operator-(const size_t& offset) const;
	
	// pointer difference
	public:
		 CONSTEXPR ptrdiff_t operator-(const const_iterator& other) const;

	// equality operators
	public:
		CONSTEXPR bool operator==(const const_iterator& other) const;
		CONSTEXPR bool operator!=(const const_iterator& other) const;
		CONSTEXPR bool operator<(const const_iterator& other) const;
		CONSTEXPR bool operator>(const const_iterator& other) const;
		CONSTEXPR bool operator<=(const const_iterator& other) const;
		CONSTEXPR bool operator>=(const const_iterator& other) const;

	// variables
	protected:
		const_pointer_type m_Ptr = nullptr;
	};

	template<class C>
	CONSTEXPR const_iterator<C>::const_iterator(const_pointer_type ptr) : m_Ptr(ptr)
	{ }
	
	template<class C>
	CONSTEXPR const_iterator<C>::const_iterator(const_pointer_type& ptr) : m_Ptr(ptr)
	{ }
	
	template<class C>
	CONSTEXPR typename const_iterator<C>::const_reference_type const_iterator<C>::operator[](const size_t& offset) const
	{
		return *(m_Ptr + offset);
	}

	template<class C>
	CONSTEXPR typename const_iterator<C>::const_reference_type const_iterator<C>::operator*() const
	{
		return *m_Ptr;
	}

	template<class C>
	CONSTEXPR typename const_iterator<C>::const_pointer_type const_iterator<C>::operator->() const
	{
		return m_Ptr;
	}

	template<class C>
	CONSTEXPR const_iterator<C>& const_iterator<C>::operator++()
	{
		m_Ptr++;
		return *this;
	}

	template<class C>
	CONSTEXPR const_iterator<C>& const_iterator<C>::operator+=(const size_t& offset)
	{
		m_Ptr += offset;
		return *this;
	}

	template<class C>
	CONSTEXPR const_iterator<C>& const_iterator<C>::operator+(const size_t& offset) const
	{
		const_iterator it = *this;
		it += offset;
		return *this;
	}

	template<class C>
	CONSTEXPR const_iterator<C> const_iterator<C>::operator++(int)
	{
		const_iterator it = *this;
		++(*this);
		return it;
	}

	template<class C>
	CONSTEXPR const_iterator<C>& const_iterator<C>::operator--()
	{
		m_Ptr--;
		return *this;
	}


	template<class C>
	CONSTEXPR const_iterator<C>& const_iterator<C>::operator-=(const size_t& offset)
	{
		return *this += -offset;
	}

	template<class C>
	CONSTEXPR const_iterator<C>& const_iterator<C>::operator-(const size_t& offset) const
	{
		const_iterator it = *this;
		it -= offset;
		return it;
	}

	template<class C>
	CONSTEXPR const_iterator<C> const_iterator<C>::operator--(int)
	{
		const_iterator it = *this;
		--(*this);
		return it;
	}

	template<class C>
	CONSTEXPR typename const_iterator<C>::ptrdiff_t const_iterator<C>::operator-(const const_iterator& other) const
	{
		return m_Ptr - other.m_Ptr;
	}

	template<class C>
	CONSTEXPR bool const_iterator<C>::operator==(const const_iterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	template<class C>
	CONSTEXPR bool const_iterator<C>::operator!=(const const_iterator& other) const
	{
		return !(*this == other);
	}

	template<class C>
	CONSTEXPR bool const_iterator<C>::operator<(const const_iterator& other) const
	{
		return m_Ptr < other.m_Ptr;
	}

	template<class C>
	CONSTEXPR bool const_iterator<C>::operator>(const const_iterator& other) const
	{
		return other < *this;
	}

	template<class C>
	CONSTEXPR bool const_iterator<C>::operator<=(const const_iterator& other) const
	{
		return !(other < *this);
	}

	template<class C>
	CONSTEXPR bool const_iterator<C>::operator>=(const const_iterator& other) const
	{
		return !(*this < other);
	}
}

namespace mystl
{
	template<class C>
	class iterator : public const_iterator<C>
	{
	// base class typedef
	public:
		using base_class = const_iterator<C>;

	// typedefs
	public:
		using value_type = typename C::value_type;
		using pointer_type = value_type*;
		using reference_type = value_type&;
		using ptrdiff_t = int;

	// constructors
	public:
		CONSTEXPR iterator(pointer_type ptr);
		~iterator() = default;

	// element access
	public:
		CONSTEXPR reference_type operator[](const size_t& offset) const;
		CONSTEXPR reference_type operator*() const;
		CONSTEXPR pointer_type operator->() const;

	// modifier functions: increment
	public:
		 CONSTEXPR iterator& operator++();
		 CONSTEXPR iterator operator++(int);
		 CONSTEXPR iterator& operator+=(const size_t& offset);
		 CONSTEXPR iterator operator+(const size_t& offset) const;

	// modifier functions: decrement
	public:
		 CONSTEXPR iterator& operator--();
		 CONSTEXPR iterator operator--(int);

		 CONSTEXPR iterator& operator-=(const size_t& offset);
		 CONSTEXPR iterator& operator-(const size_t& offset) const;
		 CONSTEXPR ptrdiff_t operator-(const iterator& other) const;

	// variables
	private:
		//pointer_type m_Ptr = nullptr;
	};

	template<class C>
	CONSTEXPR iterator<C>::iterator(pointer_type ptr) : const_iterator<C>(ptr)
	{

	}

	template<class C>
	CONSTEXPR typename iterator<C>::reference_type iterator<C>::operator[](const size_t& offset) const
	{
		return const_cast<reference_type>(base_class::operator[](offset));
	}

	template<class C>
	CONSTEXPR typename iterator<C>::reference_type iterator<C>::operator*() const
	{
		return const_cast<reference_type>(base_class::operator*());
	}

	template<class C>
	CONSTEXPR typename iterator<C>::pointer_type iterator<C>::operator->() const
	{
		return this->m_Ptr;
	}

	template<class C>
	CONSTEXPR iterator<C>& iterator<C>::operator++()
	{
		base_class::operator++();
		return *this;
	}

	template<class C>
	CONSTEXPR iterator<C>& iterator<C>::operator+=(const size_t& offset)
	{
		base_class::operator+=(offset);
		return *this;
	}

	template<class C>
	CONSTEXPR iterator<C> iterator<C>::operator+(const size_t& offset) const
	{
		iterator it = *this;
		it += offset;
		return it;
	}

	template<class C>
	CONSTEXPR iterator<C> iterator<C>::operator++(int)
	{
		iterator it = *this;
		base_class::operator++();
		return it;
	}

	template<class C>
	CONSTEXPR iterator<C>& iterator<C>::operator--()
	{
		base_class::operator--();
		return *this;
	}

	template<class C>
	CONSTEXPR iterator<C> iterator<C>::operator--(int)
	{
		iterator it = *this;
		base_class::operator--();
		return it;
	}

	template<class C>
	CONSTEXPR iterator<C>& iterator<C>::operator-=(const size_t& offset)
	{
		base_class::operator-=(offset);
		return *this;
	}

	template<class C>
	CONSTEXPR iterator<C>& iterator<C>::operator-(const size_t& offset) const
	{
		iterator it = *this;
		it -= offset;
		return *this;
	}

	template<class C>
	CONSTEXPR ptrdiff_t iterator<C>::operator-(const iterator& other) const
	{
		return this->m_Ptr - other.m_Ptr;
	}

	
}

/*

	template<typename T>
	class const_iterator
	{
	public:
		using				value_type				= typename T::value_type;
		using				const_pointer_type		= const value_type*;
		using				const_reference_type	= const value_type&;
		using				ptrdiff_t				= size_t;

	public:
		CONSTEXPR									const_iterator(const_pointer_type ptr);

	public:
		CONSTEXPR			const_reference_type	operator[](const size_t& offset);
		CONSTEXPR			const_reference_type	operator*();
		CONSTEXPR			const_pointer_type		operator->();


	public:
		 CONSTEXPR	const_iterator&			operator++();
		 CONSTEXPR	const_iterator&			operator+(const size_t& offset);
		 CONSTEXPR	const_iterator			operator++(int);

		 CONSTEXPR	const_iterator&			operator--();
		 CONSTEXPR	ptrdiff_t				operator-(const_iterator other);
		 CONSTEXPR	const_iterator&			operator-(const size_t& offset);
		 CONSTEXPR	const_iterator			operator--(int);



	public:
		CONSTEXPR	bool					operator==(const_iterator& other) const;
		CONSTEXPR	bool					operator!=(const_iterator& other) const;

	private:
					const_pointer_type		m_Ptr = nullptr;
	};

	template<typename T>
	CONSTEXPR const_iterator<T>::const_iterator(const_pointer_type ptr) : m_Ptr(ptr)
	{ }

	template<typename T>
	CONSTEXPR typename const_iterator<T>::const_reference_type
		const_iterator<T>::operator[](const size_t& offset)
	{
		return *(m_Ptr + offset);
	}

	template<typename T>
	CONSTEXPR typename const_iterator<T>::const_reference_type
		const_iterator<T>::operator*()
	{
		return *m_Ptr;
	}

	template<typename T>
	CONSTEXPR typename const_iterator<T>::const_pointer_type
		const_iterator<T>::operator->()
	{
		return m_Ptr;
	}

	template<typename T>
	CONSTEXPR const_iterator<T>& const_iterator<T>::operator++()
	{
		m_Ptr++;
		return *this;
	}

	template<typename T>
	CONSTEXPR const_iterator<T>& const_iterator<T>::operator+(const size_t& offset)
	{
		m_Ptr += offset;
		return *this;
	}

	template<typename T>
	CONSTEXPR const_iterator<T> const_iterator<T>::operator++(int)
	{
		const_iterator it = *this;
		++(*this);
		return it;
	}

	template<typename T>
	CONSTEXPR const_iterator<T>& const_iterator<T>::operator--()
	{
		m_Ptr--;
		return *this;
	}

	template<typename T>
	CONSTEXPR typename const_iterator<T>::ptrdiff_t const_iterator<T>::operator-(const_iterator other)
	{
		return m_Ptr - other.m_Ptr;
	}

	template<typename T>
	CONSTEXPR const_iterator<T>& const_iterator<T>::operator-(const size_t& offset)
	{
		m_Ptr -= offset;
		return *this;
	}

	template<typename T>
	CONSTEXPR const_iterator<T> const_iterator<T>::operator--(int)
	{
		const_iterator it = *this;
		--(*this);
		return it;
	}

	template<typename T>
	CONSTEXPR bool const_iterator<T>::operator==(const_iterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	template<typename T>
	CONSTEXPR bool const_iterator<T>::operator!=(const_iterator& other) const
	{
		return !(*this == other);
	}
	

namespace mystl
{
	
	///////////////////////////////////////////////////////////////////////////////////////
	/// iterator
	/// 
	/// This class is a templated iterator class meant to mimic the C++
	/// STL iterator. The iterator takes in a type. Note that there is no 
	/// error/bounds checking.
	/// 
	///////////////////////////////////////////////////////////////////////////////////////
	template<typename T>
	class iterator
	{
	public:
		using		value_type		= typename T::value_type;
		using		pointer_type	= value_type*;
		using		reference_type	= value_type&;
		using		ptrdiff_t		= int;

	public:
		CONSTEXPR					iterator(pointer_type ptr);

	public:
		CONSTEXPR	reference_type	operator[](const size_t& offset);
		CONSTEXPR	reference_type	operator*();
		CONSTEXPR	pointer_type	operator->();


	public:
		CONSTEXPR	iterator&		operator++();
		CONSTEXPR	iterator&		operator+(const size_t& offset);
		CONSTEXPR	iterator		operator++(int);
		
		CONSTEXPR	iterator&		operator--();
		CONSTEXPR	iterator&		operator-(const size_t& offset);
		CONSTEXPR	ptrdiff_t		operator-(iterator other);
		CONSTEXPR	iterator		operator--(int);


	public:
		CONSTEXPR	bool			operator==(const iterator& other) const;
		CONSTEXPR	bool			operator!=(const iterator& other) const;

	private:
					pointer_type	m_Ptr = nullptr;
	};

	template<typename T>
	CONSTEXPR iterator<T>::iterator(pointer_type ptr) : m_Ptr(ptr) { }

	template<typename T>
	CONSTEXPR typename iterator<T>::reference_type
		iterator<T>::operator[](const size_t& offset)
	{
		return *(m_Ptr + offset);
	}

	template<typename T>
	CONSTEXPR typename iterator<T>::reference_type
		iterator<T>::operator*()
	{
		return *m_Ptr;
	}

	template<typename T>
	CONSTEXPR typename iterator<T>::pointer_type
		iterator<T>::operator->()
	{
		return m_Ptr;
	}

	template<typename T>
	CONSTEXPR iterator<T>& iterator<T>::operator++()
	{
		m_Ptr++;
		return *this;
	}

	template<typename T>
	CONSTEXPR iterator<T>& iterator<T>::operator+(const size_t& offset)
	{
		m_Ptr += offset;
		return *this;
	}

	template<typename T>
	CONSTEXPR iterator<T> iterator<T>::operator++(int)
	{
		iterator it = *this;
		++(*this);
		return it;
	}

	template<typename T>
	CONSTEXPR iterator<T>& iterator<T>::operator-(const size_t& offset)
	{
		m_Ptr -= offset;
		return *this;
	}

	template<typename T>
	CONSTEXPR iterator<T>& iterator<T>::operator--()
	{
		m_Ptr--;
		return *this;
	}

	template<typename T>
	CONSTEXPR iterator<T> iterator<T>::operator--(int)
	{
		iterator it = *this;
		--(*this);
		return it;
	}

	template<typename T>
	CONSTEXPR typename iterator<T>::ptrdiff_t iterator<T>::operator-(iterator other)
	{
		return (m_Ptr - other.m_Ptr);
	}

	template<typename T>
	CONSTEXPR bool iterator<T>::operator==(const iterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	template<typename T>
	CONSTEXPR bool iterator<T>::operator!=(const iterator& other) const
	{
		return !(*this == other);
	}
}
*/
namespace mystl
{
	///////////////////////////////////////////////////////////////////////////////////////
	/// const_reverse_iterator
	/// 
	/// This class is a templated const_reverse_iterator class meant to mimic the C++
	/// STL const_reverse_iterator. The const_reverse_iterator takes in a type. 
	/// Note that there is no error/bounds checking.
	/// 
	///////////////////////////////////////////////////////////////////////////////////////
	template<typename T>
	class const_reverse_iterator
	{
	public:
		using		iterator_type = T;
		using		value_type				= typename T::value_type;
		using		const_pointer_type		= typename T::const_pointer_type;
		using		const_reference_type	= typename T::const_reference_type;

	public:
		CONSTEXPR							const_reverse_iterator(iterator_type ptr);

	public:
		CONSTEXPR	const_reference_type	operator[](const size_t& offset);
		CONSTEXPR	const_reference_type	operator*();
		CONSTEXPR	const_pointer_type		operator->();


	public:
		CONSTEXPR	const_reverse_iterator& operator++();
		CONSTEXPR	const_reverse_iterator& operator+(const size_t& offset);
		CONSTEXPR	const_reverse_iterator	operator++(int);
		
		CONSTEXPR	const_reverse_iterator& operator--();
		CONSTEXPR	const_reverse_iterator& operator-(const size_t& offset);
		CONSTEXPR	const_reverse_iterator	operator--(int);


	public:
		CONSTEXPR	bool					operator==(const const_reverse_iterator& other) const;
		CONSTEXPR	bool					operator!=(const const_reverse_iterator& other) const;

	private:
		iterator_type			m_ConstRevPtr = nullptr;
	};

	template<typename T>
	CONSTEXPR const_reverse_iterator<T>::const_reverse_iterator(iterator_type ptr) : m_ConstRevPtr(ptr)\
	{
	}

	template<typename T>
	CONSTEXPR typename const_reverse_iterator<T>::const_reference_type
		const_reverse_iterator<T>::operator[](const size_t& offset)
	{
		return *(m_ConstRevPtr - offset);
	}

	template<typename T>
	CONSTEXPR typename const_reverse_iterator<T>::const_reference_type
		const_reverse_iterator<T>::operator*()
	{
		return *m_ConstRevPtr;
	}

	template<typename T>
	CONSTEXPR typename const_reverse_iterator<T>::const_pointer_type
		const_reverse_iterator<T>::operator->()
	{
		return m_ConstRevPtr;
	}

	template<typename T>
	CONSTEXPR const_reverse_iterator<T>& const_reverse_iterator<T>::operator++()
	{
		m_ConstRevPtr--;
		return *this;
	}

	template<typename T>
	CONSTEXPR const_reverse_iterator<T>& const_reverse_iterator<T>::operator+(const size_t& offset)
	{
		m_ConstRevPtr -= offset;
		return *this;
	}

	template<typename T>
	CONSTEXPR const_reverse_iterator<T> const_reverse_iterator<T>::operator++(int)
	{
		const_reverse_iterator it = *this;
		--(*this);
		return it;
	}

	template<typename T>
	CONSTEXPR const_reverse_iterator<T>& const_reverse_iterator<T>::operator--()
	{
		m_ConstRevPtr++;
		return *this;
	}

	template<typename T>
	CONSTEXPR const_reverse_iterator<T>& const_reverse_iterator<T>::operator-(const size_t& offset)
	{
		m_ConstRevPtr += offset;
		return *this;
	}

	template<typename T>
	CONSTEXPR const_reverse_iterator<T> const_reverse_iterator<T>::operator--(int)
	{
		const_reverse_iterator it = *this;
		++(*this);
		return it;
	}

	template<typename T>
	CONSTEXPR bool const_reverse_iterator<T>::operator==(const const_reverse_iterator& other) const
	{
		return m_ConstRevPtr == other.m_ConstRevPtr;
	}

	template<typename T>
	CONSTEXPR bool const_reverse_iterator<T>::operator!=(const const_reverse_iterator& other) const
	{
		return !(*this == other);
	}
}

namespace mystl
{
	///////////////////////////////////////////////////////////////////////////////////////
	/// reverse_iterator
	/// 
	/// This class is a templated reverse_iterator class meant to mimic the C++
	/// STL reverse_iterator. The reverse_iterator takes in a type. 
	/// Note that there is no error/bounds checking.
	/// 
	///////////////////////////////////////////////////////////////////////////////////////
	template<typename T>
	class reverse_iterator
	{
	public:
		using		iterator_type		= T;
		using		value_type			= typename T::value_type;
		using		pointer_type		= typename T::pointer_type;
		using		reference_type		= typename T::reference_type;

	public:
		CONSTEXPR						reverse_iterator(iterator_type ptr);

	public:
		CONSTEXPR	reference_type		operator[](const size_t& offset);
		CONSTEXPR	reference_type		operator*();
		CONSTEXPR	pointer_type		operator->();


	public:
		CONSTEXPR	reverse_iterator&	operator++();
		CONSTEXPR	reverse_iterator&	operator+(const size_t& offset);
		CONSTEXPR	reverse_iterator	operator++(int);
		
		CONSTEXPR	reverse_iterator&	operator--();
		CONSTEXPR	reverse_iterator&	operator-(const size_t& offset);
		CONSTEXPR	reverse_iterator	operator--(int);


	public:
		CONSTEXPR	bool				operator==(const reverse_iterator& other) const;
		CONSTEXPR	bool				operator!=(const reverse_iterator& other) const;

	private:
					iterator_type		m_RevPtr = nullptr;
	};

	template<typename T>
	CONSTEXPR reverse_iterator<T>::reverse_iterator(iterator_type ptr) : m_RevPtr(ptr) { }

	template<typename T>
	CONSTEXPR typename reverse_iterator<T>::reference_type
		reverse_iterator<T>::operator[](const size_t& offset)
	{
		return *(m_RevPtr - offset);
	}

	template<typename T>
	CONSTEXPR typename reverse_iterator<T>::reference_type
		reverse_iterator<T>::operator*()
	{
		return *m_RevPtr;
	}

	template<typename T>
	CONSTEXPR typename reverse_iterator<T>::pointer_type
		reverse_iterator<T>::operator->()
	{
		return m_RevPtr;
	}

	template<typename T>
	CONSTEXPR reverse_iterator<T>& reverse_iterator<T>::operator++()
	{
		m_RevPtr--;
		return *this;
	}

	template<typename T>
	CONSTEXPR reverse_iterator<T>& reverse_iterator<T>::operator+(const size_t& offset)
	{
		m_RevPtr -= offset;
		return *this;
	}

	template<typename T>
	CONSTEXPR reverse_iterator<T> reverse_iterator<T>::operator++(int)
	{
		reverse_iterator it = *this;
		--(*this);
		return it;
	}

	template<typename T>
	CONSTEXPR reverse_iterator<T>& reverse_iterator<T>::operator--()
	{
		m_RevPtr++;
		return *this;
	}

	template<typename T>
	CONSTEXPR reverse_iterator<T>& reverse_iterator<T>::operator-(const size_t& offset)
	{
		m_RevPtr += offset;
		return *this;
	}

	template<typename T>
	CONSTEXPR reverse_iterator<T> reverse_iterator<T>::operator--(int)
	{
		reverse_iterator it = *this;
		++(*this);
		return it;
	}

	template<typename T>
	CONSTEXPR bool reverse_iterator<T>::operator==(const reverse_iterator& other) const
	{
		return m_RevPtr == other.m_RevPtr;
	}

	template<typename T>
	CONSTEXPR bool reverse_iterator<T>::operator!=(const reverse_iterator& other) const
	{
		return !(*this == other);
	}
}

#endif
