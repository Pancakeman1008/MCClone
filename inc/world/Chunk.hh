#pragma once

#include <array>

#include "world/Position.hh"
#include "world/Block.hh"

class Chunk {
public:
    static constexpr int Size = 16;
    static constexpr int NBlocks = Size * Size * Size;

    Chunk(ChunkPosition pos);

    auto getPos() -> ChunkPosition;

    auto getBlocks() -> std::array<BlockID, NBlocks>;
    auto getBlock(LocalPosition pos) -> BlockID;
    auto setBlock(LocalPosition pos, BlockID newBlock) -> void;

private:
    const ChunkPosition pos;
    std::array<BlockID, NBlocks> blocks = std::array<BlockID, NBlocks>();

    auto getIndex(LocalPosition pos) -> int;
};