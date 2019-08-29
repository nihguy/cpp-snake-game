
#include "allocation.hpp"

// This defines the default constructor with size and offset as zero
template<typename T>
Capstone::Allocation<T>::Allocation ():
  size({ 0, 0 }),
  offset({ 0, 0 })
{

}

// It allows the client to define the offset and size of an object
template<typename T>
Capstone::Allocation<T>::Allocation (Capstone::Vector2<T> size, Capstone::Vector2<T> offset):
  size(size),
  offset(offset)
{

}

// This copy and convert a type of Allocation to another one
template<typename T>
template<typename U>
Capstone::Allocation<T>::Allocation (const Capstone::Allocation<U>& vector):
  size(static_cast<T>(vector.size.x), static_cast<T>(vector.size.y)),
  offset(static_cast<T>(vector.offset.x), static_cast<T>(vector.offset.y))
{

}

template<typename T>
template<typename U>
const Allocation<U> Capstone::Allocation<T>::get_allocation_as () const
{
  // This returns a "copy" of the current Allocation with the type assigned
  // to template type deduction `U`
  return Allocation<U>(*this);
}

// This creates the offset of each box edge and returns the BoundingBox as well
template<typename T>
const Capstone::BoundingBox Capstone::Allocation<T>::get_bounding_box() const
{
  auto cast = get_allocation_as<int> ();

  return {
    cast.offset.y * cast.size.y,               // top
    cast.offset.y * cast.size.y + cast.size.y, // bottom
    cast.offset.x * cast.size.x,               // left
    cast.offset.x * cast.size.x + cast.size.x  // right
  };
}

// This checks if the current object and another one are colliding
template<typename T>
template<typename U>
bool Capstone::Allocation<T>::check_collision (const Capstone::Allocation<U>& other) const
{
  auto current = get_bounding_box ();
  auto target = other.get_bounding_box ();

  return (current.right > target.left) && (target.right > current.left) && // It checks X coordinate
         (current.bottom > target.top) && (target.bottom > current.top);   // It checks Y coordinate
}

// This compares the size and offset of two Allocation of the same type
template <typename T, typename U>
bool operator ==(const Capstone::Allocation<T>& left, const Capstone::Allocation<U>& right)
{
  return (left.size == right.size) && (left.offset == right.offset);
}

// This checks if the size and offset of two Allocations are different when they both have the same type
template <typename T, typename U>
bool operator !=(const Capstone::Allocation<T>& left, const Capstone::Allocation<U>& right)
{
  return !(left == right);
}
