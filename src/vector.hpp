/**
 *         _                            __   _                __
 *        (_)___ ____  ________  ____  / /__(_)___ ___   ____/ /__ _   __
 *       / / __ `/ _ \/ ___/ _ \/ __ \/ //_/ / __ `__ \ / __  / _ \ | / /
 *      / / /_/ /  __(__  )  __/ /_/ / ,< / / / / / / // /_/ /  __/ |/ /
 *   __/ /\__,_/\___/____/\___/\____/_/|_/_/_/ /_/ /_(_)__,_/\___/|___/
 *  /___/
 *
 * @author JaeSeoKim <devjaeseo@gmail.com>
 * @date 2021/09/28
 * @file src/vector.hpp
 */

#if !defined(FT__VERCTOR_HPP)
#define FT__VERCTOR_HPP

#include <iostream>
#include <memory>

#include "algorithm.hpp"
#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "type_traits.hpp"
#include "util.hpp"

namespace ft {
/**
 * @brief A standard container which offers fixed time access to individual
 * elements in any order.
 *
 * @tparam _T Type of the elements.
 * @tparam _Alloc Type of the allocator object used to define the storage
 * allocation model, defaults to `allocator<_T>`.
 */
template < class _T, class _Alloc = std::allocator< _T > >
class vector {
 public:
  /**
   * @brief The first template parameter (_T)
   */
  typedef _T value_type;
  /**
   * @brief The first template parameter (_T)
   */
  typedef _T const const_value_type;
  /**
   * @brief The second template parameter (_Alloc), defaults to
   * `_Alloc<value_type>`
   */
  typedef _Alloc allocator_type;
  /* allocator_type::reference, defaults to `value_type&` */
  typedef typename allocator_type::reference reference;
  /* allocator_type::const_reference, defaults to `const value_type&` */
  typedef typename allocator_type::const_reference const_reference;
  /* allocator_type::pointer, defaults to `value_type*` */
  typedef typename allocator_type::pointer pointer;
  /* allocator_type::const_pointer, defaults to `const value_type*` */
  typedef typename allocator_type::const_pointer const_pointer;

  /* a random access iterator to value_type */
  typedef typename ft::random_access_iterator< value_type > iterator;

  /* const_iterator	a random access iterator to const value_type */
  typedef typename ft::random_access_iterator< const_value_type >
      const_iterator;

  /* reverse_iterator<iterator>	*/
  typedef typename ft::reverse_iterator< iterator > reverse_iterator;

  /* reverse_iterator<iterator>	*/
  typedef typename ft::reverse_iterator< const_iterator >
      const_reverse_iterator;

  /* a signed integral type, identical to:
   * iterator_traits<iterator>::difference_type	 */
  typedef
      typename ft::iterator_traits< iterator >::difference_type difference_type;

  /* an unsigned integral type that can represent any non-negative value of
   * difference_type	 */
  typedef typename allocator_type::size_type size_type;

 private:
  allocator_type _alloc;
  pointer _start;
  pointer _end;
  pointer _end_capacity;

 public:
  /**
   * @brief empty container constructor (default constructor)
   * Constructs an empty container, with no elements.
   */
  explicit vector(const allocator_type& alloc = allocator_type())
      : _alloc(alloc),
        _start(u_nullptr),
        _end(u_nullptr),
        _end_capacity(u_nullptr){};

  /**
   * @brief fill constructor
   * Constructs a container with n elements. Each element is a copy of val.
   *
   * @param n Initial container size (i.e., the number of elements in the
   * container at construction).
   * @param val Value to fill the container with. Each of the n elements in the
   * container will be initialized to a copy of this value. Member type
   * value_type is the type of the elements in the container, defined in vector
   * as an alias of its first template parameter (T).
   */
  explicit vector(size_type n, const value_type& val = value_type(),
                  const allocator_type& alloc = allocator_type())
      : _alloc(alloc) {
    this->_start = this->_alloc.allocate(n);
    this->_end = this->_start;
    this->_end_capacity = this->_start + n;
    while (n--) this->_alloc.construct(this->_end++, val);
  };

