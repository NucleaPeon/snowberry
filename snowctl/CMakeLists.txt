cmake_minimum_required(VERSION 3.3)
project(snowctl
        VERSION 0.1.0.0
	LANGUAGES C CXX
	DESCRIPTION "Qt5 Command Line Music Player Controller Snowberry Component"
)
include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!

# Immediately set the version.h header
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h)

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

        set(MACOSX_BUNDLE_ICON_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../snowberry.icns )
        set(APP_ICON "${MACOSX_BUNDLE_ICON_FILE}")
        list(APPEND OTHER_TARGETS ${APP_ICON})
        list(APPEND SNOWCTL_SOURCES ${SNOWLIBS}/cocoainitializer/cocoainitializer.mm)
        list(APPEND SNOWCTL_HEADERS ${SNOWLIBS}/cocoainitializer/cocoainitializer.h)
        add_custom_target(SNOWCTL_OTHER SOURCES ${OTHER_TARGETS})
        set_property(SOURCE ${APP_ICON} PROPERTY MACOSX_PACKAGE_LOCATION
                ${MACOSX_BUNDLE_ICON_FILE})
        file(COPY ${APP_ICON} DESTINATION
                 ${CMAKE_CURRENT_BINARY_DIR})
        #add_executable(${PROJECT_NAME} MACOSX_BUNDLE
        add_executable(${PROJECT_NAME}
                ${SNOWCTL_OTHER}
                ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
                ${SNOWCTL_HEADERS}
                ${SNOWCTL_SOURCES}
                ${SNOWCTL_UIS}
                ${SNOWCTL_RES}
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
                MACOSX_BUNDLE_GUI_IDENTIFIER org.peondevelopments.snowctl
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
                ${SNOWCTL_OTHER}
                main.cpp
                ${SNOWCTL_HEADERS}
                ${SNOWCTL_SOURCES}
                ${SNOWCTL_UIS}
                ${SNOWCTL_RES}
        )
endif()

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Network)
if(APPLE)
        install(TARGETS ${PROJECT_NAME} BUNDLE DESTINATION ${CMAKE_SOURCE_DIR})
else()
        install(TARGETS ${PROJECT_NAME})
endif()
