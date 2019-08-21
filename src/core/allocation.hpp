// Copyright 2019 <Victor Borges>

#ifndef CPP_SNAKE_GAME_CORE_VECTOR4_HPP
#define CPP_SNAKE_GAME_CORE_VECTOR4_HPP

#include "vector2.hpp"

namespace Capstone
{

/**
 * This defines the bounding box of an object
 *
 * It holds each offset of the object in pixels
 *
 * @tparam T  The BoundingBox type
 */
template <typename T>
struct BoundingBox
{
  /**
   * This defines each edge of the object because they are constant
   * and obviously, can't be modified.
   *
   * @param top     The top edged of the object in pixel
   * @param bottom  The bottom edged of the object in pixel
   * @param left    The left edged of the object in pixels
   * @param right   The right edged of the object in pixels
   */
  explicit BoundingBox(const T &top, const T &bottom, const T &left, const T &right);

  // Variables
  const T top;
  const T bottom;
  const T right;
  const T left;
};


/**
 * Utility template class for manipulating offset and size of an object.
 *
 * This avoids the frequent calculation of the objects's location and make
 * collision's check easier.
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
   * This example will convert the Allocation of float type to an Allocation
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
   * The bounding box defines the offset of each edge of the object in
   * pixels.
   *
   * @return BoundingBox<T>
   */
  const BoundingBox<T> get_bounding_box() const;

  /**
   * This checks collision of two Allocationz
   *
   * This identifies if the current object is colliding with another one
   *
   * @tparam U  The Allocation type expected
   * @param other Allocation that will be compared
   * @return boolean;
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
template <typename T>
bool operator ==(const Allocation<T>& left, const Allocation<T>& right);

/**
 * Overload of binary operator !=
 *
 * This operator compares strict difference between two Allocations.
 *
 * @param left   Left operand (a Allocation)
 * @param right  Right operand (a Allocation)
 */
template <typename T>
bool operator !=(const Allocation<T>& left, const Allocation<T>& right);

#include "allocation.inl"


// Defines the most common Allocation types
typedef Allocation<int> iAllocation;
typedef Allocation<unsigned int> uAllocation;
typedef Allocation<float> fAllocation;

} // namespace Capstone

#endif // CPP_SNAKE_GAME_CORE_VECTOR4_HPP
