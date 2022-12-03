#include "renderer/GLFWInitialiser.hh"

#include <stdexcept>

#include <GLFW/glfw3.h>

auto GLFWInitialiser::init() -> void {
    if (glfwInit() != GLFW_TRUE) {
        throw std::runtime_error("Failed to initialise GLFW.");
    }
}

auto GLFWInitialiser::deinit() -> void {
    glfwMakeContextCurrent(nullptr);
    glfwTerminate();
}