  /**
   * @brief range constructor
   * Constructs a container with as many elements as the range [first,last),
   * with each element constructed from its corresponding element in that range,
   * in the same order.
   */
  template < class InputIterator >
  vector(InputIterator first, InputIterator last,
         const allocator_type& alloc = allocator_type(),
         typename ft::enable_if<
             !ft::is_integral< InputIterator >::value >::type* = u_nullptr)
      : _alloc(alloc) {
    size_type n = ft::difference(first, last);
    this->_start = this->_alloc.allocate(n);
    this->_end_capacity = this->_start + n;
    this->_end = this->_start;
    while (n--) this->_alloc.construct(this->_end++, *first++);
  };

  /**
   * @brief copy constructor
   * Constructs a container with a copy of each of the elements in x, in the
   * same order.
   */
  vector(const vector& x) : _alloc(x._alloc) {
    size_type n = x.size();
    this->_start = this->_alloc.allocate(n);
    this->_end_capacity = this->_start + n;
    this->_end = this->_start;

    pointer other = x._start;
    while (n--) this->_alloc.construct(this->_end++, *other++);
  };

  vector& operator=(const vector& x) {
    if (this != &x) {
      this->clear();
      this->insert(this->_start, x.begin(), x.end());
    }
    return *this;
  };

  /**
   * @brief Vector destructor
   * Destroys the container object.
   */
  ~vector() {
    this->clear();
    this->_alloc.deallocate(this->_start, this->capacity());
  };

  /**
   * @brief Return iterator to beginning
   * Returns an iterator pointing to the first element in the vector.
   */
  iterator begin() { return (this->_start); };

  /**
   * @brief Return iterator to beginning
   * Returns an iterator pointing to the first element in the vector.
   */
  const_iterator begin() const { return (this->_start); };

  /**
   * @brief Return reverse iterator to reverse beginning
   * Returns a reverse iterator pointing to the last element in the vector
   * (i.e., its reverse beginning).
   */
  reverse_iterator rbegin() { return reverse_iterator(iterator(this->_end)); };

  /**
   * @brief Return reverse iterator to reverse beginning
   * Returns a reverse iterator pointing to the last element in the vector
   * (i.e., its reverse beginning).
   */
  const_reverse_iterator rbegin() const { return (this->_end); };

  /**
   * @brief Return iterator to end
   * Returns an iterator referring to the past-the-end element in the vector
   * container.
   */
  iterator end() { return (this->_end); }
  /**
   * @brief Return iterator to end
   * Returns an iterator referring to the past-the-end element in the vector
   * container.
   */
  const_iterator end() const { return (this->_end); }

  /**
   * @brief Return reverse iterator to reverse end
   * Returns a reverse iterator pointing to the last element in the vector
   * (i.e., its reverse end).
   */
  reverse_iterator rend() { return reverse_iterator(this->_start); };

  /**
   * @brief Return reverse iterator to reverse end
   * Returns a reverse iterator pointing to the last element in the vector
   * (i.e., its reverse end).
   */
  const_reverse_iterator rend() const { return (this->_start); };

  /**
   * @brief Return size
   * Returns the number of elements in the vector.
   */
  size_type size() const { return (this->_end - this->_start); };

  /**
   * @brief Return maximum size
   * Returns the maximum number of elements that the vector can hold.
   */
  size_type max_size() const { return (this->_alloc.max_size()); };

  /**
   * @brief Change size
   * Resizes the container so that it contains n elements.
   *
   * @param n  New container size, expressed in number of elements.
   * Member type size_type is an unsigned integral type.
   * @param val Object whose content is copied to the added elements in case
   * that n is greater than the current container size. If not specified, the
   * default constructor is used instead.
   */
  void resize(size_type n, value_type val = value_type()) {
    if (n > this->max_size()) {
      throw std::out_of_range("ft::vector");
    }
    size_type prev_size = this->size();
    if (prev_size > n) {
      while (prev_size-- > n) {
        this->_alloc.destroy(--this->_end);
      }
      return;
    }
    this->insert(this->_end, n - prev_size, val);
  };

