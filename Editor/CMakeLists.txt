set(SOURCES
        Main.cpp
        WorldEditor.cpp)

add_executable(Editor ${SOURCES})
target_link_libraries(Editor Engine)
add_custom_command(TARGET Editor POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets/Editor $<TARGET_FILE_DIR:Editor>/Assets)