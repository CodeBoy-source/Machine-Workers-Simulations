# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/briansenas/Desktop/University/SS/P3/maquinas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/briansenas/Desktop/University/SS/P3/maquinas

# Include any dependencies generated for this target.
include CMakeFiles/ntec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ntec.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ntec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ntec.dir/flags.make

CMakeFiles/ntec.dir/src/ntec.cpp.o: CMakeFiles/ntec.dir/flags.make
CMakeFiles/ntec.dir/src/ntec.cpp.o: src/ntec.cpp
CMakeFiles/ntec.dir/src/ntec.cpp.o: CMakeFiles/ntec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/briansenas/Desktop/University/SS/P3/maquinas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ntec.dir/src/ntec.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ntec.dir/src/ntec.cpp.o -MF CMakeFiles/ntec.dir/src/ntec.cpp.o.d -o CMakeFiles/ntec.dir/src/ntec.cpp.o -c /home/briansenas/Desktop/University/SS/P3/maquinas/src/ntec.cpp

CMakeFiles/ntec.dir/src/ntec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ntec.dir/src/ntec.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/briansenas/Desktop/University/SS/P3/maquinas/src/ntec.cpp > CMakeFiles/ntec.dir/src/ntec.cpp.i

CMakeFiles/ntec.dir/src/ntec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ntec.dir/src/ntec.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/briansenas/Desktop/University/SS/P3/maquinas/src/ntec.cpp -o CMakeFiles/ntec.dir/src/ntec.cpp.s

CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o: CMakeFiles/ntec.dir/flags.make
CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o: /home/briansenas/Desktop/University/SS/P3/include/utils.cpp
CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o: CMakeFiles/ntec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/briansenas/Desktop/University/SS/P3/maquinas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o -MF CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o.d -o CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o -c /home/briansenas/Desktop/University/SS/P3/include/utils.cpp

CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/briansenas/Desktop/University/SS/P3/include/utils.cpp > CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i

CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/briansenas/Desktop/University/SS/P3/include/utils.cpp -o CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s

# Object files for target ntec
ntec_OBJECTS = \
"CMakeFiles/ntec.dir/src/ntec.cpp.o" \
"CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o"

# External object files for target ntec
ntec_EXTERNAL_OBJECTS =

bin/ntec: CMakeFiles/ntec.dir/src/ntec.cpp.o
bin/ntec: CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o
bin/ntec: CMakeFiles/ntec.dir/build.make
bin/ntec: CMakeFiles/ntec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/briansenas/Desktop/University/SS/P3/maquinas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/ntec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ntec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ntec.dir/build: bin/ntec
.PHONY : CMakeFiles/ntec.dir/build

CMakeFiles/ntec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ntec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ntec.dir/clean

CMakeFiles/ntec.dir/depend:
	cd /home/briansenas/Desktop/University/SS/P3/maquinas && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/briansenas/Desktop/University/SS/P3/maquinas /home/briansenas/Desktop/University/SS/P3/maquinas /home/briansenas/Desktop/University/SS/P3/maquinas /home/briansenas/Desktop/University/SS/P3/maquinas /home/briansenas/Desktop/University/SS/P3/maquinas/CMakeFiles/ntec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ntec.dir/depend

