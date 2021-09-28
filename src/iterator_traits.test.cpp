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
 * @file src/iterator_traits.test.cpp
 */

#include <cassert>
#include <iostream>

#include "iterator.hpp"

class TEST_ITER : public ft::iterator< ft::input_iterator_tag, int > {};

void test_iterator_traits(void) {
  std::cout << "Test: iterator_traits" << std::endl;

  typedef ft::iterator_traits< TEST_ITER > traits_test_iter;
  std::cout << "ft::iterator_traits< TEST_ITER >" << std::endl;

  assert((typeid(traits_test_iter::iterator_category) ==
          typeid(TEST_ITER::iterator_category)));
  std::cout << "\t ::iterator_category == TEST_ITER::iterator_category"
            << std::endl;

  assert(
      (typeid(traits_test_iter::value_type) == typeid(TEST_ITER::value_type)));
  std::cout << "\t ::value_type == TEST_ITER::value_type" << std::endl;

  assert((typeid(traits_test_iter::pointer) == typeid(TEST_ITER::pointer)));
  std::cout << "\t ::pointer == TEST_ITER::pointer" << std::endl;

  assert((typeid(traits_test_iter::reference) == typeid(TEST_ITER::reference)));
  std::cout << "\t ::reference == TEST_ITER::reference" << std::endl;

  assert((typeid(traits_test_iter::difference_type) ==
          typeid(TEST_ITER::difference_type)));
  std::cout << "\t ::difference_type == TEST_ITER::difference_type"
            << std::endl;

  typedef ft::iterator_traits< int* > traits_int_ptr;
  std::cout << "ft::iterator_traits< int* >" << std::endl;

  assert((typeid(traits_int_ptr::iterator_category) ==
          typeid(ft::random_access_iterator_tag)));
  std::cout
      << "\t ::random_access_iterator_tag == ft::random_access_iterator_tag"
      << std::endl;

  assert((typeid(traits_int_ptr::value_type) == typeid(int)));
  std::cout << "\t ::value_type == int" << std::endl;

  assert((typeid(traits_int_ptr::pointer) == typeid(int*)));
  std::cout << "\t ::pointer == int*" << std::endl;

  assert((typeid(traits_int_ptr::reference) == typeid(int&)));
  std::cout << "\t ::reference == int&" << std::endl;

  assert((typeid(traits_int_ptr::difference_type) == typeid(ptrdiff_t)));
  std::cout << "\t ::difference_type == ptrdiff_t" << std::endl;

  typedef ft::iterator_traits< const int* > traits_const_int_ptr;
  std::cout << "ft::iterator_traits< const int* >" << std::endl;

  assert((typeid(traits_const_int_ptr::iterator_category) ==
          typeid(ft::random_access_iterator_tag)));
  std::cout
      << "\t ::random_access_iterator_tag == ft::random_access_iterator_tag"
      << std::endl;

  assert((typeid(traits_const_int_ptr::value_type) == typeid(int)));
  std::cout << "\t ::value_type == int" << std::endl;

  assert((typeid(traits_const_int_ptr::pointer) == typeid(const int*)));
  std::cout << "\t ::pointer == const int*" << std::endl;

  assert((typeid(traits_const_int_ptr::reference) == typeid(const int&)));
  std::cout << "\t ::reference == const int&" << std::endl;

  assert((typeid(traits_const_int_ptr::difference_type) == typeid(ptrdiff_t)));
  std::cout << "\t ::difference_type == ptrdiff_t" << std::endl;
}
