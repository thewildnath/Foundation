#pragma once

#include <memory>

#include <spdlog/spdlog.h>

namespace fnd {

  class Log {
  public:
    static void init();

  inline static std::shared_ptr<spdlog::logger>& getEngineLogger() { return engineLogger; }
  inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }


  private:
    static std::shared_ptr<spdlog::logger> engineLogger;
    static std::shared_ptr<spdlog::logger> clientLogger;
  };

}

// Engine log macros
#define FND_ENGINE_TRACE(...)    ::fnd::Log::getEngineLogger()->trace(__VA_ARGS__)
#define FND_ENGINE_INFO(...)     ::fnd::Log::getEngineLogger()->info(__VA_ARGS__)
#define FND_ENGINE_WARN(...)     ::fnd::Log::getEngineLogger()->warn(__VA_ARGS__)
#define FND_ENGINE_ERROR(...)    ::fnd::Log::getEngineLogger()->error(__VA_ARGS__)
#define FND_ENGINE_CRITICAL(...) ::fnd::Log::getEngineLogger()->critical(__VA_ARGS__)

// Client log macros
#define FND_TRACE(...)           ::fnd::Log::getClientLogger()->trace(__VA_ARGS__)
#define FND_INFO(...)            ::fnd::Log::getClientLogger()->info(__VA_ARGS__)
#define FND_WARN(...)            ::fnd::Log::getClientLogger()->warn(__VA_ARGS__)
#define FND_ERROR(...)           ::fnd::Log::getClientLogger()->error(__VA_ARGS__)
#define FND_CRITICAL(...)        ::fnd::Log::getClientLogger()->critical(__VA_ARGS__)

// TODO: strip log defines from distribution builds