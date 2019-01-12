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

#pragma once

#include "primordialmachine/one_zero_functors/include.hpp"
#include "primordialmachine/math/trigonometry/angle.hpp"
#include "primordialmachine/math/trigonometry/angle_unit_degrees.hpp"
#include "primordialmachine/math/trigonometry/angle_unit_radians.hpp"
#include "primordialmachine/math/trigonometry/angle_unit_turns.hpp"
#include "primordialmachine/math/trigonometry/pi.hpp"
#include <type_traits>

namespace primordialmachine {

template<typename UNDERLYING_TYPE>
struct angle<angle_unit_radians,
             UNDERLYING_TYPE,
             std::enable_if_t<std::is_floating_point_v<UNDERLYING_TYPE>>>
{
  UNDERLYING_TYPE m_value;
  angle();
  angle(UNDERLYING_TYPE value);
  UNDERLYING_TYPE value() const;
  void value(UNDERLYING_TYPE value);
  angle<angle_unit_radians, UNDERLYING_TYPE>& operator+=(
    const angle<angle_unit_radians, UNDERLYING_TYPE>& other);
  angle<angle_unit_radians, UNDERLYING_TYPE>& operator-=(
    const angle<angle_unit_radians, UNDERLYING_TYPE>& other);
  angle<angle_unit_radians, UNDERLYING_TYPE>& operator*=(UNDERLYING_TYPE s);
  angle<angle_unit_radians, UNDERLYING_TYPE>& operator/=(UNDERLYING_TYPE s);

  /***********************************************************************************************/

  template<typename T = UNDERLYING_TYPE>
  auto to_degrees() const -> std::enable_if_t<std::is_same_v<float, T>,
                                              angle<angle_unit_degrees, float>>;

  template<typename T = UNDERLYING_TYPE>
  auto to_degrees() const
    -> std::enable_if_t<std::is_same_v<double, T>,
                        angle<angle_unit_degrees, double>>;

  template<typename T = UNDERYLING_TYPE>
  auto to_degrees() const
    -> std::enable_if_t<std::is_same_v<long double, T>,
                        angle<angle_unit_degrees, long double>>;

  /***********************************************************************************************/

  const angle<angle_unit_radians, UNDERLYING_TYPE>& to_radians() const;

  /***********************************************************************************************/

  template<typename T = UNDERLYING_TYPE>
  auto to_turns() const -> std::enable_if_t<std::is_same_v<float, T>,
                                            angle<angle_unit_turns, float>>;

  template<typename T = UNDERLYING_TYPE>
  auto to_turns() const -> std::enable_if_t<std::is_same_v<double, T>,
                                            angle<angle_unit_turns, double>>;

  template<typename T = UNDERLYING_TYPE>
  auto to_turns() const
    -> std::enable_if_t<std::is_same_v<long double, T>,
                        angle<angle_unit_turns, long double>>;
};

#pragma push_macro("CONDITION")
#define CONDITION std::enable_if_t<std::is_floating_point_v<UNDERLYING_TYPE>>

template<typename UNDERLYING_TYPE>
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::angle()
  : m_value(zero<UNDERLYING_TYPE>())
{}

template<typename UNDERLYING_TYPE>
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::angle(
  UNDERLYING_TYPE value)
  : m_value(value)
{}

template<typename UNDERLYING_TYPE>
UNDERLYING_TYPE
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::value() const
{
  return m_value;
}

template<typename UNDERLYING_TYPE>
angle<angle_unit_radians, UNDERLYING_TYPE>&
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::operator+=(
  const angle<angle_unit_radians, UNDERLYING_TYPE>& other)
{
  m_value += other.m_value;
  return *this;
}

template<typename UNDERLYING_TYPE>
angle<angle_unit_radians, UNDERLYING_TYPE>&
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::operator-=(
  const angle<angle_unit_radians, UNDERLYING_TYPE>& other)
{
  m_value -= other.m_value;
  return *this;
}

template<typename UNDERLYING_TYPE>
angle<angle_unit_radians, UNDERLYING_TYPE>&
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::operator*=(
  UNDERLYING_TYPE s)
{
  m_value *= s;
  return *this;
}

template<typename UNDERLYING_TYPE>
angle<angle_unit_radians, UNDERLYING_TYPE>&
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::operator/=(
  UNDERLYING_TYPE s)
{
  m_value /= s;
  return *this;
}

/***********************************************************************************************/

template<typename UNDERLYING_TYPE>
template<typename T>
auto
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::to_degrees() const
  -> std::enable_if_t<std::is_same_v<float, T>,
                      angle<angle_unit_degrees, float>>
{
  return angle<angle_unit_degrees, float>(m_value * 180.0F / pi<float>());
}

template<typename UNDERLYING_TYPE>
template<typename T>
auto
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::to_degrees() const
  -> std::enable_if_t<std::is_same_v<double, T>,
                      angle<angle_unit_degrees, double>>
{
  return angle<angle_unit_degrees, double>(m_value * 180.0 / pi<double>());
}

template<typename UNDERLYING_TYPE>
template<typename T>
auto
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::to_degrees() const
  -> std::enable_if_t<std::is_same_v<long double, T>,
                      angle<angle_unit_degrees, long double>>
{
  return angle<angle_unit_degrees, long double>(m_value * 180.0L /
                                                pi<long double>());
}

/***********************************************************************************************/

template<typename UNDERLYING_TYPE>
const angle<angle_unit_radians, UNDERLYING_TYPE>&
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::to_radians() const
{
  return *this;
}

/***********************************************************************************************/

template<typename UNDERLYING_TYPE>
template<typename T>
auto
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::to_turns() const
  -> std::enable_if_t<std::is_same_v<float, T>, angle<angle_unit_turns, float>>
{
  return angle<angle_unit_turns, float>(m_value / (2.0F * pi<float>()));
}

template<typename UNDERLYING_TYPE>
template<typename T>
auto
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::to_turns() const
  -> std::enable_if_t<std::is_same_v<double, T>,
                      angle<angle_unit_turns, double>>
{
  return angle<angle_unit_degrees, double>(m_value / (2.0 / pi<double>()));
}

template<typename UNDERLYING_TYPE>
template<typename T>
auto
angle<angle_unit_radians, UNDERLYING_TYPE, CONDITION>::to_turns() const
  -> std::enable_if_t<std::is_same_v<long double, T>,
                      angle<angle_unit_turns, long double>>
{
  return angle<angle_unit_turns, long double>(m_value /
                                              (2.0L * pi<long double>()));
}

/***********************************************************************************************/

#pragma pop_macro("CONDITION")

} // namespace primordialmachine
