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
CMAKE_SOURCE_DIR = C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Exercicio4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exercicio4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exercicio4.dir/flags.make

CMakeFiles/Exercicio4.dir/Djistrka.cpp.obj: CMakeFiles/Exercicio4.dir/flags.make
CMakeFiles/Exercicio4.dir/Djistrka.cpp.obj: ../Djistrka.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Exercicio4.dir/Djistrka.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Exercicio4.dir\Djistrka.cpp.obj -c C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4\Djistrka.cpp

CMakeFiles/Exercicio4.dir/Djistrka.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exercicio4.dir/Djistrka.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4\Djistrka.cpp > CMakeFiles\Exercicio4.dir\Djistrka.cpp.i

CMakeFiles/Exercicio4.dir/Djistrka.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exercicio4.dir/Djistrka.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4\Djistrka.cpp -o CMakeFiles\Exercicio4.dir\Djistrka.cpp.s

# Object files for target Exercicio4
Exercicio4_OBJECTS = \
"CMakeFiles/Exercicio4.dir/Djistrka.cpp.obj"

# External object files for target Exercicio4
Exercicio4_EXTERNAL_OBJECTS =

Exercicio4.exe: CMakeFiles/Exercicio4.dir/Djistrka.cpp.obj
Exercicio4.exe: CMakeFiles/Exercicio4.dir/build.make
Exercicio4.exe: CMakeFiles/Exercicio4.dir/linklibs.rsp
Exercicio4.exe: CMakeFiles/Exercicio4.dir/objects1.rsp
Exercicio4.exe: CMakeFiles/Exercicio4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Exercicio4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Exercicio4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exercicio4.dir/build: Exercicio4.exe

.PHONY : CMakeFiles/Exercicio4.dir/build

CMakeFiles/Exercicio4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Exercicio4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Exercicio4.dir/clean

CMakeFiles/Exercicio4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4 C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4 C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4\cmake-build-debug C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4\cmake-build-debug C:\Users\Yann\Desktop\BCC\Grafos\Exercicio4\cmake-build-debug\CMakeFiles\Exercicio4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Exercicio4.dir/depend

