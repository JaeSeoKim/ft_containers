/**
 *         _                            __   _                __
 *        (_)___ ____  ________  ____  / /__(_)___ ___   ____/ /__ _   __
 *       / / __ `/ _ \/ ___/ _ \/ __ \/ //_/ / __ `__ \ / __  / _ \ | / /
 *      / / /_/ /  __(__  )  __/ /_/ / ,< / / / / / / // /_/ /  __/ |/ /
 *   __/ /\__,_/\___/____/\___/\____/_/|_/_/_/ /_/ /_(_)__,_/\___/|___/
 *  /___/
 *
 * @author JaeSeoKim <devjaeseo@gmail.com>
 * @date 2021/10/02
 * @file src/bidirectional_iterator.hpp
 */

#if !defined(BIDIRECTIONAL_ITERATOR_HPP)
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"
#include "util.hpp"

namespace ft {

template < class T >
class bidirectional_iterator
    : public ft::iterator< ft::bidirectional_iterator_tag, T > {
 public:
  /* Preserves Iterator's category */
  typedef typename ft::iterator< ft::bidirectional_iterator_tag,
                                 T >::iterator_category iterator_category;
  /* Preserves Iterator's value type  **/
  typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::value_type
      value_type;
  /* Preserves Iterator's difference  *type */
  typedef typename ft::iterator< ft::bidirectional_iterator_tag,
                                 T >::difference_type difference_type;
  /* Preserves Iterator's pointer typ *e */
  typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::pointer
      pointer;
  /* Preserves Iterator's reference t *ype */
  typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::reference
      reference;

 protected:
  pointer ptr;

 public:
  /**
   * @brief default constructor
   */
  bidirectional_iterator(pointer ptr = ft::u_nullptr) : ptr(ptr){};

  /**
   * @brief copy / type-cast constructor
   */
  bidirectional_iterator(const bidirectional_iterator& other)
      : ptr(other.ptr){};

  template < typename diffT >
  bidirectional_iterator(const bidirectional_iterator< diffT >& other)
      : ptr(other.base()) {}

  /**
   * @brief Advances the bidirectional_iterator by one position.
   * @example ++ptr;
   */
  bidirectional_iterator& operator++() {
    ++ptr;
    return *this;
  };

  /**
   * @brief Advances the bidirectional_iterator by one position.
   * @example ptr++;
   */
  bidirectional_iterator operator++(int) {
    bidirectional_iterator tmp = *this;
    ++(*this);
    return tmp;
  };

  /**
   * @brief Relational operators== for bidirectional_iterator
   */
  bool operator==(const bidirectional_iterator< T >& other) {
    return (this->ptr == other.ptr);
  };

  /**
   * @brief Relational operators== for bidirectional_iterator
   */
  bool operator!=(const bidirectional_iterator< T >& other) {
    return (this->ptr != other.ptr);
  };

  /**
   * @brief Returns a reference to the pointed to by the iterator.
   */
  reference operator*() const { return *ptr; };

  /**
   * @brief Returns a pointer to the pointed  (in order to access one of its
   * members).
   */
  pointer operator->() const { return &(operator*()); };

  /**
   * @brief Decreases the bidirectional_iterator by one position.
   * @example --ptr;
   */
  bidirectional_iterator& operator--() {
    --ptr;
    return *this;
  };

  /**
   * @brief Decreases the bidirectional_iterator by one position.
   * @example ptr--;
   */
  bidirectional_iterator operator--(int) {
    bidirectional_iterator tmp = *this;
    --(*this);
    return tmp;
  };

  pointer const& base() const { return ptr; }
};

}  // namespace ft

#endif  // BIDIRECTIONAL_ITERATOR_HPP
