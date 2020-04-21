#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace fnd {

  template<> Log* Singleton<Log>::m_singleton = nullptr;

  Log::Log() {
    spdlog::set_pattern("%^[%T] %n: %v%$");

    m_engineLogger = spdlog::stdout_color_mt("FND");
    m_engineLogger->set_level(spdlog::level::trace);

    m_clientLogger = spdlog::stdout_color_mt("APP");
    m_clientLogger->set_level(spdlog::level::trace);
  }

  Log::~Log() {
    spdlog::drop("FND");
    spdlog::drop("APP");
  }

}
