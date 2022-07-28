#pragma once

#include <string>

namespace Editor::Panels
{
    class Base
    {
    public:
        enum class DockDirection
        {
            top,
            bottom,
            left,
            right,
            center
        };

        Base(const char *name) : m_name(name) {}

        auto name() { return m_name; }

        virtual DockDirection dock_direction() { return DockDirection::center; }

        virtual void on_gui() {}

    protected:
        std::string m_name{};
    };
} // namespace Editor::Panels