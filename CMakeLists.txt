cmake_minimum_required(VERSION 3.9.1)
project(revork)

SET(CMAKE_BUILD_TYPE DEBUG)
#SET(CMAKE_BUILD_TYPE RELEASE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Load headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/revork/src/)

# Load sources
file(GLOB SOURCES 
${CMAKE_CURRENT_SOURCE_DIR}/revork/src/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/revork/src/renderer/*.cpp
)

if(WIN32)

	SET(CMAKE_CXX_FLAGS "/std:c++latest -W3 /wd4530 /wd4005 /wd4996 /wd4244")
	set(CMAKE_GENERATOR "Visual Studio 15 2017 Win64")
	message("-- Generator set to ${CMAKE_GENERATOR}")
	add_executable(${PROJECT_NAME} ${SOURCES})

  # INCLUDE DEPENDENCIES
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dep/Windows)

	ADD_LIBRARY(opencl STATIC IMPORTED)
  SET_TARGET_PROPERTIES(opencl PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/dep/Windows/libOpenCL.a)

  ADD_LIBRARY(glew STATIC IMPORTED)
  SET_TARGET_PROPERTIES(glew PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/dep/Windows/glew32s.lib)

  ADD_LIBRARY(glfw STATIC IMPORTED)
  SET_TARGET_PROPERTIES(glfw PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/dep/Windows/glfw3.lib)
	target_link_libraries(${PROJECT_NAME} opencl glew glfw opengl32.lib user32.lib gdi32.lib kernel32.lib)

elseif(APPLE)

  SET(CMAKE_CXX_FLAGS_DEBUG "-march=native -std=c++1z -Wall -Wextra -pedantic -Wno-unused-function -Wno-unused-variable -Wno-unused-parameter")
  SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -std=c++1z -Wall -Wextra -pedantic -Wno-unused-function -Wno-unused-parameter")

	# RESOURCE FILE LOCATION
	file(GLOB RESOURCE_FILES
  "./revork/res/*.png"
  "./revork/res/*.vs"
  "./revork/res/*.fs"
	)

	add_executable(${PROJECT_NAME} ${SOURCES} main.cpp ${RESOURCE_FILES})

	# BUNDLE OPTIONS
	set_target_properties(${PROJECT_NAME} PROPERTIES
  MACOSX_BUNDLE false
  MACOSX_FRAMEWORK_IDENTIFIER org.cmake.${PROJECT_NAME}
  RESOURCE "${RESOURCE_FILES}"
	)

	# INCLUDE DEPENDENCIES
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dep/universal)
	include_directories("/usr/local/include/freetype2")

	ADD_LIBRARY(glew STATIC IMPORTED)
	SET_TARGET_PROPERTIES(glew PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/revork/dep/macOS/GL/libGLEW.a)

	ADD_LIBRARY(glfw STATIC IMPORTED)
	SET_TARGET_PROPERTIES(glfw PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/revork/dep/macOS/GLFW/libglfw3.a)

	# LINK TO TARGET
	target_link_libraries(${PROJECT_NAME} glew glfw "-lfreetype -lpthread -framework OpenGL -framework OpenCL -framework Cocoa -framework IOKIT -framework CoreVideo")

endif()
