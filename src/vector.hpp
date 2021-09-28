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

#include <memory>

#include "iterator.hpp"

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
   * @brief The second template parameter (_Alloc), defaults to
   * `_Alloc<value_type>`
   */
  typedef _Alloc allocator_type;
  /**
   * @brief allocator_type::reference, defaults to `value_type&`
   */
  typedef typename allocator_type::reference reference;
  /**
   * @brief allocator_type::const_reference, defaults to `const value_type&`
   */
  typedef typename allocator_type::const_reference const_reference;
  /**
   * @brief allocator_type::pointer, defaults to `value_type*`
   */
  typedef typename allocator_type::pointer pointer;
  /**
   * @brief allocator_type::const_pointer, defaults to `const value_type*`
   */
  typedef typename allocator_type::const_pointer const_pointer;

  /*
  TODO: add Member types

  iterator	a random access iterator to value_type	convertible to
  const_iterator const_iterator	a random access iterator to const value_type
  reverse_iterator	reverse_iterator<iterator>
  const_reverse_iterator	reverse_iterator<const_iterator>
  difference_type	a signed integral type, identical to:
  iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
  size_type	an unsigned integral type that can represent any non-negative
  value of difference_type	usually the same as size_t
  */
};

};  // namespace ft

#endif  // FT__VERCTOR_HPP
