set(SOURCES
        Main.cpp)

add_executable(Client ${SOURCES})
target_link_libraries(Client Engine)