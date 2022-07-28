set(SOURCES
        Main.cpp)

add_executable(ClientServer ${SOURCES})
target_link_libraries(ClientServer Engine)