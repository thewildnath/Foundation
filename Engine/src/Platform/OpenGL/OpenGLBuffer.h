#pragma once

#include "Foundation/Core.h"
#include "Foundation/Rendering/Buffer.h"

namespace fnd {

  class OpenGLVertexBuffer : public VertexBuffer {
  public:
    OpenGLVertexBuffer(float* vertices, size_t size);
    ~OpenGLVertexBuffer() override;

    void bind() const override;
    void unbind() const override;

  private:
    uint32_t m_rendererID;
  };

  class OpenGLIndexBuffer : public IndexBuffer {
  public:
    OpenGLIndexBuffer(uint32_t* indices, size_t count);
    ~OpenGLIndexBuffer() override;

    void bind() const override;
    void unbind() const override;

    size_t getCount() const override {
      return m_Count;
    };

  private:
    uint32_t m_rendererID;
    size_t m_Count;
  };

}