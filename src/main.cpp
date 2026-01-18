#include "main.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/event/client/ClientExitLevelEvent.h"
#include "ll/api/event/client/ClientJoinLevelEvent.h"
#include "ll/api/event/render/UIRenderEvent.h"
#include "ll/api/memory/Hook.h"
#include "ll/api/mod/RegisterHelper.h"
#include "ll/api/service/Bedrock.h"
#include "ll/api/service/TargetedBedrock.h"
#include "mc/client/game/ClientInstance.h"
#include "mc/client/game/MinecraftGame.h"
#include "mc/client/gui/CaretMeasureData.h"
#include "mc/client/gui/FontAlias.h"
#include "mc/client/gui/GuiData.h"
#include "mc/client/gui/TextAlignment.h"
#include "mc/client/gui/TextMeasureData.h"
#include "mc/client/gui/controls/UIRenderContext.h"
#include "mc/client/renderer/screen/MinecraftUIRenderContext.h"
#include "mc/deps/core/math/Color.h"
#include "mc/deps/input/RectangleArea.h"


bool inGame           = false;
bool inSettingsScreen = false;


namespace bed_map {
BedMap& BedMap::getInstance() {
    static BedMap instance;
    return instance;
}

bool BedMap::enable() { return true; }
bool BedMap::disable() { return true; }
bool BedMap::load() {
    using namespace ll::event;
    mSelf.getLogger().info("Loading BedMap");
    EventBus& bus = EventBus::getInstance();
    mSelf.getLogger().info("Loaded");
    return true;
}
} // namespace bed_map

LL_REGISTER_MOD(bed_map::BedMap, bed_map::BedMap::getInstance())