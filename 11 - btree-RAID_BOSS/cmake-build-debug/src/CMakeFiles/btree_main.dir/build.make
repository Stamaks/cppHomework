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
include src/CMakeFiles/btree_main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/btree_main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/btree_main.dir/flags.make

src/CMakeFiles/btree_main.dir/main.cpp.o: src/CMakeFiles/btree_main.dir/flags.make
src/CMakeFiles/btree_main.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/btree_main.dir/main.cpp.o"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/btree_main.dir/main.cpp.o -c "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src/main.cpp"

src/CMakeFiles/btree_main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btree_main.dir/main.cpp.i"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src/main.cpp" > CMakeFiles/btree_main.dir/main.cpp.i

src/CMakeFiles/btree_main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btree_main.dir/main.cpp.s"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src/main.cpp" -o CMakeFiles/btree_main.dir/main.cpp.s

src/CMakeFiles/btree_main.dir/btree.cpp.o: src/CMakeFiles/btree_main.dir/flags.make
src/CMakeFiles/btree_main.dir/btree.cpp.o: ../src/btree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/btree_main.dir/btree.cpp.o"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/btree_main.dir/btree.cpp.o -c "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src/btree.cpp"

src/CMakeFiles/btree_main.dir/btree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btree_main.dir/btree.cpp.i"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src/btree.cpp" > CMakeFiles/btree_main.dir/btree.cpp.i

src/CMakeFiles/btree_main.dir/btree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btree_main.dir/btree.cpp.s"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src/btree.cpp" -o CMakeFiles/btree_main.dir/btree.cpp.s

# Object files for target btree_main
btree_main_OBJECTS = \
"CMakeFiles/btree_main.dir/main.cpp.o" \
"CMakeFiles/btree_main.dir/btree.cpp.o"

# External object files for target btree_main
btree_main_EXTERNAL_OBJECTS =

src/btree_main: src/CMakeFiles/btree_main.dir/main.cpp.o
src/btree_main: src/CMakeFiles/btree_main.dir/btree.cpp.o
src/btree_main: src/CMakeFiles/btree_main.dir/build.make
src/btree_main: src/CMakeFiles/btree_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable btree_main"
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/btree_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/btree_main.dir/build: src/btree_main

.PHONY : src/CMakeFiles/btree_main.dir/build

src/CMakeFiles/btree_main.dir/clean:
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src" && $(CMAKE_COMMAND) -P CMakeFiles/btree_main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/btree_main.dir/clean

src/CMakeFiles/btree_main.dir/depend:
	cd "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/src" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src" "/home/stamaks/CLionProjects/Inst/11 - btree-RAID_BOSS/cmake-build-debug/src/CMakeFiles/btree_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/btree_main.dir/depend

