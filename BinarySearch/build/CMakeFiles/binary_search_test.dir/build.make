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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/luguangming/workspace/algorithm/BinarySearch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/luguangming/workspace/algorithm/BinarySearch/build

# Include any dependencies generated for this target.
include CMakeFiles/binary_search_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binary_search_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binary_search_test.dir/flags.make

CMakeFiles/binary_search_test.dir/main.cpp.o: CMakeFiles/binary_search_test.dir/flags.make
CMakeFiles/binary_search_test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/luguangming/workspace/algorithm/BinarySearch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binary_search_test.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/binary_search_test.dir/main.cpp.o -c /Users/luguangming/workspace/algorithm/BinarySearch/main.cpp

CMakeFiles/binary_search_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary_search_test.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/luguangming/workspace/algorithm/BinarySearch/main.cpp > CMakeFiles/binary_search_test.dir/main.cpp.i

CMakeFiles/binary_search_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary_search_test.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/luguangming/workspace/algorithm/BinarySearch/main.cpp -o CMakeFiles/binary_search_test.dir/main.cpp.s

# Object files for target binary_search_test
binary_search_test_OBJECTS = \
"CMakeFiles/binary_search_test.dir/main.cpp.o"

# External object files for target binary_search_test
binary_search_test_EXTERNAL_OBJECTS =

../bin/binary_search_test: CMakeFiles/binary_search_test.dir/main.cpp.o
../bin/binary_search_test: CMakeFiles/binary_search_test.dir/build.make
../bin/binary_search_test: CMakeFiles/binary_search_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/luguangming/workspace/algorithm/BinarySearch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/binary_search_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binary_search_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binary_search_test.dir/build: ../bin/binary_search_test

.PHONY : CMakeFiles/binary_search_test.dir/build

CMakeFiles/binary_search_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binary_search_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binary_search_test.dir/clean

CMakeFiles/binary_search_test.dir/depend:
	cd /Users/luguangming/workspace/algorithm/BinarySearch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/luguangming/workspace/algorithm/BinarySearch /Users/luguangming/workspace/algorithm/BinarySearch /Users/luguangming/workspace/algorithm/BinarySearch/build /Users/luguangming/workspace/algorithm/BinarySearch/build /Users/luguangming/workspace/algorithm/BinarySearch/build/CMakeFiles/binary_search_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binary_search_test.dir/depend
