#include <renderer/render-graph-node.hpp>

#include <renderer/opengl-context.hpp>
#include <renderer/framebuffer.hpp>

namespace leo
{

t_id RenderGraphNode::_nbNodes = 0;

RenderGraphNode::RenderGraphNode(OpenGLContext &context) : _context(context), _id(RenderGraphNode::_nbNodes++)
{
}

const std::map<std::string, const TextureWrapper &> &RenderGraphNode::getInputs() const
{
    return this->_inputs;
}

void RenderGraphNode::addInput(RenderGraphNode &in, std::string uniformName, int bufferId)
{
    // TODO: Stencil and Depth buffer case
    this->_inputs.insert(std::pair<std::string, const TextureWrapper &>(uniformName, in.getFramebuffer()->getColorBuffers()[bufferId]));
    in.addOutNode(*this);
}

Framebuffer *RenderGraphNode::getFramebuffer()
{
    return this->_output;
}

void RenderGraphNode::setFramebuffer(Framebuffer *fb)
{
    this->_output = fb;
}

void RenderGraphNode::addInNode(RenderGraphNode &in)
{
    in._addOutNode(*this);
    this->_addInNode(in);
}

void RenderGraphNode::_addInNode(RenderGraphNode &in)
{
    this->_inNodes.insert(in.getId());
}

std::set<t_id> &RenderGraphNode::getInNodes()
{
    return this->_inNodes;
}

void RenderGraphNode::addOutNode(RenderGraphNode &out)
{
    out._addInNode(*this);
    this->_addOutNode(out);
}

void RenderGraphNode::_addOutNode(RenderGraphNode &out)
{
    this->_outNodes.insert(out.getId());
}

std::set<t_id> &RenderGraphNode::getOutNodes()
{
    return this->_outNodes;
}

t_id RenderGraphNode::getId() const
{
    return this->_id;
}

void RenderGraphNode::setStringId(std::string id)
{
    this->_stringId = id;
}

std::string RenderGraphNode::getStringId()
{
    return this->_stringId;
}

} // namespace leo