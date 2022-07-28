set(SOURCES
        Main.cpp)

add_executable(Launcher ${SOURCES})
target_link_libraries(Launcher Engine)