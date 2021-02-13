#include "Foundation/fndpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

#include "Foundation/Core.h"
#include "Foundation/Rendering/Buffer.h"

namespace fnd {

  // TODO: temporary testing
  static GLenum shaderDataTypeToGLBaseType(ShaderDataType type) {
    switch (type) {
      case ShaderDataType::Bool:   return GL_BOOL;
      case ShaderDataType::Int:    return GL_INT;
      case ShaderDataType::Int2:   return GL_INT;
      case ShaderDataType::Int3:   return GL_INT;
      case ShaderDataType::Int4:   return GL_INT;
      case ShaderDataType::Float:  return GL_FLOAT;
      case ShaderDataType::Float2: return GL_FLOAT;
      case ShaderDataType::Float3: return GL_FLOAT;
      case ShaderDataType::Float4: return GL_FLOAT;
      case ShaderDataType::Mat3:   return GL_FLOAT;
      case ShaderDataType::Mat4:   return GL_FLOAT;
    }

    FND_ASSERT(false, "Unknown ShaderDataType");
    return 0;
  }

  OpenGLVertexArray::OpenGLVertexArray() {
    glCreateVertexArrays(1, &m_rendererID);
  }

  OpenGLVertexArray::~OpenGLVertexArray() {
    glDeleteVertexArrays(1, &m_rendererID);
  }

  void OpenGLVertexArray::bind() const {
    glBindVertexArray(m_rendererID);
  }

  void OpenGLVertexArray::unbind() const {
    glBindVertexArray(0);
  }

  void OpenGLVertexArray::addVertexBuffer(const SharedPtr<VertexBuffer>& vertexBuffer) {
    FND_ASSERT(vertexBuffer->getLayout().getElements().size() != 0, "VertexBuffer has no layout")

    bind();
    vertexBuffer->bind();

    size_t index = 0;
    const auto& layout = vertexBuffer->getLayout();
    for (const auto& element : layout) {
      glEnableVertexAttribArray(index);
      glVertexAttribPointer(index,
        element.getComponentCount(),
        shaderDataTypeToGLBaseType(element.type),
        element.normalised ? GL_TRUE : GL_FALSE,
        layout.getStride(),
        (const void*)element.offset
      );
      ++index;
    }

    m_vertexBuffers.push_back(vertexBuffer);

    unbind();
    vertexBuffer->unbind();
  }

  void OpenGLVertexArray::setIndexBuffer(const SharedPtr<IndexBuffer>& indexBuffer) {
    bind();
    indexBuffer->bind();

    m_indexBuffer = indexBuffer;

    unbind();
    indexBuffer->unbind();
  }

}
