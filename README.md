# __MySTL__ #
## __Introduction__ ##
This is a personal project that aims to replicate the C++ Standard Template Library. The goal of this project is to have a fuller understanding of data structures and algorithms. 

> **Note**
> All data structures and algorithms are in the `mystl` namespace.

> **Note** 
> There will be "incomplete" data structures. "Incomplete" is defined by an omission of some functions that the STL version contains.

This project is split into two parts: data structures and algorithms. Documentation is provided below.

## __Data Structures__ ##
Below are the list of data structures that have been implemented. The data structures are partitioned into subgroups: basic, trees, tables/maps/skip list, and graphs. 
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

The array data structure stores elements of a specified data type in a contiguous block of memory. In this project, the array data structure is implemented using a raw array. The array has two template arguments: a data type and a size. If no size is specified, the size defaults to 1. The array has a fixed size and cannot be changed dynamically.

> Syntax: `mystl::array<T, size>`

> **Note** 
> In release mode, bounds checking is disabled.

<details>
  <summary>Typedefs</summary>
  <p>

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
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>

  Constructor/Destructor                   | Return Type              | Description
  ---------------------------------------- | :----------------------: | :------------------:
  `array()`                                | `N/A`                    | default constructor
  `~array()`                               | `N/A`                    | default destructor
  </p>
</details>

<details>
  <summary>Element Access</summary>
  <p>

  Element Access                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :-----------------------------------------------------------:
  `operator[](const size_t& index)`        | `reference_type`         | returns a reference to the array at a specified index
  `operator[](const size_t& index) const`  | `const_reference_type`   | returns a const reference to the array at a specified index
  `at(const size_t& index) const`          | `const_reference_type`   | returns a const reference to the array at a specified index
  `front()`                                | `reference_type`         | returns a reference to the first element in the array
  `back()`                                 | `reference_type`         | returns a reference to the last element in the array
  `front() const`                          | `const_reference_type`   | returns a const reference to the first element in the array
  `back() const`                           | `const_reference_type`   | returns a const reference to the last element in the array 
  `data()`                                 | `pointer_type`           | returns a pointer to the array
  `data() const`                           | `const_pointer_type`     | returns a const pointer to the array
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>

  Mutator Functions                        | Return Type              | Description
  ---------------------------------------- | :----------------------: | :---------------------------------:
  `fill(const_reference_type fillElement)` | `void`                   | fills the array with a given value
  `swap(array& other)`                     | `void`                   | swaps two arrays
  </p>
</details>

<details>
  <summary>Size Functions</summary>
  <p>

  Size Functions                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :--------------------------------------------------------------------:
  `size() const`                           | `size_t`                 | returns the size of the array
  `max_size() const`                       | `size_t`                 | returns the max size of the array (returns the same value as size())
  `empty() const`                          | `bool`                   | returns true if the array is empty, false otherwise
  </p>
</details>

<details>
  <summary>Iterator Functions</summary>
  <p>

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
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>

  Variables  | Type           | Description
  ---------- | :------------: | :---------------------------:
  `m_Data`   | `pointer_type` | raw array with specified size
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  <p>
    
-   <details>
      <summary>Element Access</summary>
      <p>
      
      Element Access                           | Time Complexity
      ---------------------------------------- | :--------------:
      `operator[](const size_t& index)`        | O(1)
      `operator[](const size_t& index) const`  | O(1)
      `at(const size_t& index) const`          | O(1)
      `front()`                                | O(1)
      `back()`                                 | O(1)
      `front() const`                          | O(1)
      `back() const`                           | O(1)
      `data()`                                 | O(1)
      `data() const`                           | O(1)
      
      </p>
    </details>

-   <details>
      <summary>Size Functions</summary>
      <p>

      Size Functions      | Time Complexity
      ------------------- | :--------------:
      `size() const`      | O(1)
      `max_size() const`  | O(1)
      `empty() const`     | O(1)
      </p>
    </details>

-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                        | Time Complexity
      ---------------------------------------- | :--------------:
      `fill(const_reference_type fillElement)` | O(n)
      `swap(array& other)`                     | O(1)
      </p>
    </details>

-   <details>
      <summary>Iterator Functions</summary>
      <p>
      
      Iterator Functions                       | Time Complexity
      ---------------------------------------- | :--------------:
      `cbegin() const`                         | O(1)
      `cend() const`                           | O(1)
      `begin()`                                | O(1)
      `end()`                                  | O(1)
      `crbegin() const`                        | O(1)
      `crend() const`                          | O(1)
      `rbegin()`                               | O(1)
      `rend()`                                 | O(1)
      </p>
    </details>
    </p>
</details>


- - - -


### __Vector__ ###

The vector data structure stores elements of a specified data type in a contiguous block of memory that can grow and shrink dynamically. In this project, the vector data structure is implemented using a raw __dynamic__ array. The vector has one template argument: a data type. There are two size variables: size and capacity. The size refers to the amount of elements in the vector that are nonnull. The capacity refers to the amount of elements the vector can hold. If no capacity is specified in the constructor, the capacity of the vector defaults to 2. The capacity grows automatically if the size exceeds the capacity.

> Syntax: `mystl::vector<T>`

> **Note** 
> Bounds checking is not implemented.

> **Note**
> The size grows differently depending on the current size of the vector: If the size is less than 10, the vector doubles. If the size is greater or equal to 10, the size grows by 1.5 

<details>
  <summary>Typedefs</summary>
  <p>
   
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
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>
   
  Constructor/Destructor                                             | Return Type | Description
  ------------------------------------------------------------------ | :---------: | :----------------------------------------------------------:
  `vector()`                                                         | `N/A`       | vector capacity defaults to 2 if no size is specified
  `vector(const size_t& capacity)`                                   | `N/A`       | constructs vector with specified size
  `vector(const size_t& capacity, T&& fillElement)`                  | `N/A`       | constructs vector with specified size and fills it with the specified fill element
  `vector(const size_t& capacity, const_reference_type fillElement)` | `N/A`       | constructs vector with specified size and fills it with the specified fill element
  `~vector()`                                                        | `N/A`       | destructor calls clear and the ::operator delete on m_Data
  </p>
</details>

