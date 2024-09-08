set(SOURCES
	Core/Application.cpp
	Core/Window.cpp)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	list(APPEND SOURCES
		Core/Windows/Window.cpp)
endif()

add_library(Engine SHARED ${SOURCES})
install(TARGETS Engine)