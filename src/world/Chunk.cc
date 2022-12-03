#include "world/Chunk.hh"

Chunk::Chunk(ChunkPosition pos)
    : pos(pos) {}

auto Chunk::getPos() -> ChunkPosition {
    return pos;
}

auto Chunk::getBlocks() -> std::array<BlockID, NBlocks> {
    return blocks;
}

auto Chunk::getBlock(LocalPosition pos) -> BlockID {
    int index = getIndex(pos);

    return blocks[(size_t)index];
}

auto Chunk::setBlock(LocalPosition pos, BlockID newBlock) -> void {
    int index = getIndex(pos);

    blocks[(size_t)index] = newBlock;
}

auto Chunk::getIndex(LocalPosition pos) -> int {
    return pos.x
         + pos.y * Size
         + pos.z * Size * Size;
}