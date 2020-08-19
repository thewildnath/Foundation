#pragma once

#include "Foundation/fndpch.h"

namespace fnd {

  template <typename T>
  class Singleton {
  public:
    Singleton() {
      FND_SIMPLE_ASSERT(m_singleton == nullptr);
      m_singleton = static_cast<T*>(this);
    }

    ~Singleton() {
      FND_SIMPLE_ASSERT(m_singleton != nullptr);
      m_singleton = nullptr;
    }

    Singleton(const Singleton<T>&) = delete;
    Singleton& operator=(const Singleton<T>&) = delete;

    static inline T& getSingleton() {
      FND_SIMPLE_ASSERT(m_singleton != nullptr);
      return *m_singleton;
    }

    static inline T* getSingletonPtr() {
      return m_singleton;
    }

  protected:
    static T* m_singleton;
  };

}