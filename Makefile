# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/briansenas/Desktop/University/SS/P3/maquinas/CMakeFiles /home/briansenas/Desktop/University/SS/P3/maquinas//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/briansenas/Desktop/University/SS/P3/maquinas/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named maquinas1trabajador

# Build rule for target.
maquinas1trabajador: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 maquinas1trabajador
.PHONY : maquinas1trabajador

# fast build rule for target.
maquinas1trabajador/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinas1trabajador.dir/build.make CMakeFiles/maquinas1trabajador.dir/build
.PHONY : maquinas1trabajador/fast

#=============================================================================
# Target rules for targets named maquinasmodificable

# Build rule for target.
maquinasmodificable: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 maquinasmodificable
.PHONY : maquinasmodificable

# fast build rule for target.
maquinasmodificable/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinasmodificable.dir/build.make CMakeFiles/maquinasmodificable.dir/build
.PHONY : maquinasmodificable/fast

#=============================================================================
# Target rules for targets named ntec

# Build rule for target.
ntec: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ntec
.PHONY : ntec

# fast build rule for target.
ntec/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ntec.dir/build.make CMakeFiles/ntec.dir/build
.PHONY : ntec/fast

#=============================================================================
# Target rules for targets named best_model

# Build rule for target.
best_model: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 best_model
.PHONY : best_model

# fast build rule for target.
best_model/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/best_model.dir/build.make CMakeFiles/best_model.dir/build
.PHONY : best_model/fast

home/briansenas/Desktop/University/SS/P3/include/utils.o: home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o
.PHONY : home/briansenas/Desktop/University/SS/P3/include/utils.o

# target to build an object file
home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinas1trabajador.dir/build.make CMakeFiles/maquinas1trabajador.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinasmodificable.dir/build.make CMakeFiles/maquinasmodificable.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ntec.dir/build.make CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/best_model.dir/build.make CMakeFiles/best_model.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o
.PHONY : home/briansenas/Desktop/University/SS/P3/include/utils.cpp.o

home/briansenas/Desktop/University/SS/P3/include/utils.i: home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i
.PHONY : home/briansenas/Desktop/University/SS/P3/include/utils.i

# target to preprocess a source file
home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinas1trabajador.dir/build.make CMakeFiles/maquinas1trabajador.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinasmodificable.dir/build.make CMakeFiles/maquinasmodificable.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ntec.dir/build.make CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/best_model.dir/build.make CMakeFiles/best_model.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i
.PHONY : home/briansenas/Desktop/University/SS/P3/include/utils.cpp.i

home/briansenas/Desktop/University/SS/P3/include/utils.s: home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s
.PHONY : home/briansenas/Desktop/University/SS/P3/include/utils.s

# target to generate assembly for a file
home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinas1trabajador.dir/build.make CMakeFiles/maquinas1trabajador.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinasmodificable.dir/build.make CMakeFiles/maquinasmodificable.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ntec.dir/build.make CMakeFiles/ntec.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/best_model.dir/build.make CMakeFiles/best_model.dir/home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s
.PHONY : home/briansenas/Desktop/University/SS/P3/include/utils.cpp.s

src/ComputeBestModel.o: src/ComputeBestModel.cpp.o
.PHONY : src/ComputeBestModel.o

# target to build an object file
src/ComputeBestModel.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/best_model.dir/build.make CMakeFiles/best_model.dir/src/ComputeBestModel.cpp.o
.PHONY : src/ComputeBestModel.cpp.o

src/ComputeBestModel.i: src/ComputeBestModel.cpp.i
.PHONY : src/ComputeBestModel.i

# target to preprocess a source file
src/ComputeBestModel.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/best_model.dir/build.make CMakeFiles/best_model.dir/src/ComputeBestModel.cpp.i
.PHONY : src/ComputeBestModel.cpp.i

src/ComputeBestModel.s: src/ComputeBestModel.cpp.s
.PHONY : src/ComputeBestModel.s

# target to generate assembly for a file
src/ComputeBestModel.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/best_model.dir/build.make CMakeFiles/best_model.dir/src/ComputeBestModel.cpp.s
.PHONY : src/ComputeBestModel.cpp.s

