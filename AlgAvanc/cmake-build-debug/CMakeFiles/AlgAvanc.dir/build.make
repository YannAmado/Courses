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
CMAKE_SOURCE_DIR = C:\Users\Yann\Desktop\BCC\AlgAvanc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Yann\Desktop\BCC\AlgAvanc\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AlgAvanc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AlgAvanc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AlgAvanc.dir/flags.make

CMakeFiles/AlgAvanc.dir/divisao-conq1.cpp.obj: CMakeFiles/AlgAvanc.dir/flags.make
CMakeFiles/AlgAvanc.dir/divisao-conq1.cpp.obj: ../divisao-conq1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yann\Desktop\BCC\AlgAvanc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AlgAvanc.dir/divisao-conq1.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AlgAvanc.dir\divisao-conq1.cpp.obj -c C:\Users\Yann\Desktop\BCC\AlgAvanc\divisao-conq1.cpp

CMakeFiles/AlgAvanc.dir/divisao-conq1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgAvanc.dir/divisao-conq1.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Yann\Desktop\BCC\AlgAvanc\divisao-conq1.cpp > CMakeFiles\AlgAvanc.dir\divisao-conq1.cpp.i

CMakeFiles/AlgAvanc.dir/divisao-conq1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgAvanc.dir/divisao-conq1.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Yann\Desktop\BCC\AlgAvanc\divisao-conq1.cpp -o CMakeFiles\AlgAvanc.dir\divisao-conq1.cpp.s

# Object files for target AlgAvanc
AlgAvanc_OBJECTS = \
"CMakeFiles/AlgAvanc.dir/divisao-conq1.cpp.obj"

# External object files for target AlgAvanc
AlgAvanc_EXTERNAL_OBJECTS =

AlgAvanc.exe: CMakeFiles/AlgAvanc.dir/divisao-conq1.cpp.obj
AlgAvanc.exe: CMakeFiles/AlgAvanc.dir/build.make
AlgAvanc.exe: CMakeFiles/AlgAvanc.dir/linklibs.rsp
AlgAvanc.exe: CMakeFiles/AlgAvanc.dir/objects1.rsp
AlgAvanc.exe: CMakeFiles/AlgAvanc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Yann\Desktop\BCC\AlgAvanc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AlgAvanc.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AlgAvanc.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AlgAvanc.dir/build: AlgAvanc.exe

.PHONY : CMakeFiles/AlgAvanc.dir/build

CMakeFiles/AlgAvanc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AlgAvanc.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AlgAvanc.dir/clean

CMakeFiles/AlgAvanc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Yann\Desktop\BCC\AlgAvanc C:\Users\Yann\Desktop\BCC\AlgAvanc C:\Users\Yann\Desktop\BCC\AlgAvanc\cmake-build-debug C:\Users\Yann\Desktop\BCC\AlgAvanc\cmake-build-debug C:\Users\Yann\Desktop\BCC\AlgAvanc\cmake-build-debug\CMakeFiles\AlgAvanc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AlgAvanc.dir/depend

