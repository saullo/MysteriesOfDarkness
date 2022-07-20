#pragma once

#include <Engine/Event.hpp>

namespace Engine
{
    class Layer
    {
    public:
        virtual void on_gui() {}
        virtual void on_event(Event &event) {}
    };
} // namespace Engine