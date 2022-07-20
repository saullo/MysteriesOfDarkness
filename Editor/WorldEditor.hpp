#pragma once

#include <Editor/Panels/Base.hpp>
#include <Engine/Layer.hpp>
#include <memory>
#include <vector>

namespace Editor
{
    class WorldEditor : public Engine::Layer
    {
    public:
        void on_gui() override;

    private:
        std::vector<std::unique_ptr<Panels::Base>> m_panels;
    };
} // namespace Editor