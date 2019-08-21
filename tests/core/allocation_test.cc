#include "../../src/core/allocation.hpp"
#include "gtest/gtest.h"

namespace
{

TEST(Allocation, should_define_size_and_offset_as_zero_by_default) {
  // For the sake of readability
  using namespace Capstone;

  // The int allocation should defines zero to size and offset by default
  Allocation<int> iallocation;
  ASSERT_EQ (iVector2(0, 0), iallocation.size); // size is a Vector2
  ASSERT_EQ (iVector2(0, 0), iallocation.offset); // offset is a Vector2


  // The unsigned int allocation should defines zero to size and offset by default
  Allocation<unsigned int> uallocation;
  ASSERT_EQ (uVector2(0, 0), uallocation.size); // size is a Vector2
  ASSERT_EQ (uVector2(0, 0), uallocation.offset); // offset is a Vector2


  // The float allocation should defines zero to size and offset by default
  Allocation<float> fallocation;
  ASSERT_EQ (fVector2(0, 0), fallocation.size); // size is a Vector2
  ASSERT_EQ (fVector2(0, 0), fallocation.offset); // offset is a Vector2
}

TEST(Allocation, should_allocation_constructor_to_define_the_offset_and_size_based_on_type_deduction) {
  // For the sake of readability
  using namespace Capstone;

  // Should defines size and offset of the same type deduction
  // (they both as int). The first argument should represents
  // the size and the second one the offset.
  Allocation<int> iallocation{{100, 200}, {300, 400}};
  ASSERT_EQ (iVector2(100, 200), iallocation.size);
  ASSERT_EQ (iVector2(300, 400), iallocation.offset);


  // Should defines size and offset of the same type deduction
  // (they both as unsigned int). The first argument should represents
  // the size and the second one the offset.
  Allocation<unsigned int> uallocation{{100, 200}, {300, 400}};
  ASSERT_EQ (uVector2(100, 200), uallocation.size);
  ASSERT_EQ (uVector2(300, 400), uallocation.offset);

  // Should defines size and offset of the same type deduction
  // (they both as float). The first argument should represents
  // the size and the second one the offset.
  Allocation<float> fallocation{{100.5f, 200.5f}, {300.5f, 400.5f}};
  ASSERT_EQ (fVector2(100.5f, 200.5f), fallocation.size); // X coordinate
  ASSERT_EQ (fVector2(300.5f, 400.5f), fallocation.offset); // Y coordinate
}

TEST(Allocation, should_convert_a_allocation_type_to_another_using_constructor) {
  // For the sake of readability
  using namespace Capstone;

  Allocation<int> iallocation{Allocation<float>{{ 100.5f, 200.5f }, { 300.5f, 400.5f }}};

  // Should converts float to int
  ASSERT_EQ (iVector2(100, 200), iallocation.size);
  ASSERT_EQ (iVector2(300, 400), iallocation.offset);
}

TEST(Allocation, should_reassign_the_size_and_offset_using_public_variables) {
  // For the sake of readability
  using namespace Capstone;

  // Should allows the int Allocation class to defines their variables
  Allocation<int> iallocation;
  iallocation.size = iVector2(100, 200); // Vector2 must have the same deduction type
  iallocation.offset = iVector2(100, 200); // Vector2 must have the same deduction type

  ASSERT_EQ (iVector2(100, 200), iallocation.size);
  ASSERT_EQ (iVector2(100, 200), iallocation.offset);


  // Should allows the unsigned int Allocation class to defines their variables
  Allocation<unsigned int> uallocation;
  uallocation.size = uVector2(100, 200); // Vector2 must have the same deduction type
  uallocation.offset = uVector2(100, 200); // Vector2 must have the same deduction type

  ASSERT_EQ (uVector2(100, 200), uallocation.size);
  ASSERT_EQ (uVector2(100, 200), uallocation.offset);


  // Should allows the float Allocation class to defines their variables
  Allocation<float> fallocation;
  fallocation.size = fVector2(100.5f, 200.5f); // Vector2 must have the same deduction type
  fallocation.offset = fVector2(100.5f, 200.5f); // Vector2 must have the same deduction type

  ASSERT_EQ (fVector2(100.5f, 200.5f), fallocation.size);
  ASSERT_EQ (fVector2(100.5f, 200.5f), fallocation.offset);
}

TEST(Vector2, should_allocation_be_compared_with_another_one_with_the_same_type) {
  // For the sake of readability
  using namespace Capstone;

  // This defines two allocations with the same value
  auto ileft = Allocation<int>(iVector2{ 100, 200 }, iVector2{ 300, 400 });
  auto iright = Allocation<int>(iVector2{ 100, 200 }, iVector2{ 300, 400 });

  ASSERT_TRUE (ileft == iright); // Should be true because they both have the same values and type
  ASSERT_FALSE (ileft != iright); // Should be false because they both have the same values



  // This defines two allocations with the same value
  auto uleft = Allocation<unsigned int>(uVector2{ 100, 200 }, uVector2{ 300, 400 });
  auto uright = Allocation<unsigned int>(uVector2{ 100, 200 }, uVector2{ 300, 400 });

  ASSERT_TRUE (uleft == uright); // Should be true because they both have the same values and type
  ASSERT_FALSE (uleft != uright); // Should be false because they both have the same values



  // This defines two allocations with the same value
  auto fleft = Allocation<float>(fVector2{ 100.5f, 200.5f }, fVector2{ 300.5f, 400.5f });
  auto fright = Allocation<float>(fVector2{ 100.5f, 200.5f }, fVector2{ 300.5f, 400.5f });

  ASSERT_TRUE (fleft == fright); // Should be true because they both have the same values and type
  ASSERT_FALSE (fleft != fright); // Should be false because they both have the same values
}

TEST(Allocation, should_allocation_has_the_most_common_types_defined_as_shortcut) {
  // For the sake of readability
  using namespace Capstone;


  // This defines two allocations with the same value
  auto ileft = Allocation<int>({ 100, 200 }, { 300, 400 });
  auto iright = iAllocation({ 100, 200 }, { 300, 400 });

  // Should be true because they both have the same values and type
  // iAllocation == Allocation<int>
  ASSERT_TRUE (ileft == iright);


  // This defines two allocations with the same value
  auto uleft = Allocation<unsigned int>({ 100, 200 }, { 300, 400 });
  auto uright = uAllocation({ 100, 200 }, { 300, 400 });

  // Should be true because they both have the same values and type
  // iAllocation == Allocation<unsigned int>
  ASSERT_TRUE (uleft == uright);


  // This defines two allocations with the same value
  auto fleft = Allocation<float>({ 100.5f, 200.5f }, { 300.5f, 400.5f });
  auto fright = fAllocation({ 100.5f, 200.5f }, { 300.5f, 400.5f });

  // Should be true because they both have the same values and type
  // fAllocation == Allocation<float>
  ASSERT_TRUE (fleft == fright);

}

TEST(Allocation, should_size_and_offset_can_be_reassigned) {
  // For the sake of readability
  using namespace Capstone;

  iAllocation allocation;

  // Should accept additional assignment
  allocation.size = iVector2{100, 200};
  allocation.offset = iVector2{300, 400};

  ASSERT_EQ (iVector2(100, 200), allocation.size);
  ASSERT_EQ (iVector2(300, 400), allocation.offset);
}

TEST(Allocation, should_get_allocation_as_method_to_convert_the_current_allocation_to_another_one) {
  // For the sake of readabilitskypey
  using namespace Capstone;

  fAllocation fallocation({100.5f, 200.5f}, {300.5f, 400.5f});
  iAllocation iallocation({100, 200}, {300, 400});

  ASSERT_EQ (iallocation, fallocation.get_allocation_as<int>());
}

TEST(Allocation, should_get_bouding_box_return_the_object_edge_offset) {
  // For the sake of readability
  using namespace Capstone;

  iAllocation iallocation({10, 10}, {10, 10});

  auto bounding_box = iallocation.get_bounding_box ();

  ASSERT_EQ (100, bounding_box.top);
  ASSERT_EQ (110, bounding_box.bottom);
  ASSERT_EQ (100, bounding_box.left);
  ASSERT_EQ (110, bounding_box.right);
}

TEST(Allocation, should_check_collision_with_another_allocation) {
  // For the sake of readability
  using namespace Capstone;

  fAllocation fallocation_over({10.f, 10.f}, {30.9f, 40.9f});
  iAllocation iallocation_over({10, 10}, {30, 40});

  // Should return true because the allocation is over another one
  ASSERT_TRUE (fallocation_over.check_collision(iallocation_over));
  ASSERT_TRUE (iallocation_over.check_collision(fallocation_over));



  fAllocation fallocation_out({10.f, 10.f}, {20.f, 20.f});
  iAllocation iallocation_out({10, 10}, {30, 30});

  // Should return false because the allocation is not touching another one
  ASSERT_FALSE (fallocation_out.check_collision(iallocation_out));
  ASSERT_FALSE (iallocation_out.check_collision(fallocation_out));
}
}
