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
 * @file src/iterator.hpp
 */

#if !defined(FT__ITERATOR_HPP)
#define FT__ITERATOR_HPP

#include <cstddef>
namespace ft {

/**
 * @brief Empty class to identify the category of an iterator as an input
 * iterator
 */
struct input_iterator_tag {};

/**
 * @brief Empty class to identify the category of an iterator as an output
 * iterator
 */
struct output_iterator_tag {};

/**
 * @brief Empty class to identify the category of an iterator as an forward
 * iterator
 */
struct forward_iterator_tag : public input_iterator_tag {};

/**
 * @brief Empty class to identify the category of an iterator as an
 * bidirectional iterator
 */
struct bidirectional_iterator_tag : public forward_iterator_tag {};

/**
 * @brief Empty class to identify the category of an iterator as an
 * random-access iterator
 */
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

/**
 * @brief std::iterator is the base class provided to simplify definitions of
 * the required types for iterators.
 *
 * @tparam _Category the category of the iterator. Must be one of iterator
 * category tags.
 * @tparam _T the type of the values that can be obtained by dereferencing the
 * iterator. This type should be void for output iterators.
 * @tparam _Distance a type that can be used to identify distance between
 * iterators
 * @tparam _Pointer defines a pointer to the type iterated over (_T)
 * @tparam _Reference defines a reference to the type iterated over (_T)
 */
template < class Category, class T, class Distance = std::ptrdiff_t,
           class Pointer = T*, class Reference = T& >
struct iterator {
  /**
   * the category of the iterator
   */
  typedef Category iterator_category;
  /**
   * the type of the values that can be obtained by dereferencing the
   * iterator
   */
  typedef T value_type;
  /**
   * a type that can be used to identify distance between iterators
   */
  typedef Distance difference_type;
  /**
   * defines a pointer to the type iterated over (value_type)
   */
  typedef Pointer pointer;
  /**
   * defines a reference to the type iterated over (value_type)
   */
  typedef Reference reference;
};

/**
 * @brief Traits class defining properties of iterators.
 * Standard algorithms determine certain properties of the iterators passed to
 * them and the range they represent by using the members of the corresponding
 * iterator_traits instantiation.
 *
 * @tparam Iterator ft:iterator
 */
template < class Iterator >
struct iterator_traits {
  /**
   * the category of the iterator
   */
  typedef typename Iterator::iterator_category iterator_category;
  /**
   * the type of the values that can be obtained by dereferencing the
   * iterator
   */
  typedef typename Iterator::value_type value_type;
  /**
   * a type that can be used to identify distance between iterators
   */
  typedef typename Iterator::difference_type difference_type;
  /**
   * defines a pointer to the type iterated over (value_type)
   */
  typedef typename Iterator::pointer pointer;
  /**
   * defines a reference to the type iterated over (value_type)
   */
  typedef typename Iterator::reference reference;
};

/**
 * @brief Traits class defining properties of iterators.
 * Standard algorithms determine certain properties of the iterators passed to
 * them and the range they represent by using the members of the corresponding
 * iterator_traits instantiation.
 *
 * @tparam T value_type
 */
template < class T >
struct iterator_traits< T* > {
  /**
   * the category of the iterator
   */
  typedef random_access_iterator_tag iterator_category;
  /**
   * the type of the values that can be obtained by dereferencing the
   * iterator
   */
  typedef T value_type;
  /**
   * a type that can be used to identify distance between iterators
   */
  typedef ptrdiff_t difference_type;
  /**
   * defines a pointer to the type iterated over (value_type)
   */
  typedef T* pointer;
  /**
   * defines a pointer to the type iterated over (value_type)
   */
  typedef T& reference;
};

/**
 * @brief Traits class defining properties of iterators.
 * Standard algorithms determine certain properties of the iterators passed to
 * them and the range they represent by using the members of the corresponding
 * iterator_traits instantiation.
 *
 * @tparam T ft:iterator
 */
template < class T >
struct iterator_traits< const T* > {
  /**
   * the category of the iterator
   */
  typedef random_access_iterator_tag iterator_category;
  /**
   * the type of the values that can be obtained by dereferencing the
   * iterator
   */
  typedef T value_type;
  /**
   * a type that can be used to identify distance between iterators
   */
  typedef ptrdiff_t difference_type;
  /**
   * defines a pointer to the type iterated over (value_type)
   */
  typedef const T* pointer;
  /**
   * defines a reference to the type iterated over (value_type)
   */
  typedef const T& reference;
};

/**
 * @brief This class reverses the direction in which a bidirectional or
 * random-access iterator iterates through a range.
 *
 * @tparam Iterator Iterator Class
 */
template < class Iterator >
class reverse_iterator {
 public:
  /* Iterator's type */
  typedef Iterator iterator_type;
  /* Preserves Iterator's category */
  typedef
      typename iterator_traits< Iterator >::iterator_category iterator_category;
  /* Preserves Iterator's value type */
  typedef typename iterator_traits< Iterator >::value_type value_type;
  /* Preserves Iterator's difference type */
  typedef typename iterator_traits< Iterator >::difference_type difference_type;
  /* Preserves Iterator's pointer type */
  typedef typename iterator_traits< Iterator >::pointer pointer;
  /* Preserves Iterator's reference type */
  typedef typename iterator_traits< Iterator >::reference reference;

 protected:
  iterator_type current;

 public:
  /**
   * @brief default constructor
   * Constructs a reverse iterator that points to no object.
   * The internal base iterator is value-initialized.
   */
  reverse_iterator() : current(){};

