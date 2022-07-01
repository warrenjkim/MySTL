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
- [Array](#array "Goto array")
- [Vector](#vector "Goto vector")
- [List](#list "Goto list")
- [Deque](#deque "Goto deque")
- [Queue](#queue "Goto queue")
- [Stack](#stack "Goto stack")


### __Iterators__ ###
- [Const Iterator](#const-iterator "Goto const-iterator")
- [Iterator](#iterator "Goto iterator")
- [Const Reverse Iterator](#const-reverse-iterator "Goto const-reverse-iterator")
- [Reverse Iterator](#reverse-iterator "Goto reverse-iterator")
- [List Iterator](#list-iterator "Goto list-iterator")

### __Smaller Data Structures__ ###
- [Node](#node "Goto node")
   
### __WIP__ ###
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


### __Array__ ###
- `mystl::array<typename T, size_t m_Size>`
- This class is a templated array class meant to mimic the C++ STL array. 
- The array takes in a type and size. If no size is specified, the size defaults to 1. 
> **Note** 
> In release mode, bounds checking is disabled.

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

Constructor/Destructor                   | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`array()`                                | `N/A`                    | default constructor
`~array()`                               | `N/A`                    | default destructor

Element Access                           | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`operator[](const size_t& index)`        | `reference_type`         | returns a reference to the array at a specified index
`operator[](const size_t& index) const`  | `const_reference_type`   | returns a const reference to the array at a specified index
`at(const size_t& index) const`          | `const_reference_type`   | returns a const reference to the array at a specified index
`front()`                                | `reference_type`         | returns a reference to the first element in the array
`back()`                                 | `reference_type`         | returns a reference to the last element in the array
`front() const`                          | `const_reference_type`   | returns a const reference to the first element in the array
`back() const`                           | `const_reference_type`   | returns a const reference to the last element in the array 
`data()`                                 | `pointer_type`           | returns a pointer to the array
`data() const`                           | `const_pointer_type`     | returns a const pointer to the array

Size Functions                           | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`size() const`                           | `size_t`                 | returns the size of the array
`max_size() const`                       | `size_t`                 | returns the max size of the array (returns the same value as size())
`empty() const`                          | `bool`                   | returns true if the array is empty, false otherwise

Mutator Functions                        | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`fill(const_reference_type fillElement)` | `void`                   | fills the array with a given value
`swap(array& other)`                     | `void`                   | swaps two arrays

Iterator Functions                       | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`cbegin() const`                         | `const_iterator`         | returns a const_iterator that points to the beginning of the array
`cend() const`                           | `const_iterator`         | returns a const_iterator that points to the element after end of the array
`begin()`                                | `iterator`               | returns an iterator that points to the beginning of the array
`end()`                                  | `iterator`               | returns an iterator that points to the element after end of the array
`crbegin() const`                        | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the array
`crend() const`                          | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the array
`rbegin()`                               | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the array
`rend()`                                 | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the array

Variables  | Type           | Description
---------- | :------------: | :---------------------------:
`m_Data`   | `pointer_type` | raw array with specified size





### __Vector__ ###
- `mystl::vector<typename T>`
- This class is a templated vector class meant to mimic the C++ STL vector. 
- The vector takes in a type. If no size is specified in the constructor, the size defaults to 2.
> **Note** 
> Bounds checking is not implemented.

> **Note**
>The size grows differently depending on the current size of the vector: If the size is less than 10, the vector doubles. If the size is greater or equal to 10, the size grows by 1.5 


Typedefs                 | Description
------------------------ | :---------------------------------------------:
`value_type`             | value type T
`pointer_type`           | value type pointer
`reference_type`         | value type reference
`const_pointer_type`     | const value type pointer
`const_reference_type`   | const value type reference
`const_iterator`         | const_iterator with class vector<T>
`iterator`               | iterator with class vector<T>
`const_reverse_iterator` | const_reverse_iterator with class const_iterator
`reverse_iterator`       | reverse_iterator with class iterator

Constructor/Destructor                                             | Return Type | Description
------------------------------------------------------------------ | :---------: | :--------------------------------------------------------------------------------:
`vector()`                                                         | `N/A`       | vector capacity defaults to 2 if no size is specified
`vector(const size_t& capacity)`                                   | `N/A`       | constructs vector with specified size
`vector(const size_t& capacity, T&& fillElement)`                  | `N/A`       | constructs vector with specified size and fills it with the specified fill element
`vector(const size_t& capacity, const_reference_type fillElement)` | `N/A`       | constructs vector with specified size and fills it with the specified fill element
`~vector()`                                                        | `N/A`       | destructor calls clear and the ::operator delete on m_Data

Element Access                           | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`operator[](const size_t& index)`        | `reference_type`         | returns a reference to the vector at a specified index
`operator[](const size_t& index) const`  | `const_reference_type`   | returns a const reference to the vector at a specified index
`at(const size_t& index) const`          | `const_reference_type`   | returns a const reference to the vector at a specified index
`front()`                                | `reference_type`         | returns a reference to the first element in the vector
`back()`                                 | `reference_type`         | returns a reference to the last element in the vector
`front() const`                          | `const_reference_type`   | returns a const reference to the first element in the vector
`back() const`                           | `const_reference_type`   | returns a const reference to the last element in the vector
`data()`                                 | `pointer_type`           | returns a pointer to the vector
`data() const`                           | `const_pointer_type`     | returns a const pointer to the vector

Size Functions                           | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`empty() const`                          | `bool`                   | returns true if the vector is empty, false otherwise
`size() const`                           | `size_t`                 | returns the size of the vector
`max_size() const`                       | `size_t`                 | returns the max size of the vector

Mutator Functions                                                 | Return Type      | Description
----------------------------------------------------------------- | :--------------: | :------------------------------------------------------------:
`template<typename T> emplace_back(Args&&... args)`               | `reference_type` | constructs an element into the back of the vector
`template<typename T> emplace(iterator position, Args&&... args)` | `reference_type` | constructs an element at the specified position in the vector
`push_back(T&& element)`                                          | `reference_type` | inserts an element at the end of the vector
`push_back(const_reference_type element)`                         | `reference_type` | inserts an element at the end of the vector
`pop_back()`                                                      | `value_type`     | deletes the last element from the vector

Mutator Functions                                                | Return Type | Description
----------------------------------------------------------------- | :---------: | :-----------------------------------------------------------------:
`clear()`                                                         | `void`      | clears vector
`reserve(const size_t& size)`                                     | `void`      | reserves a specified size for the vector
`resize(const size_t& size)`                                      | `void`      | resizes vector to specified size
`shrink_to_fit()`                                                 | `void`      | shrinks vector to reduce unused memory

Private Helper Functions                                          | Return Type | Description
----------------------------------------------------------------- | :---------: | :----------------------------------------------------------------------------------:
`realloc(const size_t& newCapacity)`                              | `void`      | reallocates a new capacity for the vector. The growth function of the vector is as follows: size < 10 ? size doubles, else size grows 1.5x
`pow(const size_t& num, const size_t& power)`                     | `size_t`    | constructs an element at the specified position

Iterator Functions                       | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`cbegin() const`                         | `const_iterator`         | returns a const_iterator that points to the beginning of the vector
`cend() const`                           | `const_iterator`         | returns a const_iterator that points to the element after end of the vector
`begin()`                                | `iterator`               | returns an iterator that points to the beginning of the vector
`end()`                                  | `iterator`               | returns an iterator that points to the element after end of the vector
`crbegin() const`                        | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the vector
`crend() const`                          | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the vector
`rbegin()`                               | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the vector
`rend()`                                 | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the vector

Variables    | Type           | Description
------------ | :------------: | :---------------------------:
`m_Data`     | `pointer_type` | dynamic array with specified size
`m_Size`     | `size_t`       | size of the vector
`m_Capacity` | `size_t`       | capacity of the vector





### __List__ ###
- `mystl::list<typename T>`
- The `list` class is implemented with a doubly linked list
> **Note** 
>This class uses a list_iterator, which is a version of the iterator classes but for linked lists. See [List Iterator](#list-iterator "Goto list-iterator")

> **Note**
>This class uses a simple node struct. See [Node](#node "Goto node")

Typedefs                 | Description
------------------------ | :---------------------------------------------:
`value_type`             | value type T
`pointer_type`           | value type pointer
`reference_type`         | value type reference
`const_pointer_type`     | const value type pointer
`const_reference_type`   | const value type reference
`node`                   | node with type T
`node_ptr`               | node pointer
`const_iterator`         | list_const_iterator with class list<T>
`iterator`               | list_iterator with class list<T>
`const_reverse_iterator` | list_const_reverse_iterator with class const_iterator
`reverse_iterator`       | list_reverse_iterator with class iterator

Constructor/Destructor                                             | Return Type | Description
------------------------------------------------------------------ | :---------: | :--------------------------------------------------------------------------------:
`list()`                                                           | `N/A`       | list size defaults to 0 if no size is specified
`list(const size_t& size)`                                         | `N/A`       | constructs list with specified size
`vector(const size_t& size, T&& fillElement)`                      | `N/A`       | constructs list with specified size and fills it with the specified fill element
`~list()`                                                          | `N/A`       | destructor empties the list before destroying list

Element Access                           | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`operator[](const size_t& index)`        | `reference_type`         | returns a reference to the list at a specified index
`operator[](const size_t& index) const`  | `const_reference_type`   | returns a const reference to the list at a specified index
`front()`                                | `reference_type`         | returns a reference to the first element in the list
`back()`                                 | `reference_type`         | returns a reference to the last element in the list
`front() const`                          | `const_reference_type`   | returns a const reference to the first element in the list
`back() const`                           | `const_reference_type`   | returns a const reference to the last element in the list

Size Functions                           | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`empty() const`                          | `bool`                   | returns true if the list is empty, false otherwise
`size() const`                           | `size_t`                 | returns the size of the list

Mutator Functions                                                 | Return Type      | Description
----------------------------------------------------------------- | :--------------: | :------------------------------------------------------------------:
`template<typename T> emplace_front(Args&&... args)`              | `reference_type` | constructs an element into the front of the list
`template<typename T> emplace_back(Args&&... args)`               | `reference_type` | constructs an element into the back of the list
`template<typename T> emplace(iterator position, Args&&... args)` | `reference_type` | constructs an element at the specified position in the list
`insert(iterator position, T&& element)`                          | `reference_type` | inserts an element at a specified position in the list
`push_front(T&& element)`                                         | `reference_type` | inserts an element at the front of the list
`push_front(const_reference_type element)`                        | `reference_type` | inserts an element at the front of the list
`push_back(T&& element)`                                          | `reference_type` | inserts an element at the end of the list
`push_back(const_reference_type element)`                         | `reference_type` | inserts an element at the end of the list
`pop_front()`                                                     | `value_type`     | deletes the first element from the list
`pop_back()`                                                      | `value_type`     | deletes the last element from the list

Mutator Functions                                                 | Return Type | Description
----------------------------------------------------------------- | :---------: | :-----------------------------------------------------------------:
`clear()`                                                         | `void`      | clears list
`swap(list& other)`                                               | `void`      | swaps two lists
`resize(const size_t& size)`                                      | `void`      | resizes list to specified size

Mutator Functions                                                 | Return Type  | Description
----------------------------------------------------------------- | :---------:  | :-----------------------------------------------------------------:
`erase(iterator position)`                                        | `iterator`   | removes the element at the specified iterator position
`erase(iterator first, iterator last)`                            | `iterator`   | removes the elements between the first and last iterator positions
`remove(T&& element)`                                             | `value_type` | removes the element from the list given that it exists
`remove(const_reference_type element)`                            | `value_type` | removes the element from the list given that it exists
`template<class Predicate> remove_if(const Predicate& predicate)` | `void`       | removes an element based on a specified predicate
`sort()`                                                          | `void`       | sorts list
`template<class Compare> sort(const Compare& comparator)`         | `void`       | sorts list using a specified comparator
`merge()`                                                         | `void`       | merges two lists
`template<class Compare> merge(const Compare& comparator)`        | `void`       | merges two lists using a specified comparator
`reverse()`                                                       | `void`       | reverses list



Iterator Functions                       | Return Type              | Description
---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
`cbegin() const`                         | `const_iterator`         | returns a const_iterator that points to the beginning of the list
`cend() const`                           | `const_iterator`         | returns a const_iterator that points to the element after end of the list
`begin()`                                | `iterator`               | returns an iterator that points to the beginning of the list
`end()`                                  | `iterator`               | returns an iterator that points to the element after end of the list
`crbegin() const`                        | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the list
`crend() const`                          | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the list
`rbegin()`                               | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the list
`rend()`                                 | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the list

Variables    | Type           | Description
------------ | :------------: | :---------------------------:
`m_Head`     | `node-ptr`     | points to the head of the list
`m_Tail`     | `node_ptr`     | points to the tail of the list
`m_Size`     | `size_t`       | size of the list





### __Deque__ ###
Documentation WIP
### __Queue__ ###
Documentation WIP
### __Stack__ ###
Documentation WIP




## __Iterators__ ##


### __Const Iterator__ ###
- `mystl::const_iterator<class C>`
- `Abstract Class`

Typedefs               | Description
---------------------- | :---------------------------------------------:
`value_type`           | value type of T
`const_pointer_type`   | const value type pointer
`const_reference_type` | const value type reference
`ptrdiff_t`            | pointer difference: used for pointer arithmetic

Constructor                                | Return Type                | Description                                                                            | Overloadable
------------------------------------------ | :------------------------: | :------------------------------------------------------------------------------------: | :----------:
`const_iterator(const_pointer_type ptr)`   | `N/A`                      | constructor                                                                            | N

Element Access                             | Return Type                | Description                                                                            | Overloadable
------------------------------------------ | :------------------------: | :------------------------------------------------------------------------------------: | :----------:
`operator[](const size_t& offset)`         | `const_reference_type`     | returns a const reference at a given pointer offset                                    | Y
`operator*()`                              | `const_reference_type`     | dereference operator                                                                   | N
`operator->()`                             | `const_pointer_type`       | pointer operator                                                                       | N

Mutator  Functions                         | Return Type                | Description                                                                            | Overloadable
------------------------------------------ | :------------------------: | :------------------------------------------------------------------------------------: | :----------:
`operator++`                               | `const_iterator reference` | (prefix) increments const_iterator                                                     | Y
`operator++(int)`                          | `const_iterator`           | (postfix) increments const_iterator                                                    | Y
`operator+(const size_t& offset)`          | `const_iterator reference` | increments const_iterator by an offset                                                 | Y
`operator++`                               | `const_iterator reference` | (prefix) decrements const_iterator                                                     | Y
`operator++(int)`                          | `const_iterator`           | (postfix) decrements const_iterator                                                    | Y
`operator-(const size_t& offset)`          | `const_iterator reference` | decrements const_iterator by an offset                                                 | Y
`operator-(const_iterator other)`          | `ptrdiff_t`                | returns the pointer difference between two const_iterators                             | Y

Equality Operators                         | Return Type                | Description                                                                            | Overloadable
------------------------------------------ | :------------------------: | :------------------------------------------------------------------------------------: | :----------:
`operator==(const_iterator& other) const`  | `bool`                     | returns true if both const_iterators point to the same address, false otherwise        | N
`operator!=(const_iterator& othter) const` | `bool`                     | returns true if the two const_iterators point to different addresses, false otherwise  | N

Variables    | Type                 | Description
---------    | :------------------: | :---------------------:
`m_ConstPtr` | `const_pointer_type` | const pointer to object





### __Iterator__ ###
- `mystl::iterator<class C>`

Typedefs         | Description
---------------- | :---------------------------------------------:
`base_class`     | base class that iterator inherits from(const_iterator)
`value_type`     | value type of T
`pointer_type`   | const value type pointer
`reference_type` | const value type reference
`ptrdiff_t`      | pointer difference: used for pointer arithmetic

Constructor                                | Return Type                | Description                                                          | Overloadable
------------------------------------------ | :------------------------: | :------------------------------------------------------------------: | :----------:
`iterator(pointer_type ptr)`               | `N/A`                      | constructor                                                          | N

Element Access                             | Return Type          | Description                                                                | Overloadable
------------------------------------------ | :------------------: | :------------------------------------------------------------------------- | :----------:
`operator[](const size_t& offset)`         | `reference_type`     | returns a reference at a given pointer offset                              | Y
`operator*()`                              | `reference_type`     | dereference operator                                                       | N
`operator->()`                             | `pointer_type`       | pointer operator                                                           | N

Mutator  Functions                         | Return Type          | Description                                                                | Overloadable
------------------------------------------ | :------------------: | :------------------------------------------------------------------------: | :----------:
`operator++`                               | `iterator reference` | (prefix) increments iterator                                               | Y
`operator++(int)`                          | `iterator`           | (postfix) increments iterator                                              | Y
`operator+(const size_t& offset)`          | `iterator reference` | increments iterator by an offset                                           | Y
`operator++`                               | `iterator reference` | (prefix) decrements iterator                                               | Y
`operator++(int)`                          | `iterator`           | (postfix) decrements iterator                                              | Y
`operator-(const size_t& offset)`          | `iterator reference` | decrements iterator by an offset                                           | Y
`operator-(iterator other)`          | `ptrdiff_t`                | returns the pointer difference between two iterators                       | Y

Equality Operators                         | Return Type                | Description                                                                            | Overloadable
------------------------------------------ | :------------------------: | :------------------------------------------------------------------------------------: | :----------:
`operator==(const_iterator& other) const`  | `bool`                     | returns true if both const_iterators point to the same address, false otherwise        | N
`operator!=(const_iterator& othter) const` | `bool`                     | returns true if the two const_iterators point to different addresses, false otherwise  | N





### __Const Reverse Iterator__ ###
- `mystl::const_reverse_iterator<class C>`
- `Abstract Class`

Typedefs               | Description
---------------------- | :------------------------:
`iterator_type`        | type of iterator T
`value_type`           | value type of T
`const_pointer_type`   | const value type pointer
`const_reference_type` | const value type reference

Constructor                                      | Return Type                        | Description                                          | Overloadable
------------------------------------------------ | :--------------------------------: | :--------------------------------------------------: | :----------:
`const_reverse_iterator(const_pointer_type ptr)` | `N/A`                              | constructor                                          | N

Element Access                                   | Return Type                        | Description                                          | Overloadable
------------------------------------------------ | :------------------:               | :--------------------------------------------------: | :----------:
`operator[](const size_t& offset)`               | `const_reference_type`             | returns a const reference at a given pointer offset  | Y
`operator*()`                                    | `const_reference_type`             | dereference operator                                 | N
`operator->()`                                   | `const_pointer_type`               | pointer operator                                     | N

Mutator  Functions                               | Return Type                        | Description                                            | Overloadable
------------------------------------------------ | :--------------------------------: | :----------------------------------------------------: | :----------:
`operator++`                                     | `const_reverse_iterator reference` | (prefix) decrements const_reverse_iterator             | Y
`operator++(int)`                                | `const_reverse_iterator`           | (postfix) decrements const_reverse_iterator            | Y
`operator+(const size_t& offset)`                | `const_reverse_iterator reference` | decrements const_reverse_iterator by an offset         | Y
`operator++`                                     | `const_reverse_iterator reference` | (prefix) increments const_reverse_iterator             | Y
`operator++(int)`                                | `const__reverse_iterator`          | (postfix) increments const_reverse_iterator            | Y
`operator-(const size_t& offset)`                | `const_reverse_iterator reference` | increments const_reverse_iterator by an offset         | Y

Equality Operators                               | Return Type                | Description                                                                                   | Overloadable
------------------------------------------------ | :------------------------: | :-------------------------------------------------------------------------------------------: | :----------:
`operator==(const_iterator& other) const`        | `bool`                     | returns true if both const_reverse_iterators point to the same address, false otherwise       | N
`operator!=(const_iterator& othter) const`       | `bool`                     | returns true if the two const_reverse_iterators point to different addresses, false otherwise | N

Variables       | Type                 | Description
--------------- | :------------------: | :-----------------------:
`m_ConstRevPtr` | `const_pointer_type` | const pointer to object





### __Reverse Iterator__ ###
- `mystl::reverse_iterator<class C>`
- `Abstract Class`

Typedefs               | Description
---------------------- | :------------------------:
`base_class`           | base class that reverse_iterator inherits from(const_reverse_iterator)
`iterator_type`        | type of iterator T
`value_type`           | value type of T
`pointer_type`         | const value type pointer
`reference_type`       | const value type reference

Constructor                                      | Return Type                        | Description                                          | Overloadable
------------------------------------------------ | :--------------------------------: | :--------------------------------------------------: | :----------:
`reverse_iterator(pointer_type ptr)`             | `N/A`                              | constructor                                          | N

Element Access                                   | Return Type                  | Description                                          | Overloadable
------------------------------------------------ | :------------------:         | :--------------------------------------------------: | :----------:
`operator[](const size_t& offset)`               | `reference_type`             | returns a const reference at a given pointer offset  | Y
`operator*()`                                    | `reference_type`             | dereference operator                                 | N
`operator->()`                                   | `pointer_type`               | pointer operator                                     | N

Mutator  Functions                               | Return Type                  | Description                                            | Overloadable
------------------------------------------------ | :--------------------------: | :----------------------------------------------------: | :----------:
`operator++`                                     | `reverse_iterator reference` | (prefix) decrements const_reverse_iterator             | Y
`operator++(int)`                                | `reverse_iterator`           | (postfix) decrements const_reverse_iterator            | Y
`operator+(const size_t& offset)`                | `reverse_iterator reference` | decrements const_reverse_iterator by an offset         | Y
`operator++`                                     | `reverse_iterator reference` | (prefix) increments const_reverse_iterator             | Y
`operator++(int)`                                | `reverse_iterator`           | (postfix) increments const_reverse_iterator            | Y
`operator-(const size_t& offset)`                | `reverse_iterator reference` | increments const_reverse_iterator by an offset         | Y

Equality Operators                               | Return Type                | Description                                                                                   | Overloadable
------------------------------------------------ | :------------------------: | :-------------------------------------------------------------------------------------------: | :----------:
`operator==(const_iterator& other) const`        | `bool`                     | returns true if both const_reverse_iterators point to the same address, false otherwise       | N
`operator!=(const_iterator& othter) const`       | `bool`                     | returns true if the two const_reverse_iterators point to different addresses, false otherwise | N





### __List Iterator__ ###




## __Smaller Data Structures__ ##


### __Node__ ###
Typedefs               | Description
---------------------- | :------------------------:
`value_type`           | value type of T

Constructor                    | Return Type  | Description
----------------------         | :----------: | :------------:
`node()`                       | `N/A`        | default constructor
`node(const value_type& data)` | `N/A`        | assigns data to a specified value
`~node()`                      | `N/A`        | default destructor

Variables    | Type          | Description
------------ | :-----------: | :---------------------------:
`data`       | `value_type`  | data that the node holds
`next`       | `node*`       | pointer to the next node
`prev`       | `node*`       | pointer to the previous node






