# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Yann\Desktop\BCC\Grafos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Yann\Desktop\BCC\Grafos\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Grafos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Grafos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Grafos.dir/flags.make

CMakeFiles/Grafos.dir/buscarProfundidade.cpp.obj: CMakeFiles/Grafos.dir/flags.make
CMakeFiles/Grafos.dir/buscarProfundidade.cpp.obj: ../buscarProfundidade.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yann\Desktop\BCC\Grafos\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Grafos.dir/buscarProfundidade.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Grafos.dir\buscarProfundidade.cpp.obj -c C:\Users\Yann\Desktop\BCC\Grafos\buscarProfundidade.cpp

CMakeFiles/Grafos.dir/buscarProfundidade.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Grafos.dir/buscarProfundidade.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Yann\Desktop\BCC\Grafos\buscarProfundidade.cpp > CMakeFiles\Grafos.dir\buscarProfundidade.cpp.i

CMakeFiles/Grafos.dir/buscarProfundidade.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Grafos.dir/buscarProfundidade.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Yann\Desktop\BCC\Grafos\buscarProfundidade.cpp -o CMakeFiles\Grafos.dir\buscarProfundidade.cpp.s

# Object files for target Grafos
Grafos_OBJECTS = \
"CMakeFiles/Grafos.dir/buscarProfundidade.cpp.obj"

# External object files for target Grafos
Grafos_EXTERNAL_OBJECTS =

Grafos.exe: CMakeFiles/Grafos.dir/buscarProfundidade.cpp.obj
Grafos.exe: CMakeFiles/Grafos.dir/build.make
Grafos.exe: CMakeFiles/Grafos.dir/linklibs.rsp
Grafos.exe: CMakeFiles/Grafos.dir/objects1.rsp
Grafos.exe: CMakeFiles/Grafos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Yann\Desktop\BCC\Grafos\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Grafos.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Grafos.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Grafos.dir/build: Grafos.exe

.PHONY : CMakeFiles/Grafos.dir/build

CMakeFiles/Grafos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Grafos.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Grafos.dir/clean

CMakeFiles/Grafos.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Yann\Desktop\BCC\Grafos C:\Users\Yann\Desktop\BCC\Grafos C:\Users\Yann\Desktop\BCC\Grafos\cmake-build-debug C:\Users\Yann\Desktop\BCC\Grafos\cmake-build-debug C:\Users\Yann\Desktop\BCC\Grafos\cmake-build-debug\CMakeFiles\Grafos.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Grafos.dir/depend
