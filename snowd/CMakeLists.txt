cmake_minimum_required(VERSION 3.3)
project(snowd
        VERSION 1.0.0
        LANGUAGES C CXX
        DESCRIPTION "Qt5 Collection Manager and Audio Player Daemon"
)

find_package(Qt5 REQUIRED
    Core
    Widgets
    Network
    Xml
)


include_directories(.)
include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!
#add_compile_options(-v)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC ON)



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

        set(MACOSX_BUNDLE_ICON_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../snowberry.icns )
        set(APP_ICON "${MACOSX_BUNDLE_ICON_FILE}")
        list(APPEND OTHER_TARGETS ${APP_ICON})
        list(APPEND SNOWD_SOURCES ${SNOWLIBS}/cocoainitializer/cocoainitializer.mm)
        list(APPEND SNOWD_HEADERS ${SNOWLIBS}/cocoainitializer/cocoainitializer.h)
        add_custom_target(SNOWD_OTHER SOURCES ${OTHER_TARGETS})
        set_property(SOURCE ${APP_ICON} PROPERTY MACOSX_PACKAGE_LOCATION
                ${MACOSX_BUNDLE_ICON_FILE})
        file(COPY ${APP_ICON} DESTINATION
                 ${CMAKE_CURRENT_BINARY_DIR})
        #add_executable(${PROJECT_NAME} MACOSX_BUNDLE
        add_executable(${PROJECT_NAME}
                ${SNOWD_OTHER}
                ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
                ${SNOWD_HEADERS}
                ${SNOWD_SOURCES}
                ${SNOWD_UIS}
                ${SNOWD_RES}
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
                ${SNOWD_OTHER}
                main.cpp
                ${SNOWD_HEADERS}
                ${SNOWD_SOURCES}
                ${SNOWD_UIS}
                ${SNOWD_RES}
        )
endif()

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Network Qt5::Xml)
if(APPLE)
        install(TARGETS ${PROJECT_NAME} BUNDLE DESTINATION ${CMAKE_SOURCE_DIR})
else()
        install(TARGETS ${PROJECT_NAME})
endif()
