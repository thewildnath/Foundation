#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace fnd {

  std::shared_ptr<spdlog::logger> Log::engineLogger;
  std::shared_ptr<spdlog::logger> Log::clientLogger;

  void Log::init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");

    engineLogger = spdlog::stdout_color_mt("FND");
    engineLogger->set_level(spdlog::level::trace);

    clientLogger = spdlog::stdout_color_mt("APP");
    clientLogger->set_level(spdlog::level::trace);
  }

}
