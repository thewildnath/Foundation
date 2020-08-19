#pragma once

namespace fnd {

  class EnumArray {

  };

}

/*
#include <array>

// this is a new kind of array which accepts and requires its indices to be enums
template<typename E, class T, std::size_t N>
class enum_array : public std::array<T, N> {
public:
    T & operator[] (E e) {
        return std::array<T, N>::operator[]((std::size_t)e);
    }

    const T & operator[] (E e) const {
        return std::array<T, N>::operator[]((std::size_t)e);
    }
};

int main() {
    enum class Fruit : unsigned int {
        Apple,
        Kiwi
    };

    enum class Vegetable : unsigned int {
        Carrot,
        Potato
    };

    // Old way:
    std::array<int, 3> old_fruits;
    std::array<int, 3> old_veggies;

    old_fruits[(int)Fruit::Apple] = 3;          // compiles but "ugly"
    old_veggies[(int)Vegetable::Potato] = 7;    // compiles but "ugly"

    old_fruits[(int)Vegetable::Potato] = 3;     // compiles but shouldn't compile!
    old_fruits[2] = 6;                          // compiles but may or may not be desirable

    // New way:
    enum_array<Fruit, int, 3> fruits;
    enum_array<Vegetable, int, 3> veggies;

    fruits[Fruit::Apple] = 3;
    veggies[Vegetable::Potato] = 7;

    // fruits[Vegetable::Potato] = 3;   // doesn't compile :)
    // fruits[2] = 6;                   // doesn't compile
    // fruits[(int)Fruit::Apple] = 3;   // doesn't compile
}
 */


/*
template <class IndexType, class ValueType>
class EnumArray {
 public:
  ValueType& operator[](IndexType i) {
    return array_[static_cast<int>(i)];
  }

  const ValueType& operator[](IndexType i) const {
    return array_[static_cast<int>(i)];
  }

  int size() const { return size_; }

 private:
  ValueType array_[static_cast<int>(IndexType::kMaxValue) + 1];

  int size_ = static_cast<int>(IndexType::kMaxValue) + 1;
};

enum class KeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL,
    kMaxValue = KEY_PRESS_SURFACE_TOTAL
};

int main() {
    EnumArray<KeyPressSurfaces, int> array;
    array[KeyPressSurfaces::KEY_PRESS_SURFACE_DEFAULT] = 5;
    std::cout << array[KeyPressSurfaces::KEY_PRESS_SURFACE_DEFAULT] << std::endl;
    return 0;
}
 */