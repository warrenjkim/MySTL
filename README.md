# __MySTL__ #
## __Introduction__ ##
This is a personal project that aims to replicate the C++ Standard Template Library. 
The goal of this project is to have a fuller understanding of data structures and 
algorithms. Note that there will be "incomplete" data structures. "Incomplete" 
is defined by an omission of some functions that the STL version contains.

This project is split into two parts: data structures and algorithms. Documentation is 
provided below.

## __Data Structures__ ##
Below are the list of data structures that have been implemented. The data structures 
are partitioned into subgroups: basic, trees, tables/maps/skip list, and graphs. 
- Basic data structures are ones that are most commonly used.
- Trees, while not implemented in the STL, are included in this project.
- Tables/Maps/Skip Lists are more advanced data structures that implement the basic ones.
- Graphs are reperesented via an Adjacency Matrix and an Adjacency List. 

### __Basic__ ###
- [Const_Iterator](Const_Iterator "Goto ### __Const Iterator __ ###")
- [Iterator](Iterator "Goto ### __Iterator __ ###")
- [Const_Reverse_Iterator](Const_Iterator "Goto ### __Const Reverse Iterator __ ###")
- [Reverse_Iterator](Reverse_Iterator "Goto ### __Reverse Iterator __ ###")
- [Array](Array "Goto ### __Array__ ###")
- [Vector](Vector "Goto ### __Vector__ ###")

    
### __WIP__ ###
### __Basic__ ###
- List (Linked-List)
- Deque
- Queue
- Stack
### __Trees__ ###
- Binary Tree
- Binary Search Tree (BST)
- AVL Tree
- Splay Tree
- Red-Black Tree
- Priority Queue (uses heap as underlying data structure)
- Heap (min heap default)
### __Tables/Maps/Skip List__ ###
- Hash Table
- Skip List
- Map (uses red-black tree as underlying data structure)
- Unordered Map (uses hash table as underlying data structure)
### __Graphs__ ###
- Adjacency Matrix
- Adjacency List


## __Data Structures__ ##

## __Basic__ ##
### __Const Iterator__ ###
`template<class T> class const_iterator`
Typedefs               | Description
---------------------- | :---------------------------------------------:
`value_type`           | value type of T
`const_pointer_type`   | const value type pointer
`const_reference_type` | const value type reference
`ptrdiff_t`            | pointer difference: used for pointer arithmetic


Function Name                              | Return Type                | Description
------------------------------------------ | :------------------------: | :------------------------------------------------------------------------------------:
`const_iterator(const_pointer_type ptr)`   | `N/A`                      | constructor
`operator[](const size_t& offset)`         | `const_reference_type`     | returns a const reference at a given pointer offset
`operator*()`                              | `const_reference_type`     | dereference operator
`operator->()`                             | `const_pointer_type`       | pointer operator
`operator++`                               | `const_iterator reference` | (prefix) increments const_iterator
`operator++(int)`                          | `const_iterator`           | (postfix) increments const_iterator
`operator+(const size_t& offset)`          | `const_iterator reference` | increments const_iterator by an offset
`operator++`                               | `const_iterator reference` | (prefix) decrements const_iterator
`operator++(int)`                          | `const_iterator`           | (postfix) decrements const_iterator
`operator-(const size_t& offset)`          | `const_iterator reference` | decrements const_iterator by an offset
`operator-(const_iterator other)`          | `ptrdiff_t`                | returns the pointer difference between two const_iterators
`operator==(const_iterator& other) const`  | `bool`                     | returns true if both const_iterators point to the same address, false otherwise
`operator!=(const_iterator& othter) const` | `bool`                     | returns true if the two const_iterators point to different addresses, false otherwise

Variables    | Type                 | Description
---------    | :------------------: | :---------------------:
`m_ConstPtr` | `const_pointer_type` | const pointer to object





### __Iterator__ ###
`template<class T> class iterator`
Typedefs         | Description
---------------- | :---------------------------------------------:
`value_type`     | value type of T
`pointer_type`   | value type pointer
`reference_type` | value type reference
`ptrdiff_t`      | pointer difference: used for pointer arithmetic


Function Name                        | Return Type          | Description
------------------------------------ | :------------------: | :-----------------------------------------------------------------------------:
`iterator(pointer_type ptr)`         | `N/A`                | constructor
`operator[](const size_t& offset)`   | `reference_type`     | returns reference at a given pointer offset
`operator*()`                        | `reference_type`     | dereference operator
`operator->()`                       | `pointer_type`       | pointer operator
`operator++`                         | `iterator reference` | (prefix) increments iterator
`operator++(int)`                    | `iterator`           | (postfix) increments iterator
`operator+(const size_t& offset)`    | `iterator reference` | increments iterator by an offset
`operator++`                         | `iterator reference` | (prefix) decrements iterator
`operator++(int)`                    | `iterator`           | (postfix) decrements iterator
`operator-(const size_t& offset)`    | `iterator reference` | decrements iterator by an offset
`operator-(iterator other)`          | `ptrdiff_t`          | returns the pointer difference between two iterators
`operator==(iterator& other) const`  | `bool`               | returns true if both iterators point to the same address, false otherwise
`operator!=(iterator& othter) const` | `bool`               | returns true if the two iterators point to different addresses, false otherwise

Variables | Type         | Description
--------- | :----------: | :-----------------:
`m_Ptr`   | `pointer_type` | pointer to object





### __Const Reverse Iterator__ ###
`template<class T> class const_reverse_iterator`
Typedefs               | Description
---------------------- | :------------------------:
`iterator_type`        | type of iterator T
`value_type`           | value type of T
`const_pointer_type`   | const value type pointer
`const_reference_type` | const value type reference


