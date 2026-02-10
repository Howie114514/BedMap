#include "main.h"
#include "./debug.h"
#include "ll/api/event/EventBus.h"
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
#include "mc/client/gui/screens/ScreenContext.h"
#include "mc/client/renderer/screen/MinecraftUIRenderContext.h"
#include "mc/deps/core/math/Color.h"
#include "mc/deps/input/RectangleArea.h"
#include <cstdint>


bool  inGame           = false;
bool  inSettingsScreen = false;
Font* font             = nullptr;


namespace bed_map {
BedMap& BedMap::getInstance() {
    static BedMap instance;
    return instance;
}

bool BedMap::enable() { return true; }
bool BedMap::disable() { return true; }
bool BedMap::load() {
    mSelf.getLogger().info("Loading BedMap");
    using namespace ll::event;
    EventBus& bus = EventBus::getInstance();
    bus.emplaceListener<BeforeUIRenderEvent>([](BeforeUIRenderEvent& event) {
        auto& ctx = event.uiRenderContext();
        if (font == nullptr) return;
        ctx.drawText(
            *font,
            {0, 0, 100, 100, false},
            "Hello world!",
            {1.F, 1.F, 1.F, 1.F},
            1.F,
            ui::TextAlignment::Left,
            {1, 0, false, false, false},
            {-1, false}
        );
    });
    mSelf.getLogger().info("Loaded");
    return true;
}
} // namespace bed_map

LL_AUTO_TYPE_INSTANCE_HOOK(
    FontHook,
    HookPriority::High,
    MinecraftUIRenderContext,
    &MinecraftUIRenderContext::$drawText,
    void,
    ::Font&                   _font,
    ::RectangleArea const&    rect,
    ::std::string&&           text,
    ::mce::Color const&       color,
    float                     alpha,
    ::ui::TextAlignment       alignment,
    ::TextMeasureData const&  textData,
    ::CaretMeasureData const& caretData
) {
    if (_font.mAlwaysUnicode && font == nullptr) {
        font = &_font;
        bed_map::BedMap::getInstance().getSelf().getLogger().info("Got unicode font.");
    }
    origin(_font, rect, text.c_str(), color, alpha, alignment, textData, caretData);
}

LL_REGISTER_MOD(bed_map::BedMap, bed_map::BedMap::getInstance())