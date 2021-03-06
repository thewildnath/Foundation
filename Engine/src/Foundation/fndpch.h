#pragma once

#include <algorithm>
#include <cstdint>
#include <iosfwd>
#include <iostream>
#include <functional>
#include <memory>
#include <sstream>
#include <type_traits>
#include <utility>

#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Core.h"
#include "Foundation/Core/LogManager.h"

#ifdef FND_PLATFORM_WINDOWS
  #include <Windows.h>
#endif