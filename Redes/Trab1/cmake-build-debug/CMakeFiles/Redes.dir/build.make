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
CMAKE_SOURCE_DIR = C:\Users\Yann\Desktop\BCC\Redes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Yann\Desktop\BCC\Redes\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Redes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Redes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Redes.dir/flags.make

CMakeFiles/Redes.dir/sockets.c.obj: CMakeFiles/Redes.dir/flags.make
CMakeFiles/Redes.dir/sockets.c.obj: ../sockets.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yann\Desktop\BCC\Redes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Redes.dir/sockets.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Redes.dir\sockets.c.obj -c C:\Users\Yann\Desktop\BCC\Redes\sockets.c

CMakeFiles/Redes.dir/sockets.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Redes.dir/sockets.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Yann\Desktop\BCC\Redes\sockets.c > CMakeFiles\Redes.dir\sockets.c.i

CMakeFiles/Redes.dir/sockets.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Redes.dir/sockets.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Yann\Desktop\BCC\Redes\sockets.c -o CMakeFiles\Redes.dir\sockets.c.s

CMakeFiles/Redes.dir/server.c.obj: CMakeFiles/Redes.dir/flags.make
CMakeFiles/Redes.dir/server.c.obj: ../server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yann\Desktop\BCC\Redes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Redes.dir/server.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Redes.dir\server.c.obj -c C:\Users\Yann\Desktop\BCC\Redes\server.c

CMakeFiles/Redes.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Redes.dir/server.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Yann\Desktop\BCC\Redes\server.c > CMakeFiles\Redes.dir\server.c.i

CMakeFiles/Redes.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Redes.dir/server.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Yann\Desktop\BCC\Redes\server.c -o CMakeFiles\Redes.dir\server.c.s

CMakeFiles/Redes.dir/client.c.obj: CMakeFiles/Redes.dir/flags.make
CMakeFiles/Redes.dir/client.c.obj: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Yann\Desktop\BCC\Redes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Redes.dir/client.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Redes.dir\client.c.obj -c C:\Users\Yann\Desktop\BCC\Redes\client.c

CMakeFiles/Redes.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Redes.dir/client.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Yann\Desktop\BCC\Redes\client.c > CMakeFiles\Redes.dir\client.c.i

CMakeFiles/Redes.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Redes.dir/client.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Yann\Desktop\BCC\Redes\client.c -o CMakeFiles\Redes.dir\client.c.s

# Object files for target Redes
Redes_OBJECTS = \
"CMakeFiles/Redes.dir/sockets.c.obj" \
"CMakeFiles/Redes.dir/server.c.obj" \
"CMakeFiles/Redes.dir/client.c.obj"

# External object files for target Redes
Redes_EXTERNAL_OBJECTS =

Redes.exe: CMakeFiles/Redes.dir/sockets.c.obj
Redes.exe: CMakeFiles/Redes.dir/server.c.obj
Redes.exe: CMakeFiles/Redes.dir/client.c.obj
Redes.exe: CMakeFiles/Redes.dir/build.make
Redes.exe: CMakeFiles/Redes.dir/linklibs.rsp
Redes.exe: CMakeFiles/Redes.dir/objects1.rsp
Redes.exe: CMakeFiles/Redes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Yann\Desktop\BCC\Redes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Redes.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Redes.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Redes.dir/build: Redes.exe

.PHONY : CMakeFiles/Redes.dir/build

CMakeFiles/Redes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Redes.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Redes.dir/clean

CMakeFiles/Redes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Yann\Desktop\BCC\Redes C:\Users\Yann\Desktop\BCC\Redes C:\Users\Yann\Desktop\BCC\Redes\cmake-build-debug C:\Users\Yann\Desktop\BCC\Redes\cmake-build-debug C:\Users\Yann\Desktop\BCC\Redes\cmake-build-debug\CMakeFiles\Redes.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Redes.dir/depend

