#include "Foundation/fndpch.h"
#include "LogManager.h"

#include <spdlog/sinks/stdout_color_sinks.h>

#include "Foundation/Utils/Singleton.h"

namespace fnd {

  template<> LogManager* Singleton<LogManager>::s_singleton = nullptr;

  LogManager::LogManager() {
    spdlog::set_pattern("%^[%T] %n: %v%$");

    m_engineLogger = spdlog::stdout_color_mt("FND");
    m_engineLogger->set_level(spdlog::level::trace);

    m_clientLogger = spdlog::stdout_color_mt("APP");
    m_clientLogger->set_level(spdlog::level::trace);
  }

  LogManager::~LogManager() {
    spdlog::drop("FND");
    spdlog::drop("APP");
  }

}
