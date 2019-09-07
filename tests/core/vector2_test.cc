#include "../../src/core/vector2.hpp"

#include "gtest/gtest.h"

namespace
{

/**
 * This allows the Vector2 to avoid repeat each test for each template type.
 *
 * @tparam T  The type that will be assigned automatically by the GTest
 */
template <typename T>
class Vector2Test: public ::testing::Test
{
 protected:

  /**
   * It allows this class to assign the Vector2's pointer to the variable `vector2` in other to automatic
   * convert the template class using GTest template features.
   *
   * @param vector2  A pointer to the Dynamic Vector2 type
   */
  void Assign (::Capstone::Vector2<T> *vector2) {
    this->vector2 = ::std::shared_ptr<::Capstone::Vector2<T>> (vector2);
  }

 protected:
  /**
   * This holds the Vector2 instance used by the test properly
   */
  std::shared_ptr<Capstone::Vector2<T>> vector2;
};

/**
 * This defines the most common types used in Vector2. It allows the GTest
 * to convert the class automatically, so we can define the test just once
 * and check the results for each Vector2's type.
 */
using Vector2Types = ::testing::Types<int, unsigned int, float>;
TYPED_TEST_SUITE (Vector2Test, Vector2Types);


TYPED_TEST(Vector2Test, DefaultContructor_ShouldDefineTheCoordinatesAsZero)
{
  this->Assign (new ::Capstone::Vector2<TypeParam>{});

  ASSERT_EQ(this->vector2->x, 0) << "Vector2's `x` coordinates should be zero when the default constructor is called";
  ASSERT_EQ(this->vector2->y, 0) << "Vector2's `y` coordinates should be zero when the default constructor is called";
}

TYPED_TEST(Vector2Test, ParameterContructor_ShouldDefineEachCoordinate)
{
  this->Assign (new ::Capstone::Vector2<TypeParam>{ 1, 2 });

  ASSERT_EQ (this->vector2->x, 1) << "Vector2's `x` coordinate should be 1 because it is defined as first parameter on parameter constructor";
  ASSERT_EQ (this->vector2->y, 2) << "Vector2's `y` coordinate should be 1 because it is defined as second parameter on parameter constructor";
}

TYPED_TEST(Vector2Test, SingleParameterContructor_ShouldAssignTheSameValueToTheCoordinates)
{
  this->Assign (new ::Capstone::Vector2<TypeParam> (10));

  ASSERT_TRUE(this->vector2->x == this->vector2->y) << "The coordinates should be equal when the single parameter constructor is called";

  ASSERT_EQ(this->vector2->x, 10) << "The `x` coordinate value should be the same assigned as single parameter constructor argument";
  ASSERT_EQ(this->vector2->y, 10) << "The `y` coordinate value should be the same assigned as single parameter constructor argument";
}

TYPED_TEST(Vector2Test, CopyContructor_ShouldCastTheCopiedVector2ToTheCurrentType)
{
  this->Assign (new ::Capstone::Vector2<TypeParam> (::Capstone::Vector2<float>(-0.5f)));

  if (typeid (TypeParam) == typeid (float))
  {
    ASSERT_FLOAT_EQ (this->vector2->x, -0.5f) << "Vector2<float> should keep the negative float value to `x` variable";
    ASSERT_FLOAT_EQ (this->vector2->y, -0.5f) << "Vector2<float> should keep the negative float value to `y` variable";
  }
  else
  {
    ASSERT_EQ (this->vector2->x, 0) << "Vector2<int> and Vector2<unsigned int> should cast -0.5f to zero on `x` coordinate";
    ASSERT_EQ (this->vector2->y, 0) << "Vector2<int> and Vector2<unsigned int> should cast -0.5f to zero on `y` coordinate";
  }
}

TYPED_TEST(Vector2Test, Cordinates_EachCoordinateValueShouldBeReassigned)
{
  this->Assign (new ::Capstone::Vector2<TypeParam> {});

  ASSERT_EQ(this->vector2->x, 0) << "The Vector2's x coordinate should be zero because default constructor is called";
  ASSERT_EQ(this->vector2->y, 0) << "The Vector2's y coordinate should be zero because default constructor is called";

  this->vector2->x = 1;
  this->vector2->y = 1;

  ASSERT_EQ(this->vector2->x, 1) << "The Vector2's x coordinate should be reassigned to 1";
  ASSERT_EQ(this->vector2->y, 1) << "The Vector2's y coordinate should be reassigned to 1";
}

TYPED_TEST(Vector2Test, IsEqualToAndIsNotEqualToOperators_ShouldVector2BeComparedToEachOther)
{
  this->Assign (new ::Capstone::Vector2<TypeParam> {1, 2});

  auto sameCoordinates = ::Capstone::Vector2<double>(1.0, 2.0);
  auto diffCoordinates = ::Capstone::Vector2<double>(1.0, 20.0);

  ASSERT_TRUE (*this->vector2 == sameCoordinates) << "Should ignore the type and return true to `==` because all coordinate values are the same";
  ASSERT_TRUE (*this->vector2 != diffCoordinates) << "Should ignore the type and return true to `!=` because one of the coordinate values are different";

  ASSERT_FALSE (*this->vector2 == diffCoordinates) << "Should ignore the type and return false to `==` because one of the coordinate values are different";
  ASSERT_FALSE (*this->vector2 != sameCoordinates) << "Should ignore the type and return false to `!=` because all coordinate value are the same";
}

TYPED_TEST(Vector2Test, NegativeOperator_ShouldConvertCoordinatestoTheirNegativateValue)
{
  this->Assign(new ::Capstone::Vector2<TypeParam>(10, 10));

  auto negative = -*this->vector2;
  ASSERT_EQ(negative, ::Capstone::Vector2<TypeParam>(-10, -10)) << "Should convert coordinates to theirs negative values";
}

TYPED_TEST(Vector2Test, AdditionAssignmentOperator_ShouldSumTheValueToTheCurrentVector2)
{
  this->Assign(new ::Capstone::Vector2<TypeParam>(10, 10));

  *this->vector2 += ::Capstone::Vector2<TypeParam>(1, 2);
  ASSERT_EQ(*this->vector2, ::Capstone::Vector2<TypeParam>(11, 12)) << "Should sum the right value to the current one";
}

TYPED_TEST(Vector2Test, SubtractionAssignmentOperator_ShouldSubtractTheValueToTheCurrentVector2)
{
  this->Assign(new ::Capstone::Vector2<TypeParam>(10, 10));

  *this->vector2 -= ::Capstone::Vector2<TypeParam>(1, 2);
  ASSERT_EQ(*this->vector2, ::Capstone::Vector2<TypeParam>(9, 8)) << "Should subtract the right value to the current one";
}

TYPED_TEST(Vector2Test, AdditionOperator_ShouldSumTheValueofTwoVector2CreatingANewOne)
{
  this->Assign(new ::Capstone::Vector2<TypeParam>(0, 0));

  *this->vector2 = ::Capstone::Vector2<TypeParam>(1, 2) + ::Capstone::Vector2<TypeParam>(3, 4);
  ASSERT_EQ(*this->vector2, ::Capstone::Vector2<TypeParam>(4, 6)) << "Should sum the value of two vector2 creating a new one";
}

TYPED_TEST(Vector2Test, SubtractionOperator_ShouldSubtractTheValueofTwoVector2CreatingANewOne)
{
  this->Assign(new ::Capstone::Vector2<TypeParam>(0, 0));

  *this->vector2 = ::Capstone::Vector2<TypeParam>(3, 4) - ::Capstone::Vector2<TypeParam>(2, 3);
  ASSERT_EQ(*this->vector2, ::Capstone::Vector2<TypeParam>(1, 1)) << "Should subtract the value of two vector2 creating a new one";
}

TYPED_TEST(Vector2Test, MultiplicationOperator_ShouldMultilpyTheValueofEachVector2CordinateBytheNumericValueOfTheSameType)
{
  this->Assign(new ::Capstone::Vector2<TypeParam>(0, 0));

  *this->vector2 = ::Capstone::Vector2<TypeParam>(1, 2) * static_cast<TypeParam>(3);
  ASSERT_EQ(*this->vector2, ::Capstone::Vector2<TypeParam>(3, 6)) << "The Vector2 on left: should multiply its coordinates with a numeric value of the same type, creating a new Vector2 from the result";

  *this->vector2 = static_cast<TypeParam>(3) * ::Capstone::Vector2<TypeParam>(1, 2);
  ASSERT_EQ(*this->vector2, ::Capstone::Vector2<TypeParam>(3, 6)) << "The Vector2 on left: should multiply its coordinates with a numeric value of the same type, creating a new Vector2 from the result";
}

TYPED_TEST(Vector2Test, MultiplicationAssignmentOperator_ShouldMultilpyTheValueofEachVector2CordinateBytheNumericValueOfTheSameTypeAndAssignTheResultToThisVector2)
{
  this->Assign(new ::Capstone::Vector2<TypeParam>(1, 2));

  *this->vector2 *= static_cast<TypeParam>(3);
  ASSERT_EQ(*this->vector2, ::Capstone::Vector2<TypeParam>(3, 6)) << "Should multiply its coordinates with a numeric value of the same type, assigning the value to this Vector2";
}

TYPED_TEST(Vector2Test, DivisionOperator_ShouldDivideTheValueofEachVector2CordinateBytheNumericValueOfTheSameTypeCreatingANewVector2WithTheResult)
{
  this->Assign(new ::Capstone::Vector2<TypeParam>(0, 0));

  *this->vector2 = ::Capstone::Vector2<TypeParam>(2, 4) / static_cast<TypeParam>(2);
  ASSERT_EQ(*this->vector2, ::Capstone::Vector2<TypeParam>(1, 2)) << "Should divide each coordinate by the numeric value (denominator) of the same type, creating a new Vector2 with the result";
}

TYPED_TEST(Vector2Test, DivisionAssignmentOperator_ShouldDivideTheValueofEachVector2CordinateBytheNumericValueOfTheSameTypeAndAssignTheResultToThisVector2)
{
  this->Assign(new ::Capstone::Vector2<TypeParam>(2, 4));

  *this->vector2 /= static_cast<TypeParam>(2);
  ASSERT_EQ(*this->vector2, ::Capstone::Vector2<TypeParam>(1, 2)) << "Should divide each coordinate by the numeric value (denominator) of the same type, assigning the value to this Vector2";
}

TYPED_TEST(Vector2Test, Coordinates_ShouldAcceptAssignmentAsWellAsTheirTypes)
{
  this->Assign (new ::Capstone::Vector2<TypeParam> {100});

  ASSERT_EQ(this->vector2->x, 100) << "The Vector2's x coordinate should be 100 because single parameter constructor is called";
  ASSERT_EQ(this->vector2->y, 100) << "The Vector2's y coordinate should be 100 because single parameter constructor is called";

  this->vector2->x += 1;
  this->vector2->y -= 1;

  ASSERT_EQ(this->vector2->x, 101) << "The Vector2's x coordinate should be 101 because `+=` operator was used";
  ASSERT_EQ(this->vector2->y, 99) << "The Vector2's y coordinate should be 99 because `-=` operator was used";

  ++this->vector2->x;
  --this->vector2->y;

  ASSERT_EQ(this->vector2->x, 102) << "The Vector2's x coordinate should be 102 because `++` operator was used";
  ASSERT_EQ(this->vector2->y, 98) << "The Vector2's y coordinate should be 99 because `--` operator was used";

  this->vector2->x *= 2;
  this->vector2->y /= 2;

  ASSERT_EQ(this->vector2->x, 204) << "The Vector2's x coordinate should be 204 because `*=` operator was used";
  ASSERT_EQ(this->vector2->y, 49) << "The Vector2's y coordinate should be 48 because `/=` operator was used";

  this->vector2->x = 0;
  this->vector2->y = 0;

  ASSERT_EQ(this->vector2->x, 0) << "The Vector2's x coordinate should be 0 because `=` operator was used";
  ASSERT_EQ(this->vector2->y, 0) << "The Vector2's y coordinate should be 0 because `=` operator was used";
}

} // namespace