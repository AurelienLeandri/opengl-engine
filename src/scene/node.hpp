#pragma once

#include <vector>

class Node {
  public:
    Node();
    virtual ~Node();

  public:
    virtual void update(double delta) = 0;
    void addChild(Node *child);

  private:
    void _destroy();

  public:
    const std::vector<Node*> &getChildren();

  protected:
    std::vector<Node*> _children;
    
};
