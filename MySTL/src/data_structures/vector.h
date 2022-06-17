#include "iterator.h"

#define CONSTEXPR inline constexpr

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

		using		iterator				= iterator<vector<T>>;
		using		const_iterator			= const_iterator<vector<T>>;

		using		reverse_iterator		= reverse_iterator<iterator>;
		using		const_reverse_iterator	= const_reverse_iterator<const_iterator>;

	// iterator functions					(97 - 151)
	public:
		CONSTEXPR	const_iterator			cbegin() const;
		CONSTEXPR	const_iterator			cend() const;

		CONSTEXPR	iterator				begin();
		CONSTEXPR	iterator				end();

		CONSTEXPR	const_reverse_iterator	crbegin() const;
		CONSTEXPR	const_reverse_iterator	crend() const;

		CONSTEXPR	reverse_iterator		rbegin();
		CONSTEXPR	reverse_iterator		rend();

	// size functions						(153 - 175)
	public:
		CONSTEXPR	size_t					size() const;
		CONSTEXPR	size_t					max_size() const;
		CONSTEXPR	size_t					capacity() const;

		CONSTEXPR	bool					empty() const;

	// access functions						(177 - 234)
	public:
		CONSTEXPR	reference_type			operator[](const size_t& index);
		CONSTEXPR	const_reference_type	operator[](const size_t& index) const;
		CONSTEXPR	const_reference_type	at(const size_t& index) const;

		CONSTEXPR	reference_type			front();
		CONSTEXPR	reference_type			back();

		CONSTEXPR	const_reference_type	front() const;
		CONSTEXPR	const_reference_type	back() const;

		CONSTEXPR	pointer_type			data();
		CONSTEXPR	const_pointer_type		data() const;

	// mutators								(236 - 330)
	public:
		CONSTEXPR	reference_type			push_back(T&& element);
		CONSTEXPR	reference_type			push_back(const_reference_type element);

		template<typename... Args>
		CONSTEXPR	reference_type			emplace_back(Args&&... args);
		
		template<typename... Args>
		CONSTEXPR	iterator				emplace(iterator position, Args&&... args);

		CONSTEXPR	reference_type			pop_back();

	// mutators								(332 - 359)
	public:
		CONSTEXPR	void					clear();
		CONSTEXPR	void					reserve(const size_t& size);
		CONSTEXPR	void					resize(const size_t& size);
		CONSTEXPR	void					shrink_to_fit();


	// constructor/destructor				(361 - 398)
	public:
		CONSTEXPR							vector();
		CONSTEXPR							vector(const size_t& capacity);
		CONSTEXPR							vector(const size_t& capacity, T&& fillElement);
		CONSTEXPR							vector(const size_t& capacity, const_reference_type fillElement);
											~vector();

	// helpers								(401 - 443)
	private:
		CONSTEXPR	void					realloc(const size_t& newCapacity);
		CONSTEXPR	size_t					pow(const size_t& num, const size_t& power) const;

	private:
					pointer_type			m_Data		= nullptr;
					size_t					m_Size		= 0;
					size_t					m_Capacity	= 0;
	};

	template<typename T>
	CONSTEXPR typename vector<T>::const_iterator
		vector<T>::cbegin() const
	{
		return const_iterator(m_Data);
	}

	template<typename T>
	CONSTEXPR typename vector<T>::const_iterator
		vector<T>::cend() const
	{
		return const_iterator(m_Data + m_Size);
	}

	template<typename T>
	CONSTEXPR typename vector<T>::iterator
		vector<T>::begin()
	{
		return iterator(m_Data);
	}

	template<typename T>
	CONSTEXPR typename vector<T>::iterator
		vector<T>::end()
	{
		return iterator(m_Data + m_Size);
	}

	template<typename T>
	CONSTEXPR typename vector<T>::const_reverse_iterator
		vector<T>::crbegin() const
	{
		return const_reverse_iterator(cbegin());
	}

	template<typename T>
	CONSTEXPR typename vector<T>::const_reverse_iterator
		vector<T>::crend() const
	{
		return const_reverse_iterator(cend());
	}

	template<typename T>
	CONSTEXPR typename vector<T>::reverse_iterator
		vector<T>::rbegin()
	{
		return reverse_iterator(begin());
	}

	template<typename T>
	CONSTEXPR typename vector<T>::reverse_iterator
		vector<T>::rend()
	{
		return reverse_iterator(end());
	}

	template<typename T>
	CONSTEXPR size_t vector<T>::size() const
	{
		return m_Size;
	}

	template<typename T>
	CONSTEXPR size_t vector<T>::max_size() const
	{
		return pow(2, CHAR_BIT * (sizeof(m_Data[0]))) - 1;
	}

	template<typename T>
	CONSTEXPR size_t vector<T>::capacity() const
	{
		return m_Capacity;
	}

	template<typename T>
	CONSTEXPR bool vector<T>::empty() const
	{
		return m_Size == 0;
	}

	template<typename T>
	CONSTEXPR typename vector<T>::reference_type vector<T>::operator[](const size_t& index)
	{
		return m_Data[index];
	}

	template<typename T>
	CONSTEXPR typename vector<T>::const_reference_type vector<T>::operator[](const size_t& index) const
	{
		return m_Data[index];
	}

	template<typename T>
	CONSTEXPR typename vector<T>::const_reference_type vector<T>::at(const size_t& index) const
	{
		return m_Data[index];
	}

	template<typename T>
	CONSTEXPR typename vector<T>::reference_type vector<T>::front()
	{
		return m_Data[0];
	}

	template<typename T>
	CONSTEXPR typename vector<T>::reference_type vector<T>::back()
	{
		return m_Data[m_Size - 1];
	}

	template<typename T>
	CONSTEXPR typename vector<T>::const_reference_type vector<T>::front() const
	{
		return m_Data[0];
	}

	template<typename T>
	CONSTEXPR typename vector<T>::const_reference_type vector<T>::back() const
	{
		return m_Data[m_Size - 1];
	}

	template<typename T>
	CONSTEXPR typename vector<T>::pointer_type vector<T>::data()
	{
		return m_Data;
	}

	template<typename T>
	CONSTEXPR typename vector<T>::const_pointer_type vector<T>::data() const
	{
		return m_Data;
	}

	template<typename T>
	CONSTEXPR typename vector<T>::reference_type vector<T>::push_back(T&& element)
	{
		if (m_Size >= m_Capacity)
		{
			size_t growth = m_Size < 5 ? m_Capacity * 2 : m_Capacity + (m_Capacity << 1);
			realloc(growth);
		}

		m_Data[m_Size] = std::move(element);

		return m_Data[m_Size++];
	}

	template<typename T>
	CONSTEXPR typename vector<T>::reference_type vector<T>::push_back(const_reference_type element)
	{
		if (m_Size >= m_Capacity)
		{
			size_t growth = m_Size < 5 ? m_Capacity * 2 : m_Capacity + (m_Capacity << 1);
			realloc(growth);
		}

		m_Data[m_Size] = element;

		return m_Data[m_Size++];
	}

	template<typename T>
	template<typename... Args>
	CONSTEXPR typename vector<T>::reference_type vector<T>::emplace_back(Args&&... args)
	{
		if (m_Size >= m_Capacity)
		{
			size_t growth = m_Size < 5 ? m_Capacity * 2 : m_Capacity + (m_Capacity << 1);
			realloc(growth);
		}

		m_Data[m_Size] = T(std::forward<Args>(args)...);

		return m_Data[m_Size++];
	}

	template<typename T>
	template<typename... Args>
	CONSTEXPR typename vector<T>::iterator
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
		{
			temp[i++] = *(it++);
		}

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
		{
			temp[i].~T();
		}
		::operator delete(temp, size * sizeof(T));
		m_Size++;
		return position;
	}

	template<typename T>
	CONSTEXPR typename vector<T>::reference_type vector<T>::pop_back()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	template<typename T>
	CONSTEXPR void vector<T>::clear()
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}

		m_Size = 0;
	}

	template<typename T>
	CONSTEXPR void vector<T>::reserve(const size_t& size)
	{
		realloc(size);
	}

	template<typename T>
	CONSTEXPR void vector<T>::resize(const size_t& size)
	{
		realloc(size);
	}

	template<typename T>
	CONSTEXPR void vector<T>::shrink_to_fit()
	{
		realloc(m_Size);
	}

	template<typename T>
	CONSTEXPR vector<T>::vector() : m_Size(0), m_Capacity(2)
	{
		realloc(2);
	}

	template<typename T>
	CONSTEXPR vector<T>::vector(const size_t& capacity) : m_Size(0), m_Capacity(size)
	{
		realloc(capacity);
	}

	template<typename T>
	CONSTEXPR vector<T>::vector(const size_t& capacity, T&& fillElement) : m_Size(size), m_Capacity(size)
	{
		realloc(capacity);
		for (size_t i = 0; i < m_Capacity; i++)
		{
			m_Data[i] = std::move(fillElement);
		}
	}

	template<typename T>
	CONSTEXPR vector<T>::vector(const size_t& capacity, const_reference_type fillElement) : m_Size(size), m_Capacity(size)
	{
		realloc(capacity);
		for (size_t i = 0; i < m_Capacity; i++)
		{
			m_Data[i] = fillElement;
		}
	}

	template<typename T>
	vector<T>::~vector()
	{
		clear();
		::operator delete(m_Data, m_Capacity * sizeof(T));
	}

	template<typename T>
	CONSTEXPR void vector<T>::realloc(const size_t& newCapacity)
	{
		if (!m_Data)
		{
			m_Data = (T*)::operator new(newCapacity * sizeof(T));
			return;
		}

		T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

		m_Size = newCapacity < m_Size ? newCapacity : m_Size;

		for (size_t i = 0; i < m_Size; i++)
		{
			newBlock[i] = m_Data[i];
		}

		for (size_t i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}

		::operator delete(m_Data, m_Capacity * sizeof(T));
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

	template<typename T>
	CONSTEXPR size_t vector<T>::pow(const size_t& num, const size_t& exponent) const
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