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
include test/CMakeFiles/integer_types_1.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/integer_types_1.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/integer_types_1.dir/flags.make

test/CMakeFiles/integer_types_1.dir/integer_types.cpp.o: test/CMakeFiles/integer_types_1.dir/flags.make
test/CMakeFiles/integer_types_1.dir/integer_types.cpp.o: ../test/integer_types.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/integer_types_1.dir/integer_types.cpp.o"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/integer_types_1.dir/integer_types.cpp.o -c /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test/integer_types.cpp

test/CMakeFiles/integer_types_1.dir/integer_types.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/integer_types_1.dir/integer_types.cpp.i"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test/integer_types.cpp > CMakeFiles/integer_types_1.dir/integer_types.cpp.i

test/CMakeFiles/integer_types_1.dir/integer_types.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/integer_types_1.dir/integer_types.cpp.s"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test/integer_types.cpp -o CMakeFiles/integer_types_1.dir/integer_types.cpp.s

# Object files for target integer_types_1
integer_types_1_OBJECTS = \
"CMakeFiles/integer_types_1.dir/integer_types.cpp.o"

# External object files for target integer_types_1
integer_types_1_EXTERNAL_OBJECTS =

test/integer_types_1: test/CMakeFiles/integer_types_1.dir/integer_types.cpp.o
test/integer_types_1: test/CMakeFiles/integer_types_1.dir/build.make
test/integer_types_1: test/CMakeFiles/integer_types_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable integer_types_1"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/integer_types_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/integer_types_1.dir/build: test/integer_types_1

.PHONY : test/CMakeFiles/integer_types_1.dir/build

test/CMakeFiles/integer_types_1.dir/clean:
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && $(CMAKE_COMMAND) -P CMakeFiles/integer_types_1.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/integer_types_1.dir/clean

test/CMakeFiles/integer_types_1.dir/depend:
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anneriet/Afstuderen/eigen-eigen-323c052e1731 /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test/CMakeFiles/integer_types_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/integer_types_1.dir/depend

