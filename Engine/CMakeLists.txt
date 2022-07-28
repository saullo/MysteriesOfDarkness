set(SOURCES
        Application.cpp
        Window.cpp

        Graphics/Context.cpp

        Gui/Context.cpp

        Utils/Ini.cpp)

add_library(Engine ${SOURCES})
target_link_libraries(Engine imgui)