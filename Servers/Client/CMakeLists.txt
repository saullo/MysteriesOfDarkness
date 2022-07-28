set(SOURCES
        Main.cpp)

add_executable(AuthenticationServer ${SOURCES})
target_link_libraries(AuthenticationServer Engine)