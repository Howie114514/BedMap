#include "formats/v1.h"
#include "leveldb/db.h"
#include <unordered_map>

class LevelStorage {
public:
    void* palette;
    // Name,Waypoint
    std::unordered_map<std::string, bm::format::v1::Waypoint> waypoints;
    leveldb::DB*                                              db;
    std::filesystem::path                                     path;

    LevelStorage(std::filesystem::path);
};