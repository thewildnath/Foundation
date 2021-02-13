#pragma once

#include <vector>

#include "Foundation/Core.h"
#include "Foundation/Rendering/Buffer.h"

namespace fnd {

  class VertexArray {
  public:
    virtual ~VertexArray() = default;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    virtual void addVertexBuffer(const SharedPtr<VertexBuffer>& vertexBuffer) = 0;
    virtual void setIndexBuffer(const SharedPtr<IndexBuffer>& indexBuffer) = 0;

    virtual const std::vector<SharedPtr<VertexBuffer>>& getVertexBuffers() const = 0;
    virtual const SharedPtr<IndexBuffer>& getIndexBuffer() const = 0;

    static SharedPtr<VertexArray> create();
  };

}
