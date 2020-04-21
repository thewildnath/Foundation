#pragma once

#include "Foundation/fndpch.h"

// TODO: check for MSVC
#pragma warning (push)
#pragma warning ( disable: 4661)

namespace fnd {
  template <typename T>
  class Singleton {
  public:
    Singleton() {
      FND_E_ASSERT(m_singleton == nullptr, "There can only be one singleton instance.");
      m_singleton = static_cast<T*>(this);
    }

    ~Singleton() {
      FND_E_ASSERT(m_singleton != nullptr, "Singleton is not instanced.");
      m_singleton = nullptr;
    }

    Singleton(const Singleton<T>&) = delete;
    Singleton& operator=(const Singleton<T>&) = delete;

    static inline T& getSingleton() {
      FND_E_ASSERT(m_singleton != nullptr, "Singleton is not instanced.");
      return *m_singleton;
    }

    static inline T* getSingletonPtr() {
      return m_singleton;
    }

  protected:
    static T* m_singleton;
  };

}

// TODO: check for MSVC
#pragma warning (pop)