# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:\Users\james\AppData\Local\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\james\AppData\Local\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\james\Downloads\comp sci work\eulerproject"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\james\Downloads\comp sci work\eulerproject\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/eulerproject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/eulerproject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/eulerproject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eulerproject.dir/flags.make

CMakeFiles/eulerproject.dir/Q15.c.obj: CMakeFiles/eulerproject.dir/flags.make
CMakeFiles/eulerproject.dir/Q15.c.obj: C:/Users/james/Downloads/comp\ sci\ work/eulerproject/Q15.c
CMakeFiles/eulerproject.dir/Q15.c.obj: CMakeFiles/eulerproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\james\Downloads\comp sci work\eulerproject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/eulerproject.dir/Q15.c.obj"
	C:\Users\james\AppData\Local\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/eulerproject.dir/Q15.c.obj -MF CMakeFiles\eulerproject.dir\Q15.c.obj.d -o CMakeFiles\eulerproject.dir\Q15.c.obj -c "C:\Users\james\Downloads\comp sci work\eulerproject\Q15.c"

CMakeFiles/eulerproject.dir/Q15.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/eulerproject.dir/Q15.c.i"
	C:\Users\james\AppData\Local\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\james\Downloads\comp sci work\eulerproject\Q15.c" > CMakeFiles\eulerproject.dir\Q15.c.i

CMakeFiles/eulerproject.dir/Q15.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/eulerproject.dir/Q15.c.s"
	C:\Users\james\AppData\Local\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\james\Downloads\comp sci work\eulerproject\Q15.c" -o CMakeFiles\eulerproject.dir\Q15.c.s

# Object files for target eulerproject
eulerproject_OBJECTS = \
"CMakeFiles/eulerproject.dir/Q15.c.obj"

# External object files for target eulerproject
eulerproject_EXTERNAL_OBJECTS =

eulerproject.exe: CMakeFiles/eulerproject.dir/Q15.c.obj
eulerproject.exe: CMakeFiles/eulerproject.dir/build.make
eulerproject.exe: CMakeFiles/eulerproject.dir/linkLibs.rsp
eulerproject.exe: CMakeFiles/eulerproject.dir/objects1.rsp
eulerproject.exe: CMakeFiles/eulerproject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\james\Downloads\comp sci work\eulerproject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable eulerproject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\eulerproject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eulerproject.dir/build: eulerproject.exe
.PHONY : CMakeFiles/eulerproject.dir/build

CMakeFiles/eulerproject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\eulerproject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/eulerproject.dir/clean

CMakeFiles/eulerproject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\james\Downloads\comp sci work\eulerproject" "C:\Users\james\Downloads\comp sci work\eulerproject" "C:\Users\james\Downloads\comp sci work\eulerproject\cmake-build-debug" "C:\Users\james\Downloads\comp sci work\eulerproject\cmake-build-debug" "C:\Users\james\Downloads\comp sci work\eulerproject\cmake-build-debug\CMakeFiles\eulerproject.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/eulerproject.dir/depend

