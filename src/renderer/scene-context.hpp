#pragma once

#include <vector>
#include <map>

#include <renderer/global.hpp>

namespace leo
{

class DirectionLight;
class PointLight;
class BufferCollection;
class TextureWrapper;
class Texture;
class TextureOptions;
class GLTextureOptions;
class DirectionLightWrapper;
class PointLightWrapper;
class SceneGraph;
class Shader;
class OpenGLContext;
class Material;
class PBRMaterial;
class Volume;
class IBLWrapper;
class IBL;

class SceneContext
{

    using t_id = unsigned int;

public:
    SceneContext(OpenGLContext &context);

public:
    void registerDirectionLight(const DirectionLight &dl, const SceneGraph &sceneGraph, Shader &shadowShader);
    void registerPointLight(const PointLight &dl, const SceneGraph &sceneGraph, Shader &shadowShader);
    void registerMaterial(const Material &m);
    void registerMaterial(const PBRMaterial &m);
    void registerIBL(const leo::IBL &ibl, const SceneGraph &sceneGraph, Shader &hdrShader);
    void registerVolume(const Volume &volume);
    void setInstancingVBO(const std::vector<glm::mat4> &transformations);  // TODO: Should use Instancing node when the time is right
    void registerInstancedVolume(const Volume &volume);

private:
    void registerTexture(const Texture &tex, GLTextureOptions glOptionss, TextureOptions textureOptions);

public:
    // SceneGraph data
    std::map<t_id, BufferCollection> bufferCollections;
    std::map<t_id, BufferCollection> bufferCollectionsInstanced;
    std::map<t_id, TextureWrapper> textures;
    std::map<t_id, DirectionLightWrapper> dLights;
    std::map<t_id, PointLightWrapper> pLights;
    std::map<t_id, IBLWrapper> ibls;
    GLuint instancingVBO = 0;

    OpenGLContext &_context;
};

} // namespace leo