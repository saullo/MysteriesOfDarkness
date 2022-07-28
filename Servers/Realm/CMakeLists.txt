set(SOURCES
        Main.cpp)

add_executable(RealmServer ${SOURCES})
target_link_libraries(RealmServer Engine)