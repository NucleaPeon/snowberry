cmake_minimum_required(VERSION 3.3)
project(snowd
	VERSION 0.1.0
	LANGUAGES C CXX
	DESCRIPTION "Qt5 Music Player Daemon for Playback and Collection Management"
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

list(APPEND SNOWD_SOURCES
)

list(APPEND SNOWD_HEADERS
)

list(APPEND SNOWD_UIS
)

list(APPEND SNOWD_RES
)

list(APPEND SNOWD_OTHER
)


if (APPLE)
	set(CMAKE_C_COMPILER /usr/bin/clang)
	set(CMAKE_CXX_COMPILER /usr/bin/clang++)
endif()

add_executable(${PROJECT_NAME}
		${SNOWD_OTHER}
		main.cpp
		${SNOWD_HEADERS}
		${SNOWD_SOURCES}
		${SNOWD_UIS}
		${SNOWD_RES}
	)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Network)
