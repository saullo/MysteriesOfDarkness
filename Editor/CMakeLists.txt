set(SOURCES
        Main.cpp)

add_executable(Editor ${SOURCES})
target_link_libraries(Editor Engine)