#pragma once

enum class BlockID {
    Air,
    Stone,
    Dirt,
    Grass,
    ENDENUM
};

constexpr int NBlockIDs = (int)BlockID::ENDENUM;

extern const char *BlockNames[NBlockIDs];