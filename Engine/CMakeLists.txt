set(SOURCES
        Application.cpp
        Window.cpp)

add_library(Engine ${SOURCES})
target_link_libraries(Engine glfw)