<details>
  <summary>Element Access</summary>
  <p>
   
  Element Access                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :------------------------------------------------------------:
  `operator[](const size_t& index)`        | `reference_type`         | returns a reference to the vector at a specified index
  `operator[](const size_t& index) const`  | `const_reference_type`   | returns a const reference to the vector at a specified index
  `at(const size_t& index) const`          | `const_reference_type`   | returns a const reference to the vector at a specified index
  `front()`                                | `reference_type`         | returns a reference to the first element in the vector
  `back()`                                 | `reference_type`         | returns a reference to the last element in the vector
  `front() const`                          | `const_reference_type`   | returns a const reference to the first element in the vector
  `back() const`                           | `const_reference_type`   | returns a const reference to the last element in the vector
  `data()`                                 | `pointer_type`           | returns a pointer to the vector
  `data() const`                           | `const_pointer_type`     | returns a const pointer to the vector
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>
   
  Mutator Functions                                                 | Return Type      | Description
  ----------------------------------------------------------------- | :--------------: | :------------------------------------------------------------:
  `template<typename T> emplace_back(Args&&... args)`               | `reference_type` | constructs an element into the back of the vector
  `template<typename T> emplace(iterator position, Args&&... args)` | `reference_type` | constructs an element at the specified position in the vector
  `push_back(T&& element)`                                          | `reference_type` | inserts an element at the end of the vector
  `push_back(const_reference_type element)`                         | `reference_type` | inserts an element at the end of the vector
  `pop_back()`                                                      | `value_type`     | deletes the last element from the vector
  `clear()`                                                         | `void`           | clears vector
  `reserve(const size_t& size)`                                     | `void`           | reserves a specified size for the vector
  `resize(const size_t& size)`                                      | `void`           | resizes vector to specified size
  `shrink_to_fit()`                                                 | `void`           | shrinks vector to reduce unused memory
  </p>
</details>

<details>
  <summary>Size Functions</summary>
  <p>
   
  Size Functions                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :---------------------------------------------------:
  `empty() const`                          | `bool`                   | returns true if the vector is empty, false otherwise
  `size() const`                           | `size_t`                 | returns the size of the vector
  `max_size() const`                       | `size_t`                 | returns the max size of the vector
  `capacity() const`                       | `size_t`                 | returns the capacity of the vector
   </p>
</details>

<details>
  <summary>Private Helper Functions</summary>
  <p>
   
  Private Helper Functions                                          | Return Type | Description
  ----------------------------------------------------------------- | :---------: | :-------------------------------------------------------------------:
  `realloc(const size_t& newCapacity)`                              | `void`      | reallocates a new capacity for the vector. The growth function of the vector is as follows: size < 10 ? size doubles, else size grows 1.5x
  `pow(const size_t& num, const size_t& power)`                     | `size_t`    | constructs an element at the specified position
  </p>
</details>

<details>
  <summary>Iterator Functions</summary>
  <p>
   
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
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>
   
  Variables    | Type           | Description
  ------------ | :------------: | :---------------------------:
  `m_Data`     | `pointer_type` | dynamic array with specified size
  `m_Size`     | `size_t`       | size of the vector
  `m_Capacity` | `size_t`       | capacity of the vector
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  <p>
  
-   <details>
      <summary>Element Access</summary>
      <p>

      Element Access                           | Time Complexity
      ---------------------------------------- | :--------------:
      `operator[](const size_t& index)`        | O(1)
      `operator[](const size_t& index) const`  | O(1)
      `at(const size_t& index) const`          | O(1)
      `front()`                                | O(1)
      `back()`                                 | O(1)
      `front() const`                          | O(1)
      `back() const`                           | O(1)
      `data()`                                 | O(1)
      `data() const`                           | O(1)
      </p>
    </details>

-   <details>
      <summary>Size Functions</summary>
      <p>

      Size Functions      | Time Complexity
      ------------------- | :--------------:
      `empty() const`     | O(1)
      `size() const`      | O(1)
      `max_size() const`  | O(1)
      `capacity() const`  | O(1)
      </p>
    </details>

-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                                                 | Time Complexity
      ----------------------------------------------------------------- | :--------------:
      `template<typename T> emplace_back(Args&&... args)`               | Amortized O(1)
      `template<typename T> emplace(iterator position, Args&&... args)` | O(n)
      `push_back(T&& element)`                                          | Amortized O(1)
      `push_back(const_reference_type element)`                         | Amortized O(1)
      `pop_back()`                                                      | Amortized O(1)
      `clear()`                                                         | O(n)
      `reserve(const size_t& size)`                                     | O(1)
      `resize(const size_t& size)`                                      | O(n)
      `shrink_to_fit()`                                                 | O(n)
      </p>
    </details>

-   <details>
      <summary>Private Helper Functions</summary>
      <p>

      Private Helper Functions                                          | Time Complexity
      ----------------------------------------------------------------- | :--------------:
      `realloc(const size_t& newCapacity)`                              | O(n)
      `pow(const size_t& num, const size_t& power)`                     | O(n)
      </p>
    </details>

-   <details>
      <summary>Iterator Functions</summary>
      <p>
      
      Iterator Functions                       | Time Complexity
      ---------------------------------------- | :--------------:
      `cbegin() const`                         | O(1)
      `cend() const`                           | O(1)
      `begin()`                                | O(1)
      `end()`                                  | O(1)
      `crbegin() const`                        | O(1)
      `crend() const`                          | O(1)
      `rbegin()`                               | O(1)
      `rend()`                                 | O(1)
      </p>
    </details>
    </p>
</details>

 - - - -


### __List__ ###

