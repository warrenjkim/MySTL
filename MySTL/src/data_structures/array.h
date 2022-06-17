#ifndef ARRAY_H
#define ARRAY_H
#include <assert.h>


#if defined _DEBUG
#define OUT_OF_RANGE(index) assert("Array subscript out of range" && index < m_Size)
#define EMPTY_ARRAY() assert("Array is empty" && m_Size != 0)

#else
#define OUT_OF_RANGE(index)
#define EMPTY_ARRAY()

#endif

#define CONSTEXPR inline constexpr
#include "iterator.h"

namespace mystl {

	///////////////////////////////////////////////////////////////////////////////////////
	/// array
	/// 
	/// This class is a templated array class meant to mimic the C++ STL array. 
	/// The array takes in a type and a size. If no size is specified, the size
	/// defaults to 1. Note that in release mode, bounds checking is disabled.
	///
	/// Example usage:
	///		array<int, 5> arr;		initializes array with size 5
	///		arr.fill(4);			fills array with 4: arr => [4, 4, 4, 4, 4]
	///		arr[2] = 1;				arr => [4, 4, 1, 4, 4]
	///		int x = arr.at(4);		x => 4
	/// 
	///////////////////////////////////////////////////////////////////////////////////////

	template<typename T, size_t m_Size = 1>
	class array
	{
	// typedefs
	public:
		using		value_type				= T;

		using		reference_type			= value_type&;
		using		pointer_type					= value_type*;

		using		const_reference_type	= const value_type&;
		using		const_pointer_type			= const value_type*;

		using		iterator				= iterator<array<T, m_Size>>;
		using		const_iterator			= const_iterator<array<T, m_Size>>;

		using		reverse_iterator		= reverse_iterator<iterator>;
		using		const_reverse_iterator	= const_reverse_iterator<const_iterator>;

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
		CONSTEXPR	size_t					size() const;
		CONSTEXPR	size_t					max_size() const;

		CONSTEXPR	bool					empty() const;

	// access functions
	public:
		CONSTEXPR	reference_type			operator[](const size_t& index);
		CONSTEXPR	const_reference_type	operator[](const size_t& index) const;
		CONSTEXPR	const_reference_type	at(const size_t& index) const;
	
		CONSTEXPR	reference_type			front();
		CONSTEXPR	reference_type			back();

		CONSTEXPR	const_reference_type	front() const;
		CONSTEXPR	const_reference_type	back() const;

		CONSTEXPR	pointer_type					data();
		CONSTEXPR	const_pointer_type			data() const;

	// mutators
	public:
					[[noreturn]] void		fill(const_reference_type filler);
					[[noreturn]] void		swap(array& other);

	// constructor/destructor
	public:
											array()  = default;
											~array() = default;

	// variables
	private:
					value_type				m_Data[m_Size]{};
	};

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::const_iterator
		array<T, m_Size>::cbegin() const
	{
		return const_iterator(m_Data);
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::const_iterator
		array<T, m_Size>::cend() const
	{
		return const_iterator(m_Data + m_Size);
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::iterator
		array<T, m_Size>::begin()
	{
		return iterator(m_Data);
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::iterator
		array<T, m_Size>::end()
	{
		return iterator(m_Data + m_Size);
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::const_reverse_iterator
		array<T, m_Size>::crbegin() const
	{
		return const_reverse_iterator(cend());
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::const_reverse_iterator
		array<T, m_Size>::crend() const
	{
		return const_reverse_iterator(cbegin());
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::reverse_iterator
		array<T, m_Size>::rbegin()
	{
		return reverse_iterator(end());
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::reverse_iterator
		array<T, m_Size>::rend()
	{
		return reverse_iterator(begin());
	}
	template<typename T, size_t m_Size>
	CONSTEXPR size_t array<T, m_Size>::size() const
	{
		return m_Size;
	}

	template<typename T, size_t m_Size>
	CONSTEXPR size_t array<T, m_Size>::max_size() const
	{
		return m_Size;
	}

	template<typename T, size_t m_Size>
	CONSTEXPR bool array<T, m_Size>::empty() const
	{
		return m_Size == 0;
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::reference_type
		array<T, m_Size>::operator[](const size_t& index)
	{
		OUT_OF_RANGE(index);
		return m_Data[index];
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::const_reference_type
		array<T, m_Size>::operator[](const size_t& index) const
	{
		OUT_OF_RANGE(index);
		return m_Data[index];
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::const_reference_type
		array<T, m_Size>::at(const size_t& index) const
	{
		OUT_OF_RANGE(index);
		return m_Data[index];
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::reference_type
		array<T, m_Size>::front()
	{
		EMPTY_ARRAY();
		return m_Data[0];
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::reference_type
		array<T, m_Size>::back()
	{
		EMPTY_ARRAY();
		return m_Data[m_Size - 1];
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::const_reference_type
		array<T, m_Size>::front() const
	{
		EMPTY_ARRAY();
		return m_Data[0];
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::const_reference_type
		array<T, m_Size>::back() const
	{
		EMPTY_ARRAY();
		return m_Data[m_Size - 1];
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::pointer_type
		array<T, m_Size>::data()
	{
		return m_Data;
	}

	template<typename T, size_t m_Size>
	CONSTEXPR typename array<T, m_Size>::const_pointer_type
		array<T, m_Size>::data() const
	{
		return m_Data;
	}

	template<typename T, size_t m_Size>
	inline void array<T, m_Size>::fill(const_reference_type filler)
	{
		EMPTY_ARRAY();
		for (size_t i = 0; i < m_Size; i++)
		{
			m_Data[i] = filler;
		}
	}

	template<typename T, size_t m_Size>
	inline void array<T, m_Size>::swap(array& other)
	{
		array temp = *this;
		*this = other;
		other = temp;
	}
}

#endif