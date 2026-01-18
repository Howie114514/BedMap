#pragma once

#include "boost/multi_index_container.hpp"
#include "mc/deps/core/math/Color.h"
#include <string>

namespace bm::format::v1 {
// Metadata
static int chunkCacheFormatVersion = 0x0001;

// Chunk
struct Color {
    short id;
    int   color;
};
struct Biome {
    short       id;
    std::string name;
};
struct Block {
    short colorId;
    short biomeId;
};
struct CachedChunk {
    int x;
    int z;
    // Colors, X,Y,Z
    short payload[16][16][384];
};
// Waypoint
struct JSONColor {
    float r;
    float g;
    float b;
    float a;
    explicit JSONColor(mce::Color);
};

struct Waypoint {
    std::string name;
    std::string dimension;
    JSONColor   color;
    int         x;
    int         y;
    int         z;
};
} // namespace bm::format::v1