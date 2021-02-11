#pragma once

#include "Foundation/Core.h"

namespace fnd {

  class VertexBuffer {
  public:
    virtual ~VertexBuffer() = default;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    static SharedPtr<VertexBuffer> create(float* vertices, size_t size);
  };

  class IndexBuffer {
  public:
    virtual ~IndexBuffer() = default;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    virtual size_t getCount() const = 0;

    static SharedPtr<IndexBuffer> create(uint32_t* indices, size_t count);
  };

}