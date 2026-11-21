#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(NCMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto bottomMenu = this->getChildByID("bottom-menu");
        if (!bottomMenu) return true;

        auto button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
            this,
            menu_selector(NCMenuLayer::onButtonClick)
        );
        button->setID("nullcore-button"_spr);

        bottomMenu->addChild(button);
        bottomMenu->updateLayout();

        return true;
    }

    void onButtonClick(CCObject*) {
        FLAlertLayer::create(
            "NullCore",
            "This is just a test currently, so nothing special here.",
            "A'ighty!"
        )->show();
    }
};