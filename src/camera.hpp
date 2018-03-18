#pragma once

// Std. Includes
#include <vector>

// GL Includes
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

// Default camera values
const GLfloat YAW        = -90.0f;
const GLfloat PITCH      =  0.0f;
const GLfloat SPEED      =  3.0f;
const GLfloat SENSITIVTY =  0.25f;
const GLfloat ZOOM       =  45.0f;


/* An camera class that processes input and calculates the corresponding Eular Angles,
 * Vectors and Matrices for use in OpenGL
 */
class Camera
{
  public:

    // Constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW,
        GLfloat pitch = PITCH);
    // Constructor with scalar values
    Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY,
        GLfloat upZ, GLfloat yaw, GLfloat pitch);
    // Returns the view matrix calculated using Eular Angles and the LookAt Matrix
    glm::mat4 getViewMatrix() const;
    // Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void processKeyboard(Camera_Movement direction, GLfloat deltaTime);
    // Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void processMouse(GLfloat xoffset, GLfloat yoffset,
        GLboolean constrainPitch = true);
    // Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void processMouseScroll(GLfloat yoffset);

  private:
    // Calculates the front vector from the Camera's (updated) Eular Angles
    void updateCameraVectors();
    // Camera Attributes
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    // Eular Angles
    GLfloat yaw;
    GLfloat pitch;
    // Camera options
    GLfloat movementSpeed;
    GLfloat mouseSensitivity;
  public:
    GLfloat getZoom() const {
      return zoom;
    }

    void setZoom(GLfloat zoom) {
      Camera::zoom = zoom;
    }

  private:
    GLfloat zoom;

  public:
    const glm::vec3 &getPosition() const {
      return position;
    }

    void setPosition(const glm::vec3 &position) {
      Camera::position = position;
    }

    const glm::vec3 &getFront() const {
      return front;
    }

    void setFront(const glm::vec3 &front) {
      Camera::front = front;
    }

    const glm::vec3 &getUp() const {
      return up;
    }

    void setUp(const glm::vec3 &up) {
      Camera::up = up;
    }

    const glm::vec3 &getRight() const {
      return right;
    }

    void setRight(const glm::vec3 &right) {
      Camera::right = right;
    }

    const glm::vec3 &getWorldUp() const {
      return worldUp;
    }

    void setWorldUp(const glm::vec3 &worldUp) {
      Camera::worldUp = worldUp;
    }

    GLfloat getYaw() const {
      return yaw;
    }

    void setYaw(GLfloat yaw) {
      Camera::yaw = yaw;
    }

    GLfloat getPitch() const {
      return pitch;
    }

    void setPitch(GLfloat pitch) {
      Camera::pitch = pitch;
    }

    GLfloat getMovementSpeed() const {
      return movementSpeed;
    }

    void setMovementSpeed(GLfloat movementSpeed) {
      Camera::movementSpeed = movementSpeed;
    }

    GLfloat getMouseSensitivity() const {
      return mouseSensitivity;
    }

    void setMouseSensitivity(GLfloat mouseSensitivity) {
      Camera::mouseSensitivity = mouseSensitivity;
    }

};
