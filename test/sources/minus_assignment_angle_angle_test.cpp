///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Trigonometry Library
// Copyright (C) 2017-2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "primordialmachine/math/trigonometry/include.hpp"
#include "gtest/gtest.h"

namespace primordialmachine {

TEST(trigonometry_tests, minus_assignment_angle_angle_tests)
{
  {
    using degrees = angle<angle_unit_degrees, float>;
    auto x = degrees(1.f);
    x -= degrees(2.f);
    ASSERT_TRUE(degrees(-1.f) == x);
  }
  {
    using radians = angle<angle_unit_radians, float>;
    auto x = radians(1.f);
    x -= radians(2.f);
    ASSERT_TRUE(radians(-1.f) == x);
  }
  {

    using turns = angle<angle_unit_turns, float>;
    auto x = turns(1.f);
    x -= turns(2.f);
    ASSERT_TRUE(turns(-1.f) == x);
  }
}

} // namespace primordialmachine