src/maquinasmodificable.o: src/maquinasmodificable.cpp.o
.PHONY : src/maquinasmodificable.o

# target to build an object file
src/maquinasmodificable.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinasmodificable.dir/build.make CMakeFiles/maquinasmodificable.dir/src/maquinasmodificable.cpp.o
.PHONY : src/maquinasmodificable.cpp.o

src/maquinasmodificable.i: src/maquinasmodificable.cpp.i
.PHONY : src/maquinasmodificable.i

# target to preprocess a source file
src/maquinasmodificable.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinasmodificable.dir/build.make CMakeFiles/maquinasmodificable.dir/src/maquinasmodificable.cpp.i
.PHONY : src/maquinasmodificable.cpp.i

src/maquinasmodificable.s: src/maquinasmodificable.cpp.s
.PHONY : src/maquinasmodificable.s

# target to generate assembly for a file
src/maquinasmodificable.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinasmodificable.dir/build.make CMakeFiles/maquinasmodificable.dir/src/maquinasmodificable.cpp.s
.PHONY : src/maquinasmodificable.cpp.s

src/multiplesmaquinas1trabajador.o: src/multiplesmaquinas1trabajador.cpp.o
.PHONY : src/multiplesmaquinas1trabajador.o

# target to build an object file
src/multiplesmaquinas1trabajador.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinas1trabajador.dir/build.make CMakeFiles/maquinas1trabajador.dir/src/multiplesmaquinas1trabajador.cpp.o
.PHONY : src/multiplesmaquinas1trabajador.cpp.o

src/multiplesmaquinas1trabajador.i: src/multiplesmaquinas1trabajador.cpp.i
.PHONY : src/multiplesmaquinas1trabajador.i

# target to preprocess a source file
src/multiplesmaquinas1trabajador.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinas1trabajador.dir/build.make CMakeFiles/maquinas1trabajador.dir/src/multiplesmaquinas1trabajador.cpp.i
.PHONY : src/multiplesmaquinas1trabajador.cpp.i

src/multiplesmaquinas1trabajador.s: src/multiplesmaquinas1trabajador.cpp.s
.PHONY : src/multiplesmaquinas1trabajador.s

# target to generate assembly for a file
src/multiplesmaquinas1trabajador.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/maquinas1trabajador.dir/build.make CMakeFiles/maquinas1trabajador.dir/src/multiplesmaquinas1trabajador.cpp.s
.PHONY : src/multiplesmaquinas1trabajador.cpp.s

src/ntec.o: src/ntec.cpp.o
.PHONY : src/ntec.o

# target to build an object file
src/ntec.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ntec.dir/build.make CMakeFiles/ntec.dir/src/ntec.cpp.o
.PHONY : src/ntec.cpp.o

src/ntec.i: src/ntec.cpp.i
.PHONY : src/ntec.i

# target to preprocess a source file
src/ntec.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ntec.dir/build.make CMakeFiles/ntec.dir/src/ntec.cpp.i
.PHONY : src/ntec.cpp.i

src/ntec.s: src/ntec.cpp.s
.PHONY : src/ntec.s

# target to generate assembly for a file
src/ntec.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ntec.dir/build.make CMakeFiles/ntec.dir/src/ntec.cpp.s
.PHONY : src/ntec.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... best_model"
	@echo "... maquinas1trabajador"
	@echo "... maquinasmodificable"
	@echo "... ntec"
	@echo "... home/briansenas/Desktop/University/SS/P3/include/utils.o"
	@echo "... home/briansenas/Desktop/University/SS/P3/include/utils.i"
	@echo "... home/briansenas/Desktop/University/SS/P3/include/utils.s"
	@echo "... src/ComputeBestModel.o"
	@echo "... src/ComputeBestModel.i"
	@echo "... src/ComputeBestModel.s"
	@echo "... src/maquinasmodificable.o"
	@echo "... src/maquinasmodificable.i"
	@echo "... src/maquinasmodificable.s"
	@echo "... src/multiplesmaquinas1trabajador.o"
	@echo "... src/multiplesmaquinas1trabajador.i"
	@echo "... src/multiplesmaquinas1trabajador.s"
	@echo "... src/ntec.o"
	@echo "... src/ntec.i"
	@echo "... src/ntec.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

