#pragma once

#include "leveldb/db.h"
#include <filesystem>
#include <string>
#include <unordered_map>

/**
结构:

bedmap
    /worlds
        /{local/server}-{IP/Level folder name}-{level name} - 通过这些信息生成唯一的ID
            /metadata - 元数据
            /palette - 方块调色板
            /biomes.json - 群系数据
            /waypoints.json - 路标点
            /db - leveldb数据库
*/

class WorldStorage {
public:
    WorldStorage();

    std::filesystem::path path;
    std::string           world;

    leveldb::DB* db;

    std::vector<int>         blockPalette;
    std::vector<std::string> biomesData;
    // 对应blockPalette的索引
    std::unordered_map<int, short>         colors;
    std::unordered_map<std::string, short> biomes;

    std::string getBiomeName(short id);
    short       getBiomeId(std::string id);
    void        loadBiomes();

    void loadPalette();
    void savePalette();

    std::vector<int> readChunk();
    std::string      getChunkKey(std::string dimension, int x, int z);
};