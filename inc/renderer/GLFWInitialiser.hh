#pragma once

#include "LibraryInitialiser.hh"

class GLFWInitialiser : public LibraryInitialiser<GLFWInitialiser> {
public:
    static auto init() -> void;
    static auto deinit() -> void;
};