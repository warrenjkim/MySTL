#ifndef VECTOR_H
#define VECTOR_H

#include "iterator.h"

///////////////////////////////////////////////////////////////////////////////////////
/// vector																			///
///																					///
/// This class is a templated vector class meant to mimic the C++ STL vector.		///
/// The vector takes in a type. If no size is specified, the size					///
/// defaults to 2. Note that bounds checking isn't implemented. The size grows		///
/// differently depending on the current size: size < 10 ? size doubles :			///
/// size grows by 1.5x.																///
///																					///
///////////////////////////////////////////////////////////////////////////////////////

namespace mystl
{
	template<typename T>
	class vector
	{
	// typedefs
	public:
		using		value_type				= T;

		using		reference_type			= T&;
		using		pointer_type			= T*;

		using		const_reference_type	= const T&;
		using		const_pointer_type		= const T*;

		using		const_iterator			= const_iterator<vector<T>>;
		using		iterator				= iterator<vector<T>>;

		using		const_reverse_iterator	= const_reverse_iterator<const_iterator>;
		using		reverse_iterator		= reverse_iterator<iterator>;

	// constructor/destructor
	public:
		constexpr							vector();
		constexpr							vector(const size_t& capacity);
		constexpr							vector(const size_t& capacity, T&& fillElement);
		constexpr							vector(const size_t& capacity, const_reference_type fillElement);
		constexpr							vector(const vector& other);
											~vector();

	// size functions
	public:
		constexpr	size_t					size() const;
		constexpr	size_t					max_size() const;
		constexpr	size_t					capacity() const;

		constexpr	bool					empty() const;

	// access functions
	public:
		constexpr	reference_type			operator[](const size_t& index);
		constexpr	const_reference_type	operator[](const size_t& index) const;
		constexpr	const_reference_type	at(const size_t& index) const;

		constexpr	reference_type			front();
		constexpr	reference_type			back();

		constexpr	const_reference_type	front() const;
		constexpr	const_reference_type	back() const;

		constexpr	pointer_type			data();
		constexpr	const_pointer_type		data() const;

	// mutator functions
	public:
		constexpr	reference_type			push_back(T&& element);
		constexpr	reference_type			push_back(const_reference_type element);

		template<typename... Args>
		constexpr	reference_type			emplace_back(Args&&... args);
		
		template<typename... Args>
		constexpr	iterator				emplace(iterator position, Args&&... args);

		constexpr	reference_type			pop_back();

	// mutator functions
	public:
					[[noreturn]] void		clear();
					[[noreturn]] void		reserve(const size_t& size);
					[[noreturn]] void		resize(const size_t& size);
					[[noreturn]] void		shrink_to_fit();

	// operators
	public:
		constexpr	vector<T>&				operator=(const vector& other);

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

	// helpers
	private:
		constexpr	void					realloc(const size_t& newCapacity);
		constexpr	size_t					pow(const size_t& num, const size_t& power) const;

	// variables
	private:
					pointer_type			m_Data		= nullptr;
					size_t					m_Size		= 0;
					size_t					m_Capacity	= 0;
	};

	template<typename T>
	constexpr vector<T>::vector() : m_Data(nullptr), m_Size(0), m_Capacity(2)
	{
		realloc(2);
	}

	template<typename T>
	constexpr vector<T>::vector(const size_t& capacity) : m_Data(nullptr), m_Size(0), m_Capacity(capacity)
	{
		realloc(capacity);
	}

	template<typename T>
	constexpr vector<T>::vector(const size_t& capacity, T&& fillElement) : m_Data(nullptr), m_Size(capacity), m_Capacity(capacity)
	{
		realloc(capacity);
		for (size_t i = 0; i < m_Capacity; i++)
			m_Data[i] = std::move(fillElement);
	}

	template<typename T>
	constexpr vector<T>::vector(const size_t& capacity, const_reference_type fillElement) : m_Data(nullptr), m_Size(capacity), m_Capacity(capacity)
	{
		realloc(capacity);
		for (size_t i = 0; i < m_Capacity; i++)
			m_Data[i] = fillElement;
	}

	template<typename T>
	constexpr vector<T>::vector(const vector& other)
	{
		m_Size = other.m_Size;
		m_Capacity = other.m_Capacity;
		m_Data = (T*)::operator new(m_Capacity * sizeof(T));

		for (size_t i = 0; i < m_Size; i++)
			new(&m_Data[i]) T(std::move(other.m_Data[i]));
	}

	template<typename T>
	vector<T>::~vector()
	{
		clear();
		::operator delete(m_Data, m_Capacity * sizeof(T));
	}


	template<typename T>
	constexpr size_t 
		vector<T>::size() const
	{
		return m_Size;
	}

	template<typename T>
	constexpr size_t 
		vector<T>::max_size() const
	{
		return pow(2, CHAR_BIT * (sizeof(m_Data[0]))) - 1;
	}

	template<typename T>
	constexpr size_t 
		vector<T>::capacity() const
	{
		return m_Capacity;
	}

	template<typename T>
	constexpr bool 
		vector<T>::empty() const
	{
		return m_Size == 0;
	}

	template<typename T>
	constexpr typename vector<T>::reference_type 
		vector<T>::operator[](const size_t& index)
	{
		return m_Data[index];
	}

	template<typename T>
	constexpr typename vector<T>::const_reference_type 
		vector<T>::operator[](const size_t& index) const
	{
		return m_Data[index];
	}

	template<typename T>
	constexpr typename vector<T>::const_reference_type 
		vector<T>::at(const size_t& index) const
	{
		return m_Data[index];
	}

	template<typename T>
	constexpr typename vector<T>::reference_type 
		vector<T>::front()
	{
		return m_Data[0];
	}

