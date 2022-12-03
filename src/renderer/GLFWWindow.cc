#include "renderer/GLFWWindow.hh"

#include <bits/iterator_concepts.h>
#include <utility>
#include <stdexcept>

#include <GLFW/glfw3.h>

    #include <iostream>

GLFWWindow::GLFWWindow(GLVersion glVersion, Config::Window config) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, getMajorVersion(glVersion));
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, getMinorVersion(glVersion));
    if (shouldUseCoreProfile(glVersion))
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(config.width, config.height, config.title.c_str(), nullptr, nullptr);
    if (window == nullptr) {
        const char* description; glfwGetError(&description);
        std::cout << description << std::endl;
        throw std::runtime_error("Failed to create GLFW window.");
    }
}

GLFWWindow::GLFWWindow(GLFWWindow&& other) noexcept {
    window = std::exchange(other.window, nullptr);
}

auto GLFWWindow::operator==(GLFWWindow&& other) noexcept -> GLFWWindow& {
    window = std::exchange(other.window, nullptr);
    return *this;
}

auto GLFWWindow::use() -> void {
    glfwMakeContextCurrent(window);
}

auto GLFWWindow::shouldExit() -> bool {
    return glfwWindowShouldClose(window);
}

auto GLFWWindow::pollEvents() -> void {
    glfwPollEvents();
}

auto GLFWWindow::getMajorVersion(GLVersion glVersion) -> int {
    switch (glVersion) {
        case GLVersion::GL10:
        case GLVersion::GL11:
        case GLVersion::GL12:
        case GLVersion::GL13:
        case GLVersion::GL14:
        case GLVersion::GL15:
            return 1;

        case GLVersion::GL20:
        case GLVersion::GL21:
            return 2;
        
        case GLVersion::GL30:
        case GLVersion::GL31:
        case GLVersion::GL32:
        case GLVersion::GL33:
            return 3;
        
        case GLVersion::GL40:
        case GLVersion::GL41:
        case GLVersion::GL42:
        case GLVersion::GL43:
        case GLVersion::GL44:
        case GLVersion::GL45:
        case GLVersion::GL46:
            return 4;
        
        default:
            throw std::runtime_error("GLFWWindow::getMajorVersion() invalid version");
    }
}

auto GLFWWindow::getMinorVersion(GLVersion glVersion) -> int {
    switch (glVersion) {
        case GLVersion::GL10:
        case GLVersion::GL20:
        case GLVersion::GL30:
        case GLVersion::GL40:
            return 0;
        
        case GLVersion::GL11:
        case GLVersion::GL21:
        case GLVersion::GL31:
        case GLVersion::GL41:
            return 1;
        
        case GLVersion::GL12:
        case GLVersion::GL32:
        case GLVersion::GL42:
            return 2;
        
        case GLVersion::GL13:
        case GLVersion::GL33:
        case GLVersion::GL43:
            return 3;
        
        case GLVersion::GL14:
        case GLVersion::GL44:
            return 4;
        
        case GLVersion::GL15:
        case GLVersion::GL45:
            return 5;
        
        case GLVersion::GL46:
            return 6;
        
        default:
            throw std::runtime_error("GLFWWindow::getMinorVersion() invalid version");
    }
}

auto GLFWWindow::shouldUseCoreProfile(GLVersion glVersion) -> bool {
    switch (glVersion) {
        case GLVersion::GL10:
        case GLVersion::GL11:
        case GLVersion::GL12:
        case GLVersion::GL13:
        case GLVersion::GL14:
        case GLVersion::GL15:
        case GLVersion::GL20:
        case GLVersion::GL21:
        case GLVersion::GL30:
        case GLVersion::GL31:
            return false;
        case GLVersion::GL32:
        case GLVersion::GL33:
        case GLVersion::GL40:
        case GLVersion::GL41:
        case GLVersion::GL42:
        case GLVersion::GL43:
        case GLVersion::GL44:
        case GLVersion::GL45:
        case GLVersion::GL46:
            return true;
    }

    return false; // not reachable under normal circumstances
}