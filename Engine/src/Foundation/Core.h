#pragma once

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
  #define FND_ENABLE_ASSERTIONS

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
#ifdef FND_ENABLE_ASSERTIONS
  #define FND_E_ASSERT(x, ...) { if (!(x)) { FND_E_ERROR("Assertion failed: {0}", __VA_ARGS__); FND_DEBUG_BREAK; } }
  #define FND_ASSERT(x, ...) { if (!(x)) { FND_ERROR("Assertion failed: {0}", __VA_ARGS__); FND_DEBUG_BREAK; } }
#else
  #define FND_E_ASSERT(x, ...)
  #define FND_ASSERT(x, ...)
#endif

// Other useful macros
#define FND_BIT(x) (1u << x)

#define FND_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)