#pragma once

#include <memory>

namespace Engine::Core
{
    class Window
    {
      public:
        static Window &instance();

        virtual void init() = 0;
        virtual void update() = 0;
        virtual void show() = 0;

      private:
        static std::unique_ptr<Window> s_instance;
    };
} // namespace Engine::Core