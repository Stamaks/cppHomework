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
CMAKE_SOURCE_DIR = /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download

# Utility rule file for googletest-download.

# Include the progress variables for this target.
include CMakeFiles/googletest-download.dir/progress.make

CMakeFiles/googletest-download: CMakeFiles/googletest-download-complete


CMakeFiles/googletest-download-complete: googletest-download-prefix/src/googletest-download-stamp/googletest-download-install
CMakeFiles/googletest-download-complete: googletest-download-prefix/src/googletest-download-stamp/googletest-download-mkdir
CMakeFiles/googletest-download-complete: googletest-download-prefix/src/googletest-download-stamp/googletest-download-download
CMakeFiles/googletest-download-complete: googletest-download-prefix/src/googletest-download-stamp/googletest-download-patch
CMakeFiles/googletest-download-complete: googletest-download-prefix/src/googletest-download-stamp/googletest-download-configure
CMakeFiles/googletest-download-complete: googletest-download-prefix/src/googletest-download-stamp/googletest-download-build
CMakeFiles/googletest-download-complete: googletest-download-prefix/src/googletest-download-stamp/googletest-download-install
CMakeFiles/googletest-download-complete: googletest-download-prefix/src/googletest-download-stamp/googletest-download-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'googletest-download'"
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E make_directory /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E touch /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles/googletest-download-complete
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E touch /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src/googletest-download-stamp/googletest-download-done

googletest-download-prefix/src/googletest-download-stamp/googletest-download-install: googletest-download-prefix/src/googletest-download-stamp/googletest-download-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'googletest-download'"
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-build && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E echo_append
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-build && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E touch /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src/googletest-download-stamp/googletest-download-install

googletest-download-prefix/src/googletest-download-stamp/googletest-download-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'googletest-download'"
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E make_directory /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-src
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E make_directory /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-build
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E make_directory /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E make_directory /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/tmp
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E make_directory /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src/googletest-download-stamp
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E make_directory /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E touch /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src/googletest-download-stamp/googletest-download-mkdir

googletest-download-prefix/src/googletest-download-stamp/googletest-download-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-gitinfo.txt
googletest-download-prefix/src/googletest-download-stamp/googletest-download-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'googletest-download'"
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -P /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/tmp/googletest-download-gitclone.cmake
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E touch /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src/googletest-download-stamp/googletest-download-download

googletest-download-prefix/src/googletest-download-stamp/googletest-download-patch: googletest-download-prefix/src/googletest-download-stamp/googletest-download-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No patch step for 'googletest-download'"
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E echo_append
	/opt/clion-2018.2/bin/cmake/linux/bin/cmake -E touch /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src/googletest-download-stamp/googletest-download-patch

googletest-download-prefix/src/googletest-download-stamp/googletest-download-configure: googletest-download-prefix/tmp/googletest-download-cfgcmd.txt
googletest-download-prefix/src/googletest-download-stamp/googletest-download-configure: googletest-download-prefix/src/googletest-download-stamp/googletest-download-skip-update
googletest-download-prefix/src/googletest-download-stamp/googletest-download-configure: googletest-download-prefix/src/googletest-download-stamp/googletest-download-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No configure step for 'googletest-download'"
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-build && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E echo_append
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-build && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E touch /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src/googletest-download-stamp/googletest-download-configure

googletest-download-prefix/src/googletest-download-stamp/googletest-download-build: googletest-download-prefix/src/googletest-download-stamp/googletest-download-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No build step for 'googletest-download'"
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-build && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E echo_append
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-build && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E touch /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src/googletest-download-stamp/googletest-download-build

googletest-download-prefix/src/googletest-download-stamp/googletest-download-test: googletest-download-prefix/src/googletest-download-stamp/googletest-download-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'googletest-download'"
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-build && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E echo_append
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-build && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E touch /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/googletest-download-prefix/src/googletest-download-stamp/googletest-download-test

googletest-download-prefix/src/googletest-download-stamp/googletest-download-skip-update: googletest-download-prefix/src/googletest-download-stamp/googletest-download-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Skipping update step for 'googletest-download'"
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-src && /opt/clion-2018.2/bin/cmake/linux/bin/cmake -E echo_append

googletest-download: CMakeFiles/googletest-download
googletest-download: CMakeFiles/googletest-download-complete
googletest-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-install
googletest-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-mkdir
googletest-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-download
googletest-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-patch
googletest-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-configure
googletest-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-build
googletest-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-test
googletest-download: googletest-download-prefix/src/googletest-download-stamp/googletest-download-skip-update
googletest-download: CMakeFiles/googletest-download.dir/build.make

.PHONY : googletest-download

# Rule to build all files generated by this target.
CMakeFiles/googletest-download.dir/build: googletest-download

.PHONY : CMakeFiles/googletest-download.dir/build

CMakeFiles/googletest-download.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/googletest-download.dir/cmake_clean.cmake
.PHONY : CMakeFiles/googletest-download.dir/clean

CMakeFiles/googletest-download.dir/depend:
	cd /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download /home/stamaks/CLionProjects/Inst/safearray/cmake-build-debug/googletest-download/CMakeFiles/googletest-download.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/googletest-download.dir/depend
