#ifndef QUEUE_H
#define QUEUE_H

#include "deque.h"

///////////////////////////////////////////////////////////////////////////////////////
/// queue																			///
///																					///
/// This class is a templated queue class meant to mimic the C++ STL queue.			///
/// The queue takes in a type. This class is essentially a wrapper for the			///
/// deque class.																	///
///																					///
///////////////////////////////////////////////////////////////////////////////////////


namespace mystl
{
	template<typename T>
	class queue
	{
	// typedefs
	public:
		using		value_type				= T;

		using		reference_type			= T&;
		using		pointer_type			= T*;

		using		const_reference_type	= const T&;
		using		const_pointer_type		= const T*;

	// constructor/destructor
	public:
		constexpr							queue();

	// element access
	public:
		constexpr	reference_type			front();
		constexpr	const_reference_type	front() const;

		constexpr	reference_type			back();
		constexpr	const_reference_type	back() const;

	// size functions
	public:
		constexpr	size_t					size() const;
		constexpr	bool					empty() const;

	// mutator functions
	public:
		constexpr	reference_type			push(T&& element);
		constexpr	reference_type			push(const_reference_type element);

		template<typename... Args>
		constexpr	reference_type			emplace(Args&& ...args);

		constexpr	value_type				pop();

	// variables
	private:
		deque<T> m_Data;
	};

	template<typename T>
	constexpr queue<T>::queue() : m_Data()
	{

	}

	template<typename T>
	constexpr typename queue<T>::reference_type
		queue<T>::front()
	{
		return m_Data.front();
	}

	template<typename T>
	constexpr typename queue<T>::const_reference_type
		queue<T>::front() const
	{
		return m_Data.front();
	}

	template<typename T>
	constexpr typename queue<T>::reference_type
		queue<T>::back()
	{
		return m_Data.back();
	}

	template<typename T>
	constexpr typename queue<T>::const_reference_type
		queue<T>::back() const
	{
		return m_Data.back();
	}

	template<typename T>
	constexpr size_t 
		queue<T>::size() const
	{
		return m_Data.size();
	}

	template<typename T>
	constexpr bool 
		queue<T>::empty() const
	{
		return m_Data.empty();
	}

	template<typename T>
	constexpr typename queue<T>::reference_type
		queue<T>::push(T&& element)
	{
		return m_Data.push_back(element);
	}

	template<typename T>
	constexpr typename queue<T>::reference_type
		queue<T>::push(const_reference_type element)
	{
		return m_Data.push_back(element);
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename queue<T>::reference_type
		queue<T>::emplace(Args && ...args)
	{
		return m_Data.emplace_back(std::forward<Args>(args)...);
	}

	template<typename T>
	constexpr typename queue<T>::value_type
		queue<T>::pop()
	{
		auto val = m_Data.front();

		m_Data.pop_front();

		return val;
	}
}

#endif