#pragma once

#include <type_traits>

namespace fnd {

  #define ENUM_OPERATOR(T, op) \
    template <typename U = std::underlying_type_t<T>> \
    inline constexpr T operator op(const T& a, const T& b) { return static_cast<T>(static_cast<U>(a) op static_cast<U>(b)); } \
    template <typename U = std::underlying_type_t<T>> \
    inline T& operator op##=(T& a, const T& b) { a = a op b; return a; }

}