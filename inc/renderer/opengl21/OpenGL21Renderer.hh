#pragma once

struct GLFWwindow;

#include "renderer/IRenderer.hh"

#include "Config.hh"
#include "world/Position.hh"

class OpenGL21Renderer : public IRenderer {
public:
    OpenGL21Renderer(Config::Window config);
    ~OpenGL21Renderer();

    OpenGL21Renderer(const OpenGL21Renderer& other) = delete;
    auto operator==(const OpenGL21Renderer& other) -> OpenGL21Renderer& = delete;
    OpenGL21Renderer(OpenGL21Renderer&& other);
    auto operator==(OpenGL21Renderer&& other) -> OpenGL21Renderer&;

    auto shouldExit() -> bool override;
    auto draw() -> void override;

    auto updateCameraPosition(Position newPos) -> void override;
    auto updateChunk(const Chunk& chunk) -> void override;

private:
    GLFWwindow* window;
};