#pragma once

#include <renderer/texture-wrapper.hpp>

#include <iostream>
#include <vector>

namespace leo
{

class Texture;

enum FrameBufferType
{
  DEFAULT,
  DEPTH_MAP,
  CUBE_MAP // TODO: cleaner solution
};

typedef struct FramebufferOptions
{
  bool multiSampled = false;
  unsigned int nbSamples = 4;
  bool hdr = false;
  FrameBufferType type = FrameBufferType::DEFAULT;
  unsigned int width = 1620;
  unsigned int height = 1080;
} FramebufferOptions;

class Framebuffer
{
public:
  Framebuffer(FramebufferOptions options = {});
  Framebuffer(const Framebuffer &other);
  virtual ~Framebuffer();

public:
  Framebuffer &operator=(const Framebuffer &other);

public:
  GLuint getId() const { return this->_id; }
  const std::vector<TextureWrapper> &getColorBuffers() const { return this->_colorBuffers; }
  void loadFrameBuffer(GLuint bindingType = GL_FRAMEBUFFER) const;
  void generate();
  const FramebufferOptions &getOptions() const;
  bool isInitialized() const;

private:
  bool _checkInitialized() const;

private:
  bool _initialized = false;
  GLuint _id = 0;
  std::vector<TextureWrapper> _colorBuffers;
  std::vector<std::shared_ptr<Texture>> _cubeMapTextures;
  GLenum _drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
  Texture *_renderedTexture = nullptr;
  const FramebufferOptions _options;

  private:
  static GLenum _colorAttachmentNames[4];

}; // class Framebuffer

} // namespace leo
