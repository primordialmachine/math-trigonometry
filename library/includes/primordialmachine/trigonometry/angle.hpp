///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Trigonometry Library
// Copyright (C) 2017-2018 Michael Heilmann
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

#pragma once

#include "primordialmachine/trigonometry/cos.hpp"
#include "primordialmachine/trigonometry/cot.hpp"
#include "primordialmachine/trigonometry/sin.hpp"
#include "primordialmachine/trigonometry/tan.hpp"

namespace primordialmachine {

/// @tparam UNIT An AngleUnit type denoting the unit in which the angles are
/// measured.
/// @tparam UNDERLYING_TYPE The underlying type representing the angle values.
/// @tparam ENABLED For SFINAE.
template<typename UNIT, typename TYPE, typename ENABLED = void>
struct angle;

template<typename UNIT, typename UNDERLYING_TYPE>
angle<UNIT, UNDERLYING_TYPE>
operator+(angle<UNIT, UNDERLYING_TYPE> a, angle<UNIT, UNDERLYING_TYPE> b)
{
  a += b;
  return a;
}

template<typename UNIT, typename UNDERLYING_TYPE>
angle<UNIT, UNDERLYING_TYPE>
operator-(angle<UNIT, UNDERLYING_TYPE> a, angle<UNIT, UNDERLYING_TYPE> b)
{
  a -= b;
  return a;
}

template<typename UNIT, typename UNDERLYING_TYPE>
angle<UNIT, UNDERLYING_TYPE> operator*(angle<UNIT, UNDERLYING_TYPE> a, UNIT s)
{
  a *= s;
  return a;
}

template<typename UNIT, typename UNDERLYING_TYPE>
angle<UNIT, UNDERLYING_TYPE>
operator/(angle<UNIT, UNDERLYING_TYPE> a, UNDERLYING_TYPE s)
{
  a /= s;
  return a;
}

template<typename UNIT, typename UNDERLYING_TYPE>
angle<UNIT, UNDERLYING_TYPE> operator*(UNDERLYING_TYPE s,
                                       angle<UNIT, UNDERLYING_TYPE> a)
{
  a *= s;
  return a;
}

template<typename UNIT, typename UNDERLYING_TYPE>
struct cos_functor<angle<UNIT, UNDERLYING_TYPE>, void>
{
  auto operator()(const angle<UNIT, UNDERLYING_TYPE>& a) const
  {
    return cos(a.to_radians().value());
  }
};

template<typename UNIT, typename UNDERLYING_TYPE>
struct cot_functor<angle<UNIT, UNDERLYING_TYPE>, void>
{
  auto operator()(const angle<UNIT, UNDERLYING_TYPE>& a) const
  {
    return cot(a.to_radians().value());
  }
};

template<typename UNIT, typename UNDERLYING_TYPE>
struct sin_functor<angle<UNIT, UNDERLYING_TYPE>, void>
{
  auto operator()(const angle<UNIT, UNDERLYING_TYPE>& a) const
  {
    return sin(a.to_radians().value());
  }
};

template<typename UNIT, typename UNDERLYING_TYPE>
struct tan_functor<angle<UNIT, UNDERLYING_TYPE>, void>
{
  auto operator()(const angle<UNIT, UNDERLYING_TYPE>& a) const
  {
    return tan(a.to_radians().value());
  }
};

} // namespace primordialmachine
