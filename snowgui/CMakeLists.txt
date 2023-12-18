cmake_minimum_required(VERSION 3.3)
project(snowgui
        VERSION 0.1.0.0
	LANGUAGES C CXX
	DESCRIPTION "Qt5 Graphical Interface Snowberry Component"
)

# Immediately set the version.h header
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h @ONLY)

include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!
#add_compile_options(-v)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!
#add_compile_options(-v)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED
    Core
    Gui
    Widgets
    Network
)

list(APPEND SNOWGUI_SOURCES
    about.cpp
    preferences.cpp
    mainwindow.cpp
)

list(APPEND SNOWGUI_HEADERS
    ../globals.h
    about.h
    preferences.h
    mainwindow.h
)

list(APPEND SNOWGUI_UIS
    about.ui
    preferences.ui
    mainwindow.ui
)

list(APPEND SNOWGUI_RES
)

list(APPEND SNOWGUI_OTHER
)


if (APPLE)
	set(CMAKE_C_COMPILER /usr/bin/clang)
	set(CMAKE_CXX_COMPILER /usr/bin/clang++)
	set(MACOSX_BUNDLE_ICON_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../snowberry.icns )
	set(APP_ICON "${MACOSX_BUNDLE_ICON_FILE}")
	list(APPEND SNOWGUI_OTHER ${APP_ICON})
        list(APPEND SNOWGUI_SOURCES ${SNOWLIBS}/cocoainitializer/cocoainitializer.mm)
        list(APPEND SNOWGUI_HEADERS ${SNOWLIBS}/cocoainitializer/cocoainitializer.h)
	add_custom_target(OTHER_FILES SOURCES ${SNOWGUI_OTHER})
	set_property(SOURCE ${APP_ICON} PROPERTY MACOSX_PACKAGE_LOCATION
		${MACOSX_BUNDLE_ICON_FILE})
	file(COPY ${APP_ICON} DESTINATION
		 ${CMAKE_CURRENT_BINARY_DIR})
	add_executable(${PROJECT_NAME} MACOSX_BUNDLE
		${OTHER_FILES}
		${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
		${SNOWGUI_HEADERS}
		${SNOWGUI_SOURCES}
		${SNOWGUI_UIS}
		${SNOWGUI_RES}
	)
	target_sources(${PROJECT_NAME} PRIVATE
		${SNOWGUI_OTHER}
	)
	set_source_files_properties(
		${SNOWGUI_OTHER}
		PROPERTIES
		MACOSX_PACKAGE_LOCATION Resources/
	)
	set_target_properties(${PROJECT_NAME} PROPERTIES
		BUNDLE TRUE
		MACOSX_BUNDLE_GUI_IDENTIFIER org.peondevelopments.snowgui
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
		${SNOWGUI_OTHER}
		main.cpp
		${SNOWGUI_HEADERS}
		${SNOWGUI_SOURCES}
		${SNOWGUI_UIS}
		${SNOWGUI_RES}
	)
endif()

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Network Qt5::Gui Qt5::Widgets)

if(APPLE)
        install(TARGETS ${PROJECT_NAME} BUNDLE DESTINATION ${CMAKE_SOURCE_DIR})
else()
        install(TARGETS ${PROJECT_NAME})
endif()
