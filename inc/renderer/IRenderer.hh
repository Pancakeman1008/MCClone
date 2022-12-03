#pragma once

#include "world/Position.hh"
#include "world/Chunk.hh"

class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual auto shouldExit() -> bool;
    virtual auto draw() -> void;

    virtual auto updateCameraPosition(Position newPos) -> void;
    virtual auto updateChunk(const Chunk& chunk) -> void;
};