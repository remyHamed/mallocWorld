# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/malloWor.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/malloWor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/malloWor.dir/flags.make

CMakeFiles/malloWor.dir/main.c.obj: CMakeFiles/malloWor.dir/flags.make
CMakeFiles/malloWor.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/malloWor.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\malloWor.dir\main.c.obj -c "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\main.c"

CMakeFiles/malloWor.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloWor.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\main.c" > CMakeFiles\malloWor.dir\main.c.i

CMakeFiles/malloWor.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloWor.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\main.c" -o CMakeFiles\malloWor.dir\main.c.s

CMakeFiles/malloWor.dir/Battle.c.obj: CMakeFiles/malloWor.dir/flags.make
CMakeFiles/malloWor.dir/Battle.c.obj: ../Battle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/malloWor.dir/Battle.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\malloWor.dir\Battle.c.obj -c "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\Battle.c"

CMakeFiles/malloWor.dir/Battle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloWor.dir/Battle.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\Battle.c" > CMakeFiles\malloWor.dir\Battle.c.i

CMakeFiles/malloWor.dir/Battle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloWor.dir/Battle.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\Battle.c" -o CMakeFiles\malloWor.dir\Battle.c.s

# Object files for target malloWor
malloWor_OBJECTS = \
"CMakeFiles/malloWor.dir/main.c.obj" \
"CMakeFiles/malloWor.dir/Battle.c.obj"

# External object files for target malloWor
malloWor_EXTERNAL_OBJECTS =

malloWor.exe: CMakeFiles/malloWor.dir/main.c.obj
malloWor.exe: CMakeFiles/malloWor.dir/Battle.c.obj
malloWor.exe: CMakeFiles/malloWor.dir/build.make
malloWor.exe: CMakeFiles/malloWor.dir/linklibs.rsp
malloWor.exe: CMakeFiles/malloWor.dir/objects1.rsp
malloWor.exe: CMakeFiles/malloWor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable malloWor.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\malloWor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/malloWor.dir/build: malloWor.exe
.PHONY : CMakeFiles/malloWor.dir/build

CMakeFiles/malloWor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\malloWor.dir\cmake_clean.cmake
.PHONY : CMakeFiles/malloWor.dir/clean

CMakeFiles/malloWor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld" "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld" "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\cmake-build-debug" "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\cmake-build-debug" "C:\Users\vette\OneDrive\Bureau\langage c\mallocWorld\cmake-build-debug\CMakeFiles\malloWor.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/malloWor.dir/depend