Function Name                                    | Return Type                        | Description
------------------------------------------------ | :--------------------------------: | :----------------------------------------------------------------------------:
`const_reverse_iterator(const_pointer_type ptr)` | `N/A`                              | constructor
`operator[](const size_t& offset)`               | `const_reference_type`             | returns a const reference at a given pointer offset
`operator*()`                                    | `const_reference_type`             | dereference operator
`operator->()`                                   | `const_pointer_type`               | pointer operator
`operator++`                                     | `const_reverse_iterator reference` | (prefix) decrements const_reverse_iterator
`operator++(int)`                                | `const_reverse_iterator`           | (postfix) decrements const_reverse_iterator
`operator+(const size_t& offset)`                | `const_reverse_iterator reference` | decrements const_reverse_iterator by an offset
`operator++`                                     | `const_reverse_iterator reference` | (prefix) increments const_reverse_iterator
`operator++(int)`                                | `const__reverse_iterator`          | (postfix) increments const_reverse_iterator
`operator-(const size_t& offset)`                | `const_reverse_iterator reference` | increments const_reverse_iterator by an offset
`operator==(const_iterator& other) const`        | `bool`                             | returns true if both const_reverse_iterators point to the same address, false                                                                                           otherwise
`operator!=(const_iterator& othter) const`       | `bool`                             | returns true if the two const_reverse_iterators point to different addresses,                                                                                           false otherwise

Variables       | Type               | Description
--------------- | :----------------: | :-----------------------:
`m_ConstRevPtr` | `const_pointer_type` | const pointer to object





### __Reverse Iterator__ ###
`template<class T> class reverse_iterator`
Typedefs                | Description
----------------------- | :------------------:
`iterator_type`         | type of iterator T
`value_type`            | value type of T
`pointer_type`          | value type pointer
`reference_type`        | value type reference


Function Name                                | Return Type                  | Description
-------------------------------------------- | :--------------------------: | :-----------------------------------------------------------------------------:
`reverse_iterator(pointer_type ptr)`         | `N/A`                        | constructor
`operator[](const size_t& offset)`           | `reference_type`             | returns reference at a given pointer offset
`operator*()`                                | `reference_type`             | dereference operator
`operator->()`                               | `pointer_type`               | pointer operator
`operator++`                                 | `reverse_iterator reference` | (prefix) decrements reverse_iterator
`operator++(int)`                            | `reverse_iterator`           | (postfix) decrements reverse_iterator
`operator+(const size_t& offset)`            | `reverse_iterator reference` | decrements reverse_iterator by an offset
`operator++`                                 | `reverse_iterator reference` | (prefix) increments reverse_iterator
`operator++(int)`                            | `reverse_iterator`           | (postfix) increments reverse_iterator
`operator-(const size_t& offset)`            | `reverse_iterator reference` | increments reverse_iterator by an offset
`operator==(reverse_iterator& other) const`  | `bool`                       | returns true if both reverse_iterators point to the same address, false otherwise
`operator!=(reverse_iterator& othter) const` | `bool`                       | returns true if the two reverse_iterators point to different addresses, false otherwise

Variables  | Type         | Description
---------- | :----------: | :---------------:
`m_RevPtr` | `pointer_type` | pointer to object

### Array
`template<typename T, size_t m_Size> class array`
Typedefs                 | Description
------------------------ | :---------------------------------------------:
`value_type`             | value type T
`pointer_type`           | value type pointer
`reference_type`         | value type reference
`const_pointer_type`     | const value type pointer
`const_reference_type`   | const value type reference
`const_iterator`         | const_iterator with class array<T, m_Size>
`iterator`               | iterator with class array<T, m_Size>
`const_reverse_iterator` | const_reverse_iterator with class const_iterator
`reverse_iterator`       | reverse_iterator with class iterator


Function Name                            | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`array()`                                | `N/A`                    | default constructor
`cbegin() const`                         | `const_iterator`         | returns a const_iterator that points to the beginning of the array
`cend() const`                           | `const_iterator`         | returns a const_iterator that points to the element after end of the array
`begin()`                                | `iterator`               | returns an iterator that points to the beginning of the array
`end()`                                  | `iterator`               | returns an iterator that points to the element after end of the array
`crbegin() const`                        | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the array
`crend() const`                          | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the array
`rbegin()`                               | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the array
`rend()`                                 | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the array
`size() const`                           | `size_t`                 | returns the size of the array
`max_size() const`                       | `size_t`                 | returns the max size of the array (returns the same value as size())
`empty() const`                          | `bool`                   | returns true if the array is empty, false otherwise
`operator[](const size_t& index)`        | `reference_type`         | returns a reference to the array at a specified index
`operator[](const size_t& index) const`  | `const_reference_type`   | returns a const reference to the array at a specified index
`at(const size_t& index) const`          | `const_reference_type`   | returns a const reference to the array at a specified index
`front()`                                | `reference_type`         | returns a reference to the first element in the array
`back()`                                 | `reference_type`         | returns a reference to the last element in the array
`front() const`                          | `const_reference_type`   | returns a const reference to the first element in the array
`back() const`                           | `const_reference_type`   | returns a const reference to the last element in the array 
`data()`                                 | `pointer_type`           | returns a pointer to the array
`data() const`                           | `const_pointer_type`     | returns a const pointer to the array
`fill(const_reference_type fillElement)` | `[[noreturn]] void`      | fills the array with a given value
`swap(array& other)`                     | `[[noreturn]] void`      | swaps two arrays


Variables  | Type           | Description
---------- | :----------:   | :---------------------------:
`m_Data`   | `pointer_type` | raw array with specified size
