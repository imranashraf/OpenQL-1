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
include test/CMakeFiles/umfpack_support_1.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/umfpack_support_1.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/umfpack_support_1.dir/flags.make

test/CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.o: test/CMakeFiles/umfpack_support_1.dir/flags.make
test/CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.o: ../test/umfpack_support.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.o"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.o -c /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test/umfpack_support.cpp

test/CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.i"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test/umfpack_support.cpp > CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.i

test/CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.s"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test/umfpack_support.cpp -o CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.s

# Object files for target umfpack_support_1
umfpack_support_1_OBJECTS = \
"CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.o"

# External object files for target umfpack_support_1
umfpack_support_1_EXTERNAL_OBJECTS =

test/umfpack_support_1: test/CMakeFiles/umfpack_support_1.dir/umfpack_support.cpp.o
test/umfpack_support_1: test/CMakeFiles/umfpack_support_1.dir/build.make
test/umfpack_support_1: /usr/lib/x86_64-linux-gnu/libumfpack.so
test/umfpack_support_1: /usr/lib/x86_64-linux-gnu/libcolamd.so
test/umfpack_support_1: /usr/lib/x86_64-linux-gnu/libamd.so
test/umfpack_support_1: /usr/lib/x86_64-linux-gnu/libcholmod.so
test/umfpack_support_1: blas/libeigen_blas.so
test/umfpack_support_1: test/CMakeFiles/umfpack_support_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable umfpack_support_1"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/umfpack_support_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/umfpack_support_1.dir/build: test/umfpack_support_1

.PHONY : test/CMakeFiles/umfpack_support_1.dir/build

test/CMakeFiles/umfpack_support_1.dir/clean:
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test && $(CMAKE_COMMAND) -P CMakeFiles/umfpack_support_1.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/umfpack_support_1.dir/clean

test/CMakeFiles/umfpack_support_1.dir/depend:
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anneriet/Afstuderen/eigen-eigen-323c052e1731 /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/test /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/test/CMakeFiles/umfpack_support_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/umfpack_support_1.dir/depend

