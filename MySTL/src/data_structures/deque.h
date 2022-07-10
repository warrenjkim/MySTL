#ifndef DEQUE_H
#define DEQUE_H

#include "list.h"
#include "list_iterator.h"

///////////////////////////////////////////////////////////////////////////////////////
/// deque																			///
///																					///
/// This class is a templated deque class meant to mimic the C++ STL deque.			///
/// The deque takes in a type. If no size is specified, the size					///
/// defaults to 0. Note that bounds checking isn't implemented. This class is		///
/// essentially a wrapper for the list class.										///
///																					///
///////////////////////////////////////////////////////////////////////////////////////

namespace mystl
{
	template<typename T>
	class deque
	{
	// typedefs
	public:
		using		value_type				= T;

		using		reference_type			= T&;
		using		pointer_type			= T*;

		using		const_reference_type	= const T&;
		using		const_pointer_type		= const T*;

		using		const_iterator			= list_const_iterator<list<T>>;
		using		iterator				= list_iterator<list<T>>;

		using		const_reverse_iterator	= list_const_reverse_iterator<const_iterator>;
		using		reverse_iterator		= list_reverse_iterator<iterator>;

	// constructor/destructor
	public:
		constexpr							deque();
		constexpr							deque(const size_t& size);
		constexpr							deque(const size_t& size, const_reference_type fillElement);

	// element access
	public:
		constexpr	reference_type			operator[](const size_t& offset);
		constexpr	reference_type			front();
		constexpr	reference_type			back();

		constexpr	const_reference_type	front() const;
		constexpr	const_reference_type	back() const;

	// size functions
	public:
		constexpr	bool					empty() const;
		constexpr	size_t					size() const;

	// mutator functions
	public:
		template<typename... Args>
		constexpr	reference_type			emplace_front(Args&&... args);

		template<typename... Args>
		constexpr	reference_type			emplace_back(Args&&... args);

		constexpr	reference_type			push_front(T&& element);
		constexpr	reference_type			push_front(const_reference_type element);

		constexpr	reference_type			push_back(T&& element);
		constexpr	reference_type			push_back(const_reference_type element);

		constexpr	value_type				pop_front();
		constexpr	value_type				pop_back();

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

	// variables
	private:
					list<T>					m_Data;
	};

	template<typename T>
	constexpr deque<T>::deque() : m_Data()
	{

	}

	template<typename T>
	constexpr deque<T>::deque(const size_t& size) : m_Data(size)
	{

	}

	template<typename T>
	constexpr deque<T>::deque(const size_t& size, const_reference_type fillElement) : m_Data(size, fillElement)
	{

	}

	template<typename T>
	constexpr bool 
		deque<T>::empty() const
	{
		return m_Data.empty();
	}

	template<typename T>
	constexpr size_t 
		deque<T>::size() const
	{
		return m_Data.size();
	}

	template<typename T>
	constexpr typename deque<T>::reference_type 
		deque<T>::operator[](const size_t& offset)
	{
		return m_Data[offset];
	}

	template<typename T>
	constexpr typename deque<T>::reference_type 
		deque<T>::front()
	{
		return m_Data.front();
	}

	template<typename T>
	constexpr typename deque<T>::reference_type 
		deque<T>::back()
	{
		return m_Data.back();
	}

	template<typename T>
	constexpr typename deque<T>::const_reference_type 
		deque<T>::front() const
	{
		return m_Data.front();
	}

	template<typename T>
	constexpr typename deque<T>::const_reference_type 
		deque<T>::back() const
	{
		return m_Data.back();
	}

	template<typename T>
	constexpr typename deque<T>::reference_type 
		deque<T>::push_front(T&& element)
	{
		return m_Data.emplace_front(element);
	}

	template<typename T>
	constexpr typename deque<T>::reference_type 
		deque<T>::push_front(const_reference_type element)
	{
		return m_Data.emplace_front(element);
	}

	template<typename T>
	constexpr typename deque<T>::reference_type 
		deque<T>::push_back(T&& element)
	{
		return m_Data.emplace_back(element);
	}
	
	template<typename T>
	constexpr typename deque<T>::reference_type 
		deque<T>::push_back(const_reference_type element)
	{
		return m_Data.emplace_back(element);
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename deque<T>::reference_type deque<T>::emplace_front(Args && ...args)
	{
		return m_Data.emplace_front(std::forward<Args>(args)...);
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename deque<T>::reference_type deque<T>::emplace_back(Args && ...args)
	{
		return m_Data.emplace_back(std::forward<Args>(args)...);
	}

	template<typename T>
	constexpr typename deque<T>::value_type 
		deque<T>::pop_front()
	{
		return m_Data.pop_front();
	}

	template<typename T>
	constexpr typename deque<T>::value_type 
		deque<T>::pop_back()
	{
		return m_Data.pop_back();
	}

	template<typename T>
	constexpr typename deque<T>::const_iterator 
		deque<T>::cbegin() const
	{
		return m_Data.cbegin();
	}

	template<typename T>
	constexpr typename deque<T>::const_iterator 
		deque<T>::cend() const
	{
		return m_Data.cend();
	}

	template<typename T>
	constexpr typename deque<T>::iterator 
		deque<T>::begin()
	{
		return m_Data.begin();
	}

	template<typename T>
	constexpr typename deque<T>::iterator 
		deque<T>::end()
	{
		return m_Data.end();
	}

	template<typename T>
	constexpr typename deque<T>::const_reverse_iterator 
		deque<T>::crbegin() const
	{
		return m_Data.crbegin();
	}

	template<typename T>
	constexpr typename deque<T>::const_reverse_iterator 
		deque<T>::crend() const
	{
		return m_Data.crend();
	}

	template<typename T>
	constexpr typename deque<T>::reverse_iterator 
		deque<T>::rbegin()
	{
		return m_Data.rbegin();
	}

	template<typename T>
	constexpr typename deque<T>::reverse_iterator 
		deque<T>::rend()
	{
		return m_Data.rend();
	}
}

#endif