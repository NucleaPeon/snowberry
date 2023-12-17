cmake_minimum_required(VERSION 3.3)
project(snowctl
	VERSION 0.1.0
	LANGUAGES C CXX
	DESCRIPTION "Qt5 Command Line Music Player Controller Snowberry Component"
)

include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!
#add_compile_options(-v)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED
    Core
    Network
)

list(APPEND SNOWCTL_SOURCES
)

list(APPEND SNOWCTL_HEADERS
)

list(APPEND SNOWCTL_UIS
)

list(APPEND SNOWCTL_RES
)

list(APPEND SNOWCTL_OTHER
)


if (APPLE)
	set(CMAKE_C_COMPILER /usr/bin/clang)
	set(CMAKE_CXX_COMPILER /usr/bin/clang++)
endif()

add_executable(${PROJECT_NAME}
		${SNOWCTL_OTHER}
		main.cpp
		${SNOWCTL_HEADERS}
		${SNOWCTL_SOURCES}
		${SNOWCTL_UIS}
		${SNOWCTL_RES}
	)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Network)
