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

# Utility rule file for ExperimentalConfigure.

# Include the progress variables for this target.
include tests/CMakeFiles/ExperimentalConfigure.dir/progress.make

tests/CMakeFiles/ExperimentalConfigure:
	cd /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests && /opt/clion-2018.2/bin/cmake/linux/bin/ctest -D ExperimentalConfigure

ExperimentalConfigure: tests/CMakeFiles/ExperimentalConfigure
ExperimentalConfigure: tests/CMakeFiles/ExperimentalConfigure.dir/build.make

.PHONY : ExperimentalConfigure

# Rule to build all files generated by this target.
tests/CMakeFiles/ExperimentalConfigure.dir/build: ExperimentalConfigure

.PHONY : tests/CMakeFiles/ExperimentalConfigure.dir/build

tests/CMakeFiles/ExperimentalConfigure.dir/clean:
	cd /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalConfigure.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/ExperimentalConfigure.dir/clean

tests/CMakeFiles/ExperimentalConfigure.dir/depend:
	cd /home/stamaks/CLionProjects/Inst/point/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stamaks/CLionProjects/Inst/point /home/stamaks/CLionProjects/Inst/point/tests /home/stamaks/CLionProjects/Inst/point/cmake-build-debug /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests /home/stamaks/CLionProjects/Inst/point/cmake-build-debug/tests/CMakeFiles/ExperimentalConfigure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/ExperimentalConfigure.dir/depend

