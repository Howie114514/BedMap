#include "main.h"

namespace bed_map {
BedMap& BedMap::getInstance() {
    static BedMap instance;
    return instance;
}

bool BedMap::enable() { return true; }
bool BedMap::disable() { return true; }
bool BedMap::load() { return true; }
} // namespace bed_map