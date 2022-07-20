add_subdirectory(glfw)
add_subdirectory(glad)

set(IMGUI_SOURCES
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp

        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_opengl3.cpp)

add_library(imgui ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC imgui)
target_link_libraries(imgui glfw)