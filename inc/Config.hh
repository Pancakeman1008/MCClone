#pragma once

#include <string>

struct Config {
    struct Window {
        int width = 1024;
        int height = 768;
        std::string title = "";
    };

    enum class Renderer {
        Vulkan,
        OpenGL21,
    };

    auto getDefaultRenderer() const -> Renderer;

    Window window = Window();
    Renderer renderer = getDefaultRenderer();
};