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
 * @file src/utill.hpp
 */
#if !defined(UTIL_HPP)
#define UTIL_HPP

#include "iterator.hpp"

namespace ft {

struct nullptr_t {
 private:
  void operator&() const;

 public:
  template < class T >
  inline operator T*() const {
    return 0;
  }

  template < class C, class T >
  inline operator T C::*() const {
    return 0;
  }
};

static nullptr_t u_nullptr = {};

template < class InputIterator >
typename ft::iterator_traits< InputIterator >::difference_type difference(
    InputIterator first, InputIterator last) {
  typedef
      typename ft::iterator_traits< InputIterator >::difference_type size_type;
  size_type n = 0;
  for (; first != last; ++first) {
    ++n;
  }
  return n;
}

}  // namespace ft

#endif  // UTIL_HPP
