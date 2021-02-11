#pragma once

#include "Foundation/Core.h"

namespace fnd {

  template <typename T>
  class Singleton {
  public:
    Singleton() {
      FND_SIMPLE_ASSERT(s_singleton == nullptr);
      s_singleton = static_cast<T*>(this);
    }

    ~Singleton() {
      FND_SIMPLE_ASSERT(s_singleton != nullptr);
      s_singleton = nullptr;
    }

    Singleton(const Singleton<T>&) = delete;
    Singleton& operator=(const Singleton<T>&) = delete;

    static inline T& getSingleton() {
      FND_SIMPLE_ASSERT(s_singleton != nullptr);
      return *s_singleton;
    }

    static inline T* getSingletonPtr() {
      return s_singleton;
    }

  protected:
    static T* s_singleton;
  };

}