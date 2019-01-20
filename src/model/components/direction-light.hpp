#pragma once

#include <model/components/light.hpp>

namespace leo {
namespace model {
  
  class DirectionLight;

  typedef struct DirectionLightUniform : public LightUniform {
    DirectionLightUniform();
    DirectionLightUniform(const DirectionLight &light);
    ~DirectionLightUniform();
    DirectionLightUniform(const DirectionLightUniform &other);
    DirectionLightUniform &operator=(const DirectionLightUniform &other);
    glm::vec4 direction;
  } DirectionLightUniform;

  class DirectionLight : public Light {
    public:
      DirectionLight();
      DirectionLight(glm::vec3 ambient, glm::vec3 diffuse,
          glm::vec3 specular);
      DirectionLight(float constant, float linear, float quadratic,
          glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
      virtual ~DirectionLight() {}
      DirectionLight(const DirectionLight &other);
      DirectionLight &operator=(const DirectionLight &other);

    public:
      glm::vec4 getTransformedDirection(const glm::mat4x4 &transformation);

    private:
      glm::vec4 _direction;

    public:
      const glm::vec4 &getDirection() { return this->_direction; }
      void getDirection(const glm::vec4 &value) { this->_direction = value; }

    friend DirectionLightUniform::DirectionLightUniform(const DirectionLight &light);
  };

}  // namespace model
}  // namespace leo