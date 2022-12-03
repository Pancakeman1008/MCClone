#pragma once

#include "renderer/IRenderer.hh"

#include "Config.hh"
#include "renderer/GLFWWindow.hh"

class OpenGL21Renderer : public IRenderer {
public:
    OpenGL21Renderer(Config::Window windowConfig);

    auto shouldExit() -> bool override;
    auto draw() -> void override;
    
    auto updateCameraPosition(Position newPos) -> void override;
    auto updateChunk(const Chunk& chunk) -> void override;

private:
    GLFWWindow window;
};