#pragma once

#include <spdlog/spdlog.h>

#include "Foundation/Core.h"
#include "Foundation/Core/AbstractManager.h"

namespace fnd {

  class FND_API LogManager : public AbstractManager<LogManager> {
  public:
    LogManager();
    ~LogManager();

    inline std::shared_ptr<spdlog::logger>& getEngineLogger() { return m_engineLogger; }
    inline std::shared_ptr<spdlog::logger>& getClientLogger() { return m_clientLogger; }

  private:
    std::shared_ptr<spdlog::logger> m_engineLogger;
    std::shared_ptr<spdlog::logger> m_clientLogger;
  };

}

// Log macros
#ifdef FND_BUILD_ENGINE
  #define FND_GET_LOGGER ::fnd::LogManager::getSingletonPtr()->getEngineLogger()
#else
  #define FND_GET_LOGGER ::fnd::LogManager::getSingletonPtr()->getClientLogger()
#endif

#define FND_TRACE(...)      FND_GET_LOGGER->trace(__VA_ARGS__)
#define FND_DEBUG(...)      FND_GET_LOGGER->debug(__VA_ARGS__)
#define FND_INFO(...)       FND_GET_LOGGER->info(__VA_ARGS__)
#define FND_WARN(...)       FND_GET_LOGGER->warn(__VA_ARGS__)
#define FND_ERROR(...)      FND_GET_LOGGER->error(__VA_ARGS__)
#define FND_CRITICAL(...)   FND_GET_LOGGER->critical(__VA_ARGS__)

// TODO: strip log defines from distribution builds