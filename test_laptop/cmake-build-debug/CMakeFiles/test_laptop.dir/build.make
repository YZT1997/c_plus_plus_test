# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Clion\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\GithubCode\c_plus_plus_test\test_laptop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\GithubCode\c_plus_plus_test\test_laptop\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_laptop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_laptop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_laptop.dir/flags.make

CMakeFiles/test_laptop.dir/9_7.cpp.obj: CMakeFiles/test_laptop.dir/flags.make
CMakeFiles/test_laptop.dir/9_7.cpp.obj: CMakeFiles/test_laptop.dir/includes_CXX.rsp
CMakeFiles/test_laptop.dir/9_7.cpp.obj: ../9_7.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\GithubCode\c_plus_plus_test\test_laptop\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_laptop.dir/9_7.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test_laptop.dir\9_7.cpp.obj -c E:\GithubCode\c_plus_plus_test\test_laptop\9_7.cpp

CMakeFiles/test_laptop.dir/9_7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_laptop.dir/9_7.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\GithubCode\c_plus_plus_test\test_laptop\9_7.cpp > CMakeFiles\test_laptop.dir\9_7.cpp.i

CMakeFiles/test_laptop.dir/9_7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_laptop.dir/9_7.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\GithubCode\c_plus_plus_test\test_laptop\9_7.cpp -o CMakeFiles\test_laptop.dir\9_7.cpp.s

# Object files for target test_laptop
test_laptop_OBJECTS = \
"CMakeFiles/test_laptop.dir/9_7.cpp.obj"

# External object files for target test_laptop
test_laptop_EXTERNAL_OBJECTS =

test_laptop.exe: CMakeFiles/test_laptop.dir/9_7.cpp.obj
test_laptop.exe: CMakeFiles/test_laptop.dir/build.make
test_laptop.exe: CMakeFiles/test_laptop.dir/linklibs.rsp
test_laptop.exe: CMakeFiles/test_laptop.dir/objects1.rsp
test_laptop.exe: CMakeFiles/test_laptop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\GithubCode\c_plus_plus_test\test_laptop\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_laptop.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_laptop.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_laptop.dir/build: test_laptop.exe

.PHONY : CMakeFiles/test_laptop.dir/build

CMakeFiles/test_laptop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_laptop.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_laptop.dir/clean

CMakeFiles/test_laptop.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\GithubCode\c_plus_plus_test\test_laptop E:\GithubCode\c_plus_plus_test\test_laptop E:\GithubCode\c_plus_plus_test\test_laptop\cmake-build-debug E:\GithubCode\c_plus_plus_test\test_laptop\cmake-build-debug E:\GithubCode\c_plus_plus_test\test_laptop\cmake-build-debug\CMakeFiles\test_laptop.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_laptop.dir/depend

