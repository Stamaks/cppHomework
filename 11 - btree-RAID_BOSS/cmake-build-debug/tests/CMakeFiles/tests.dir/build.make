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
CMAKE_SOURCE_DIR = "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug"

# Include any dependencies generated for this target.
include tests/CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/tests.dir/flags.make

tests/CMakeFiles/tests.dir/adapters1_tests.cpp.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/adapters1_tests.cpp.o: ../tests/adapters1_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/tests.dir/adapters1_tests.cpp.o"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/adapters1_tests.cpp.o -c "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/adapters1_tests.cpp"

tests/CMakeFiles/tests.dir/adapters1_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/adapters1_tests.cpp.i"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/adapters1_tests.cpp" > CMakeFiles/tests.dir/adapters1_tests.cpp.i

tests/CMakeFiles/tests.dir/adapters1_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/adapters1_tests.cpp.s"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/adapters1_tests.cpp" -o CMakeFiles/tests.dir/adapters1_tests.cpp.s

tests/CMakeFiles/tests.dir/btree1_tests.cpp.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/btree1_tests.cpp.o: ../tests/btree1_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/tests.dir/btree1_tests.cpp.o"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/btree1_tests.cpp.o -c "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/btree1_tests.cpp"

tests/CMakeFiles/tests.dir/btree1_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/btree1_tests.cpp.i"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/btree1_tests.cpp" > CMakeFiles/tests.dir/btree1_tests.cpp.i

tests/CMakeFiles/tests.dir/btree1_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/btree1_tests.cpp.s"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/btree1_tests.cpp" -o CMakeFiles/tests.dir/btree1_tests.cpp.s

tests/CMakeFiles/tests.dir/__/src/btree.cpp.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/__/src/btree.cpp.o: ../src/btree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/tests.dir/__/src/btree.cpp.o"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/__/src/btree.cpp.o -c "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src/btree.cpp"

tests/CMakeFiles/tests.dir/__/src/btree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/src/btree.cpp.i"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src/btree.cpp" > CMakeFiles/tests.dir/__/src/btree.cpp.i

tests/CMakeFiles/tests.dir/__/src/btree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/src/btree.cpp.s"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src/btree.cpp" -o CMakeFiles/tests.dir/__/src/btree.cpp.s

tests/CMakeFiles/tests.dir/gtest/gtest-all.cc.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/gtest/gtest-all.cc.o: ../tests/gtest/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/tests.dir/gtest/gtest-all.cc.o"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/gtest/gtest-all.cc.o -c "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/gtest/gtest-all.cc"

tests/CMakeFiles/tests.dir/gtest/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/gtest/gtest-all.cc.i"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/gtest/gtest-all.cc" > CMakeFiles/tests.dir/gtest/gtest-all.cc.i

tests/CMakeFiles/tests.dir/gtest/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/gtest/gtest-all.cc.s"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/gtest/gtest-all.cc" -o CMakeFiles/tests.dir/gtest/gtest-all.cc.s

tests/CMakeFiles/tests.dir/gtest/gtest_main.cc.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/gtest/gtest_main.cc.o: ../tests/gtest/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object tests/CMakeFiles/tests.dir/gtest/gtest_main.cc.o"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/gtest/gtest_main.cc.o -c "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/gtest/gtest_main.cc"

tests/CMakeFiles/tests.dir/gtest/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/gtest/gtest_main.cc.i"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/gtest/gtest_main.cc" > CMakeFiles/tests.dir/gtest/gtest_main.cc.i

tests/CMakeFiles/tests.dir/gtest/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/gtest/gtest_main.cc.s"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests/gtest/gtest_main.cc" -o CMakeFiles/tests.dir/gtest/gtest_main.cc.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/adapters1_tests.cpp.o" \
"CMakeFiles/tests.dir/btree1_tests.cpp.o" \
"CMakeFiles/tests.dir/__/src/btree.cpp.o" \
"CMakeFiles/tests.dir/gtest/gtest-all.cc.o" \
"CMakeFiles/tests.dir/gtest/gtest_main.cc.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests/tests: tests/CMakeFiles/tests.dir/adapters1_tests.cpp.o
tests/tests: tests/CMakeFiles/tests.dir/btree1_tests.cpp.o
tests/tests: tests/CMakeFiles/tests.dir/__/src/btree.cpp.o
tests/tests: tests/CMakeFiles/tests.dir/gtest/gtest-all.cc.o
tests/tests: tests/CMakeFiles/tests.dir/gtest/gtest_main.cc.o
tests/tests: tests/CMakeFiles/tests.dir/build.make
tests/tests: tests/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable tests"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/tests.dir/build: tests/tests

.PHONY : tests/CMakeFiles/tests.dir/build

tests/CMakeFiles/tests.dir/clean:
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/tests.dir/clean

tests/CMakeFiles/tests.dir/depend:
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/tests" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/tests/CMakeFiles/tests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/tests.dir/depend

