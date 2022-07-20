set(SOURCES
        Application.cpp
        Window.cpp

        Graphics/Context.cpp)

add_library(Engine ${SOURCES})
target_link_libraries(Engine glfw glad)