  /**
   * @brief Return size of allocated storage capacity
   * Returns the size of the storage space currently allocated for the vector,
   * expressed in terms of elements.
   */
  size_type capacity() const { return (this->_end_capacity - this->_start); };

  /**
   * @brief Test whether vector is empty
   * Returns whether the vector is empty (i.e. whether its size is 0).
   */
  bool empty() const { return (this->size() == 0); };

  /**
   * @brief Request a change in capacity
   * Requests that the vector capacity be at least enough to contain n elements.
   *
   * @param n Minimum capacity for the vector.
   */
  void reserve(size_type n) {
    if (n > this->max_size()) {
      throw std::out_of_range("ft::vector");
    }

    if (this->capacity() >= n) {
      return;
    }

    pointer prev_start = this->_start;
    pointer prev_end = this->_end;
    size_type prev_capacity = this->capacity();

    this->_start = this->_alloc.allocate(n);
    this->_end_capacity = this->_start + n;
    this->_end = this->_start;

    for (pointer target = prev_start; target != prev_end; ++target) {
      this->_alloc.construct(this->_end++, *target);
    }
    for (size_type len = prev_end - prev_start; len > 0; --len) {
      this->_alloc.destroy(--prev_end);
    }
    this->_alloc.deallocate(prev_start, prev_capacity);
  };

  /**
   * @brief  Access element
   * Returns a reference to the element at position n in the vector container.
   */
  reference operator[](size_type n) { return (this->_start[n]); };
  /**
   * @brief  Access element
   * Returns a reference to the element at position n in the vector container.
   */
  const_reference operator[](size_type n) const { return (this->_start[n]); };

  /**
   * @brief Access element
   * Returns a reference to the element at position n in the vector.
   */
  reference at(size_type n) {
    if (this->size() < n) {
      throw std::out_of_range("ft::vector");
    }
    return (this->_start[n]);
  };

  /**
   * @brief Access element
   * Returns a reference to the element at position n in the vector.
   */
  const_reference at(size_type n) const {
    if (this->size() < n) {
      throw std::out_of_range("ft::vector");
    }
    return (this->_start[n]);
  };

  /**
   * @brief Access first element
   * Returns a reference to the first element in the vector.
   */
  reference front() { return (*this->_start); };

  /**
   * @brief Access first element
   * Returns a reference to the first element in the vector.
   */
  const_reference front() const { return (*this->_start); };

  /**
   * @brief Access last element
   * Returns a reference to the last element in the vector.
   */
  reference back() { return *(this->_end - 1); };

  /**
   * @brief Access last element
   * Returns a reference to the last element in the vector.
   */
  const_reference back() const { return *(this->_end - 1); };

  /**
   * @brief Assign vector content
   * Assigns new contents to the vector, replacing its current contents, and
   * modifying its size accordingly.
   *
   * @tparam InputIterator
   * @param first start
   * @param last end
   */
  template < class InputIterator >
  void assign(
      InputIterator first, InputIterator last,
      typename ft::enable_if<
          !ft::is_integral< InputIterator >::value >::type* = u_nullptr) {
    size_type n = ft::difference(first, last);
    if (this->capacity() < n) {
      this->_start = this->_alloc.allocate(n);
      this->_end_capacity = this->_start + n;
      this->_end = this->_start;
    } else {
      this->clear();
    }
    while (n--) this->_alloc.construct(this->_end++, *first++);
  };

  /**
   * @brief Assign vector content
   * Assigns new contents to the vector, replacing its current contents, and
   * modifying its size accordingly.
   *
   * @param n New size for the container.
   * @param val Value to fill the container with
   */
  void assign(size_type n, const value_type& val) {
    this->clear();
    if (this->capacity() >= n) {
      while (n--) this->_alloc.construct(this->_end++, val);
    } else {
      this->_start = this->_alloc.allocate(n);
      this->_end_capacity = this->_start + n;
      this->_end = this->_start;
      while (n--) this->_alloc.construct(this->_end++, val);
    }
  };

