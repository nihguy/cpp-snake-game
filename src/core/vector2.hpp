
#ifndef CPP_SNAKE_GAME_CORE_VECTOR2_HPP
#define CPP_SNAKE_GAME_CORE_VECTOR2_HPP

namespace Capstone
{

/**
 * Utility template class for manipulating 2-dimensional vectors
 *
 * This class was strongly inspired by SFML's Vector2. If you'd like to check
 * the original code, please take a look at:
 *
 * https://github.com/SFML/SFML/blob/master/include/SFML/System/Vector2.hpp
 * https://github.com/SFML/SFML/blob/master/include/SFML/System/Vector2.inl
 *
 * @tparam T  A numeric type
 */
template<typename T>
class Vector2 {
 public:
  /**
   * The default constructor
   */
  Vector2 ();

  /**
   * This defines the same value for X and Y coordinates
   *
   * @param equal  It fills x and y with the same value.
   */
  Vector2 (T equal);

  /**
   * Construct the vector from its coordinates
   *
   * @param X  X coordinate
   * @param Y  Y coordinate
   */
  Vector2 (T X, T Y);

  /**
   * This constructor doesn't replace the copy constructor,
   * it's called only when U != T.
   * A call to this constructor will fail to compile if U
   * is not convertible to T.
   *
   * @tparam U  Assumes another vector type
   * @param vector  The vector type that will be converted to the current one
   */
  template<typename U>
  explicit Vector2 (const Vector2<U>& vector);

  /**
   * This defines the vector's coordinates
   */
  T x;
  T y;
};

/**
 * Overload of unary operator -
 *
 * @param right Vector to negate
 *
 * @return Memberwise opposite of the vector
 */
template<typename T>
Vector2<T> operator -(const Vector2<T>& right);

/**
 * Overload of binary operator +=
 *
 * This operator performs a memberwise addition of both vectors,
 * and assigns the result to \a left.
 *
 * @param left  Left operand (a vector)
 * @param right Right operand (a vector)
 *
 * @return Reference to \a left
 */
template<typename T>
Vector2<T> operator +=(Vector2<T>& left, const Vector2<T>& right);

/**
 *  Overload of binary operator -=
 *
 * This operator performs a memberwise subtraction of both vectors,
 * and assigns the result to \a left.
 *
 * @param left  Left operand (a vector)
 * @param right Right operand (a vector)
 *
 * @return Reference to \a left
 */
template<typename T>
Vector2<T> operator -=(Vector2<T>& left, const Vector2<T>& right);

/**
 * Overload of binary operator +
 *
 * @param left  Left operand (a vector)
 * @param right Right operand (a vector)
 *
 * @return Memberwise addition of both vectors
 */
template<typename T>
Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right);

/**
 * Overload of binary operator -
 *
 * @param left  Left operand (a vector)
 * @param right Right operand (a vector)
 *
 * @return Memberwise subtraction of both vectors
 */
template<typename T>
Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right);

/**
 * Overload of binary operator *
 *
 * @param left  Left operand (a vector)
 * @param right Right operand (a scalar value)
 *
 * @return Memberwise multiplication by \a right
 */
template<typename T>
Vector2<T> operator *(const Vector2<T>& left, T right);

/**
 * Overload of binary operator *
 *
 * @param left  Left operand (a scalar value)
 * @param right Right operand (a vector)
 *
 * @return Memberwise multiplication by \a left
 */
template<typename T>
Vector2<T> operator *(T left, const Vector2<T>& right);

/**
 * Overload of binary operator *=
 *
 * This operator performs a memberwise multiplication by \a right,
 * and assigns the result to \a left.
 *
 * @param left  Left operand (a vector)
 * @param right Right operand (a scalar value)
 *
 * @return Reference to \a left
 */
template<typename T>
Vector2<T>& operator *=(Vector2<T>& left, T right);

/**
 * Overload of binary operator /
 *
 * @param left  Left operand (a vector)
 * @param right Right operand (a scalar value)
 *
 * @return Memberwise division by \a right
 */
template<typename T>
Vector2<T> operator /(const Vector2<T>& left, T right);

/**
 * Overload of binary operator /=
 *
 * This operator performs a memberwise division by \a right,
 * and assigns the result to \a left.
 *
 * @param left  Left operand (a vector)
 * @param right Right operand (a scalar value)
 *
 * @return Reference to \a left
 */
template<typename T>
Vector2<T>& operator /=(Vector2<T>& left, T right);

/**
 * Overload of binary operator ==
 *
 * This operator compares strict equality between two vectors.
 *
 * @param left   Left operand (a vector)
 * @param right  Right operand (a vector)
 */
template <typename T, typename U>
bool operator ==(const Vector2<T>& left, const Vector2<U>& right);

/**
 * Overload of binary operator !=
 *
 * This operator compares strict difference between two Vector2.
 *
 * @param left   Left operand (a vector)
 * @param right  Right operand (a vector)
 */
template <typename T, typename U>
bool operator !=(const Vector2<T>& left, const Vector2<U>& right);

#include "vector2.inl"


// This defines the most common Vector2 types
typedef Vector2<int> iVector2;
typedef Vector2<unsigned int> uVector2;
typedef Vector2<float> fVector2;

} // namespace Capstone



#endif // CPP_SNAKE_GAME_CORE_VECTOR2_HPP
