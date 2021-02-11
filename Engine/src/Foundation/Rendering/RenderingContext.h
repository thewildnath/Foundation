#pragma once

#include "Foundation/Core.h"

namespace fnd {

  class RenderingContext {
  public:
    virtual ~RenderingContext() = default;

    virtual void init() = 0;
    virtual void swapBuffers() = 0;

    static UniquePtr<RenderingContext> create(void* window);
  };

}