/**
 *         _                            __   _                __
 *        (_)___ ____  ________  ____  / /__(_)___ ___   ____/ /__ _   __
 *       / / __ `/ _ \/ ___/ _ \/ __ \/ //_/ / __ `__ \ / __  / _ \ | / /
 *      / / /_/ /  __(__  )  __/ /_/ / ,< / / / / / / // /_/ /  __/ |/ /
 *   __/ /\__,_/\___/____/\___/\____/_/|_/_/_/ /_/ /_(_)__,_/\___/|___/
 *  /___/
 *
 * @author JaeSeoKim <devjaeseo@gmail.com>
 * @date 2021/10/01
 * @file src/random_access_iterator.hpp
 */

#if !defined(RANDOM_ACCESS_ITERATOR_HPP)
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "util.hpp"

namespace ft {

template < class T >
class random_access_iterator
    : public ft::iterator< ft::random_access_iterator_tag, T > {
 public:
  /* Preserves Iterator's category */
  typedef typename ft::iterator< ft::random_access_iterator_tag,
                                 T >::iterator_category iterator_category;
  /* Preserves Iterator's value type  **/
  typedef typename ft::iterator< ft::random_access_iterator_tag, T >::value_type
      value_type;
  /* Preserves Iterator's difference  *type */
  typedef typename ft::iterator< ft::random_access_iterator_tag,
                                 T >::difference_type difference_type;
  /* Preserves Iterator's pointer typ *e */
  typedef typename ft::iterator< ft::random_access_iterator_tag, T >::pointer
      pointer;
  /* Preserves Iterator's reference t *ype */
  typedef typename ft::iterator< ft::random_access_iterator_tag, T >::reference
      reference;

 protected:
  pointer _ptr;

 public:
  /**
   * @brief default constructor
   */
  random_access_iterator(pointer _ptr = ft::u_nullptr) : _ptr(_ptr){};

  /**
   * @brief copy Construct
   */
  random_access_iterator(const random_access_iterator< T >& other)
      : _ptr(other._ptr){};

  /**
   * @brief random_access_iterator< const T > casting operator
   *
   * @return random_access_iterator< const T >
   */
  operator random_access_iterator< const T >() const { return this->_ptr; }

  /**
   * @brief Advances the random_access_iterator by one position.
   * @example ++_ptr;
   */
  random_access_iterator& operator++() {
    ++_ptr;
    return *this;
  };

  /**
   * @brief Advances the random_access_iterator by one position.
   * @example _ptr++;
   */
  random_access_iterator operator++(int) {
    random_access_iterator tmp = *this;
    ++(*this);
    return tmp;
  };

  /**
   * @brief Returns a reference to the pointed to by the iterator.
   */
  reference operator*() const { return *_ptr; };

  /**
   * @brief Returns a pointer to the pointed  (in order to access one of its
   * members).
   */
  pointer operator->() const { return &(operator*()); };

  /**
   * @brief Decreases the random_access_iterator by one position.
   * @example --_ptr;
   */
  random_access_iterator& operator--() {
    --_ptr;
    return *this;
  };

  /**
   * @brief Decreases the random_access_iterator by one position.
   * @example _ptr--;
   */
  random_access_iterator operator--(int) {
    random_access_iterator tmp = *this;
    --(*this);
    return tmp;
  };

  /**
   * @brief Returns a iterator pointing to the _ptrent located n
   * positions away from the _ptrent the iterator _ptrly points to.
   */
  random_access_iterator operator+(difference_type n) const {
    return random_access_iterator(this->_ptr + n);
  };

  /**
   * @brief Advances the random_access_iterator by n _ptrent positions.
   */
  random_access_iterator& operator+=(difference_type n) {
    this->_ptr += n;
    return *this;
  };

  /**
   * @brief Returns a iterator pointing to the _ptrent located n
   * positions before the _ptrent the iterator _ptrly points to.
   */
  random_access_iterator operator-(difference_type n) const {
    return random_access_iterator(this->_ptr - n);
  }

  /**
   * @brief Advances the random_access_iterator by n _ptrent positions.
   */
  random_access_iterator& operator-=(difference_type n) {
    this->_ptr -= n;
    return *this;
  };

  /**
   * @brief Accesses the _ptrent located n positions away from the _ptrent
   * _ptrly pointed to by the iterator.
   */
  reference operator[](difference_type n) const { return (this->_ptr[n]); };

  /**
   * @brief get base _ptr
   *
   * @return pointer const&
   */
  pointer const& base() const { return this->_ptr; }
};

/**
 * @brief Relational operators== for random_access_iterator
 */
template < class T1, class T2 >
bool operator==(const random_access_iterator< T1 >& lhs,
                const random_access_iterator< T2 >& rhs) {
  return (lhs.base() == rhs.base());
};

/**
 * @brief Relational operators!= for random_access_iterator
 */
template < class T1, class T2 >
bool operator!=(const random_access_iterator< T1 >& lhs,
                const random_access_iterator< T2 >& rhs) {
  return (lhs.base() != rhs.base());
};

/**
 * @brief Relational operators< for random_access_iterator
 */
template < class T1, class T2 >
bool operator<(const random_access_iterator< T1 > lhs,
               const random_access_iterator< T2 >& rhs) {
  return (lhs.base() < rhs.base());
};

/**
 * @brief Relational operators<= for random_access_iterator
 */
template < class T1, class T2 >
bool operator<=(const random_access_iterator< T1 >& lhs,
                const random_access_iterator< T2 >& rhs) {
  return (lhs.base() <= rhs.base());
};

/**
 * @brief Relational operators> for random_access_iterator
 */
template < class T1, class T2 >
bool operator>(const random_access_iterator< T1 > lhs,
               const random_access_iterator< T2 >& rhs) {
  return (lhs.base() > rhs.base());
};

/**
 * @brief Relational operators>= for random_access_iterator
 */
template < class T1, class T2 >
bool operator>=(const random_access_iterator< T1 >& lhs,
                const random_access_iterator< T2 >& rhs) {
  return (lhs.base() >= rhs.base());
};

/**
 * @brief Returns a iterator pointing to the _ptrent located n positions
 * away from the _ptrent pointed to by iter.
 *
 * @param n  Number of _ptrents to offset.
 * Member type difference_type is an alias of Iterator's own difference type.
 * @param iter iterator.
 */
template < class Iterator >
random_access_iterator< Iterator > operator+(
    typename random_access_iterator< Iterator >::difference_type n,
    const random_access_iterator< Iterator >& iter) {
  return iter + n;
};

/**
 * @brief Returns the distance between lhs and rhs.
 */
template < class T1, class T2 >
typename random_access_iterator< T1 >::difference_type operator-(
    const random_access_iterator< T2 >& lhs,
    const random_access_iterator< T1 >& rhs) {
  return lhs.base() - rhs.base();
};

}  // namespace ft

#endif  // RANDOM_ACCESS_ITERATOR_HPP
