# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ola/Bureau/C++/Tictactoe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ola/Bureau/C++/Tictactoe/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mainProg.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mainProg.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mainProg.dir/flags.make

src/CMakeFiles/mainProg.dir/main.cpp.o: src/CMakeFiles/mainProg.dir/flags.make
src/CMakeFiles/mainProg.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ola/Bureau/C++/Tictactoe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mainProg.dir/main.cpp.o"
	cd /home/ola/Bureau/C++/Tictactoe/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainProg.dir/main.cpp.o -c /home/ola/Bureau/C++/Tictactoe/src/main.cpp

src/CMakeFiles/mainProg.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainProg.dir/main.cpp.i"
	cd /home/ola/Bureau/C++/Tictactoe/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ola/Bureau/C++/Tictactoe/src/main.cpp > CMakeFiles/mainProg.dir/main.cpp.i

src/CMakeFiles/mainProg.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainProg.dir/main.cpp.s"
	cd /home/ola/Bureau/C++/Tictactoe/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ola/Bureau/C++/Tictactoe/src/main.cpp -o CMakeFiles/mainProg.dir/main.cpp.s

# Object files for target mainProg
mainProg_OBJECTS = \
"CMakeFiles/mainProg.dir/main.cpp.o"

# External object files for target mainProg
mainProg_EXTERNAL_OBJECTS =

src/mainProg: src/CMakeFiles/mainProg.dir/main.cpp.o
src/mainProg: src/CMakeFiles/mainProg.dir/build.make
src/mainProg: src/CMakeFiles/mainProg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ola/Bureau/C++/Tictactoe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mainProg"
	cd /home/ola/Bureau/C++/Tictactoe/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainProg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mainProg.dir/build: src/mainProg

.PHONY : src/CMakeFiles/mainProg.dir/build

src/CMakeFiles/mainProg.dir/clean:
	cd /home/ola/Bureau/C++/Tictactoe/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mainProg.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mainProg.dir/clean

src/CMakeFiles/mainProg.dir/depend:
	cd /home/ola/Bureau/C++/Tictactoe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ola/Bureau/C++/Tictactoe /home/ola/Bureau/C++/Tictactoe/src /home/ola/Bureau/C++/Tictactoe/build /home/ola/Bureau/C++/Tictactoe/build/src /home/ola/Bureau/C++/Tictactoe/build/src/CMakeFiles/mainProg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mainProg.dir/depend

