#pragma once

#include <array>
#include <type_traits>

namespace fnd {

  template<typename E, typename T>
  class EnumArray : public std::array<T, static_cast<size_t>(E::ENUM_SIZE)> {
  public:
    T& operator[](E e) {
      return std::array<T, static_cast<size_t>(E::ENUM_SIZE)>::operator[](static_cast<size_t>(e));
    }

    const T& operator[](E e) const {
      return std::array<T, static_cast<size_t>(E::ENUM_SIZE)>::operator[](static_cast<size_t>(e));
    }
  };

}