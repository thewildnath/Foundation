#pragma once

#include <string>

#include "Foundation/Core.h"

namespace fnd {

  class FND_API Shader {
  public:
    Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
    ~Shader();

    void bind() const;
    void unbind() const;

  private:
    uint32_t m_rendererID;
  };

}

