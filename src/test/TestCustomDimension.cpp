#include "ll/api/event/EventBus.h"
#include "ll/api/event/server/ServerStartedEvent.h"
#include "more_dimensions/api/dimension/CustomDimensionManager.h"
#include "more_dimensions/api/dimension/SimpleCustomDimension.h"

static bool reg = [] {
    using namespace ll::event;
    EventBus::getInstance().emplaceListener<ServerStartedEvent>([](ServerStartedEvent&) {
        more_dimensions::CustomDimensionManager::getInstance()
            .addDimension<more_dimensions::SimpleCustomDimension>("CreativeFlatWorld", 0, GeneratorType::Flat);
    });
    return true;
}();
