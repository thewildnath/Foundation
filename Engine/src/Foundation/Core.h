#pragma once

#include <memory>

// Find current platform
#ifdef _WIN32
  #ifdef _WIN64
    #define FND_PLATFORM_WINDOWS
  #else
    #error "x86 builds are not supported!"
  #endif
#else
  #error "Only Windows is supported!"
#endif

// Macro for exporting/importing Windows DLLs
// Taken from https://atomheartother.github.io/c++/2018/07/12/CPPDynLib.html
#ifdef FND_BUILD_SHARED
  #ifdef FND_BUILD_ENGINE
  // Exporting
    #ifdef __GNUC__
      #define FND_API __attribute__ ((dllexport))
    #else
      #define FND_API __declspec(dllexport)
    #endif
  #else
  // Importing
    #ifdef __GNUC__
      #define FND_API __attribute__ ((dllimport))
    #else
      #define FND_API __declspec(dllimport)
    #endif
  #endif
#else
    #define FND_API
#endif

// Debug preprocessor directives
#ifdef FND_BUILD_DEBUG
  #ifdef _MSC_VER
    #define FND_DEBUG_BREAK __debugbreak()
  #else
    #warning "Implement DEBUG_BREAK defintion for other compilers"
    #define FND_DEBUG_BREAK
  #endif
#else
  #define FND_DEBUG_BREAK
#endif

// Assertions
// TODO: improve assert system
#define FND_SIMPLE_ASSERT(x) { if (!(x)) { abort(); } }
#define FND_ASSERT(x, ...) { if (!(x)) { FND_ERROR("Assertion failed: {0}", __VA_ARGS__); FND_DEBUG_BREAK; std::abort(); } }

// Other useful macros
#define FND_BIT(x) (1u << x)
#define FND_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace fnd {
  template<typename T>
  using UniquePtr = std::unique_ptr<T>;

  template<typename T, typename ... Args>
  constexpr UniquePtr<T> makeUnique(Args&& ... args)
  {
    return std::make_unique<T>(std::forward<Args>(args)...);
  }

  template<typename T>
  using SharedPtr = std::shared_ptr<T>;

  template<typename T, typename ... Args>
  constexpr SharedPtr<T> makeShared(Args&& ... args)
  {
    return std::make_shared<T>(std::forward<Args>(args)...);
  }
}