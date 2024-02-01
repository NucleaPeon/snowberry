cmake_minimum_required(VERSION 3.3)
project(snowd-runner
        VERSION 0.1.0.0
        LANGUAGES C CXX
        DESCRIPTION "Qt5 Collection Manager and Audio Player Daemon Run Process"
)

# Immediately set the version.h header
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/../version.h)

find_package(Qt5 REQUIRED Core)

include_directories(.)
include_directories(..)
include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!
#add_compile_options(-v)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC ON)

if (APPLE)
        set(CMAKE_C_COMPILER /usr/bin/clang)
        set(CMAKE_CXX_COMPILER /usr/bin/clang++)

        set(MACOSX_BUNDLE_ICON_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../../snowberry.icns )
        set(APP_ICON "${MACOSX_BUNDLE_ICON_FILE}")
        list(APPEND OTHER_TARGETS ${APP_ICON})
        set_property(SOURCE ${APP_ICON} PROPERTY MACOSX_PACKAGE_LOCATION
                ${MACOSX_BUNDLE_ICON_FILE})
        file(COPY ${APP_ICON} DESTINATION
                 ${CMAKE_CURRENT_BINARY_DIR})
        add_executable(${PROJECT_NAME}
                ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )
        target_sources(${PROJECT_NAME} PRIVATE
                ${OTHER_TARGETS}
        )
        set_source_files_properties(
                ${OTHER_TARGETS}
                PROPERTIES
                MACOSX_PACKAGE_LOCATION Resources/
        )
        set_target_properties(${PROJECT_NAME} PROPERTIES
                BUNDLE TRUE
                MACOSX_BUNDLE_GUI_IDENTIFIER org.peondevelopments.snowd
                MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME}
                MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
                MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION}
        )
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS
                 "-Wl,-F/Library/Frameworks")
        target_link_libraries(${PROJECT_NAME} stdc++
                "-framework Cocoa"
                objc
        )
else()
        add_executable(${PROJECT_NAME}
                ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )
endif()

target_link_libraries(${PROJECT_NAME} Qt5::Core)
if(APPLE)
        install(TARGETS ${PROJECT_NAME} BUNDLE DESTINATION ${CMAKE_SOURCE_DIR})
else()
        install(TARGETS ${PROJECT_NAME})
endif()
