# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2\build

# Include any dependencies generated for this target.
include CMakeFiles/proyectogrupal4_sit2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proyectogrupal4_sit2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proyectogrupal4_sit2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proyectogrupal4_sit2.dir/flags.make

CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.obj: CMakeFiles/proyectogrupal4_sit2.dir/flags.make
CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.obj: C:/Users/javie/Documents/uem21/prgestlin/proyectogrupal4_sit2/main.cpp
CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.obj: CMakeFiles/proyectogrupal4_sit2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.obj"
	c:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.obj -MF CMakeFiles\proyectogrupal4_sit2.dir\main.cpp.obj.d -o CMakeFiles\proyectogrupal4_sit2.dir\main.cpp.obj -c C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2\main.cpp

CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.i"
	c:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2\main.cpp > CMakeFiles\proyectogrupal4_sit2.dir\main.cpp.i

CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.s"
	c:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2\main.cpp -o CMakeFiles\proyectogrupal4_sit2.dir\main.cpp.s

# Object files for target proyectogrupal4_sit2
proyectogrupal4_sit2_OBJECTS = \
"CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.obj"

# External object files for target proyectogrupal4_sit2
proyectogrupal4_sit2_EXTERNAL_OBJECTS =

proyectogrupal4_sit2.exe: CMakeFiles/proyectogrupal4_sit2.dir/main.cpp.obj
proyectogrupal4_sit2.exe: CMakeFiles/proyectogrupal4_sit2.dir/build.make
proyectogrupal4_sit2.exe: CMakeFiles/proyectogrupal4_sit2.dir/linkLibs.rsp
proyectogrupal4_sit2.exe: CMakeFiles/proyectogrupal4_sit2.dir/objects1
proyectogrupal4_sit2.exe: CMakeFiles/proyectogrupal4_sit2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proyectogrupal4_sit2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proyectogrupal4_sit2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proyectogrupal4_sit2.dir/build: proyectogrupal4_sit2.exe
.PHONY : CMakeFiles/proyectogrupal4_sit2.dir/build

CMakeFiles/proyectogrupal4_sit2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proyectogrupal4_sit2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proyectogrupal4_sit2.dir/clean

CMakeFiles/proyectogrupal4_sit2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2 C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2 C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2\build C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2\build C:\Users\javie\Documents\uem21\prgestlin\proyectogrupal4_sit2\build\CMakeFiles\proyectogrupal4_sit2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proyectogrupal4_sit2.dir/depend

