# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/CLionProjects/FDF_

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/CLionProjects/FDF_/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FDF_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FDF_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FDF_.dir/flags.make

CMakeFiles/FDF_.dir/main.cpp.o: CMakeFiles/FDF_.dir/flags.make
CMakeFiles/FDF_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/CLionProjects/FDF_/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FDF_.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FDF_.dir/main.cpp.o -c /Users/mac/CLionProjects/FDF_/main.cpp

CMakeFiles/FDF_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FDF_.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/CLionProjects/FDF_/main.cpp > CMakeFiles/FDF_.dir/main.cpp.i

CMakeFiles/FDF_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FDF_.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/CLionProjects/FDF_/main.cpp -o CMakeFiles/FDF_.dir/main.cpp.s

CMakeFiles/FDF_.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/FDF_.dir/main.cpp.o.requires

CMakeFiles/FDF_.dir/main.cpp.o.provides: CMakeFiles/FDF_.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/FDF_.dir/build.make CMakeFiles/FDF_.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/FDF_.dir/main.cpp.o.provides

CMakeFiles/FDF_.dir/main.cpp.o.provides.build: CMakeFiles/FDF_.dir/main.cpp.o


# Object files for target FDF_
FDF__OBJECTS = \
"CMakeFiles/FDF_.dir/main.cpp.o"

# External object files for target FDF_
FDF__EXTERNAL_OBJECTS =

FDF_: CMakeFiles/FDF_.dir/main.cpp.o
FDF_: CMakeFiles/FDF_.dir/build.make
FDF_: CMakeFiles/FDF_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mac/CLionProjects/FDF_/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FDF_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FDF_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FDF_.dir/build: FDF_

.PHONY : CMakeFiles/FDF_.dir/build

CMakeFiles/FDF_.dir/requires: CMakeFiles/FDF_.dir/main.cpp.o.requires

.PHONY : CMakeFiles/FDF_.dir/requires

CMakeFiles/FDF_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FDF_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FDF_.dir/clean

CMakeFiles/FDF_.dir/depend:
	cd /Users/mac/CLionProjects/FDF_/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/CLionProjects/FDF_ /Users/mac/CLionProjects/FDF_ /Users/mac/CLionProjects/FDF_/cmake-build-debug /Users/mac/CLionProjects/FDF_/cmake-build-debug /Users/mac/CLionProjects/FDF_/cmake-build-debug/CMakeFiles/FDF_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FDF_.dir/depend

