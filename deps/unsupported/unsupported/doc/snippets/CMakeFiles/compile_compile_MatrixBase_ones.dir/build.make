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
include unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/depend.make

# Include the progress variables for this target.
include unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/progress.make

# Include the compile flags for this target's objects.
include unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/flags.make

unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.o: unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/flags.make
unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.o: unsupported/doc/snippets/compile_compile_MatrixBase_ones.cpp
unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.o: doc/snippets/compile_MatrixBase_ones.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.o"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.o -c /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets/compile_compile_MatrixBase_ones.cpp

unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.i"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets/compile_compile_MatrixBase_ones.cpp > CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.i

unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.s"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets/compile_compile_MatrixBase_ones.cpp -o CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.s

# Object files for target compile_compile_MatrixBase_ones
compile_compile_MatrixBase_ones_OBJECTS = \
"CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.o"

# External object files for target compile_compile_MatrixBase_ones
compile_compile_MatrixBase_ones_EXTERNAL_OBJECTS =

unsupported/doc/snippets/compile_compile_MatrixBase_ones: unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/compile_compile_MatrixBase_ones.cpp.o
unsupported/doc/snippets/compile_compile_MatrixBase_ones: unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/build.make
unsupported/doc/snippets/compile_compile_MatrixBase_ones: unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable compile_compile_MatrixBase_ones"
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile_compile_MatrixBase_ones.dir/link.txt --verbose=$(VERBOSE)
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets && ./compile_compile_MatrixBase_ones >/home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets/compile_MatrixBase_ones.out

# Rule to build all files generated by this target.
unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/build: unsupported/doc/snippets/compile_compile_MatrixBase_ones

.PHONY : unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/build

unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/clean:
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets && $(CMAKE_COMMAND) -P CMakeFiles/compile_compile_MatrixBase_ones.dir/cmake_clean.cmake
.PHONY : unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/clean

unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/depend:
	cd /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anneriet/Afstuderen/eigen-eigen-323c052e1731 /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/doc/snippets /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets /home/anneriet/Afstuderen/eigen-eigen-323c052e1731/unsupported/unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unsupported/doc/snippets/CMakeFiles/compile_compile_MatrixBase_ones.dir/depend