  /**
   * @brief Add element at the end
   *
   * @param val Value to be copied (or moved) to the new element.
   */
  void push_back(const value_type& val) {
    if (this->_end_capacity == this->_end) {
      size_type capacity =
          (this->size() == 0) ? 1 : (this->_end_capacity - this->_start) * 2;
      this->reserve(capacity);
    }
    this->_alloc.construct(this->_end++, val);
  };

  /**
   * @brief Delete last element
   * Removes the last element in the vector, effectively reducing the container
   * size by one.
   */
  void pop_back() { this->_alloc.destroy(--this->_end); };

  /**
   * @brief Insert elements
   *
   * @param position
   * @param val
   * @return iterator An iterator that points to the first of the newly inserted
   * elements.
   */
  iterator insert(iterator position, const value_type& val) {
    size_type pos_at = &(*position) - this->_start;
    this->insert(position, 1, val);
    return (this->_start + pos_at);
  };

  /**
   * @brief fill Insert elements
   *
   * @param position
   * @param n
   * @param val
   */
  void insert(iterator position, size_type n, const value_type& val) {
    size_type pos_at = &(*position) - this->_start;

    if (this->capacity() >= this->size() + n) {
      for (size_type i = 0; i < this->size() - pos_at; ++i) {
        this->_alloc.construct(this->_end + n - i, *(this->_end - i));
        this->_alloc.destroy(this->_end - i);
      }
      this->_end = this->_start + this->size() + n;
      for (size_type i = 0; i < n; ++i) {
        this->_alloc.construct(this->_start + pos_at + i, val);
      }
      return;
    }

    size_type next_capacity = this->size() + n;

    pointer prev_start = this->_start;
    pointer prev_end = this->_end;
    size_type prev_size = this->size();
    size_type prev_capacity = this->capacity();

    this->_start = this->_alloc.allocate(next_capacity);
    this->_end = this->_start + prev_size + n;
    this->_end_capacity = this->_end;

    for (size_type i = 0; i < pos_at; ++i) {
      this->_alloc.construct(this->_start + i, *(prev_start + i));
      this->_alloc.destroy(prev_start + i);
    }

    for (size_type i = 0; i < prev_size - pos_at; ++i) {
      this->_alloc.construct(this->_end - i - 1, *(prev_end - i - 1));
      this->_alloc.destroy(prev_end - i - 1);
    }

    for (size_type i = 0; i < n; ++i) {
      this->_alloc.construct(this->_start + pos_at + i, val);
    }

    this->_alloc.deallocate(prev_start, prev_capacity);
    return;
  };

  /**
   * @brief range Insert elements
   *
   * @tparam InputIterator
   * @param position
   * @param first
   * @param last
   */
  template < class InputIterator >
  void insert(
      iterator position, InputIterator first, InputIterator last,
      typename ft::enable_if<
          !ft::is_integral< InputIterator >::value >::type* = u_nullptr) {
    size_type pos_at = &(*position) - this->_start;
    size_type n = ft::difference(first, last);

    if (this->capacity() >= this->size() + n) {
      for (size_type i = 0; i < this->size() - pos_at; ++i) {
        this->_alloc.construct(this->_end + n - i, *(this->_end - i));
        this->_alloc.destroy(this->_end - i);
      }
      this->_end = this->_start + this->size() + n;
      for (size_type i = 0; i < n; ++i) {
        this->_alloc.construct(this->_start + pos_at + i, *first++);
      }
      return;
    }

    size_type next_capacity = this->size() + n;

    pointer prev_start = this->_start;
    pointer prev_end = this->_end;
    size_type prev_size = this->size();
    size_type prev_capacity = this->capacity();

    this->_start = this->_alloc.allocate(next_capacity);
    this->_end = this->_start + prev_size + n;
    this->_end_capacity = this->_end;

    for (size_type i = 0; i < pos_at; ++i) {
      this->_alloc.construct(this->_start + i, *(prev_start + i));
      this->_alloc.destroy(prev_start + i);
    }

    for (size_type i = 0; i < prev_size - pos_at; ++i) {
      this->_alloc.construct(this->_end - i - 1, *(prev_end - i - 1));
      this->_alloc.destroy(prev_end - i - 1);
    }

    for (size_type i = 0; i < n; ++i) {
      this->_alloc.construct(this->_start + pos_at + i, *first++);
    }
    this->_alloc.deallocate(prev_start, prev_capacity);
    return;
  }

