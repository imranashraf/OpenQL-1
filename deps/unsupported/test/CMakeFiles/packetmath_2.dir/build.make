# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anneriet/Afstuderen/eigen-eigen-323c052e1731

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported

# Include any dependencies generated for this target.
include test/CMakeFiles/packetmath_2.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/packetmath_2.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/packetmath_2.dir/flags.make

test/CMakeFiles/packetmath_2.dir/packetmath.cpp.o: test/CMakeFiles/packetmath_2.dir/flags.make
test/CMakeFiles/packetmath_2.dir/packetmath.cpp.o: ../test/packetmath.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/packetmath_2.dir/packetmath.cpp.o"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/packetmath_2.dir/packetmath.cpp.o -c /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test/packetmath.cpp

test/CMakeFiles/packetmath_2.dir/packetmath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/packetmath_2.dir/packetmath.cpp.i"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test/packetmath.cpp > CMakeFiles/packetmath_2.dir/packetmath.cpp.i

test/CMakeFiles/packetmath_2.dir/packetmath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/packetmath_2.dir/packetmath.cpp.s"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test/packetmath.cpp -o CMakeFiles/packetmath_2.dir/packetmath.cpp.s

# Object files for target packetmath_2
packetmath_2_OBJECTS = \
"CMakeFiles/packetmath_2.dir/packetmath.cpp.o"

# External object files for target packetmath_2
packetmath_2_EXTERNAL_OBJECTS =

test/packetmath_2: test/CMakeFiles/packetmath_2.dir/packetmath.cpp.o
test/packetmath_2: test/CMakeFiles/packetmath_2.dir/build.make
test/packetmath_2: test/CMakeFiles/packetmath_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable packetmath_2"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/packetmath_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/packetmath_2.dir/build: test/packetmath_2

.PHONY : test/CMakeFiles/packetmath_2.dir/build

test/CMakeFiles/packetmath_2.dir/clean:
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && $(CMAKE_COMMAND) -P CMakeFiles/packetmath_2.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/packetmath_2.dir/clean

test/CMakeFiles/packetmath_2.dir/depend:
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anneriet/Afstuderen/eigen-eigen-323c052e1731 /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test/CMakeFiles/packetmath_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/packetmath_2.dir/depend

