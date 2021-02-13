#include "Foundation/fndpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace fnd {

  // OpenGLVertexBuffer

  OpenGLVertexBuffer::OpenGLVertexBuffer(const float* vertices, size_t size) {
    glCreateBuffers(1, &m_rendererID);
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    unbind();
  }

  OpenGLVertexBuffer::~OpenGLVertexBuffer() {
    glDeleteBuffers(1, &m_rendererID);
  }

  void OpenGLVertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
  }

  void OpenGLVertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  // OpenGLIndexBuffer

  OpenGLIndexBuffer::OpenGLIndexBuffer(const uint32_t* indices, size_t count)
    : m_Count(count) {
    glCreateBuffers(1, &m_rendererID);
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);

    unbind();
  }

  OpenGLIndexBuffer::~OpenGLIndexBuffer() {
    glDeleteBuffers(1, &m_rendererID);
  }

  void OpenGLIndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
  }

  void OpenGLIndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

}