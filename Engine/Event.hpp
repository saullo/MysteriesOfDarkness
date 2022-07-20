#pragma once

#include <utility>

#define EVENT_TYPE(type)                                                                                               \
    static Type get_static_type()                                                                                      \
    {                                                                                                                  \
        return Type::type;                                                                                             \
    }                                                                                                                  \
                                                                                                                       \
    virtual Type get_type() const override                                                                             \
    {                                                                                                                  \
        return get_static_type();                                                                                      \
    }

#define EVENT_HANDLER(handler)                                                                                         \
    [this](auto &&...args) -> decltype(auto) { return this->handler(std::forward<decltype(args)>(args)...); }

namespace Engine
{
    class Event
    {
    public:
        enum class Type
        {
            invalid,
            framebuffer_size
        };

        [[nodiscard]] virtual Type get_type() const = 0;
    };

    class EventCaller
    {
    public:
        EventCaller(Event &event) : m_event(event) {}

        template <typename Type, typename Handler> void call(const Handler &handler)
        {
            if (m_event.get_type() == Type::get_static_type())
                handler(static_cast<Type &>(m_event));
        }

    private:
        Event &m_event;
    };

    class FramebufferSizeEvent : public Event
    {
    public:
        FramebufferSizeEvent(int width, int height) : m_width(width), m_height(height) {}

        EVENT_TYPE(framebuffer_size)

        [[nodiscard]] int width() const { return m_width; }
        [[nodiscard]] int height() const { return m_height; }

    private:
        int m_width{-1};
        int m_height{-1};
    };
} // namespace Engine