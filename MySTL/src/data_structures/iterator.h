#ifndef ITERATOR_H
#define ITERATOR_H

#define CONSTEXPR inline constexpr

namespace mystl
{
	///////////////////////////////////////////////////////////////////////////////////////
	/// const_iterator
	/// 
	/// This class is a templated const_iterator class meant to mimic the C++
	/// STL const_iterator. The const_iterator takes in a type. Note that there is no 
	/// error/bounds checking.
	///
	/// Example usage:
	///		for(const auto& x : arr) { do something; }
	/// 
	///		auto& begIt = arr.cbegin();
	///		auto& endIt = arr.cend();
	/// 
	///////////////////////////////////////////////////////////////////////////////////////
	template<typename T>
	class const_iterator
	{
	public:
		using		value_type				= typename T::value_type;
		using		const_pointer_type		= const value_type*;
		using		const_reference_type	= const value_type&;
		using		ptrdiff_t				= std::ptrdiff_t;

	public:
		CONSTEXPR							const_iterator(const_pointer_type ptr);

	public:
		CONSTEXPR	const_reference_type	operator[](const size_t& offset);
		CONSTEXPR	const_reference_type	operator*();
		CONSTEXPR	const_pointer_type		operator->();


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
					const_pointer_type		m_ConstPtr = nullptr;
	};

	template<typename T>
	CONSTEXPR const_iterator<T>::const_iterator(const_pointer_type ptr) : m_ConstPtr(ptr) { }

	template<typename T>
	CONSTEXPR typename const_iterator<T>::const_reference_type
		const_iterator<T>::operator[](const size_t& offset)
	{
		return *(m_ConstPtr + offset);
	}

	template<typename T>
	CONSTEXPR typename const_iterator<T>::const_reference_type
		const_iterator<T>::operator*()
	{
		return *m_ConstPtr;
	}

	template<typename T>
	CONSTEXPR typename const_iterator<T>::const_pointer_type
		const_iterator<T>::operator->()
	{
		return m_ConstPtr;
	}

	template<typename T>
	CONSTEXPR const_iterator<T>& const_iterator<T>::operator++()
	{
		m_ConstPtr++;
		return *this;
	}

	template<typename T>
	CONSTEXPR const_iterator<T>& const_iterator<T>::operator+(const size_t& offset)
	{
		m_ConstPtr += offset;
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
		m_ConstPtr--;
		return *this;
	}

	template<typename T>
	CONSTEXPR typename const_iterator<T>::ptrdiff_t const_iterator<T>::operator-(const_iterator other)
	{
		return m_ConstPtr - other.m_ConstPtr;
	}

	template<typename T>
	CONSTEXPR const_iterator<T>& const_iterator<T>::operator-(const size_t& offset)
	{
		m_ConstPtr -= offset;
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
		return m_ConstPtr == other.m_ConstPtr;
	}

	template<typename T>
	CONSTEXPR bool const_iterator<T>::operator!=(const_iterator& other) const
	{
		return !(*this == other);
	}
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
	/// Example usage:
	///		for(const auto& x : arr) { do something; }
	/// 
	///		auto& begIt = arr.begin();
	///		auto& endIt = arr.end();
	/// 
	///////////////////////////////////////////////////////////////////////////////////////
	template<typename T>
	class iterator
	{
	public:
		using		value_type		= typename T::value_type;
		using		pointer_type	= value_type*;
		using		reference_type	= value_type&;
		using		ptrdiff_t = std::ptrdiff_t;

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

namespace mystl
{
	///////////////////////////////////////////////////////////////////////////////////////
	/// const_reverse_iterator
	/// 
	/// This class is a templated const_reverse_iterator class meant to mimic the C++
	/// STL const_reverse_iterator. The const_reverse_iterator takes in a type. 
	/// Note that there is no error/bounds checking.
	///
	/// Example usage:
	///		auto& begIt = arr.crbegin();
	///		auto& endIt = arr.crend();
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
	CONSTEXPR const_reverse_iterator<T>::const_reverse_iterator(iterator_type ptr) : m_ConstRevPtr(ptr) { }

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
	/// Example usage:
	///		auto& begIt = arr.rbegin();
	///		auto& endIt = arr.rend();
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
