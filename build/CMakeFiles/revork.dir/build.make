# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mathiassen/Revork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mathiassen/Revork/build

# Include any dependencies generated for this target.
include CMakeFiles/revork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/revork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/revork.dir/flags.make

CMakeFiles/revork.dir/revork/src/camera.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/camera.cpp.o: ../revork/src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/revork.dir/revork/src/camera.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/camera.cpp.o -c /Users/mathiassen/Revork/revork/src/camera.cpp

CMakeFiles/revork.dir/revork/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/camera.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/camera.cpp > CMakeFiles/revork.dir/revork/src/camera.cpp.i

CMakeFiles/revork.dir/revork/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/camera.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/camera.cpp -o CMakeFiles/revork.dir/revork/src/camera.cpp.s

CMakeFiles/revork.dir/revork/src/camera.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/camera.cpp.o.requires

CMakeFiles/revork.dir/revork/src/camera.cpp.o.provides: CMakeFiles/revork.dir/revork/src/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/camera.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/camera.cpp.o.provides

CMakeFiles/revork.dir/revork/src/camera.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/camera.cpp.o


CMakeFiles/revork.dir/revork/src/config.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/config.cpp.o: ../revork/src/config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/revork.dir/revork/src/config.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/config.cpp.o -c /Users/mathiassen/Revork/revork/src/config.cpp

CMakeFiles/revork.dir/revork/src/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/config.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/config.cpp > CMakeFiles/revork.dir/revork/src/config.cpp.i

CMakeFiles/revork.dir/revork/src/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/config.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/config.cpp -o CMakeFiles/revork.dir/revork/src/config.cpp.s

CMakeFiles/revork.dir/revork/src/config.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/config.cpp.o.requires

CMakeFiles/revork.dir/revork/src/config.cpp.o.provides: CMakeFiles/revork.dir/revork/src/config.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/config.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/config.cpp.o.provides

CMakeFiles/revork.dir/revork/src/config.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/config.cpp.o


CMakeFiles/revork.dir/revork/src/imgui.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/imgui.cpp.o: ../revork/src/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/revork.dir/revork/src/imgui.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/imgui.cpp.o -c /Users/mathiassen/Revork/revork/src/imgui.cpp

CMakeFiles/revork.dir/revork/src/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/imgui.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/imgui.cpp > CMakeFiles/revork.dir/revork/src/imgui.cpp.i

CMakeFiles/revork.dir/revork/src/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/imgui.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/imgui.cpp -o CMakeFiles/revork.dir/revork/src/imgui.cpp.s

CMakeFiles/revork.dir/revork/src/imgui.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/imgui.cpp.o.requires

CMakeFiles/revork.dir/revork/src/imgui.cpp.o.provides: CMakeFiles/revork.dir/revork/src/imgui.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/imgui.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/imgui.cpp.o.provides

CMakeFiles/revork.dir/revork/src/imgui.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/imgui.cpp.o


CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o: ../revork/src/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o -c /Users/mathiassen/Revork/revork/src/imgui_draw.cpp

CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/imgui_draw.cpp > CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.i

CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/imgui_draw.cpp -o CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.s

CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o.requires

CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o.provides: CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o.provides

CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o


CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o: ../revork/src/imgui_impl_glfw_gl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o -c /Users/mathiassen/Revork/revork/src/imgui_impl_glfw_gl3.cpp

CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/imgui_impl_glfw_gl3.cpp > CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.i

CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/imgui_impl_glfw_gl3.cpp -o CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.s

CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o.requires

CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o.provides: CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o.provides

CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o


CMakeFiles/revork.dir/revork/src/revork.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/revork.cpp.o: ../revork/src/revork.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/revork.dir/revork/src/revork.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/revork.cpp.o -c /Users/mathiassen/Revork/revork/src/revork.cpp

CMakeFiles/revork.dir/revork/src/revork.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/revork.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/revork.cpp > CMakeFiles/revork.dir/revork/src/revork.cpp.i

CMakeFiles/revork.dir/revork/src/revork.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/revork.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/revork.cpp -o CMakeFiles/revork.dir/revork/src/revork.cpp.s

CMakeFiles/revork.dir/revork/src/revork.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/revork.cpp.o.requires

CMakeFiles/revork.dir/revork/src/revork.cpp.o.provides: CMakeFiles/revork.dir/revork/src/revork.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/revork.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/revork.cpp.o.provides

CMakeFiles/revork.dir/revork/src/revork.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/revork.cpp.o


CMakeFiles/revork.dir/revork/src/window_manager.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/window_manager.cpp.o: ../revork/src/window_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/revork.dir/revork/src/window_manager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/window_manager.cpp.o -c /Users/mathiassen/Revork/revork/src/window_manager.cpp

CMakeFiles/revork.dir/revork/src/window_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/window_manager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/window_manager.cpp > CMakeFiles/revork.dir/revork/src/window_manager.cpp.i

