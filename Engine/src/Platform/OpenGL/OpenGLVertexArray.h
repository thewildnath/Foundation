#pragma once

#include <vector>

#include "Foundation/Core.h"
#include "Foundation/Rendering/Buffer.h"
#include "Foundation/Rendering/VertexArray.h"
namespace fnd {

  class OpenGLVertexArray : public VertexArray {
  public:
    OpenGLVertexArray();
    ~OpenGLVertexArray() override;

    void bind() const override ;
    void unbind() const override ;

    void addVertexBuffer(const SharedPtr<VertexBuffer>& vertexBuffer) override;
    void setIndexBuffer(const SharedPtr<IndexBuffer>& indexBuffer) override;

    const std::vector<SharedPtr<VertexBuffer>>& getVertexBuffers() const override { return m_vertexBuffers; };
    const SharedPtr<IndexBuffer>& getIndexBuffer() const { return m_indexBuffer; };

  private:
    uint32_t m_rendererID;

    std::vector<SharedPtr<VertexBuffer>> m_vertexBuffers;
    SharedPtr<IndexBuffer> m_indexBuffer;
  };

}
