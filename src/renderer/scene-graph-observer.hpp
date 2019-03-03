#pragma once

#include <controller/observer.hpp>
#include <renderer/renderer.hpp>

namespace leo
{

namespace model {
  class Component;
}

namespace renderer
{

class SceneGraphObserver : public controller::Observer
{
  public:
    SceneGraphObserver(Renderer &renderer);

  public:
    virtual void notified(controller::Subject *c, controller::Event event);
    void notified(model::Volume *volume, controller::Event event);
    void notified(model::Entity *entity, controller::Event event);

  private:
    void _loadComponent(model::Volume *volume);

  private:
    Renderer &_renderer;
};

} // namespace renderer
} // namespace leo