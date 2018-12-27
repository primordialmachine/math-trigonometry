#include "primordialmachine/trigonometry/include.hpp"
#include "gtest/gtest.h"

TEST(trigonometry_test, angle_test)
{
  using namespace primordialmachine;
  using degrees = angle<angle_unit_degrees, float>;
  using radians = angle<angle_unit_radians, float>;
  using turns = angle<angle_unit_turns, float>;
  (degrees(360.f)).to_degrees();
  (degrees(360.f)).to_radians();
  (degrees(360.f)).to_turns();
  (radians(0.f)).to_degrees();
  (radians(0.f)).to_radians();
  (radians(0.f)).to_turns();
  (turns(0.f)).to_degrees();
  (turns(0.f)).to_radians();
  (turns(0.f)).to_turns();
}
