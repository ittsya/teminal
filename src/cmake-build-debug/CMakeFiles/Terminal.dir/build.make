# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /var/lib/snapd/snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ittsya/SDL2/teminal/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ittsya/SDL2/teminal/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Terminal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Terminal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Terminal.dir/flags.make

CMakeFiles/Terminal.dir/screen.cpp.o: CMakeFiles/Terminal.dir/flags.make
CMakeFiles/Terminal.dir/screen.cpp.o: ../screen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ittsya/SDL2/teminal/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Terminal.dir/screen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Terminal.dir/screen.cpp.o -c /home/ittsya/SDL2/teminal/src/screen.cpp

CMakeFiles/Terminal.dir/screen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terminal.dir/screen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ittsya/SDL2/teminal/src/screen.cpp > CMakeFiles/Terminal.dir/screen.cpp.i

CMakeFiles/Terminal.dir/screen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terminal.dir/screen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ittsya/SDL2/teminal/src/screen.cpp -o CMakeFiles/Terminal.dir/screen.cpp.s

CMakeFiles/Terminal.dir/main.cpp.o: CMakeFiles/Terminal.dir/flags.make
CMakeFiles/Terminal.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ittsya/SDL2/teminal/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Terminal.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Terminal.dir/main.cpp.o -c /home/ittsya/SDL2/teminal/src/main.cpp

CMakeFiles/Terminal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Terminal.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ittsya/SDL2/teminal/src/main.cpp > CMakeFiles/Terminal.dir/main.cpp.i

CMakeFiles/Terminal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Terminal.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ittsya/SDL2/teminal/src/main.cpp -o CMakeFiles/Terminal.dir/main.cpp.s

# Object files for target Terminal
Terminal_OBJECTS = \
"CMakeFiles/Terminal.dir/screen.cpp.o" \
"CMakeFiles/Terminal.dir/main.cpp.o"

# External object files for target Terminal
Terminal_EXTERNAL_OBJECTS =

/home/ittsya/SDL2/teminal/bin/Terminal: CMakeFiles/Terminal.dir/screen.cpp.o
/home/ittsya/SDL2/teminal/bin/Terminal: CMakeFiles/Terminal.dir/main.cpp.o
/home/ittsya/SDL2/teminal/bin/Terminal: CMakeFiles/Terminal.dir/build.make
/home/ittsya/SDL2/teminal/bin/Terminal: CMakeFiles/Terminal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ittsya/SDL2/teminal/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/ittsya/SDL2/teminal/bin/Terminal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Terminal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Terminal.dir/build: /home/ittsya/SDL2/teminal/bin/Terminal

.PHONY : CMakeFiles/Terminal.dir/build

CMakeFiles/Terminal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Terminal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Terminal.dir/clean

CMakeFiles/Terminal.dir/depend:
	cd /home/ittsya/SDL2/teminal/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ittsya/SDL2/teminal/src /home/ittsya/SDL2/teminal/src /home/ittsya/SDL2/teminal/src/cmake-build-debug /home/ittsya/SDL2/teminal/src/cmake-build-debug /home/ittsya/SDL2/teminal/src/cmake-build-debug/CMakeFiles/Terminal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Terminal.dir/depend