The list data structure is a representation of a linked list and stores elements of a specified data type in non-contiguous memory locations. In this project, the list data structure is implemented using a doubly linked list and uses a smaller, simple [node](#node "Goto node") struct as a subcontainer. The list takes in one template argument: a data type. A singly linked list has a pointer to the next node in the list, while a doubly linked list has pointers to the next __and__ previous nodes in the list. A doubly linked list was chosen over a singly linked list for this project due to its versatility and performance benefits.

> Syntax: `mystl::list<T>`

> **Note** 
> This class uses a list_iterator, which is a version of the iterator data structure but for linked lists. See [List Iterator](#list-iterator "Goto list-iterator")

> **Note**
> This data structure is used to implement the [deque](#deque "Goto deque") data structure.

<details>
  <summary>Typedefs</summary>
  <p>

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
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>
   
  Constructor/Destructor                                             | Return Type | Description
  ------------------------------------------------------------------ | :---------: | :------------------------------------------------------------------:
  `list()`                                                           | `N/A`       | list size defaults to 0 if no size is specified
  `list(const size_t& size)`                                         | `N/A`       | constructs list with specified size
  `vector(const size_t& size, T&& fillElement)`                      | `N/A`       | constructs list with specified size and fills it with the specified fill element
  `~list()`                                                          | `N/A`       | destructor empties the list before destroying list
  </p>
</details>

<details>
  <summary>Element Access</summary>
  <p>
   
  Element Access                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
  `operator[](const size_t& index)`        | `reference_type`         | returns a reference to the list at a specified index
  `operator[](const size_t& index) const`  | `const_reference_type`   | returns a const reference to the list at a specified index
  `front()`                                | `reference_type`         | returns a reference to the first element in the list
  `back()`                                 | `reference_type`         | returns a reference to the last element in the list
  `front() const`                          | `const_reference_type`   | returns a const reference to the first element in the list
  `back() const`                           | `const_reference_type`   | returns a const reference to the last element in the list
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>
   
  Mutator Functions                                                 | Return Type      | Description
  ----------------------------------------------------------------- | :--------------: | :----------------------------------------------------------:
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
  `clear()`                                                         | `void`           | clears list
  `swap(list& other)`                                               | `void`           | swaps two lists
  `resize(const size_t& size)`                                      | `void`           | resizes list to specified size
  `erase(iterator position)`                                        | `iterator`       | removes the element at the specified iterator position
  `erase(iterator first, iterator last)`                            | `iterator`       | removes the elements between the first and last iterator positions
  `remove(T&& element)`                                             | `value_type`     | removes the element from the list given that it exists
  `remove(const_reference_type element)`                            | `value_type`     | removes the element from the list given that it exists
  `template<class Predicate> remove_if(const Predicate& predicate)` | `void`           | removes an element based on a specified predicate
  </p>
</details>

<details>
  <summary>Mutator Functions (Algorithms)</summary>
  <p>
   
  Mutator Functions (Algorithms)                                    | Return Type      | Description
  ----------------------------------------------------------------- | :--------------: | :----------------------------------------------------------:
  `sort()`                                                          | `void`           | sorts list in ASCII order
  `template<class Compare> sort(const Compare& comparator)`         | `void`           | sorts list using a specified comparator
  `merge()`                                                         | `void`           | merges two lists
  `template<class Compare> merge(const Compare& comparator)`        | `void`           | merges two lists using a specified comparator
  `reverse()`                                                       | `void`           | reverses list
  </p>
</details>
  
<details>
  <summary>Size Functions</summary>
  <p>
   
  Size Functions                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
  `empty() const`                          | `bool`                   | returns true if the list is empty, false otherwise
  `size() const`                           | `size_t`                 | returns the size of the list
  </p>
</details>

<details>
  <summary>Iterator Functions</summary>
  <p>
   
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
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>
   
  Variables    | Type           | Description
  ------------ | :------------: | :---------------------------:
  `m_Head`     | `node-ptr`     | points to the head of the list
  `m_Tail`     | `node_ptr`     | points to the tail of the list
  `m_Size`     | `size_t`       | size of the list
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  <p>
  
-   <details>
      <summary>Element Access</summary>
      <p>

      Element Access                           | Time Complexity
      ---------------------------------------- | :--------------:
      `operator[](const size_t& index)`        | O(n)
      `operator[](const size_t& index) const`  | O(n)
      `front()`                                | O(1)
      `back()`                                 | O(1)
      `front() const`                          | O(1)
      `back() const`                           | O(1)
      </p>
    </details>


-   <details>
      <summary>Size Functions</summary>
      <p>

      Size Functions                           | Time Complexity
      ---------------------------------------- | :--------------:
      `empty() const`                          | O(1)
      `size() const`                           | O(1)
      </p>
    </details>


-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                                                 | Time Complexity
      ----------------------------------------------------------------- | :--------------:
      `template<typename T> emplace_front(Args&&... args)`              | O(1)
      `template<typename T> emplace_back(Args&&... args)`               | O(1)
      `template<typename T> emplace(iterator position, Args&&... args)` | O(n)
      `insert(iterator position, T&& element)`                          | O(n)
      `push_front(T&& element)`                                         | O(1)
      `push_front(const_reference_type element)`                        | O(1)
      `push_back(T&& element)`                                          | O(1)
      `push_back(const_reference_type element)`                         | O(1)
      `pop_front()`                                                     | O(1)
      `pop_back()`                                                      | O(1)
      `clear()`                                                         | O(n)
      `swap(list& other)`                                               | O(1)
      `resize(const size_t& size)`                                      | O(n)
      `erase(iterator position)`                                        | O(n)
      `erase(iterator first, iterator last)`                            | O(n)
      `remove(T&& element)`                                             | O(n)
      `remove(const_reference_type element)`                            | O(n)
      `template<class Predicate> remove_if(const Predicate& predicate)` | O(n)
      `sort()`                                                          | O(nlog(n))
      `template<class Compare> sort(const Compare& comparator)`         | O(nlog(n))
      `merge()`                                                         | O(n + m)
      `template<class Compare> merge(const Compare& comparator)`        | O(n + m)
      `reverse()`                                                       | O(n)
      </p>
    </details>

-   <details>
      <summary>Iterator Functions</summary>
      <p>

      Iterator Functions                       | Time Complexity
      ---------------------------------------- | :--------------:
      `cbegin() const`                         | O(1)
      `cend() const`                           | O(1)
      `begin()`                                | O(1)
      `end()`                                  | O(1)
      `crbegin() const`                        | O(1)
      `crend() const`                          | O(1)
      `rbegin()`                               | O(1)
      `rend()`                                 | O(1)
      </p>
    </details>
    </p>
</details>


- - - -


### __Deque__ ###

The deque data structures is a double ended queue that stores elements of a specified data type in non-contiguous memory locations. In this project, the deque data structure is implemented using the [list](#list "Goto list") data structure, and because of this, the memory locations are non-contiguous. The deque takes in one template argument: a data type. A deque allows for insertion and removal of elements to either the front or back. This specific implementation of a deque is essentially a wrapper for the list data structure.

> Syntax: `mystl::deque<T>`

> **Note** 
> Bounds checking is not implemented.

> **Note** 
>This class uses a list_iterator, which is a version of the iterator data structure but for linked lists. See [List Iterator](#list-iterator "Goto list-iterator")

> **Note** 
> This data structure is used to implement the [queue](#queue "Goto queue") and [stack](#stack "Goto stack") data structure.

<details>
  <summary>Typedefs</summary>
  <p>
   
  Typedefs                 | Description
  ------------------------ | :---------------------------------------------:
  `value_type`             | value type T
  `pointer_type`           | value type pointer
  `reference_type`         | value type reference
  `const_pointer_type`     | const value type pointer
  `const_reference_type`   | const value type reference
  `const_iterator`         | list_const_iterator with class list<T>
  `iterator`               | list_iterator with class list<T>
  `const_reverse_iterator` | list_const_reverse_iterator with class const_iterator
  `reverse_iterator`       | list_reverse_iterator with class iterator
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>
  
  Constructor/Destructor                                            | Return Type | Description
  ----------------------------------------------------------------- | :---------: | :-------------------------------------------------------------------:
  `deque()`                                                         | `N/A`       | deque size defaults to 0 if no size is specified
  `deque(const size_t& capacity)`                                   | `N/A`       | constructs deque with specified size
  `deque(const size_t& capacity, const_reference_type fillElement)` | `N/A`       | constructs deque with specified size and fills it with the specified fill element
  </p>
</details>

<details>
  <summary>Element Access</summary>
  <p>
   
  Element Access                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :----------------------------------------------------------:
  `operator[](const size_t& index)`        | `reference_type`         | returns a reference to the deque at a specified index
  `operator[](const size_t& index) const`  | `const_reference_type`   | returns a const reference to the deque at a specified index
  `front()`                                | `reference_type`         | returns a reference to the first element in the deque
  `back()`                                 | `reference_type`         | returns a reference to the last element in the deque
  `front() const`                          | `const_reference_type`   | returns a const reference to the first element in the deque
  `back() const`                           | `const_reference_type`   | returns a const reference to the last element in the deque
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>
   
  Mutator Functions                                                 | Return Type      | Description
  ----------------------------------------------------------------- | :--------------: | :------------------------------------------------:
  `template<typename T> emplace_back(Args&&... args)`               | `reference_type` | constructs an element into the back of the deque
  `template<typename T> emplace_front(Args&&... args)`              | `reference_type` | constructs an element into the front of the deque
  `push_front(T&& element)`                                         | `reference_type` | inserts an element at the front of the deque
  `push_front(const_reference_type element)`                        | `reference_type` | inserts an element at the front of the deque
  `push_back(T&& element)`                                          | `reference_type` | inserts an element at the end of the deque
  `push_back(const_reference_type element)`                         | `reference_type` | inserts an element at the end of the deque
  `pop_front()`                                                     | `value_type`     | deletes the first element from the deque
  `pop_back()`                                                      | `value_type`     | deletes the last element from the deque

  </p>
</details>

<details>
  <summary>Size Functions</summary>
  <p>
   
  Size Functions                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :--------------------------------------------------:
  `empty() const`                          | `bool`                   | returns true if the deque is empty, false otherwise
 `size() const`                           | `size_t`                 | returns the size of the deque
  </p>
</details>

<details>
  <summary>Iterator Functions</summary>
  <p>
   
  Iterator Functions                       | Return Type              | Description
  ---------------------------------------- | :----------------------: | :-----------------------------------------------------------------------------:
  `cbegin() const`                         | `const_iterator`         | returns a const_iterator that points to the beginning of the deque
  `cend() const`                           | `const_iterator`         | returns a const_iterator that points to the element after end of the deque
  `begin()`                                | `iterator`               | returns an iterator that points to the beginning of the deque
  `end()`                                  | `iterator`               | returns an iterator that points to the element after end of the deque
  `crbegin() const`                        | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the deque
  `crend() const`                          | `const_reverse_iterator` | returns a const_reverse_iterator that points to the element after end of the deque
  `rbegin()`                               | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the deque
  `rend()`                                 | `reverse_iterator`       | returns a reverse_iterator that points to the element after end of the deque
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>
   
  Variables    | Type           | Description
  ------------ | :------------: | :---------------------------:
  `m_Data`     | `list<T>`      | doubly linked list
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  <p>
  
-   <details>
      <summary>Element Access</summary>
      <p>

      Element Access                           | Time Complexity
      ---------------------------------------- | :--------------:
      `operator[](const size_t& index)`        | O(n)
      `operator[](const size_t& index) const`  | O(n)
      `front()`                                | O(1)
      `back()`                                 | O(1)
      `front() const`                          | O(1)
      `back() const`                           | O(1)
      </p>
    </details>


-   <details>
      <summary>Size Functions</summary>
      <p>

      Size Functions                           | Time Complexity
      ---------------------------------------- | :--------------:
      `empty() const`                          | O(1)
      `size() const`                           | O(1)
      </p>
    </details>


-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                                                 | Time Complexity
      ----------------------------------------------------------------- | :--------------:
      `template<typename T> emplace_front(Args&&... args)`              | O(1)
      `template<typename T> emplace_back(Args&&... args)`               | O(1)
      `push_front(T&& element)`                                         | O(1)
      `push_front(const_reference_type element)`                        | O(1)
      `push_back(T&& element)`                                          | O(1)
      `push_back(const_reference_type element)`                         | O(1)
      `pop_front()`                                                     | O(1)
      `pop_back()`                                                      | O(1)
      </p>
    </details>

-   <details>
      <summary>Iterator Functions</summary>
      <p>

      Iterator Functions                       | Time Complexity
      ---------------------------------------- | :--------------:
      `cbegin() const`                         | O(1)
      `cend() const`                           | O(1)
      `begin()`                                | O(1)
      `end()`                                  | O(1)
      `crbegin() const`                        | O(1)
      `crend() const`                          | O(1)
      `rbegin()`                               | O(1)
      `rend()`                                 | O(1)
      </p>
    </details>
    </p>
</details>


 - - - -
 
 
### __Queue__ ###

The queue data structure is a First In First Out (FIFO) data structure that stores elements of a specified data type in non-contiguous memory locations. In this project, the queue data structure is implemented using the [deque](#deque "Goto deque") data structure, and because of this, the memory locations are non-contiguous. The queue takes in one template argument: a data type. A queue allows for the insertion of elements at the back and deletion of elements at the front. This specific implementation of a deque is essentially a wrapper for the deque data structure.

> Syntax: `mystl::queue<T>`

> **Note** 
>This class has no iterator functions

<details>
  <summary>Typedefs</summary>
  <p>
  
  Typedefs                 | Description
  ------------------------ | :---------------------------------------------:
  `value_type`             | value type T
  `pointer_type`           | value type pointer
  `reference_type`         | value type reference
  `const_pointer_type`     | const value type pointer
  `const_reference_type`   | const value type reference
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>
  
  Constructor/Destructor                   | Return Type | Description
  ---------------------------------------- | :---------: | :-----------------------------------------------:
  `queue()`                                | `N/A`       | queue size defaults to 0 if no size is specified
  </p>
</details>

<details>
  <summary>Element Access</summary>
  <p>
  
  Element Access                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :----------------------------------------------------------:
  `front()`                                | `reference_type`         | returns a reference to the first element in the queue
  `back()`                                 | `reference_type`         | returns a reference to the last element in the queue
  `front() const`                          | `const_reference_type`   | returns a const reference to the first element in the queue
  `back() const`                           | `const_reference_type`   | returns a const reference to the last element in the queue
  </p>
</details>

<details>
  <summary>Size Functions</summary>
  <p>
  
  Size Functions                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :--------------------------------------------------:
  `empty() const`                          | `bool`                   | returns true if the queue is empty, false otherwise
  `size() const`                           | `size_t`                 | returns the size of the queue
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>
   
  Mutator Functions                                                 | Return Type      | Description
  ----------------------------------------------------------------- | :--------------: | :-----------------------------------------------:
  `template<typename T> emplace(Args&&... args)`                    | `reference_type` | constructs an element into the back of the queue
  `push(T&& element)`                                               | `reference_type` | inserts an element at the end of the queue
  `push(const_reference_type element)`                              | `reference_type` | inserts an element at the end of the queue
  `pop()`                                                           | `value_type`     | deletes the first element from the queue
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>
   
  Variables    | Type           | Description
  ------------ | :------------: | :----------:
  `m_Data`     | `deque<T>`      | a deque
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  <p>
  
-   <details>
      <summary>Element Access</summary>
      <p>

      Element Access                           | Time Complexity
      ---------------------------------------- | :--------------:
      `front()`                                | O(1)
      `back()`                                 | O(1)
      `front() const`                          | O(1)
      `back() const`                           | O(1)
      </p>
    </details>


-   <details>
      <summary>Size Functions</summary>
      <p>

      Size Functions                           | Time Complexity
      ---------------------------------------- | :--------------:
      `empty() const`                          | O(1)
      `size() const`                           | O(1)
      </p>
    </details>


-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                                           | Time Complexity
      ----------------------------------------------------------- | :--------------:
      `template<typename T> emplace(Args&&... args)`              | O(1)
      `push(T&& element)`                                         | O(1)
      `push(const_reference_type element)`                        | O(1)
      `pop()`                                                     | O(1)
      </p>
    </details>
    </p>
</details>


 - - - -
 
 
### __Stack__ ###

The stack data structure is a Last In First Out (LIFO) or First In Last Out (FILO) data structure that stores elements of a specified data stype in non-contiguous memory locations. In this project, the stack data structure is implemented using the [deque](#deque "Goto deque") data structure, and because of this, the memory locations are non-contiguous. The stack takes in one template argument: a data type. A stack allows for the insertion and deletion of elements at the front. This specific implementation of a deque is essentially a wrapper for the deque data structure.

> Syntax: `mystl::stack<T>`

> **Note** 
>This class has no iterator functions

<details>
  <summary>Typedefs</summary>
  <p>
   
  Typedefs                 | Description
  ------------------------ | :-------------------------:
  `value_type`             | value type T
  `pointer_type`           | value type pointer
  `reference_type`         | value type reference
  `const_pointer_type`     | const value type pointer
  `const_reference_type`   | const value type reference
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>
   
  Constructor/Destructor                                             | Return Type | Description
  ------------------------------------------------------------------ | :---------: | :-----------------------------------------------:
  `stack()`                                                          | `N/A`       | stack size defaults to 0 if no size is specified
  </p>
</details>

<details>
  <summary>Element Access</summary>
  <p>
   
  Element Access                         | Return Type              | Description
  -------------------------------------- | :----------------------: | :----------------------------------------------------------:
  `top()`                                | `reference_type`         | returns a reference to the first element in the stack
  `top() const`                          | `const_reference_type`   | returns a const reference to the first element in the stack
  </p>
</details>

<details>
  <summary>Size Functions</summary>
  <p>
  
  Size Functions                           | Return Type              | Description
  ---------------------------------------- | :----------------------: | :--------------------------------------------------:
  `empty() const`                          | `bool`                   | returns true if the stack is empty, false otherwise
  `size() const`                           | `size_t`                 | returns the size of the stack
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>
   
  Mutator Functions                                                 | Return Type      | Description
  ----------------------------------------------------------------- | :--------------: | :------------------------------------------------:
  `template<typename T> emplace(Args&&... args)`                    | `reference_type` | constructs an element into the front of the stack
  `push(T&& element)`                                               | `reference_type` | inserts an element at the front of the stack
  `push(const_reference_type element)`                              | `reference_type` | inserts an element at the front of the stack
  `pop()`                                                           | `value_type`     | deletes the first element from the stack
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>
  
  Variables    | Type           | Description
  ------------ | :------------: | :----------:
  `m_Data`     | `deque<T>`     | a deque
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  <p>
  
-   <details>
      <summary>Element Access</summary>
      <p>

      Element Access                         | Time Complexity
      -------------------------------------- | :--------------:
      `top()`                                | O(1)
      `top() const`                          | O(1)
      </p>
    </details>


-   <details>
      <summary>Size Functions</summary>
      <p>

      Size Functions                           | Time Complexity
      ---------------------------------------- | :--------------:
      `empty() const`                          | O(1)
      `size() const`                           | O(1)
      </p>
    </details>


-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                                           | Time Complexity
      ----------------------------------------------------------- | :--------------:
      `template<typename T> emplace(Args&&... args)`              | O(1)
      `push(T&& element)`                                         | O(1)
      `push(const_reference_type element)`                        | O(1)
      `pop()`                                                     | O(1)
      </p>
    </details>
    </p>
</details>


- - - -


## __Iterators__ ##


### __Const Iterator__ ###

The const iterator data structure is a pointer to a constant object. In this project, the const iterator data structure is implemented using a raw const pointer. The const iterator has one template argument: a data type. Const iterators are most often used in classes, therefore the syntax for the template arguments uses `<class C>` rather than `<typename T>`. Most data structures (excluding queue and stack) have built in const iterator functions. Most common usage utilizes the `auto` keyword. To access the iterator without `auto`, the syntax is as follows: `mystl::data_structure<T>::const_iterator`.

> Syntax: `mystl::const_iterator<C>`

> **Note**
> This class is the parent class of [iterator](#iterator "Goto iterator").

<details>
  <summary>Typedefs</summary>
  <p>
  
  Typedefs               | Description
  ---------------------- | :---------------------------------------------:
  `value_type`           | value type of T
  `const_pointer_type`   | const value type pointer
  `const_reference_type` | const value type reference
  `ptrdiff_t`            | pointer difference: used for pointer arithmetic
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>
  
  Constructor                                | Return Type                | Description      | Overloadable
  ------------------------------------------ | :------------------------: | :--------------: | :----------:
  `const_iterator(const_pointer_type ptr)`   | `N/A`                      | constructor      | N
  </p>
</details>

<details>
  <summary>Element Access</summary>
  <p>
  
  Element Access                             | Return Type                | Description                                           | Overloadable
  ------------------------------------------ | :------------------------: | :---------------------------------------------------: | :----------:
  `operator[](const size_t& offset)`         | `const_reference_type`     | returns a const reference at a given pointer offset   | Y
  `operator*()`                              | `const_reference_type`     | dereference operator                                  | N
  `operator->()`                             | `const_pointer_type`       | pointer operator                                      | N
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>
  
  Mutator Functions                          | Return Type                | Description                                                  | Overloadable
  ------------------------------------------ | :------------------------: | :----------------------------------------------------------: | :----------:
  `operator++`                               | `const_iterator reference` | (prefix) increments const_iterator.                          | Y
  `operator++(int)`                          | `const_iterator`           | (postfix) increments const_iterator                          | Y
  `operator+(const size_t& offset)`          | `const_iterator reference` | increments const_iterator by an offset                       | Y
  `operator++`                               | `const_iterator reference` | (prefix) decrements const_iterator                           | Y
  `operator++(int)`                          | `const_iterator`           | (postfix) decrements const_iterator                          | Y
  `operator-(const size_t& offset)`          | `const_iterator reference` | decrements const_iterator by an offset                       | Y
  `operator-(const_iterator other)`          | `ptrdiff_t`                | returns the pointer difference between two const_iterators   | Y
  </p>
</details>

<details>
  <summary>Equality Operators</summary>
  <p>
  
  Equality Operators                         | Return Type                | Description                                                                            | Overloadable
  ------------------------------------------ | :------------------------: | :----------------------------------------------------------:                           | :----------:
  `operator==(const_iterator& other) const`  | `bool`                     | returns true if both const_iterators point to the same address, false otherwise        | N
  `operator!=(const_iterator& othter) const` | `bool`                     | returns true if the two const_iterators point to different addresses, false otherwise  | N
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>
  
  Variables    | Type                 | Description
  ---------    | :------------------: | :---------------------:
  `m_ConstPtr` | `const_pointer_type` | const pointer to object
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  
-   <details>
      <summary>Element Access</summary>
      <p>

      Element Access                             | Time Complexity
      ------------------------------------------ | :--------------:
      `operator[](const size_t& offset)`         | O(1)
      `operator*()`                              | O(1)
      `operator->()`                             | O(1)
      </p>
    </details>

-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                          | Time Complexity
      ------------------------------------------ | :--------------:
      `operator++`                               | O(1)
      `operator++(int)`                          | O(1)
      `operator+(const size_t& offset)`          | O(1)
      `operator++`                               | O(1)
      `operator++(int)`                          | O(1)
      `operator-(const size_t& offset)`          | O(1)
      `operator-(const_iterator other)`          | O(1)
      </p>
    </details>

-   <details>
      <summary>Equality Operators</summary>
      <p>

      Equality Operators                         | Time Complexity
      ------------------------------------------ | :--------------:
      `operator==(const_iterator& other) const`  | O(1)
      `operator!=(const_iterator& othter) const` | O(1)
      </p>
    </details>
    </p>
</details>


- - - -


### __Iterator__ ###

The iterator data structure is a pointer to a mutable object. In this project, the iterator data structure is implemented using a raw pointer. The iterator has one template argument: a data type. Iterators are most often used in classes, therefore the syntax for the template arguments uses `<class C>` rather than `<typename T>`. Most data structures (excluding queue and stack) have built in iterator functions. Most common usage utilizes the `auto` keyword. To access the iterator without `auto`, the syntax is as follows: `mystl::data_structure<T>::iterator`.

> Syntax: `mystl::iterator<C>`

> **Note**
> This class inherits from [const_iterator](#const-iterator "Goto const-iterator")

<details>
  <summary>Typedefs</summary>
  <p>
  
  Typedefs         | Description
  ---------------- | :---------------------------------------------:
  `base_class`     | base class that iterator inherits from(const_iterator)
  `value_type`     | value type of T
  `pointer_type`   | const value type pointer
  `reference_type` | const value type reference
  `ptrdiff_t`      | pointer difference: used for pointer arithmetic
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>
  
  Constructor                                | Return Type                | Description  | Overloadable
  ------------------------------------------ | :------------------------: | :----------: | :----------:
  `iterator(pointer_type ptr)`               | `N/A`                      | constructor  | N
  </p>
</details>

<details>
  <summary>Typedefs</summary>
  <p>
  
  Element Access                             | Return Type          | Description                                     | Overloadable
  ------------------------------------------ | :------------------: | :---------------------------------------------: | :----------:
  `operator[](const size_t& offset)`         | `reference_type`     | returns a reference at a given pointer offset   | Y
  `operator*()`                              | `reference_type`     | dereference operator                            | N
  `operator->()`                             | `pointer_type`       | pointer operator                                | N
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>
  
  Mutator Functions                          | Return Type          | Description                                            | Overloadable
  ------------------------------------------ | :------------------: | :----------------------------------------------------: | :----------:
  `operator++`                               | `iterator reference` | (prefix) increments iterator                           | Y
  `operator++(int)`                          | `iterator`           | (postfix) increments iterator                          | Y
  `operator+(const size_t& offset)`          | `iterator reference` | increments iterator by an offset                       | Y
  `operator++`                               | `iterator reference` | (prefix) decrements iterator                           | Y
  `operator++(int)`                          | `iterator`           | (postfix) decrements iterator                          | Y
  `operator-(const size_t& offset)`          | `iterator reference` | decrements iterator by an offset                       | Y
  `operator-(iterator other)`                | `ptrdiff_t`          | returns the pointer difference between two iterators   | Y
  </p>
</details>

<details>
  <summary>Equality Operators</summary>
  <p>
  
  Equality Operators                         | Return Type                | Description                                                                      | Overloadable
  ------------------------------------------ | :------------------------: | :------------------------------------------------------------------------------: | :----------:
  `operator==(const_iterator& other) const`  | `bool`                     | returns true if both iterators point to the same address, false otherwise        | N
  `operator!=(const_iterator& othter) const` | `bool`                     | returns true if the two iterators point to different addresses, false otherwise  | N
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  
-   <details>
      <summary>Element Access</summary>
      <p>

      Element Access                             | Time Complexity
      ------------------------------------------ | :--------------:
      `operator[](const size_t& offset)`         | O(1)
      `operator*()`                              | O(1)
      `operator->()`                             | O(1)
      </p>
    </details>

-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                          | Time Complexity
      ------------------------------------------ | :--------------:
      `operator++`                               | O(1)
      `operator++(int)`                          | O(1)
      `operator+(const size_t& offset)`          | O(1)
      `operator++`                               | O(1)
      `operator++(int)`                          | O(1)
      `operator-(const size_t& offset)`          | O(1)
      `operator-(const_iterator other)`          | O(1)
      </p>
    </details>

-   <details>
      <summary>Equality Operators</summary>
      <p>

      Equality Operators                         | Time Complexity
      ------------------------------------------ | :--------------:
      `operator==(const_iterator& other) const`  | O(1)
      `operator!=(const_iterator& othter) const` | O(1)
      </p>
    </details>
    </p>
</details>


- - - -


### __Const Reverse Iterator__ ###

The const reverse iterator data structure is a pointer to a constant object. In this project, the const reverse iterator data structure is implemented using a const raw pointer. The const reverse iterator has one template argument: a data type. Const reverse iterators are most often used in classes, therefore the syntax for the template arguments uses `<class C>` rather than `<typename T>`. Most data structures (excluding queue and stack) have built in const reverse iterator functions. Most common usage utilizes the `auto` keyword. To access the reverse iterator without `auto`, the syntax is as follows: `mystl::data_structure<T>::const_reverse_iterator`.

> Syntax: `mystl::const_reverse_iterator<C>`

> **Note**
> This class is the parent class of [reverse_iterator](#reverse-iterator "Goto reverse-iterator")


<details>
  <summary>Typedefs</summary>
  <p>

  Typedefs               | Description
  ---------------------- | :------------------------:
  `iterator_type`        | type of iterator T
  `value_type`           | value type of T
  `const_pointer_type`   | const value type pointer
  `const_reference_type` | const value type reference
  </p>
</details>


<details>
  <summary>Constructor/Destructor</summary>
  <p>

  Constructor                                      | Return Type                        | Description                                          | Overloadable
  ------------------------------------------------ | :--------------------------------: | :--------------------------------------------------: | :----------:
  `const_reverse_iterator(const_pointer_type ptr)` | `N/A`                              | constructor                                          | N
  </p>
</details>

<details>
  <summary>Element Access</summary>
  <p>
  
  Element Access                                   | Return Type                        | Description                                          | Overloadable
  ------------------------------------------------ | :------------------:               | :--------------------------------------------------: | :----------:
  `operator[](const size_t& offset)`               | `const_reference_type`             | returns a const reference at a given pointer offset  | Y
  `operator*()`                                    | `const_reference_type`             | dereference operator                                 | N
  `operator->()`                                   | `const_pointer_type`               | pointer operator                                     | N
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>
  
  Mutator Functions                                | Return Type                        | Description                                            | Overloadable
  ------------------------------------------------ | :--------------------------------: | :----------------------------------------------------: | :----------:
  `operator++`                                     | `const_reverse_iterator reference` | (prefix) decrements const_reverse_iterator             | Y
  `operator++(int)`                                | `const_reverse_iterator`           | (postfix) decrements const_reverse_iterator            | Y
  `operator+(const size_t& offset)`                | `const_reverse_iterator reference` | decrements const_reverse_iterator by an offset         | Y
  `operator++`                                     | `const_reverse_iterator reference` | (prefix) increments const_reverse_iterator             | Y
  `operator++(int)`                                | `const__reverse_iterator`          | (postfix) increments const_reverse_iterator            | Y
  `operator-(const size_t& offset)`                | `const_reverse_iterator reference` | increments const_reverse_iterator by an offset         | Y
  </p>
</details>

<details>
  <summary>Equality Operators</summary>
  <p>
  
  Equality Operators                               | Return Type                | Description                                                                                   | Overloadable
  ------------------------------------------------ | :------------------------: | :-------------------------------------------------------------------------------------------: | :----------:
  `operator==(const_iterator& other) const`        | `bool`                     | returns true if both const_reverse_iterators point to the same address, false otherwise       | N
  `operator!=(const_iterator& othter) const`       | `bool`                     | returns true if the two const_reverse_iterators point to different addresses, false otherwise | N
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>
  
  Variables       | Type                 | Description
  --------------- | :------------------: | :-----------------------:
  `m_ConstRevPtr` | `const_pointer_type` | const pointer to object
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  
-   <details>
      <summary>Element Access</summary>
      <p>

      Element Access                             | Time Complexity
      ------------------------------------------ | :--------------:
      `operator[](const size_t& offset)`         | O(1)
      `operator*()`                              | O(1)
      `operator->()`                             | O(1)
      </p>
    </details>

-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                          | Time Complexity
      ------------------------------------------ | :--------------:
      `operator++`                               | O(1)
      `operator++(int)`                          | O(1)
      `operator+(const size_t& offset)`          | O(1)
      `operator++`                               | O(1)
      `operator++(int)`                          | O(1)
      `operator-(const size_t& offset)`          | O(1)
      </p>
    </details>

-   <details>
      <summary>Equality Operators</summary>
      <p>

      Equality Operators                         | Time Complexity
      ------------------------------------------ | :--------------:
      `operator==(const_iterator& other) const`  | O(1)
      `operator!=(const_iterator& othter) const` | O(1)
      </p>
    </details>
    </p>
</details>


- - - -


### __Reverse Iterator__ ###

The reverse iterator data structure is a pointer to a mutable object. In this project, the reverse iterator data structure is implemented using a raw pointer. The reverse iterator has one template argument: a data type. Reverse iterators are most often used in classes, therefore the syntax for the template arguments uses `<class C>` rather than `<typename T>`. Most data structures (excluding queue and stack) have built in reverse iterator functions. Most common usage utilizes the `auto` keyword. To access the reverse iterator without `auto`, the syntax is as follows: `mystl::data_structure<T>::reverse_iterator`.

> Syntax: `mystl::reverse_iterator<C>`

> **Note**
> This class inherits from [const_reverse_iterator](#const-reverse-iterator "Goto const-reverse-iterator")

<details>
  <summary>Typedefs</summary>
  <p>
  
  Typedefs               | Description
  ---------------------- | :------------------------:
  `base_class`           | base class that reverse_iterator inherits from(const_reverse_iterator)
  `iterator_type`        | type of iterator T
  `value_type`           | value type of T
  `pointer_type`         | const value type pointer
  `reference_type`       | const value type reference
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>
  
  Constructor                                      | Return Type                        | Description                                          | Overloadable
  ------------------------------------------------ | :--------------------------------: | :--------------------------------------------------: | :----------:
  `reverse_iterator(pointer_type ptr)`             | `N/A`                              | constructor                                          | N
  </p>
</details>

<details>
  <summary>Element Access</summary>
  <p>

  Element Access                                   | Return Type                  | Description                                          | Overloadable
  ------------------------------------------------ | :------------------:         | :--------------------------------------------------: | :----------:
  `operator[](const size_t& offset)`               | `reference_type`             | returns a const reference at a given pointer offset  | Y
  `operator*()`                                    | `reference_type`             | dereference operator                                 | N
  `operator->()`                                   | `pointer_type`               | pointer operator                                     | N
  </p>
</details>

<details>
  <summary>Mutator Functions</summary>
  <p>
  
Mutator Functions                                | Return Type                  | Description                                            | Overloadable
------------------------------------------------ | :--------------------------: | :----------------------------------------------------: | :----------:
`operator++`                                     | `reverse_iterator reference` | (prefix) decrements const_reverse_iterator             | Y
`operator++(int)`                                | `reverse_iterator`           | (postfix) decrements const_reverse_iterator            | Y
`operator+(const size_t& offset)`                | `reverse_iterator reference` | decrements const_reverse_iterator by an offset         | Y
`operator++`                                     | `reverse_iterator reference` | (prefix) increments const_reverse_iterator             | Y
`operator++(int)`                                | `reverse_iterator`           | (postfix) increments const_reverse_iterator            | Y
`operator-(const size_t& offset)`                | `reverse_iterator reference` | increments const_reverse_iterator by an offset         | Y
  </p>
</details>

<details>
  <summary>Equality Operators</summary>
  <p>
  
  Equality Operators                               | Return Type                | Description                                                                                   | Overloadable
  ------------------------------------------------ | :------------------------: | :-------------------------------------------------------------------------------------------: | :----------:
  `operator==(const_iterator& other) const`        | `bool`                     | returns true if both const_reverse_iterators point to the same address, false otherwise       | N
  `operator!=(const_iterator& othter) const`       | `bool`                     | returns true if the two const_reverse_iterators point to different addresses, false otherwise | N
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>
  
  Variables       | Type                 | Description
  --------------- | :------------------: | :-----------------------:
  `m_ConstRevPtr` | `const_pointer_type` | const pointer to object
  </p>
</details>

<details>
  <summary>Time Complexity</summary>
  
-   <details>
      <summary>Element Access</summary>
      <p>

      Element Access                             | Time Complexity
      ------------------------------------------ | :--------------:
      `operator[](const size_t& offset)`         | O(1)
      `operator*()`                              | O(1)
      `operator->()`                             | O(1)
      </p>
    </details>

-   <details>
      <summary>Mutator Functions</summary>
      <p>

      Mutator Functions                          | Time Complexity
      ------------------------------------------ | :--------------:
      `operator++`                               | O(1)
      `operator++(int)`                          | O(1)
      `operator+(const size_t& offset)`          | O(1)
      `operator++`                               | O(1)
      `operator++(int)`                          | O(1)
      `operator-(const size_t& offset)`          | O(1)
      </p>
    </details>

-   <details>
      <summary>Equality Operators</summary>
      <p>

      Equality Operators                         | Time Complexity
      ------------------------------------------ | :--------------:
      `operator==(const_iterator& other) const`  | O(1)
      `operator!=(const_iterator& othter) const` | O(1)
      </p>
    </details>
    </p>
</details>


- - - -


### __List Iterator__ ###


- - - -


## __Smaller Data Structures__ ##

### __Node__ ###

The node struct is a simple subcontainer. In this project, the node data structure is implemented using a templated type and two other nodes. The node takes in one template argument: a data type. Nodes are most used in linked list data structures.

<details>
  <summary>Typedefs</summary>
  <p>
  
  Typedefs               | Description
  ---------------------- | :------------------------:
  `value_type`           | value type of T
  </p>
</details>

<details>
  <summary>Constructor/Destructor</summary>
  <p>
  
  Constructor                    | Return Type  | Description
  ----------------------         | :----------: | :------------:
  `node()`                       | `N/A`        | default constructor
  `node(const value_type& data)` | `N/A`        | assigns data to a specified value
  `~node()`                      | `N/A`        | default destructor
  </p>
</details>

<details>
  <summary>Variables</summary>
  <p>
  
  Variables    | Type          | Description
  ------------ | :-----------: | :---------------------------:
  `data`       | `value_type`  | data that the node holds
  `next`       | `node*`       | pointer to the next node
  `prev`       | `node*`       | pointer to the previous node
  </p>
</details>

- - - -
