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
- [Const_Iterator](#const-iterator "Goto const-iterator")
- [Iterator](#iterator "Goto iterator")
- [Const_Reverse_Iterator](#const-reverse-iterator "Goto const-reverse-iterator")
- [Reverse_Iterator](#reverse-iterator "Goto reverse-iterator")
- [Array](#array "Goto array")
- [Vector](#vector "Goto array")

    
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
- `mystl::const_iterator<class C>`
- `Abstract Class`

Typedefs               | Description
---------------------- | :---------------------------------------------:
`value_type`           | value type of T
`const_pointer_type`   | const value type pointer
`const_reference_type` | const value type reference
`ptrdiff_t`            | pointer difference: used for pointer arithmetic

Function Name                              | Return Type                | Description                                                                            | Overloadable
------------------------------------------ | :------------------------: | :------------------------------------------------------------------------------------: | :----------:
`const_iterator(const_pointer_type ptr)`   | `N/A`                      | constructor                                                                            | N
`operator[](const size_t& offset)`         | `const_reference_type`     | returns a const reference at a given pointer offset                                    | Y
`operator*()`                              | `const_reference_type`     | dereference operator                                                                   | N
`operator->()`                             | `const_pointer_type`       | pointer operator                                                                       | N
`operator++`                               | `const_iterator reference` | (prefix) increments const_iterator                                                     | Y
`operator++(int)`                          | `const_iterator`           | (postfix) increments const_iterator                                                    | Y
`operator+(const size_t& offset)`          | `const_iterator reference` | increments const_iterator by an offset                                                 | Y
`operator++`                               | `const_iterator reference` | (prefix) decrements const_iterator                                                     | Y
`operator++(int)`                          | `const_iterator`           | (postfix) decrements const_iterator                                                    | Y
`operator-(const size_t& offset)`          | `const_iterator reference` | decrements const_iterator by an offset                                                 | Y
`operator-(const_iterator other)`          | `ptrdiff_t`                | returns the pointer difference between two const_iterators                             | Y
`operator==(const_iterator& other) const`  | `bool`                     | returns true if both const_iterators point to the same address, false otherwise        | N
`operator!=(const_iterator& othter) const` | `bool`                     | returns true if the two const_iterators point to different addresses, false otherwise  | N

Variables    | Type                 | Description
---------    | :------------------: | :---------------------:
`m_ConstPtr` | `const_pointer_type` | const pointer to object





### __Iterator__ ###
- `mystl::iterator<class C>`
- `Abstract Class`

Typedefs         | Description
---------------- | :---------------------------------------------:
`value_type`     | value type of T
`pointer_type`   | value type pointer
`reference_type` | value type reference
`ptrdiff_t`      | pointer difference: used for pointer arithmetic

Function Name                        | Return Type          | Description                                                                     | Overloadable
------------------------------------ | :------------------: | :-----------------------------------------------------------------------------: | :----------:
`iterator(pointer_type ptr)`         | `N/A`                | constructor                                                                     | N
`operator[](const size_t& offset)`   | `reference_type`     | returns reference at a given pointer offset                                     | Y
`operator*()`                        | `reference_type`     | dereference operator                                                            | N
`operator->()`                       | `pointer_type`       | pointer operator                                                                | N
`operator++`                         | `iterator reference` | (prefix) increments iterator                                                    | Y
`operator++(int)`                    | `iterator`           | (postfix) increments iterator                                                   | Y
`operator+(const size_t& offset)`    | `iterator reference` | increments iterator by an offset                                                | Y
`operator++`                         | `iterator reference` | (prefix) decrements iterator                                                    | Y
`operator++(int)`                    | `iterator`           | (postfix) decrements iterator                                                   | Y
`operator-(const size_t& offset)`    | `iterator reference` | decrements iterator by an offset                                                | Y
`operator-(iterator other)`          | `ptrdiff_t`          | returns the pointer difference between two iterators                            | Y
`operator==(iterator& other) const`  | `bool`               | returns true if both iterators point to the same address, false otherwise       | N
`operator!=(iterator& othter) const` | `bool`               | returns true if the two iterators point to different addresses, false otherwise | N

Variables | Type         | Description
--------- | :----------: | :-----------------:
`m_Ptr`   | `pointer_type` | pointer to object





### __Const Reverse Iterator__ ###
- `mystl::const_reverse_iterator<class C>`
- `Abstract Class`

Typedefs               | Description
---------------------- | :------------------------:
`iterator_type`        | type of iterator T
`value_type`           | value type of T
`const_pointer_type`   | const value type pointer
`const_reference_type` | const value type reference

Function Name                                    | Return Type                        | Description                                                                    | Overloadable
------------------------------------------------ | :--------------------------------: | :----------------------------------------------------------------------------: | :----------:
`const_reverse_iterator(const_pointer_type ptr)` | `N/A`                              | constructor                                                                    | N
`operator[](const size_t& offset)`               | `const_reference_type`             | returns a const reference at a given pointer offset                            | Y
`operator*()`                                    | `const_reference_type`             | dereference operator                                                           | N
`operator->()`                                   | `const_pointer_type`               | pointer operator                                                               | N
`operator++`                                     | `const_reverse_iterator reference` | (prefix) decrements const_reverse_iterator                                     | Y
`operator++(int)`                                | `const_reverse_iterator`           | (postfix) decrements const_reverse_iterator                                    | Y
`operator+(const size_t& offset)`                | `const_reverse_iterator reference` | decrements const_reverse_iterator by an offset                                 | Y
`operator++`                                     | `const_reverse_iterator reference` | (prefix) increments const_reverse_iterator                                     | Y
`operator++(int)`                                | `const__reverse_iterator`          | (postfix) increments const_reverse_iterator                                    | Y
`operator-(const size_t& offset)`                | `const_reverse_iterator reference` | increments const_reverse_iterator by an offset                                 | Y
`operator==(const_iterator& other) const`        | `bool`                             | returns true if both const_reverse_iterators point to the same address, false  | N                                                                                      otherwise
`operator!=(const_iterator& othter) const`       | `bool`                             | returns true if the two const_reverse_iterators point to different addresses,  | N                                                                                      false otherwise

Variables       | Type                 | Description
--------------- | :------------------: | :-----------------------:
`m_ConstRevPtr` | `const_pointer_type` | const pointer to object





### __Reverse Iterator__ ###
- `mystl::reverse_iterator<class C>`
- `Abstract Class`

Typedefs                | Description
----------------------- | :------------------:
`iterator_type`         | type of iterator T
`value_type`            | value type of T
`pointer_type`          | value type pointer
`reference_type`        | value type reference

Function Name                                | Return Type                  | Description                                                                             | Overloadable
-------------------------------------------- | :--------------------------: | :-------------------------------------------------------------------------------------: | :----------:
`reverse_iterator(pointer_type ptr)`         | `N/A`                        | constructor                                                                             | N
`operator[](const size_t& offset)`           | `reference_type`             | returns reference at a given pointer offset                                             | Y
`operator*()`                                | `reference_type`             | dereference operator                                                                    | N
`operator->()`                               | `pointer_type`               | pointer operator                                                                        | N
`operator++`                                 | `reverse_iterator reference` | (prefix) decrements reverse_iterator                                                    | Y
`operator++(int)`                            | `reverse_iterator`           | (postfix) decrements reverse_iterator                                                   | Y
`operator+(const size_t& offset)`            | `reverse_iterator reference` | decrements reverse_iterator by an offset                                                | Y
`operator++`                                 | `reverse_iterator reference` | (prefix) increments reverse_iterator                                                    | Y
`operator++(int)`                            | `reverse_iterator`           | (postfix) increments reverse_iterator                                                   | Y
`operator-(const size_t& offset)`            | `reverse_iterator reference` | increments reverse_iterator by an offset                                                | Y
`operator==(reverse_iterator& other) const`  | `bool`                       | returns true if both reverse_iterators point to the same address, false otherwise       | N
`operator!=(reverse_iterator& othter) const` | `bool`                       | returns true if the two reverse_iterators point to different addresses, false otherwise | N

Variables  | Type           | Description
---------- | :------------: | :---------------:
`m_RevPtr` | `pointer_type` | pointer to object





### __Array__ ###
- `mystl::array<typename T, size_t m_Size>`

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
`fill(const_reference_type fillElement)` | `[[noreturn]] void`      | fills the array with a given value
`swap(array& other)`                     | `[[noreturn]] void`      | swaps two arrays

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
`empty() const`                          | `bool`                   | returns true if the vector is empty, false otherwise

Modifier Functions                                                | Return Type      | Description
----------------------------------------------------------------- | :--------------: | :------------------------------------------------------------:
`template<typename T> emplace_back(Args&&... args)`               | `reference_type` | constructs an element into the back of the vector
`template<typename T> emplace(iterator position, Args&&... args)` | `reference_type` | constructs an element at the specified position
`push_back(T&& element)`                                          | `reference_type` | inserts element at the end of the vector
`push_back(const_reference_type element)`                         | `reference_type` | inserts element at the end of the vector
`pop_back()`                                                      | `reference_type` | deletes the last element from the vector

Modifier Functions                                                | Return Type | Description
----------------------------------------------------------------- | :---------: | :-----------------------------------------------------------------:
`clear()`                                                         | `void`      | constructs an element into the back of the vector
`reserve(cosnt size_t& size)`                                     | `void`      | constructs an element at the specified position
`resize(const size_t& size)`                                      | `void`      | inserts element at the end of the vector
`shrink_to_fit()`                                                 | `void`      | inserts element at the end of the vector

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
`m_Size`     | `pointer_type` | size of the vector
`m_Capacity` | `pointer_type` | capacity of the vector




