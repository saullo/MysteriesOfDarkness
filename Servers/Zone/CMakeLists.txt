set(SOURCES
        Main.cpp)

add_executable(ZoneServer ${SOURCES})
target_link_libraries(ZoneServer Engine)