  /**
   * @brief initalization constructor
   * Constructs a reverse iterator from some original iterator it. The behavior
   * of the constructed object replicates the original, except that it iterates
   * through its pointed elements in the reverse order.
   *
   * @param it An iterator, whose sense of iteration is inverted in the
   * constructed object. Member type iterator_type is the underlying
   * bidirectional iterator type (the class template parameter: Iterator).
   */
  explicit reverse_iterator(iterator_type it) : current(it){};

  /**
   * @brief copy / type-cast constructor
   * Constructs a reverse iterator from some other reverse iterator. The
   * constructed object keeps the same sense of iteration as rev_it.
   *
   * @param rev_it An iterator of a reverse_iterator type, whose sense of
   * iteration is preserved.
   */
  template < class Iter >
  reverse_iterator(const reverse_iterator< Iter >& rev_it)
      : current(rev_it.base()){};

  /**
   * @brief Returns a copy of the base iterator.
   */
  iterator_type base() const { return current; };

  /**
   * @brief Returns a reference to the element pointed to by the iterator.
   */
  reference operator*() const {
    iterator_type tmp_iter = current;
    return *(--tmp_iter);
  };

  /**
   * @brief Returns a reverse iterator pointing to the element located n
   * positions away from the element the iterator currently points to.
   */
  reverse_iterator operator+(difference_type n) const {
    return reverse_iterator(current - n);
  }
  /**
   * @brief Advances the reverse_iterator by one position.
   * @example ++ri;
   */
  reverse_iterator& operator++() {
    --current;
    return *this;
  };
  /**
   * @brief Advances the reverse_iterator by one position.
   * @example ri++;
   */
  reverse_iterator operator++(int) {
    reverse_iterator tmp = *this;
    --(*this);
    return tmp;
  };
  /**
   * @brief Advances the reverse_iterator by n element positions.
   */
  reverse_iterator& operator+=(difference_type n) {
    current -= n;
    return *this;
  };

  /**
   * @brief Returns a reverse iterator pointing to the element located n
   * positions before the element the iterator currently points to.
   */
  reverse_iterator operator-(difference_type n) const {
    return reverse_iterator(current + n);
  }
  /**
   * @brief Decreases the reverse_iterator by one position.
   * @example --ri;
   */
  reverse_iterator& operator--() {
    ++current;
    return *this;
  };
  /**
   * @brief Decreases the reverse_iterator by one position.
   * @example ri++;
   */
  reverse_iterator operator--(int) {
    reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
  };
  /**
   * @brief Advances the reverse_iterator by n element positions.
   */
  reverse_iterator& operator-=(difference_type n) {
    current += n;
    return *this;
  };

  /**
   * @brief Returns a pointer to the element pointed to by the iterator (in
   * order to access one of its members).
   */
  pointer operator->() const { return &(operator*()); }

  /**
   * @brief Accesses the element located n positions away from the element
   * currently pointed to by the iterator.
   */
  reference operator[](difference_type n) const { return (current[-n - 1]); };
};

/**
 * @brief Relational operators== for reverse_iterator
 */
template < class Iterator >
bool operator==(const reverse_iterator< Iterator >& lhs,
                const reverse_iterator< Iterator >& rhs) {
  return (lhs.base() == rhs.base());
};

/**
 * @brief Relational operators!= for reverse_iterator
 */
template < class Iterator >
bool operator!=(const reverse_iterator< Iterator >& lhs,
                const reverse_iterator< Iterator >& rhs) {
  return (lhs.base() != rhs.base());
};

/**
 * @brief Relational operators< for reverse_iterator
 */
template < class Iterator >
bool operator<(const reverse_iterator< Iterator >& lhs,
               const reverse_iterator< Iterator >& rhs) {
  return (lhs.base() < rhs.base());
};

/**
 * @brief Relational operators<= for reverse_iterator
 */
template < class Iterator >
bool operator<=(const reverse_iterator< Iterator >& lhs,
                const reverse_iterator< Iterator >& rhs) {
  return (lhs.base() <= rhs.base());
};

/**
 * @brief Relational operators> for reverse_iterator
 */
template < class Iterator >
bool operator>(const reverse_iterator< Iterator >& lhs,
               const reverse_iterator< Iterator >& rhs) {
  return (lhs.base() > rhs.base());
};

/**
 * @brief Relational operators>= for reverse_iterator
 */
template < class Iterator >
bool operator>=(const reverse_iterator< Iterator >& lhs,
                const reverse_iterator< Iterator >& rhs) {
  return (lhs.base() >= rhs.base());
};

/**
 * @brief Returns a reverse iterator pointing to the element located n positions
 * away from the element pointed to by rev_it.
 *
 * @param n  Number of elements to offset.
 * Member type difference_type is an alias of Iterator's own difference type.
 * @param rev_it Reverse iterator.
 */
template < class Iterator >
reverse_iterator< Iterator > operator+(
    typename reverse_iterator< Iterator >::difference_type n,
    const reverse_iterator< Iterator >& rev_it) {
  return rev_it + n;
};

/**
 * @brief Returns the distance between lhs and rhs.
 */
template < class Iterator >
typename reverse_iterator< Iterator >::difference_type operator-(
    const reverse_iterator< Iterator >& lhs,
    const reverse_iterator< Iterator >& rhs) {
  return rhs.base() - lhs.base();
};

}  // namespace ft

#endif  // FT__ITERATOR_HPP
