#pragma once

struct GLFWwindow;

#include "renderer/GLFWInitialiser.hh"
#include "Config.hh"

class GLFWWindow {
public:
    enum class GLVersion {
        GL10, GL11, GL12, GL13, GL14, GL15,
        GL20, GL21,
        GL30, GL31, GL32, GL33,
        GL40, GL41, GL42, GL43, GL44, GL45, GL46
    };

    GLFWWindow(Config::Window config);
    GLFWWindow(GLVersion glVerion, Config::Window config);

    GLFWWindow(const GLFWWindow& other) = delete;
    auto operator==(const GLFWWindow& other) -> GLFWWindow& = delete;
    GLFWWindow(GLFWWindow&& other) noexcept;
    auto operator==(GLFWWindow&& other) noexcept -> GLFWWindow&;

    auto use() -> void;

    auto shouldExit() -> bool;
    auto pollEvents() -> void;

private:
    GLFWInitialiser initialiser = GLFWInitialiser();
    GLFWwindow *window;

    static auto getMajorVersion(GLVersion glVersion) -> int;
    static auto getMinorVersion(GLVersion glVersion) -> int;
    static auto shouldUseCoreProfile(GLVersion glVersion) -> bool;
};