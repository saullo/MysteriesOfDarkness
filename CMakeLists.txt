cmake_minimum_required(VERSION 3.29)
project(MysteriesOfDarkness)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

function(window_binary bin_name)
	add_executable(${bin_name} ${SOURCES})
	target_link_libraries(${bin_name} PRIVATE Engine)

	if(CMAKE_SYSTEM_NAME MATCHES "Windows")
		target_link_options(${bin_name} PRIVATE "/SUBSYSTEM:WINDOWS")
	endif()

	install(TARGETS ${bin_name})
	install(FILES $<TARGET_RUNTIME_DLLS:${bin_name}> TYPE BIN)
endfunction()

add_subdirectory(Engine)
add_subdirectory(Launcher)