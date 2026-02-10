#pragma once

// main options
#include <string>
#include <vector>

enum class MapTypes {
    Default,
    Terrain,
    Cave,
};

struct Options {
    bool showPlayers                    = true;
    bool showWaypoints                  = true;
    bool showWaypointsInWorld           = true;
    bool showOverworldWaypointsInNether = true;
    bool showNetherWaypointsInOverworld = true;
    bool showStructures                 = true;
    bool showChunks                     = true;

    bool changeCenterPosWhenOpen   = true;
    bool changeCaveMapTopYWhenOpen = true;

    int openHotKey         = 77; // M
    int moveToPlayerHotKey = 13; // Enter

    bool                     enableCache = true;
    double                   scale       = 1.00;
    int                      caveMapTopY = 0;
    MapTypes                 mapType     = MapTypes::Default;
    std::vector<std::string> excluded;
};

namespace bed_map {
static Options options;
}