#include "../../src/core/color.hpp"

#include "gtest/gtest.h"

namespace
{

using ::Capstone::Color;

TEST(Color, DefaultConstructor_ShouldTheColorBeBlack)
{
  Color color{};

  ASSERT_EQ (color.r, 0) << "The red channel should be zero because default constructor is called";
  ASSERT_EQ (color.g, 0) << "The green channel should be zero because default constructor is called";
  ASSERT_EQ (color.b, 0) << "The blue channel should be zero because default constructor is called";
  ASSERT_EQ (color.a, 255) << "The alpha channel should be 255 because default constructor is called";
}

TEST(Color, ParameterContructor_ShouldAssignEachColorChannel) {
  Color color{100, 150, 200};

  ASSERT_EQ (color.r, 100) << "The alpha channel should be 100 because it's assigned to parameter constructor is called";
  ASSERT_EQ (color.g, 150) << "The green channel should be 150 because it's assigned to parameter constructor is called";
  ASSERT_EQ (color.b, 200) << "The blue channel should be 200 because it's assigned to parameter constructor is called";

  ASSERT_EQ (color.a, 255) << "The alpha channel should be 255 because it's not defined in parameter constructor";
}

TEST(Color, ParameterContructor_ShouldAssignTheAlphaChannelAsOptionalArgument) {
  Color color{100, 150, 200, 0};

  ASSERT_EQ (color.r, 100) << "The red channel should be 100 because it's assigned to parameter constructor is called";
  ASSERT_EQ (color.g, 150) << "The green channel should be 150 because it's assigned to parameter constructor is called";
  ASSERT_EQ (color.b, 200) << "The blue channel should be 200 because it's assigned to parameter constructor is called";

  ASSERT_EQ (color.a, 0) << "The alpha channel should be 0 because it's assigned to parameter constructor is called";
}

TEST(Color, Channels_ShouldClampEachOneTo255WhenItExceeds) {
  Color color{300, 400, 500, 600};

  ASSERT_EQ (color.r, 255) << "The red channel should be clamped to 255 because the parameter constructor argument exceeds";
  ASSERT_EQ (color.g, 255) << "The green channel should be clamped to 255 because the parameter constructor argument exceeds";
  ASSERT_EQ (color.b, 255) << "The blue channel should be clamped to 255 because the parameter constructor argument exceeds";
  ASSERT_EQ (color.a, 255) << "The alpha channel should be clamped to 255 because the parameter constructor argument exceeds";
}

TEST(Color, Channels_ShouldClampEachChannelsToZeroWhenItIsInferior) {
  Color color{-100, -200, -300, -400};

  ASSERT_EQ (color.r, 0) << "The red channel should be clamped to zero because the parameter constructor argument is lower of it";
  ASSERT_EQ (color.g, 0) << "The green channel should be clamped to zero because the parameter constructor argument is lower of it";
  ASSERT_EQ (color.b, 0) << "The blue channel should be clamped to zero because the parameter constructor argument is lower of it";
  ASSERT_EQ (color.a, 0) << "The alpha channel should be clamped to zero because the parameter constructor argument is lower of it";
}

TEST(Color, SingleParameterContructor_ShouldAssignColorAsHexadecimal) {
  Color color{0xCCDDEEFF};

  ASSERT_EQ (color.r, 204) << "The red channel should be 204 because the first hexadecimal byte is defined as `CC` on parameter constructor";
  ASSERT_EQ (color.g, 221) << "The green channel should be 221 because the second hexadecimal byte is defined as `DD` on parameter constructor";
  ASSERT_EQ (color.b, 238) << "The blue channel should be 204 because the third hexadecimal byte is defined as `EE` on parameter constructor";
  ASSERT_EQ (color.a, 255) << "The alpha channel should be 255 because the fourth hexadecimal byte is defined as `FF` on parameter constructor";
}

TEST(Color, IsEqualToAndIsNotEqualToOperators_ShouldAColorComparedToEachOther) {
  Color color{255, 255, 255, 255};

  ASSERT_TRUE (color == Color(255, 255, 255, 255)) << "Should be true to `==` because each channel is equivalent";
  ASSERT_TRUE (color != Color(255, 255, 255, 0))  << "Should be true to `!=` because one of the channels is not equivalent";
}

TEST(Color, ShouldOffersTheMostCommonColorAsStaticVariables)
{
  ASSERT_TRUE (Color::White == Color(255, 255, 255, 255)) << "Should be true because they both have the same channels";
  ASSERT_TRUE (Color::Red == Color (255, 0, 0, 255)) << "Should be true because they both have the same channels";
  ASSERT_TRUE (Color::Green == Color (0, 255, 0, 255)) << "Should be true because they both have the same channels";
  ASSERT_TRUE (Color::Blue == Color (0, 0, 255, 255)) << "Should be true because they both have the same channels";
  ASSERT_TRUE (Color::Cyan == Color (0, 255, 255, 255)) << "Should be true because they both have the same channels";
  ASSERT_TRUE (Color::Magenta == Color (255, 0, 255, 255)) << "Should be true because they both have the same channels";
  ASSERT_TRUE (Color::Yellow == Color (255, 255, 0, 255)) << "Should be true because they both have the same channels";
  ASSERT_TRUE (Color::Black == Color (0, 0, 0, 255)) << "Should be true because they both have the same channels";
  ASSERT_TRUE (Color::Transparent == Color(0, 0, 0, 0)) << "Should be true because they both have the same channels";
}

TEST(Color, SubtractionOperator_ShouldCreateANewDarkenColor) {
  Color transparent = (Color::White - Color::White);
  ASSERT_TRUE (Color(0, 0, 0, 0) == transparent) << "Should remove all the opacity channel by default";

  Color solid = (Color::Red - Color(255, 0, 0, 0));
  ASSERT_TRUE (Color(0, 0, 0, 255) == solid) << "Should not remove the opacity channel because one of them is zero";

  Color darken = (Color::White - Color(127, 127, 127, 0));
  ASSERT_TRUE (Color(128, 128, 128, 255) == darken) << "Should darken color from white to grey";

  Color clamped = (Color(0, 0, 0, 255) - Color(255, 255, 0, 255));
  ASSERT_TRUE (Color(0, 0, 0, 0) == clamped) << "Should clamp each channel lower than zero to zero";
}

TEST(Color, AdditionOperator_ShouldCreateANewLightenColor) {
  Color clamped = Color::White + Color::White;
  ASSERT_EQ(clamped, Color::White) << "Should clamp each channel higher than 255 to 255";

  Color white = Color::Yellow + Color::Blue;
  ASSERT_EQ(white, Color::White) << "Should add 255 to blue channel creating a new white color";

  Color gray = Color::Black + Color(128, 128, 128);
  ASSERT_EQ(gray, Color(128, 128, 128, 255)) << "Should create lighten grey from black color adding 128 to each channel";
}

TEST(Color, MultiplicationOperator_ShouldCreateANewDarkenColor) {
  Color dark_red = Color::Red * Color(50, 50, 50);
  ASSERT_EQ(dark_red, Color(50, 0, 0, 255)) << "Should create a darken red color multiplying each channel to 50";

  Color dark_gray = Color(80, 80, 80) * Color(33, 33, 33);
  ASSERT_EQ(dark_gray, Color(10, 10, 10, 255)) << "Should create a darken gray color multiplying each channel to 33";
}

TEST(Color, AdditionAssignmentOperator_ShouldLightenTheCurrentColor)
{
  auto clamped = Color::White;
  clamped += Color::White;
  ASSERT_EQ(clamped, Color::White) << "Should clamp each channel higher than 255 to 255";

  auto yellow = Color::Yellow;
  yellow += Color::Blue;
  ASSERT_EQ(yellow, Color::White) << "Should add 255 to the current blue channel lighten the color from yellow to white";

  auto black = Color::Black;
  black +=  Color(128, 128, 128);
  ASSERT_EQ(black, Color(128, 128, 128, 255)) << "Should lighten the black to grey color adding 128 to each channel";
}

TEST(Color, SubtractionAssignmentOperator_ShouldDarkenTheCurrentColor)
{
  auto white = Color::White;
  white -= Color(55, 55, 55);
  ASSERT_EQ(white, Color(200, 200, 200, 0)) << "Should remove all the opacity channel by default";

  auto solid = Color::White;
  solid -= Color(55, 55, 55, 0);
  ASSERT_TRUE (Color(200, 200, 200, 255) == solid) << "Should not remove the opacity channel because one of them is zero";

  auto darken = Color::White;
  darken -= Color(127, 127, 127, 0);
  ASSERT_TRUE (Color(128, 128, 128, 255) == darken) << "Should darken the current color from white to grey";

  auto clamped = Color::Black;
  clamped -= Color(255, 255, 255, 0);
  ASSERT_EQ(clamped, Color(0, 0, 0, 255)) << "Should clamp each channel lower than zero to zero";
}

TEST(Color, MultiplicationAssignmentOperator_ShouldDarkenTheCurrentColor)
{
  Color white = Color::White;
  white *= Color(128, 128, 128, 255);
  ASSERT_EQ(white, Color(128, 128, 128, 255)) << "Should darken the current color (including alpha) and clamp the values to 255";
}

} // namespace
