#include "renderer/opengl21/OpenGL21Renderer.hh"

#include <stdexcept>
#include <utility>

#include <GLFW/glfw3.h>

OpenGL21Renderer::OpenGL21Renderer(Config::Window config) {
    if (glfwInit() != GLFW_TRUE) {
        throw std::runtime_error("Failed to initialise GLFW.");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    window = glfwCreateWindow(config.width, config.height, config.title.c_str(), nullptr, nullptr);
    if (window == nullptr) {
        throw std::runtime_error("Failed to create GLFW window.");
    }

    glfwMakeContextCurrent(window);
}

OpenGL21Renderer::~OpenGL21Renderer() {
    glfwMakeContextCurrent(nullptr);
    glfwTerminate();
}

OpenGL21Renderer::OpenGL21Renderer(OpenGL21Renderer&& other) {
    window = std::exchange(other.window, nullptr);
}

auto OpenGL21Renderer::operator==(OpenGL21Renderer&& other) -> OpenGL21Renderer& {
    window = std::exchange(other.window, nullptr);
    return *this;
}

auto OpenGL21Renderer::shouldExit() -> bool {
    return glfwWindowShouldClose(window);
}

auto OpenGL21Renderer::draw() -> void {
    // TODO
}

auto OpenGL21Renderer::updateCameraPosition(Position newPos) -> void {
    (void)newPos;
    // TODO
}

auto OpenGL21Renderer::updateChunk(const Chunk &chunk) -> void {
    (void)chunk;
    // TODO
}