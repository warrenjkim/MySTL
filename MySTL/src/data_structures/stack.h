#ifndef STACK_H
#define STACK_H
#include "deque.h"

///////////////////////////////////////////////////////////////////////////////////////
/// stack																			///
///																					///
/// This class is a templated stack class meant to mimic the C++ STL stack.			///
/// The stack takes in a type. This class is essentially a wrapper for the			///
/// deque class.																	///
///																					///
///////////////////////////////////////////////////////////////////////////////////////

namespace mystl
{
	template<typename T>
	class stack
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
		constexpr							stack();

	// size functions
	public:
		constexpr	size_t					size() const;
		constexpr	bool					empty() const;

	// element access
	public:
		constexpr	reference_type			top();
		constexpr	const_reference_type	top() const;

	// mutator functions
	public:
		constexpr	reference_type			push(T&& element);
		constexpr	reference_type			push(const_reference_type element);

		template<typename... Args>
		constexpr	reference_type			emplace(Args&&... args);

		constexpr	value_type				pop();

	// variables
	private:
					deque<T>				m_Data;
	};

	template<typename T>
	constexpr stack<T>::stack() : m_Data()
	{

	}

	template<typename T>
	constexpr size_t 
		stack<T>::size() const
	{
		return m_Data.size();
	}

	template<typename T>
	constexpr bool 
		stack<T>::empty() const
	{
		return m_Data.empty();
	}

	template<typename T>
	constexpr typename stack<T>::reference_type
		stack<T>::top()
	{
		return m_Data.front();
	}

	template<typename T>
	constexpr typename stack<T>::const_reference_type
		stack<T>::top() const
	{
		return m_Data.front();
	}

	template<typename T>
	constexpr typename stack<T>::reference_type
		stack<T>::push(T&& element)
	{
		return m_Data.push_front(element);
	}

	template<typename T>
	constexpr typename stack<T>::reference_type
		stack<T>::push(const_reference_type element)
	{
		return m_Data.push_front(element);
	}

	template<typename T>
	template<typename ...Args>
	constexpr typename stack<T>::reference_type
		stack<T>::emplace(Args && ...args)
	{
		return m_Data.emplace_front(std::forward<Args>(args)...);
	}

	template<typename T>
	constexpr typename stack<T>::value_type
		stack<T>::pop()
	{
		auto val = m_Data.front();
		
		m_Data.pop_front();

		return val;
	}
}

#endif