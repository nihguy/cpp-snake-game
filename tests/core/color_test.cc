#include "../../src/core/color.hpp"
#include "gtest/gtest.h"

namespace
{

// This tests if constructor can assign the value correctly
TEST(Color, should_assign_color_channel_on_constructor) {
  Capstone::Color white {255, 255, 255};

  ASSERT_EQ (255, white.r); // Red channel
  ASSERT_EQ (255, white.g); // Green channel
  ASSERT_EQ (255, white.b); // Blue channel

  // The alpha channel is assigned as 255 as default
  EXPECT_EQ (255, white.a);
}

TEST(Color, should_assigning_alpha_channel_as_optional_argument) {
  // The fourth argument should assign alpha channel
  Capstone::Color transparent {255, 255, 255, 0};

  EXPECT_EQ (255, transparent.r); // Red channel
  EXPECT_EQ (255, transparent.g); // Green channel
  EXPECT_EQ (255, transparent.b); // Blue channel

  ASSERT_EQ (0, transparent.a); // Alpha channel
}

TEST(Color, should_clamp_the_channels_to_255_when_it_exceeds_on_constructor) {
  Capstone::Color white (300, 300, 300, 300);

  ASSERT_EQ (255, white.r); // Red channel
  ASSERT_EQ (255, white.g); // Green channel
  ASSERT_EQ (255, white.b); // Blue channel
  ASSERT_EQ (255, white.a); // Alpha channel
}

TEST(Color, should_clamp_the_channels_to_0_when_it_lower_on_constructor) {
  Capstone::Color black (-255, -255, -255, -255);

  ASSERT_EQ (0, black.r); // Red channel
  ASSERT_EQ (0, black.g); // Green channel
  ASSERT_EQ (0, black.b); // Blue channel
  ASSERT_EQ (0, black.a); // Alpha channel
}

TEST(Color, should_assign_color_using_hexadecimal_on_constructor) {
  // The two last numbers represents the alpha channel
  Capstone::Color red (0xFF0000FF);

  ASSERT_EQ (255, red.r); // Red channel
  ASSERT_EQ (0, red.g); // Green channel
  ASSERT_EQ (0, red.b); // Blue channel
  ASSERT_EQ (255, red.a); // Alpha channel
}

TEST(Color, should_constructor_to_define_black_as_default_color) {
  // This defines "solid" black (with alpha channel as 255)
  Capstone::Color black;

  ASSERT_EQ (0, black.r); // Red channel
  ASSERT_EQ (0, black.g); // Green channel
  ASSERT_EQ (0, black.b); // Blue channel
  ASSERT_EQ (255, black.a); // Alpha channel
}

TEST(Color, should_color_be_compared_with_another_one) {
  // For the sake of readability
  using namespace Capstone;

  // This is the main color
  Color black1;

  // There are colors will be compared to the above one
  Color black2;
  Color red {255, 0, 0};

  // Should be true
  ASSERT_TRUE (black1 == black2); // When asserting same colors
  ASSERT_TRUE (black1 != red); // When checking if different colors are equals

  // Should be false
  ASSERT_FALSE (black1 == red); // When comparing different colors
  ASSERT_FALSE (black1 != black2); // When checking if the same colors are equals
}

TEST(Color, should_color_offers_the_most_common_color_as_static_variables) {
  // For the sake of readability
  using namespace Capstone;

  // This defines the "full" White color
  ASSERT_TRUE (Color::White == Color (255, 255, 255, 255));

  // This defines the "RGB" primary colors
  ASSERT_TRUE (Color::Red == Color (255, 0, 0, 255));
  ASSERT_TRUE (Color::Green == Color (0, 255, 0, 255));
  ASSERT_TRUE (Color::Blue == Color (0, 0, 255, 255));

  // This defines the "CMYK" primary colors
  ASSERT_TRUE (Color::Cyan ==  Color (0, 255, 255, 255));
  ASSERT_TRUE (Color::Magenta == Color (255, 0, 255, 255));
  ASSERT_TRUE (Color::Yellow == Color (255, 255, 0, 255));
  ASSERT_TRUE (Color::Black == Color (0, 0, 0, 255));

  // Transparent (total opacity)
  ASSERT_TRUE(Color::Transparent == Color(0, 0, 0, 0));
}

TEST(Color, should_create_a_new_darken_color_when_subtract_two_of_them) {
  // For the sake of readability
  using namespace Capstone;

  // Should remove 255 from Yellow's green and alpha channel
  Color new_red_color = Color::Yellow - Color::Green;
  ASSERT_EQ(new_red_color, Color(255, 0, 0, 0)); // Yellow - Green = Transparent Red color

  // Should subtract 127 from each color channel and
  // preserve the opacity channel because it's zero
  Color new_gray_color = Color::White - Color(127, 127, 127, 0);
  ASSERT_EQ(new_gray_color, Color(128, 128, 128, 255));

  // Should subtract when a color is defined as hexadecimal
  Color new_gray_color_from_hex = Color::White - Color(0x7F7F7F00);
  ASSERT_EQ(new_gray_color_from_hex, Color(128, 128, 128, 255));

  // Should clamp the value to 0 when it's lower than zero
  Color black = Color(0, 0, 0, 255) - Color(255, 255, 0, 0);
  ASSERT_EQ(black, Color(0, 0, 0, 255));
}

TEST(Color, should_create_a_new_lighten_color_when_add_two_of_them) {
  // For the sake of readability
  using namespace Capstone;

  // Should add 255 from each color channel.
  // The values exceeds 255 will be clamped to this value
  Color clamped = Color::White + Color::White;
  ASSERT_EQ(clamped, Color::White);

  // Should sum 255 to Yellow's blue channel
  // The values exceeds 255 will be clamped to this value
  Color white = Color::Yellow + Color::Blue;
  ASSERT_EQ(white, Color::White);

  // Should add 128 from each color channel and keep the alpha channel
  Color gray = Color::Black + Color(128, 128, 128, 0);
  ASSERT_EQ(gray, Color(128, 128, 128, 255));

  // Should lighten color when a color is defined as hexadecimal as well
  Color gray_from_hex = Color::Black + Color(0x80808000);
  ASSERT_EQ(gray_from_hex, Color(128, 128, 128, 255));
}

TEST(Color, should_create_a_new_darken_color_when_multiply_two_of_them) {
  // For the sake of readability
  using namespace Capstone;

  // Should multiply each color channel.
  // The values exceeds 255 will be clamped to this value
  Color dark_red = Color::Red * Color(50, 50, 50);
  ASSERT_EQ(dark_red, Color(50, 0, 0, 255));

  // Should sum 255 to Yellow's blue channel
  // The values exceeds 255 will be clamped to this value
  Color dark_gray = Color(80, 80, 80) * Color(33, 33, 33);
  ASSERT_EQ(dark_gray, Color(10, 10, 10, 255));

  // Should darken each Color's channel a color is defined as hexadecimal as well
  Color dark_gray_from_hex = Color(80, 80, 80) * Color(0x212121FF);
  ASSERT_EQ(dark_gray_from_hex, Color(10, 10, 10, 255));
}

TEST(Color, should_lighten_the_current_color_when_addition_assignment_is_used) {
  // For the sake of readability
  using namespace Capstone;

  // Should lighten the current color adding the right value.
  Color black = Color::Black;
  black += Color(128, 128, 128);
  ASSERT_EQ(black, Color(128, 128, 128, 255));

  // Should lighten the current color adding the right value.
  // The values exceeds 255 will be clamped to this value
  Color red = Color::Red;
  red += Color(50, 50, 50);
  ASSERT_EQ(red, Color(255, 50, 50, 255));

  // Should lighten the current color adding an hexadecimal as well
  Color green = Color::Green;
  green += Color(0xFF0000FF);
  ASSERT_EQ(green, Color::Yellow);
}

TEST(Color, should_darken_the_current_color_when_subtraction_assignment_is_used) {
  // For the sake of readability
  using namespace Capstone;

  // Should darken the current color (including alpha) when
  // subtracting the right value
  Color white = Color::White;
  white -= Color(55, 55, 55, 255);
  ASSERT_EQ(white, Color(200, 200, 200, 0));

  // Should clamp the value of each color channel to zero if it exceeds this value
  // Should keep the alpha channel because te right value of this is zero
  Color clamped = Color::Black;
  clamped -= Color(128, 128, 128, 0);
  ASSERT_EQ(clamped, Color(0, 0, 0, 255));

  // Should darken the current color subtracting an hexadecimal as well
  Color red = Color::Red;
  red -= Color(0xFF000000);
  ASSERT_EQ(red, Color::Black);
}

TEST(Color, should_darken_the_current_color_when_multiplication_assignment_is_used) {
  // For the sake of readability
  using namespace Capstone;

  // Should darken the current color (including alpha) when
  // subtracting the right value clamp the values to 255 if it exceeds.
  Color white = Color::White;
  white *= Color(128, 128, 128, 255);
  ASSERT_EQ(white, Color(128, 128, 128, 255));

  // Should darken the current color multiplying an hexadecimal as well
  Color red = Color::Red;
  red *= Color(0x800000FF);
  ASSERT_EQ(red, Color(128, 0, 0, 255));
}

}
