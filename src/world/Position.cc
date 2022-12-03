#include "world/Position.hh"

#include <cmath>

#include "world/Chunk.hh"

auto Position::fromBlockPosition(BlockPosition pos) -> Position {
    return Position {
        .x = (double)pos.x,
        .y = (double)pos.y,
        .z = (double)pos.z,
    };
}

auto Position::fromChunkPosition(ChunkPosition pos) -> Position {
    return Position {
        .x = (double)(pos.x * Chunk::Size),
        .y = (double)(pos.y * Chunk::Size),
        .z = (double)(pos.z * Chunk::Size),
    };
}

auto Position::fromLocalPosition(ChunkPosition chunkPos, LocalPosition localPos) -> Position {
    return Position {
        .x = (double)(chunkPos.x * Chunk::Size + localPos.x),
        .y = (double)(chunkPos.y * Chunk::Size + localPos.y),
        .z = (double)(chunkPos.z * Chunk::Size + localPos.z),
    };
}

auto BlockPosition::fromPosition(Position pos) -> BlockPosition {
    return BlockPosition {
        .x = (int)floor(pos.x),
        .y = (int)floor(pos.y),
        .z = (int)floor(pos.z),
    };
}

auto BlockPosition::fromChunkPosition(ChunkPosition pos) -> BlockPosition {
    return BlockPosition {
        .x = pos.x * Chunk::Size,
        .y = pos.y * Chunk::Size,
        .z = pos.z * Chunk::Size,
    };
}

auto BlockPosition::fromLocalPosition(ChunkPosition chunkPos, LocalPosition localPos) -> BlockPosition {
    return BlockPosition {
        .x = chunkPos.x * Chunk::Size + localPos.x,
        .y = chunkPos.y * Chunk::Size + localPos.y,
        .z = chunkPos.z * Chunk::Size + localPos.z,
    };
}

auto ChunkPosition::fromPosition(Position pos) -> ChunkPosition {
    return ChunkPosition {
        .x = (int)pos.x / Chunk::Size,
        .y = (int)pos.y / Chunk::Size,
        .z = (int)pos.z / Chunk::Size,
    };
}

auto ChunkPosition::fromBlockPosition(BlockPosition pos) -> ChunkPosition {
    return ChunkPosition {
        .x = pos.x / Chunk::Size,
        .y = pos.y / Chunk::Size,
        .z = pos.z / Chunk::Size,
    };
}

auto LocalPosition::fromPosition(ChunkPosition chunkPos, Position pos) -> LocalPosition {
    return LocalPosition {
        .x = (int)pos.x - chunkPos.x * Chunk::Size,
        .y = (int)pos.y - chunkPos.y * Chunk::Size,
        .z = (int)pos.z - chunkPos.z * Chunk::Size,
    };
}

auto LocalPosition::fromBlockPosition(ChunkPosition chunkPos, BlockPosition pos) -> LocalPosition {
    return LocalPosition {
        .x = pos.x - chunkPos.x * Chunk::Size,
        .y = pos.y - chunkPos.y * Chunk::Size,
        .z = pos.z - chunkPos.z * Chunk::Size,
    };
}
