#include "renderer/opengl21/OpenGL21Renderer.hh"

OpenGL21Renderer::OpenGL21Renderer(Config::Window windowConfig)
    : window(GLFWWindow::GLVersion::GL21, windowConfig) {}

auto OpenGL21Renderer::shouldExit() -> bool {
    return window.shouldExit();
}

auto OpenGL21Renderer::draw() -> void {
    // TODO
    window.pollEvents();
}

auto OpenGL21Renderer::updateCameraPosition(Position newPos) -> void {
    // TODO
    (void)newPos;
}

auto OpenGL21Renderer::updateChunk(const Chunk& chunk) -> void {
    // TODO
    (void)chunk;
}