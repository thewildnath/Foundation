#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include "Foundation/Core.h"

namespace fnd {

  enum class ShaderDataType {
    None = 0,
    Bool,
    Int, Int2, Int3, Int4,
    Float, Float2, Float3, Float4,
    Mat3, Mat4
  };

  static size_t shaderDataTypeSize(ShaderDataType type) {
    switch (type) {
      case ShaderDataType::None:   return 0;
      case ShaderDataType::Bool:   return sizeof(bool);
      case ShaderDataType::Int:    return sizeof(int);
      case ShaderDataType::Int2:   return sizeof(int) * 2;
      case ShaderDataType::Int3:   return sizeof(int) * 3;
      case ShaderDataType::Int4:   return sizeof(int) * 4;
      case ShaderDataType::Float:  return sizeof(float);
      case ShaderDataType::Float2: return sizeof(float) * 2;
      case ShaderDataType::Float3: return sizeof(float) * 3;
      case ShaderDataType::Float4: return sizeof(float) * 4;
      case ShaderDataType::Mat3:   return sizeof(float) * 3 * 3;
      case ShaderDataType::Mat4:   return sizeof(float) * 4 * 4;
    }

    FND_ASSERT(false, "Unknown ShaderDataType");
    return 0;
  }

  struct BufferElement {
    ShaderDataType type;
    std::string name;
    size_t size;
    size_t offset;
    bool normalised;

    BufferElement(ShaderDataType type, const std::string& name, bool normalised = false)
      : type(type), name(name), size(shaderDataTypeSize(type)), offset(0), normalised(normalised) {}

    size_t getComponentCount() const {
      switch (type) {
        case ShaderDataType::None:   return 0;
        case ShaderDataType::Bool:   return 1;
        case ShaderDataType::Int:    return 1;
        case ShaderDataType::Int2:   return 2;
        case ShaderDataType::Int3:   return 3;
        case ShaderDataType::Int4:   return 4;
        case ShaderDataType::Float:  return 1;
        case ShaderDataType::Float2: return 2;
        case ShaderDataType::Float3: return 3;
        case ShaderDataType::Float4: return 4;
        case ShaderDataType::Mat3:   return 3 * 3;
        case ShaderDataType::Mat4:   return 4 * 4;
      }

      FND_ASSERT(false, "Unknown ShaderDataType");
      return 0;
    }
  };

  class BufferLayout {
  public:
    BufferLayout() = default;
    BufferLayout(const std::initializer_list<BufferElement>& elements);

    inline const std::vector<BufferElement>& getElements() const { return m_elements; }
    inline size_t getStride() const { return m_stride; }

    // Iterators
    std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
    std::vector<BufferElement>::iterator end() { return m_elements.end(); }
    std::vector<BufferElement>::const_iterator begin() const { return m_elements.begin(); }
    std::vector<BufferElement>::const_iterator end()	const { return m_elements.end(); }

  private:
    std::vector<BufferElement> m_elements;
    size_t m_stride = 0;
  };

  class VertexBuffer {
  public:
    virtual ~VertexBuffer() = default;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    virtual void setLayout(const BufferLayout& layout) = 0;
    virtual const BufferLayout& getLayout() const = 0;

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