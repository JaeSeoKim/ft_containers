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
 * @file src/utility.hpp
 */
#if !defined(UTILITY_HPP)
#define UTILITY_HPP

namespace ft {

/**
 * @brief Pair of values
 * This class couples together a pair of values, which may be of different types
 * (T1 and T2). The individual values can be accessed through its public members
 * first and second.
 *
 * Pairs are a particular case of tuple.
 * @tparam T1 Type of member first, aliased as first_type.
 * @tparam T2 Type of member second, aliased as second_type.
 */
template < class T1, class T2 >
struct pair {
 public:
  /* The first template parameter (T1)	Type of member first. */
  typedef T1 first_type;
  /* The second template parameter (T2)	Type of member second. */
  typedef T2 second_type;

  /* The first value in the pair */
  first_type first;
  /* The second value in the pair */
  second_type second;

  /* Constructs a pair object with its elements value-initialized. */
  pair() : first(), second(){};

  /**
   * The object is initialized with the contents of the pr pair object.
   * The corresponding member of pr is passed to the constructor of each of its
   * members.
   *
   * @param pr Another pair object.
   * This may be an object of the same type as the object being constructed or
   * of a pair type whose elements' types are implicitly convertible to those in
   * the pair being constructed.
   */
  template < class U, class V >
  pair(const pair< U, V >& pr) : first(pr.first), second(pr.second){};

  /**
   * Member first is constructed with a and member second with b.
   *
   * @param a An object of the type of first, or some other type implicitly
   * convertible to it.
   * @param b An object of the type of second, or some other type implicitly
   * convertible to it.
   */
  pair(const first_type& a, const second_type& b) : first(a), second(b){};

  /**
   * Assigns pr as the new content for the pair object.
   *
   * @param pr Another pair object.
   */
  pair& operator=(const pair& pr) {
    first = pr.first;
    second = pr.second;

    return *this;
  };
};

template < class T1, class T2 >
bool operator==(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

template < class T1, class T2 >
bool operator!=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
  return !(lhs == rhs);
}

template < class T1, class T2 >
bool operator<(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
  return lhs.first < rhs.first ||
         (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template < class T1, class T2 >
bool operator<=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
  return !(rhs < lhs);
}

template < class T1, class T2 >
bool operator>(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
  return rhs < lhs;
}

template < class T1, class T2 >
bool operator>=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
  return !(lhs < rhs);
}

/**
 * @brief Exchanges the values of a and b.
 */
template < class T >
void swap(T& a, T& b) {
  T c(a);
  a = b;
  b = c;
}

/**
 * @brief Constructs a pair object with its first element set to x and its
 * second element set to y.
 *
 * @param x Values for the members first and second, respectively, of the pair
 * object being constructed.
 * @param y Values for the members first and second, respectively, of the pair
 * object being constructed.
 */
template < class T1, class T2 >
pair< T1, T2 > make_pair(T1 x, T2 y) {
  return (pair< T1, T2 >(x, y));
}

}  // namespace ft

#endif  // UTILITY_HPP
