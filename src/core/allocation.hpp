
#ifndef CPP_SNAKE_GAME_CORE_ALLOCATION_HPP
#define CPP_SNAKE_GAME_CORE_ALLOCATION_HPP

#include "vector2.hpp"

namespace Capstone
{

/**
 * The bounding box
 *
 * It holds each edge's offset of the object, starting from top
 * to bottom, from left to right of screen converting the values
 * to integer to make collision check easier
 */
struct BoundingBox
{
  /**
   * This defines the constant edge of each object's offset
   * converting the values to integer.
   *
   * @param top     The top edged of the object in pixel
   * @param bottom  The bottom edged of the object in pixel
   * @param left    The left edged of the object in pixels
   * @param right   The right edged of the object in pixels
   */
  BoundingBox(const int &top, const int &bottom, const int &left, const int &right):
    top(top),
    left(left),
    bottom(bottom),
    right(right)
  {

  }

  /**
   * There are the constant edge of each object's offset
   */
  const int top;
  const int bottom;
  const int right;
  const int left;
};


/**
 * Utility template class for manipulating offset and size of an object.
 *
 * This defines the object's location and make collision's check easier.
 *
 * @tparam T  Commonly a number type
 */
template <typename T>
class Allocation
{
 public:
  /**
   * Default constructor
   *
   * This defines the offset and the size as zero.
   */
  Allocation();

  /**
   * Parameterized constructor
   *
   * This defines the offset and the size of the object.
   *
   * @param size  The width and height of object
   * @param offset  The offset of the object
   */
  Allocation(Vector2<T> size, Vector2<T> offset);

  /**
   * This constructs an Allocation from another one
   *
   * This constructor doesn't replace the copy constructor, it's called
   * only when U != T. A call to this constructor will fail to compile
   * if U is not convertible to T.
   *
   * @tparam U The original type;
   * @param vector Allocation that will be converted to current type.
   */
  template<typename U>
  explicit Allocation (const Allocation<U>& vector);

  /**
   * This copy the current offset and size values into a new Allocation
   * from another type.
   *
   * It uses the type deduction to convert the current Allocation to
   * another type as follows:
   *
   *   auto int_alloc = Capstone::fAllocation.get_allocation_as<int>();
   *
   * This example will convert the Allocation of float type to the Allocation
   * of int type.
   *
   * @tparam U  The Allocation type expected
   * @return Allocation<U>
   */
  template<typename U>
  const Allocation<U> get_allocation_as () const;


  /**
   * This returns the bounding box of the current object.
   *
   * The bounding box defines each edge's offset of the object from top
   * to bottom, left to right of screen.
   *
   * @return BoundingBox  The value of each offset converted to integer
   */
  const BoundingBox get_bounding_box() const;

  /**
   * This checks collision of two Allocations
   *
   * This identifies if the current object is colliding with another one
   *
   * @tparam U  The Allocation type expected
   * @param other Allocation that will be compared
   * @return boolean
   */
  template<typename U>
  bool check_collision(const Allocation<U>& other) const;

 public:
  /**
   * This defines the width and height of an element using a template class
   * Vector2
   */
  Vector2<T> size;

  /**
   * This defines the offset of an element using a template class Vector2
   */
  Vector2<T> offset;
};

/**
 * Overload of binary operator ==
 *
 * This operator compares strict equality between two Allocations.
 *
 * @param left   Left operand (a Allocation)
 * @param right  Right operand (a Allocation)
 */
template <typename T, typename U>
bool operator ==(const Allocation<T>& left, const Allocation<U>& right);

/**
 * Overload of binary operator !=
 *
 * This operator compares strict difference between two Allocations.
 *
 * @param left   Left operand (a Allocation)
 * @param right  Right operand (a Allocation)
 */
template <typename T, typename U>
bool operator !=(const Allocation<T>& left, const Allocation<U>& right);

#include "allocation.inl"


// Defines the most common Allocation types
typedef Allocation<int> iAllocation;
typedef Allocation<unsigned int> uAllocation;
typedef Allocation<float> fAllocation;

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_ALLOCATION_HPP
