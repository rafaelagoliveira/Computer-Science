# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/build

# Include any dependencies generated for this target.
include CMakeFiles/simpleNodeDeque.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/simpleNodeDeque.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/simpleNodeDeque.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simpleNodeDeque.dir/flags.make

CMakeFiles/simpleNodeDeque.dir/main.cpp.o: CMakeFiles/simpleNodeDeque.dir/flags.make
CMakeFiles/simpleNodeDeque.dir/main.cpp.o: /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/main.cpp
CMakeFiles/simpleNodeDeque.dir/main.cpp.o: CMakeFiles/simpleNodeDeque.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simpleNodeDeque.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/simpleNodeDeque.dir/main.cpp.o -MF CMakeFiles/simpleNodeDeque.dir/main.cpp.o.d -o CMakeFiles/simpleNodeDeque.dir/main.cpp.o -c /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/main.cpp

CMakeFiles/simpleNodeDeque.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleNodeDeque.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/main.cpp > CMakeFiles/simpleNodeDeque.dir/main.cpp.i

CMakeFiles/simpleNodeDeque.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleNodeDeque.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/main.cpp -o CMakeFiles/simpleNodeDeque.dir/main.cpp.s

CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.o: CMakeFiles/simpleNodeDeque.dir/flags.make
CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.o: /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/Deque/src/Deque.cpp
CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.o: CMakeFiles/simpleNodeDeque.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.o -MF CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.o.d -o CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.o -c /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/Deque/src/Deque.cpp

CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/Deque/src/Deque.cpp > CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.i

CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/Deque/src/Deque.cpp -o CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.s

CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.o: CMakeFiles/simpleNodeDeque.dir/flags.make
CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.o: /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/Deque/src/Node.cpp
CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.o: CMakeFiles/simpleNodeDeque.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.o -MF CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.o.d -o CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.o -c /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/Deque/src/Node.cpp

CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/Deque/src/Node.cpp > CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.i

CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/Deque/src/Node.cpp -o CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.s

# Object files for target simpleNodeDeque
simpleNodeDeque_OBJECTS = \
"CMakeFiles/simpleNodeDeque.dir/main.cpp.o" \
"CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.o" \
"CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.o"

# External object files for target simpleNodeDeque
simpleNodeDeque_EXTERNAL_OBJECTS =

simpleNodeDeque: CMakeFiles/simpleNodeDeque.dir/main.cpp.o
simpleNodeDeque: CMakeFiles/simpleNodeDeque.dir/Deque/src/Deque.cpp.o
simpleNodeDeque: CMakeFiles/simpleNodeDeque.dir/Deque/src/Node.cpp.o
simpleNodeDeque: CMakeFiles/simpleNodeDeque.dir/build.make
simpleNodeDeque: CMakeFiles/simpleNodeDeque.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable simpleNodeDeque"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simpleNodeDeque.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simpleNodeDeque.dir/build: simpleNodeDeque
.PHONY : CMakeFiles/simpleNodeDeque.dir/build

CMakeFiles/simpleNodeDeque.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simpleNodeDeque.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simpleNodeDeque.dir/clean

CMakeFiles/simpleNodeDeque.dir/depend:
	cd /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/build /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/build /home/tanjerina/Documentos/CC/CC-2023/PP/simpleListDeque/build/CMakeFiles/simpleNodeDeque.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simpleNodeDeque.dir/depend