	template<typename T>
	constexpr typename vector<T>::reference_type 
		vector<T>::back()
	{
		return m_Data[m_Size - 1];
	}

	template<typename T>
	constexpr typename vector<T>::const_reference_type 
		vector<T>::front() const
	{
		return m_Data[0];
	}

	template<typename T>
	constexpr typename vector<T>::const_reference_type 
		vector<T>::back() const
	{
		return m_Data[m_Size - 1];
	}

	template<typename T>
	constexpr typename vector<T>::pointer_type 
		vector<T>::data()
	{
		return m_Data;
	}

	template<typename T>
	constexpr typename vector<T>::const_pointer_type 
		vector<T>::data() const
	{
		return m_Data;
	}

	template<typename T>
	constexpr typename vector<T>::reference_type 
		vector<T>::push_back(T&& element)
	{
		return emplace_back(element);
	}

	template<typename T>
	constexpr typename vector<T>::reference_type 
		vector<T>::push_back(const_reference_type element)
	{
		return emplace_back(element);
	}

	template<typename T>
	template<typename... Args>
	constexpr typename vector<T>::reference_type 
		vector<T>::emplace_back(Args&&... args)
	{
		if (m_Size >= m_Capacity)
		{
			size_t growth = m_Size < 5 ? m_Capacity * 2 : m_Capacity + (m_Capacity << 1);
			realloc(growth);
		}

		new(&m_Data[m_Size]) T(std::forward<Args>(args)...);

		return m_Data[m_Size++];
	}

	template<typename T>
	template<typename... Args>
	constexpr typename vector<T>::iterator
		vector<T>::emplace(iterator position, Args&&... args)
	{
		ptrdiff_t diff = end() - position;

		if (m_Size == 0)
		{
			emplace_back(args...);
			return begin();
		}

		if (m_Size >= m_Capacity)
		{
			size_t growth = m_Size < 5 ? m_Capacity * 2 : m_Capacity + (m_Capacity << 1);
			realloc(growth);
		}

		T* temp = new T[diff]{};
		iterator it = begin() + diff;
		size_t i = 0;

		while (it != end())
			new(&temp[i++]) T(std::move(*(it++)));

		size_t size = i;

		m_Data[diff] = T(std::forward<Args>(args)...);

		it = begin() + diff + 1;
		i = 0;

		while (diff > 0)
		{
			*(it++) = temp[i++];
			diff--;
		}

		
		for (size_t i = 0; i < size; i++)
			temp[i].~T();

		::operator delete(temp, size * sizeof(T));
		m_Size++;

		return position;
	}

	template<typename T>
	constexpr typename vector<T>::reference_type 
		vector<T>::pop_back()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	template<typename T>
	inline void 
		vector<T>::clear()
	{
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();

		m_Size = 0;
	}

	template<typename T>
	inline void 
		vector<T>::reserve(const size_t& size)
	{
		realloc(size);
	}

	template<typename T>
	inline void 
		vector<T>::resize(const size_t& size)
	{
		realloc(size);
	}

	template<typename T>
	inline void 
		vector<T>::shrink_to_fit()
	{
		realloc(m_Size);
	}

	template<typename T>
	constexpr vector<T>& vector<T>::operator=(const vector& other)
	{
		m_Size = other.m_Size;
		m_Capacity = other.m_Capacity;
		m_Data = (T*)::operator new(m_Capacity * sizeof(T));
		
		for (size_t i = 0; i < m_Size; i++)
			new(&m_Data[i]) T(std::move(other.m_Data[i]));
		
		return *this;
	}


	template<typename T>
	constexpr typename vector<T>::const_iterator
		vector<T>::cbegin() const
	{
		return const_iterator(m_Data);
	}

	template<typename T>
	constexpr typename vector<T>::const_iterator
		vector<T>::cend() const
	{
		return const_iterator(m_Data + m_Size);
	}

	template<typename T>
	constexpr typename vector<T>::iterator
		vector<T>::begin()
	{
		return iterator(m_Data);
	}

	template<typename T>
	constexpr typename vector<T>::iterator
		vector<T>::end()
	{
		return iterator(m_Data + m_Size);
	}

	template<typename T>
	constexpr typename vector<T>::const_reverse_iterator
		vector<T>::crbegin() const
	{
		return const_reverse_iterator(cbegin());
	}

	template<typename T>
	constexpr typename vector<T>::const_reverse_iterator
		vector<T>::crend() const
	{
		return const_reverse_iterator(cend());
	}

	template<typename T>
	constexpr typename vector<T>::reverse_iterator
		vector<T>::rbegin()
	{
		return reverse_iterator(begin());
	}

	template<typename T>
	constexpr typename vector<T>::reverse_iterator
		vector<T>::rend()
	{
		return reverse_iterator(end());
	}

	template<typename T>
	constexpr void
		vector<T>::realloc(const size_t& newCapacity)
	{
		if (!m_Data)
		{
			m_Data = (T*)::operator new(newCapacity * sizeof(T));
			return;
		}

		T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

		m_Size = newCapacity < m_Size ? newCapacity : m_Size;

		for (size_t i = 0; i < m_Size; i++)
			new(&newBlock[i]) T(std::move(m_Data[i]));

		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();

		::operator delete(m_Data, m_Capacity * sizeof(T));
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

	template<typename T>
	constexpr size_t 
		vector<T>::pow(const size_t& num, const size_t& exponent) const
	{
		size_t power = num;
		for (size_t i = 1; i < exponent; i++)
		{
			power >> 1;
			if (power * num == 0)
			{
				power /= num;
				break;
			}
		}

		return power;
	}
}

#endif