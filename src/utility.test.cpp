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
 * @file src/utility.test.cpp
 */

#include "utility.hpp"

#include <cassert>
#include <iostream>
#include <map>
#include <vector>

void test_pair(void) {
  std::cout << "\t pair" << std::endl;

  std::pair< std::string, double > std_product1;  // default constructor
  std::pair< std::string, double > std_product2("tomatoes",
                                                2.30);  // value init
  std::pair< std::string, double > std_product3(
      std_product2);  // copy constructor

  std_product1 = std::make_pair(std::string("lightbulbs"),
                                0.99);  // using make_pair (move)

  std_product2.first = "shoes";  // the type of first is string
  std_product2.second = 39.90;   // the type of second is double

  ft::pair< std::string, double > ft_product1;  // default constructor
  ft::pair< std::string, double > ft_product2("tomatoes", 2.30);  // value init
  ft::pair< std::string, double > ft_product3(ft_product2);  // copy constructor

  ft_product1 = ft::make_pair(std::string("lightbulbs"),
                              0.99);  // using make_pair (move)

  ft_product2.first = "shoes";  // the type of first is string
  ft_product2.second = 39.90;   // the type of second is double

  ft::pair< std::string, double > ft_assign = ft_product3;
  std::pair< std::string, double > std_assign = std_product3;

  assert(std_product1.first == ft_product1.first &&
         std_product1.second == ft_product1.second);
  assert(std_product2.first == ft_product2.first &&
         std_product2.second == ft_product2.second);
  assert(std_product3.first == ft_product3.first &&
         std_product3.second == ft_product3.second);
  assert(std_assign.first == ft_assign.first &&
         std_assign.second == ft_assign.second);
  assert((std_product1 == std_product2) == (ft_product1 == ft_product2));
  assert((std_product1 != std_product2) == (ft_product1 != ft_product2));
  assert((std_product1 < std_product2) == (ft_product1 < ft_product2));
  assert((std_product1 > std_product2) == (ft_product1 > ft_product2));
  assert((std_product1 <= std_product2) == (ft_product1 <= ft_product2));
  assert((std_product1 >= std_product2) == (ft_product1 >= ft_product2));
};

void test_utility(void) {
  std::cout << "Test: utility" << std::endl;
  test_pair();
}
