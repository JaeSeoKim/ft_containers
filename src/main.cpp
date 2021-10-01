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
 * @file src/main.cpp
 */

#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

#include "iterator.hpp"
#include "test.hpp"

int main(void) {
  std::cout << "Test: ft_containers" << std::endl;

  test_iterator_traits();
  test_reverse_iterator();
  test_algorithm();
  test_utility();

  return 0;
}
