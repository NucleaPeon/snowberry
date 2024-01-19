cmake_minimum_required(VERSION 3.3)
project(snowberry
        VERSION 0.9.0.0
	LANGUAGES C CXX
	DESCRIPTION "Qt5 Collection-based Music Player for Linux, OS X and Windows"
)

# Build Plan
#  - Snowberry is made up of snowgui, snowd and snowctl components (gui, daemon  and cli)
#  - Installation should be done via a pkg for OSX, but a DMG file should be
#    for snowgui, snowd and snowctl assuming all dependencies are met and simply have
#    defensive checks for things it relies on (and create a static build to
#    incorporate Qt5 deps)

set(SNOWLIBS "${PROJECT_SOURCE_DIR}/libs")

include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(snowd)
add_subdirectory(snowctl)
add_subdirectory(snowgui)

# Generate dmg bundle

# if(APPLE)
#	install(TARGETS ${PROJECT_NAME} BUNDLE DESTINATION ${CMAKE_SOURCE_DIR})
#else()
#	install(TARGETS ${PROJECT_NAME})
#endif()
