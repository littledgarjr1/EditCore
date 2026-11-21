#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
using namespace geode::prelude;

class $modify(ECEditorUI, EditorUI) {
    struct Fields {
        CCLabelBMFont* counter = nullptr;
    };

    bool init(LevelEditorLayer* layer) {
        if (!EditorUI::init(layer)) return false;

        auto winSize = CCDirector::get()->getWinSize();

        auto label = CCLabelBMFont::create("Objects: 0", "bigFont.fnt");
        label->setScale(0.4f);
        label->setOpacity(150);
        label->setAnchorPoint({0.f, 1.f});
        label->setPosition({10.f, winSize.height - 10.f});
        this->addChild(label, 100);

        m_fields->counter = label;
        this->schedule(schedule_selector(ECEditorUI::updateCounter), 0.5f);
        return true;
    }

    void updateCounter(float) {
        if (!m_fields->counter || !m_editorLayer) return;
        auto count = m_editorLayer->m_objects->count();
        m_fields->counter->setString(fmt::format("Objects: {}", count).c_str());
    }
};