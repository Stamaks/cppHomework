# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stamaks/CLionProjects/Inst/point

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stamaks/CLionProjects/Inst/point/cmake-build-debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/runUnitTests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/runUnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/runUnitTests.dir/flags.make

tests/CMakeFiles/runUnitTests.dir/point_array_test.cpp.o: tests/CMakeFiles/runUnitTests.dir/flags.make
tests/CMakeFiles/runUnitTests.dir/point_array_test.cpp.o: ../tests/point_array_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stamaks/CLionProjects/Inst/point/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/runUnitTests.dir/point_array_test.cpp.o"
	cd /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runUnitTests.dir/point_array_test.cpp.o -c /home/stamaks/CLionProjects/Inst/point/tests/point_array_test.cpp

tests/CMakeFiles/runUnitTests.dir/point_array_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/point_array_test.cpp.i"
	cd /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stamaks/CLionProjects/Inst/point/tests/point_array_test.cpp > CMakeFiles/runUnitTests.dir/point_array_test.cpp.i

tests/CMakeFiles/runUnitTests.dir/point_array_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/point_array_test.cpp.s"
	cd /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stamaks/CLionProjects/Inst/point/tests/point_array_test.cpp -o CMakeFiles/runUnitTests.dir/point_array_test.cpp.s

# Object files for target runUnitTests
runUnitTests_OBJECTS = \
"CMakeFiles/runUnitTests.dir/point_array_test.cpp.o"

# External object files for target runUnitTests
runUnitTests_EXTERNAL_OBJECTS =

tests/runUnitTests: tests/CMakeFiles/runUnitTests.dir/point_array_test.cpp.o
tests/runUnitTests: tests/CMakeFiles/runUnitTests.dir/build.make
tests/runUnitTests: googletest-build/googlemock/gtest/libgtestd.a
tests/runUnitTests: googletest-build/googlemock/libgmockd.a
tests/runUnitTests: src/libcore.a
tests/runUnitTests: googletest-build/googlemock/gtest/libgtestd.a
tests/runUnitTests: tests/CMakeFiles/runUnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stamaks/CLionProjects/Inst/point/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runUnitTests"
	cd /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runUnitTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/runUnitTests.dir/build: tests/runUnitTests

.PHONY : tests/CMakeFiles/runUnitTests.dir/build

tests/CMakeFiles/runUnitTests.dir/clean:
	cd /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/runUnitTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/runUnitTests.dir/clean

tests/CMakeFiles/runUnitTests.dir/depend:
	cd /home/stamaks/CLionProjects/Inst/point/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stamaks/CLionProjects/Inst/point /home/stamaks/CLionProjects/Inst/point/tests /home/stamaks/CLionProjects/Inst/point/cmake-build-debug /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests/CMakeFiles/runUnitTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/runUnitTests.dir/depend
