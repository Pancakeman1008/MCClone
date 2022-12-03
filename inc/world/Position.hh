#pragma once

struct Position;
struct BlockPosition;
struct ChunkPosition;
struct LocalPosition;

struct Position {
    double x, y, z = 0.0;

    static auto fromBlockPosition(BlockPosition pos) -> Position;
    static auto fromChunkPosition(ChunkPosition pos) -> Position;
    static auto fromLocalPosition(ChunkPosition chunkPos, LocalPosition localPos) -> Position;
};

struct BlockPosition {
    int x, y, z = 0;

    static auto fromPosition(Position pos) -> BlockPosition;
    static auto fromChunkPosition(ChunkPosition pos) -> BlockPosition;
    static auto fromLocalPosition(ChunkPosition chunkPos, LocalPosition localPos) -> BlockPosition;
};

struct ChunkPosition {
    int x, y, z = 0;

    static auto fromPosition(Position pos) -> ChunkPosition;
    static auto fromBlockPosition(BlockPosition pos) -> ChunkPosition;
};

struct LocalPosition {
    int x, y, z = 0;

    static auto fromPosition(ChunkPosition chunkPos, Position pos) -> LocalPosition;
    static auto fromBlockPosition(ChunkPosition chunkPos, BlockPosition pos) -> LocalPosition;
};