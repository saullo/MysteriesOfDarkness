#pragma once

#include <glad/glad.h>

namespace Engine::Graphics
{
    class Context
    {
    public:
        static constexpr auto glsl_version = "#version 460";
        static constexpr auto major_version = 4;
        static constexpr auto minor_version = 6;

        void on_init();
        void on_render();
    };
} // namespace Engine::Graphics