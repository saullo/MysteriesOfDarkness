#pragma once

#include <glad/glad.h>

namespace Engine::Graphics
{
    class Context
    {
    public:
        void on_init();
        void on_render();
    };
} // namespace Engine::Graphics