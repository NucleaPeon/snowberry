cmake_minimum_required(VERSION 3.3)
project(snowgui
	VERSION 0.1.0
	LANGUAGES C CXX
	DESCRIPTION "Qt5 Graphical Interface Snowberry Component"
)

include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!
#add_compile_options(-v)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


include(GNUInstallDirs)  # REQUIRED TO INSTALL PKGCONFIG TO PROPER DIR!
#add_compile_options(-v)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED
    Core
    Network
)

list(APPEND SNOWGUI_SOURCES
)

list(APPEND SNOWGUI_HEADERS
)

list(APPEND SNOWGUI_UIS
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
	list(APPEND OTHER_TARGETS ${APP_ICON})
	list(APPEND CHUPNP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/cocoainitializer.mm)
	list(APPEND CHUPNP_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/cocoainitializer.h)
	add_custom_target(OTHER_FILES SOURCES ${OTHER_TARGETS})
	set_property(SOURCE ${APP_ICON} PROPERTY MACOSX_PACKAGE_LOCATION
		${MACOSX_BUNDLE_ICON_FILE})
	file(COPY ${APP_ICON} DESTINATION
		 ${CMAKE_CURRENT_BINARY_DIR})
	add_executable(${PROJECT_NAME} MACOSX_BUNDLE
		${OTHER_FILES}
		${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
		${CHUPNP_HEADERS}
		${CHUPNP_SOURCES}
		${CHUPNP_UIS}
		${CHUPNP_RES}
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
		MACOSX_BUNDLE_GUI_IDENTIFIER org.qtupnp.chupnp
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
endif()

add_executable(${PROJECT_NAME}
		${SNOWGUI_OTHER}
		main.cpp
		${SNOWGUI_HEADERS}
		${SNOWGUI_SOURCES}
		${SNOWGUI_UIS}
		${SNOWGUI_RES}
	)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Network)

