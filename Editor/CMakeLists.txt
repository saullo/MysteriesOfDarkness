set(SOURCES
        Main.cpp
        WorldEditor.cpp)

add_executable(Editor ${SOURCES})
target_link_libraries(Editor Engine)