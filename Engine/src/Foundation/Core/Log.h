#pragma once

#include <spdlog/spdlog.h>

#include "Foundation/Core.h"
#include "Foundation/Utils/Singleton.h"

namespace fnd {

  class FND_API Log : public Singleton<Log> {
  public:
    Log();
    ~Log();

    inline std::shared_ptr<spdlog::logger>& getEngineLogger() { return m_engineLogger; }
    inline std::shared_ptr<spdlog::logger>& getClientLogger() { return m_clientLogger; }

  private:
    std::shared_ptr<spdlog::logger> m_engineLogger;
    std::shared_ptr<spdlog::logger> m_clientLogger;
  };

}

// Log macros
#ifdef FND_BUILD_ENGINE
  #define FND_GET_LOGGER ::fnd::Log::getSingletonPtr()->getEngineLogger()
#else
  #define FND_GET_LOGGER ::fnd::Log::getSingletonPtr()->getClientLogger()
#endif

#define FND_TRACE(...)      FND_GET_LOGGER->trace(__VA_ARGS__)
#define FND_DEBUG(...)      FND_GET_LOGGER->debug(__VA_ARGS__)
#define FND_INFO(...)       FND_GET_LOGGER->info(__VA_ARGS__)
#define FND_WARN(...)       FND_GET_LOGGER->warn(__VA_ARGS__)
#define FND_ERROR(...)      FND_GET_LOGGER->error(__VA_ARGS__)
#define FND_CRITICAL(...)   FND_GET_LOGGER->critical(__VA_ARGS__)



// TODO: strip log defines from distribution builds