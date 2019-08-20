#include "../../src/core/vector2.hpp"
#include "gtest/gtest.h"

namespace
{

TEST(Vector2, should_define_coordinates_as_zero_by_default) {
  // For the sake of readability
  using namespace Capstone;

  // The int vector should defines zero to coordinates by default
  Vector2<int> ivector2;
  ASSERT_EQ (0, ivector2.x); // X coordinate
  ASSERT_EQ (0, ivector2.y); // Y coordinate


  // The unsigned int vector should defines zero to coordinates by default
  Vector2<unsigned int> uvector2;
  ASSERT_EQ (0, uvector2.x); // X coordinate
  ASSERT_EQ (0, uvector2.y); // Y coordinate

  // The float vector should defines zero to coordinates by default
  Vector2<float> fvector2;
  ASSERT_EQ (0, fvector2.x); // X coordinate
  ASSERT_EQ (0, fvector2.y); // Y coordinate
}

TEST(Vector2, should_assign_the_same_value_to_coordinates_when_constructor_has_one_argument) {
  // For the sake of readability
  using namespace Capstone;

  // Should defines the same value
  Vector2<int> ivector2{1000};
  ASSERT_EQ (1000, ivector2.x); // X coordinate
  ASSERT_EQ (1000, ivector2.y); // Y coordinate

  // Should defines the same value
  Vector2<unsigned int> uvector2{1000};
  ASSERT_EQ (1000, uvector2.x); // X coordinate
  ASSERT_EQ (1000, uvector2.y); // Y coordinate

  // Should defines the same value
  Vector2<float> fvector2{1000.5f};
  ASSERT_EQ (1000.5f, fvector2.x); // X coordinate
  ASSERT_EQ (1000.5f, fvector2.y); // Y coordinate
}

TEST(Vector2, should_convert_a_vector_type_to_another_using_constructor) {
  // For the sake of readability
  using namespace Capstone;

  Vector2<int> ivector2{Vector2<float>{1.5f}};

  // Should converts float to int
  ASSERT_EQ (1, ivector2.x); // X coordinate
  ASSERT_EQ (1, ivector2.y); // Y coordinate
}

TEST(Vector2, should_define_the_two_coordinates_on_constructor) {
  // For the sake of readability
  using namespace Capstone;

  // The first argument represents the X coordinate
  // and the second one represents the Y coordinates
  Vector2<int> ivector2{10, 20};
  ASSERT_EQ (10, ivector2.x); // X coordinate
  ASSERT_EQ (20, ivector2.y); // Y coordinate

  Vector2<unsigned int> uvector2{10, 20};
  ASSERT_EQ (10, uvector2.x); // X coordinate
  ASSERT_EQ (20, uvector2.y); // Y coordinate

  Vector2<float> fvector2{10.5f, 20.5f};
  ASSERT_EQ (10.5f, fvector2.x); // X coordinate
  ASSERT_EQ (20.5f, fvector2.y); // Y coordinate
}

TEST(Vector2, should_reassign_each_coordinate_using_public_variables) {
  // For the sake of readability
  using namespace Capstone;

  // This defines vector of int type
  Vector2<int> ivector2;
  ivector2.x = 10;
  ivector2.y = 20;

  ASSERT_EQ (10, ivector2.x); // X coordinate
  ASSERT_EQ (20, ivector2.y); // Y coordinate


  // This defines vector of unsigned int type
  Vector2<unsigned int> uvector2;
  uvector2.x = 10;
  uvector2.y = 20;

  ASSERT_EQ (10, uvector2.x); // X coordinate
  ASSERT_EQ (20, uvector2.y); // Y coordinate


  // This defines vector of float type
  Vector2<float> fvector2;
  fvector2.x = 10.5f;
  fvector2.y = 20.5f;

  ASSERT_EQ (10.5f, fvector2.x); // X coordinate
  ASSERT_EQ (20.5f, fvector2.y); // Y coordinate
}

TEST(Vector2, should_vector2_be_compared_with_another_one_with_the_same_type) {
  // For the sake of readability
  using namespace Capstone;

  // Should be true because they both have the same values and type
  ASSERT_TRUE (Vector2<int>(100, 200) == Vector2<int>(100, 200));

  // Should be false because they both have the same values
  ASSERT_FALSE (Vector2<int>(100, 200) != Vector2<int>(100, 200));



  // Should be true because they both have the same values and type
  ASSERT_TRUE (Vector2<unsigned int>(100, 200) == Vector2<unsigned int>(100, 200));

  // Should be false because they both have the same values
  ASSERT_FALSE (Vector2<unsigned int>(100, 200) != Vector2<unsigned int>(100, 200));



  // Should be true because they both have the same values and type
  ASSERT_TRUE (Vector2<float>(100.5f, 200.5f) == Vector2<float>(100.5f, 200.5f));

  // Should be false because they both have the same values
  ASSERT_FALSE (Vector2<float>(100.5f, 200.5f) != Vector2<float>(100.5f, 200.5f));


  // Variable of type Vector2 can be compared as well
  Vector2<int> left {100, 200};
  Vector2<int> right {100, 200};

  ASSERT_TRUE(left == right);
  ASSERT_FALSE(left != right);

}

TEST(Vector2, should_vector2_has_the_most_common_types_defined_as_shortcut) {
  // For the sake of readability
  using namespace Capstone;

  // Should be true because they both have the same values and type
  // iVector == Vector<int>
  ASSERT_TRUE (iVector2(100, 200) == Vector2<int>(100, 200));

  // Should be true because they both have the same values and type
  // uVector == Vector<unsigned int>
  ASSERT_TRUE (uVector2(100, 200) == Vector2<unsigned int>(100, 200));

  // should be true because they both have the same values and type
  // fVector == Vector<float>
  ASSERT_TRUE (fVector2(100.5f, 200.5f) == Vector2<float>(100.5f, 200.5f));
}

TEST(Vector2, should_vector2_coordinates_to_accept_assignment_as_well_as_their_types) {
  // For the sake of readability
  using namespace Capstone;

  iVector2 vector2;

  // Should accept additional assignment
  vector2.x += 10;
  ASSERT_EQ(10, vector2.x);

  // Should accept subtraction assignment
  vector2.x -= 5;
  ASSERT_EQ(5, vector2.x);

  // Should accept multiplication assignment
  vector2.x *= 2;
  ASSERT_EQ(10, vector2.x);

  // Should accept division assignment
  vector2.x /= 2;
  ASSERT_EQ(5, vector2.x);

  // Should accept module assignment
  vector2.x %= 2;
  ASSERT_EQ(1, vector2.x);
}

}