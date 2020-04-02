#pragma once

#ifdef _WIN32
  #ifdef _WIN64
    #define FND_PLATFORM_WINDOWS64
  #else
    #error "x86 builds are not supported!"
  #endif
#else
  #error "Only Windows is supported!"
#endif