CMakeFiles/revork.dir/revork/src/window_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/window_manager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/window_manager.cpp -o CMakeFiles/revork.dir/revork/src/window_manager.cpp.s

CMakeFiles/revork.dir/revork/src/window_manager.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/window_manager.cpp.o.requires

CMakeFiles/revork.dir/revork/src/window_manager.cpp.o.provides: CMakeFiles/revork.dir/revork/src/window_manager.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/window_manager.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/window_manager.cpp.o.provides

CMakeFiles/revork.dir/revork/src/window_manager.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/window_manager.cpp.o


CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o: ../revork/src/renderer/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o -c /Users/mathiassen/Revork/revork/src/renderer/renderer.cpp

CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/renderer/renderer.cpp > CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.i

CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/renderer/renderer.cpp -o CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.s

CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o.requires

CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o.provides: CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o.provides

CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o


CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o: ../revork/src/renderer/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o -c /Users/mathiassen/Revork/revork/src/renderer/shader.cpp

CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/renderer/shader.cpp > CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.i

CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/renderer/shader.cpp -o CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.s

CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o.requires

CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o.provides: CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o.provides

CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o


CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o: ../revork/src/renderer/skybox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o -c /Users/mathiassen/Revork/revork/src/renderer/skybox.cpp

CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/renderer/skybox.cpp > CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.i

CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/renderer/skybox.cpp -o CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.s

CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o.requires

CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o.provides: CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o.provides

CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o


CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o: ../revork/src/renderer/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o -c /Users/mathiassen/Revork/revork/src/renderer/texture.cpp

CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/revork/src/renderer/texture.cpp > CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.i

CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/revork/src/renderer/texture.cpp -o CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.s

CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o.requires

CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o.provides: CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o.provides

CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o.provides.build: CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o


CMakeFiles/revork.dir/main.cpp.o: CMakeFiles/revork.dir/flags.make
CMakeFiles/revork.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/revork.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/revork.dir/main.cpp.o -c /Users/mathiassen/Revork/main.cpp

CMakeFiles/revork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/revork.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathiassen/Revork/main.cpp > CMakeFiles/revork.dir/main.cpp.i

CMakeFiles/revork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/revork.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathiassen/Revork/main.cpp -o CMakeFiles/revork.dir/main.cpp.s

CMakeFiles/revork.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/revork.dir/main.cpp.o.requires

CMakeFiles/revork.dir/main.cpp.o.provides: CMakeFiles/revork.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/revork.dir/build.make CMakeFiles/revork.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/revork.dir/main.cpp.o.provides

CMakeFiles/revork.dir/main.cpp.o.provides.build: CMakeFiles/revork.dir/main.cpp.o


# Object files for target revork
revork_OBJECTS = \
"CMakeFiles/revork.dir/revork/src/camera.cpp.o" \
"CMakeFiles/revork.dir/revork/src/config.cpp.o" \
"CMakeFiles/revork.dir/revork/src/imgui.cpp.o" \
"CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o" \
"CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o" \
"CMakeFiles/revork.dir/revork/src/revork.cpp.o" \
"CMakeFiles/revork.dir/revork/src/window_manager.cpp.o" \
"CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o" \
"CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o" \
"CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o" \
"CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o" \
"CMakeFiles/revork.dir/main.cpp.o"

# External object files for target revork
revork_EXTERNAL_OBJECTS =

../bin/revork: CMakeFiles/revork.dir/revork/src/camera.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/config.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/imgui.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/revork.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/window_manager.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o
../bin/revork: CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o
../bin/revork: CMakeFiles/revork.dir/main.cpp.o
../bin/revork: CMakeFiles/revork.dir/build.make
../bin/revork: ../revork/dep/macOS/GL/libGLEW.a
../bin/revork: ../revork/dep/macOS/GLFW/libglfw3.a
../bin/revork: CMakeFiles/revork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mathiassen/Revork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ../bin/revork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/revork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/revork.dir/build: ../bin/revork

.PHONY : CMakeFiles/revork.dir/build

CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/camera.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/config.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/imgui.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/imgui_draw.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/imgui_impl_glfw_gl3.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/revork.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/window_manager.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/renderer/renderer.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/renderer/shader.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/renderer/skybox.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/revork/src/renderer/texture.cpp.o.requires
CMakeFiles/revork.dir/requires: CMakeFiles/revork.dir/main.cpp.o.requires

.PHONY : CMakeFiles/revork.dir/requires

CMakeFiles/revork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/revork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/revork.dir/clean

CMakeFiles/revork.dir/depend:
	cd /Users/mathiassen/Revork/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mathiassen/Revork /Users/mathiassen/Revork /Users/mathiassen/Revork/build /Users/mathiassen/Revork/build /Users/mathiassen/Revork/build/CMakeFiles/revork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/revork.dir/depend