  /**
   * @brief Erase elements
   *
   * @param position
   * @return iterator
   */
  iterator erase(iterator position) {
    size_type pos_at = &(*position) - this->_start;
    this->_alloc.destroy(&(*position));
    for (size_type i = 0; i < this->size() - pos_at; ++i) {
      this->_alloc.construct(this->_start + pos_at + i,
                             *(this->_start + pos_at + i + 1));
      this->_alloc.destroy(this->_start + pos_at + i + 1);
    }
    --this->_end;
    return this->_start + pos_at;
  };
  /**
   * @brief range Erase elements
   *
   * @param first
   * @param last
   * @return iterator
   */
  iterator erase(iterator first, iterator last) {
    size_type pos_at = &(*first) - this->_start;
    size_type n = last - first;
    for (size_type i = 0; i < n; ++i) {
      this->_alloc.destroy(&(*(first + i)));
    }
    for (size_type i = 0; i < this->size() - pos_at; ++i) {
      this->_alloc.construct(this->_start + pos_at + i,
                             *(this->_start + pos_at + i + n));
      this->_alloc.destroy(this->_start + pos_at + i + n);
    }
    this->_end = this->_start + this->size() - n;
    return this->_start + pos_at;
  };

  /**
   * @brief Swap content
   *
   * @param x other vector;
   */
  void swap(vector& x) {
    if (&x == this) {
      return;
    }

    pointer start = x._start;
    pointer end = x._end;
    pointer end_capacity = x._end_capacity;
    x._start = this->_start;
    x._end = this->_end;
    x._end_capacity = this->_end_capacity;
    this->_start = start;
    this->_end = end;
    this->_end_capacity = end_capacity;
  };

  /**
   * @brief Clear content
   * Removes all elements from the vector (which are destroyed), leaving the
   * container with a size of 0.
   */
  void clear() {
    while (this->_start != this->_end) {
      this->_alloc.destroy(--this->_end);
    }
  };

  /**
   * @brief Get the allocator object
   *
   * @return allocator_type
   */
  allocator_type get_allocator() const { return this->_alloc; };
};

/**
 * @brief Compare operator for vector
 *
 * @tparam T
 * @tparam Alloc
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
template < class T, class Alloc >
bool operator==(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }
  return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};

/**
 * @brief Non Compare operator for vector
 *
 * @tparam T
 * @tparam Alloc
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
template < class T, class Alloc >
bool operator!=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
  return !(lhs == rhs);
};

/**
 * @brief Compare Operator for vector
 *
 * @tparam T
 * @tparam Alloc
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
template < class T, class Alloc >
bool operator<(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end());
};

/**
 * @brief Compare Operator for vector
 *
 * @tparam T
 * @tparam Alloc
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
template < class T, class Alloc >
bool operator<=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
  return (!(rhs < lhs));
};

/**
 * @brief Compare Operator for vector
 *
 * @tparam T
 * @tparam Alloc
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
template < class T, class Alloc >
bool operator>(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
  return (rhs < lhs);
};

/**
 * @brief Compare Operator for vector
 *
 * @tparam T
 * @tparam Alloc
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
template < class T, class Alloc >
bool operator>=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
  return (!(lhs < rhs));
};

/**
 * @brief Exchange contents of vectors
 *
 * @tparam T
 * @tparam Alloc
 * @param x
 * @param y
 */
template < class T, class Alloc >
void swap(vector< T, Alloc >& x, vector< T, Alloc >& y) {
  x.swap(y);
};

};  // namespace ft

#endif  // FT__VERCTOR_HPP
