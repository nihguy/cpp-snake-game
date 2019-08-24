#include "../../src/core/allocation.hpp"

#include "gtest/gtest.h"

namespace
{

/**
 * This allows the Allocation to avoid repeat each test for each template type.
 *
 * @tparam T  The type that will be assigned automatically by the GTest
 */
template <typename T>
class AllocationTest: public ::testing::Test
{
 protected:

  /**
   * It allows this class to assign the Allocation's pointer to the variable `allocation` in other to automatic
   * convert the template class using GTest template features.
   *
   * @param vector2  A pointer to the Dynamic Allocation type
   */
  void Assign (::Capstone::Allocation<T> *vector2) {
    this->allocation = ::std::shared_ptr<::Capstone::Allocation<T>> (vector2);
  }

 protected:
  /**
   * This holds the Allocation instance used by the test properly
   */
  std::shared_ptr<Capstone::Allocation<T>> allocation;
};

/**
 * This defines the most common types used in Allocation. It allows the GTest
 * to convert the class automatically, so we can define the test just once
 * and check the results for each Allocation's type.
 */
using AllocationTypes = ::testing::Types<int, unsigned int, float>;
TYPED_TEST_SUITE (AllocationTest, AllocationTypes);


TYPED_TEST(AllocationTest, DefaultContructor_ShouldDefineTheMeasuresAsZero)
{
  this->Assign (new ::Capstone::Allocation<TypeParam>{});

  ASSERT_EQ(this->allocation->size, ::Capstone::Vector2<TypeParam>{}) << "Allocation's size coordinates should be zero when the default constructor is called";
  ASSERT_EQ(this->allocation->offset, ::Capstone::Vector2<TypeParam>{}) << "Allocation's offset coordinates should be zero when the default constructor is called";
}


TYPED_TEST(AllocationTest, ParameterContructor_ShouldAssignImplicitVector2WithTheSameTypeAsArgument)
{
  this->Assign (new ::Capstone::Allocation<TypeParam>{{ 1, 2 }, { 3, 4 }}); // < Implicit Vector2<TypeParam> arguments

  ASSERT_EQ (this->allocation->size, ::Capstone::Vector2<TypeParam> (1, 2)) << "Allocation should accept implicit Vector2 with the same type as `size` arguments";
  ASSERT_EQ (this->allocation->offset, ::Capstone::Vector2<TypeParam> (3, 4)) << "Allocation should accept implicit Vector2 with the same type as `offset` arguments";
}

TYPED_TEST(AllocationTest, ParameterContructor_ShouldAssignExplicitVector2WithTheSameTypeAsArgument)
{
  this->Assign (new ::Capstone::Allocation<TypeParam>{
      ::Capstone::Vector2<TypeParam> { 1, 2 },
      ::Capstone::Vector2<TypeParam> { 3, 4 }});

  ASSERT_EQ (this->allocation->size, ::Capstone::Vector2<TypeParam> (1, 2)) << "Allocation should accept explicit Vector2 with the same type as `size` arguments";
  ASSERT_EQ (this->allocation->offset, ::Capstone::Vector2<TypeParam> (3, 4)) << "Allocation should accept explicit Vector2 with the same type as `offset` arguments";
}

TYPED_TEST(AllocationTest, CopyContructor_ShouldCastTheCopiedVector2ToTheCurrentType)
{
  auto original = ::Capstone::Allocation<double>{{ 100.5f, 200.5f }, { 300.5f, 400.5f }};
  this->Assign (new ::Capstone::Allocation<TypeParam>{original});

  ASSERT_STRNE(typeid(*this->allocation).name(), typeid(original).name()) << "The Allocation type should not be the same because it was converted";

  auto converted = this->allocation->template get_allocation_as<double> ();
  ASSERT_STREQ(typeid(original).name(), typeid(converted).name()) << "The Allocation type should be the same because it was converted";


  if (typeid(TypeParam) == typeid(float))
  {
    ASSERT_TRUE (*this->allocation == original) << "Should be true because Allocation<double> converted from Allocation<float> have the same coordinates values";
  }
  else
  {
    ASSERT_FALSE (*this->allocation == original) << "Should be false because Allocation<double> converted from Allocation<non-float> have different coordinates values";
  }

  ASSERT_TRUE (*this->allocation == converted) << "Should be true because the value was converted from the first one";
}

TYPED_TEST(AllocationTest, Measures_ShouldBeReassigned)
{
  this->Assign (new ::Capstone::Allocation<TypeParam>{});

  this->allocation->size = ::Capstone::Vector2<TypeParam>(100, 200);
  this->allocation->offset = ::Capstone::Vector2<TypeParam>(300, 400);

  ASSERT_EQ (this->allocation->size, ::Capstone::Vector2<TypeParam>(100, 200)) << "Allocation's size should be reassigned because they both have the same type";
  ASSERT_EQ (this->allocation->offset, ::Capstone::Vector2<TypeParam>(300, 400)) << "Allocation's offset should be reassigned because they both have the same type";
}

TYPED_TEST(AllocationTest, IsEqualToAndIsNotEqualToOperators_ShouldAllocationBeComparedToEachOther)
{
  this->Assign (new ::Capstone::Allocation<TypeParam>{{100, 200}, {300, 400}});

  ASSERT_TRUE (*this->allocation == ::Capstone::Allocation<TypeParam>({100, 200}, {300, 400})) << "Should be true to `==` because they both have the same measures";
  ASSERT_FALSE (*this->allocation != ::Capstone::Allocation<TypeParam>({100, 200}, {300, 400})) << "Should be false to `!=` because they both have the same measures";

  ASSERT_TRUE (*this->allocation == ::Capstone::Allocation<double>({100.0, 200.0}, {300.0, 400.0})) << "Should be true to `==` because they both have the same measures";
  ASSERT_FALSE (*this->allocation != ::Capstone::Allocation<double>({100.0, 200.0}, {300.0, 400.0})) << "Should be false to `!=` because they both have the same measures";
}

TYPED_TEST(AllocationTest, ShouldOffersTheMostCommonAlocationTypeAsShortcut)
{
  this->Assign (new ::Capstone::Allocation<TypeParam>{{100, 200}, {300, 400}});

  if (typeid (TypeParam) == typeid (int))
  {
    auto iShortcut = ::Capstone::iAllocation({100, 200}, {300, 400});
    ASSERT_STREQ (typeid (*this->allocation).name(), typeid (iShortcut).name()) << "The iAllocation should be a shortcut to Allocation<int>";
  }

  if (typeid (TypeParam) == typeid (unsigned int))
  {
    auto uShortcut = ::Capstone::uAllocation({100, 200}, {300, 400});
    ASSERT_STREQ (typeid (*this->allocation).name(), typeid (uShortcut).name()) << "The uAllocation should be a shortcut to Allocation<unsigned int>";
  }

  if (typeid (TypeParam) == typeid (float))
  {
    auto fShortcut = ::Capstone::fAllocation({100.f, 200.f}, {300.f, 400.f});
    ASSERT_STREQ (typeid (*this->allocation).name(), typeid (fShortcut).name()) << "The fAllocation should be a shortcut to Allocation<float>";
  }
}

TYPED_TEST(AllocationTest, GetAllocationAs_ShouldMethodCastTheCurrentTypeUsingTemplateArgumentDeductionType)
{
  this->Assign (new ::Capstone::Allocation<TypeParam>{});

  auto expected = ::Capstone::Allocation<double>{};
  ASSERT_STRNE(typeid(*this->allocation).name(), typeid(expected).name()) << "The Allocations should not be the same type because it was converted";

  auto converted = this->allocation->template get_allocation_as<double> ();
  ASSERT_STREQ(typeid(converted).name(), typeid(expected).name()) << "The Allocations should be the same type because it was converted";

  ASSERT_EQ(*this->allocation, converted) << "The allocation should be equal because they both have the same measures";
}

TYPED_TEST(AllocationTest, GetBoundigBox_ShouldMethodReturnTheObjectEdgeOffset)
{
  this->Assign (new ::Capstone::Allocation<TypeParam>{{10, 10}, {10, 10}});

  ::Capstone::BoundingBox<TypeParam> boundingBox = this->allocation->get_bounding_box ();

  ASSERT_EQ (100, boundingBox.top) << "Should return true because top edge is the product of offset and size `y` coordinates";
  ASSERT_EQ (110, boundingBox.bottom) << "Should return true because bottom edge is the product of offset and size `y` coordinates plus `y` size";
  ASSERT_EQ (100, boundingBox.left) << "Should return true because left edge is the product of offset and size `x` coordinates";
  ASSERT_EQ (110, boundingBox.right) << "Should return true because right edge is the product of offset and size `x` coordinates plus `x` size";
}

TYPED_TEST(AllocationTest, CheckCollision_ShouldMethodCheckAllocationCollisionBetweenEachOther)
{
  this->Assign (new ::Capstone::Allocation<TypeParam>{{10, 10}, {30, 40}});

  ::Capstone::fAllocation over({10.f, 10.f}, {30.9f, 40.9f});

  ASSERT_TRUE (over.check_collision(*this->allocation)) << "Should return true because the allocation is colliding each other";
  ASSERT_TRUE (this->allocation->check_collision(over)) << "Should return true because the allocation is colliding each other";

  ::Capstone::fAllocation out({10.f, 10.f}, {20.f, 20.f});

  ASSERT_FALSE (out.check_collision(*this->allocation)) << "Should return false because the allocation is not colliding each other";
  ASSERT_FALSE (this->allocation->check_collision(out)) << "Should return false because the allocation is not colliding each other";
}
}
