#pragma once

#include "world/Position.hh"
#include "world/Chunk.hh"

class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual auto shouldExit() -> bool = 0;
    virtual auto draw() -> void = 0;

    virtual auto updateCameraPosition(Position newPos) -> void = 0;
    virtual auto updateChunk(const Chunk& chunk) -> void = 0;
};