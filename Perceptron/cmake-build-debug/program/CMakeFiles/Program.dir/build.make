# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Pliki\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Pliki\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Studia\InteligentnaAnalizaDanych

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug

# Include any dependencies generated for this target.
include program/CMakeFiles/Program.dir/depend.make

# Include the progress variables for this target.
include program/CMakeFiles/Program.dir/progress.make

# Include the compile flags for this target's objects.
include program/CMakeFiles/Program.dir/flags.make

program/CMakeFiles/Program.dir/src/main.cpp.obj: program/CMakeFiles/Program.dir/flags.make
program/CMakeFiles/Program.dir/src/main.cpp.obj: program/CMakeFiles/Program.dir/includes_CXX.rsp
program/CMakeFiles/Program.dir/src/main.cpp.obj: ../program/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object program/CMakeFiles/Program.dir/src/main.cpp.obj"
	cd /d D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug\program && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Program.dir\src\main.cpp.obj -c D:\Studia\InteligentnaAnalizaDanych\program\src\main.cpp

program/CMakeFiles/Program.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Program.dir/src/main.cpp.i"
	cd /d D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug\program && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Studia\InteligentnaAnalizaDanych\program\src\main.cpp > CMakeFiles\Program.dir\src\main.cpp.i

program/CMakeFiles/Program.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Program.dir/src/main.cpp.s"
	cd /d D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug\program && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Studia\InteligentnaAnalizaDanych\program\src\main.cpp -o CMakeFiles\Program.dir\src\main.cpp.s

# Object files for target Program
Program_OBJECTS = \
"CMakeFiles/Program.dir/src/main.cpp.obj"

# External object files for target Program
Program_EXTERNAL_OBJECTS =

program/Program.exe: program/CMakeFiles/Program.dir/src/main.cpp.obj
program/Program.exe: program/CMakeFiles/Program.dir/build.make
program/Program.exe: program/CMakeFiles/Program.dir/linklibs.rsp
program/Program.exe: program/CMakeFiles/Program.dir/objects1.rsp
program/Program.exe: program/CMakeFiles/Program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Program.exe"
	cd /d D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug\program && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Program.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
program/CMakeFiles/Program.dir/build: program/Program.exe

.PHONY : program/CMakeFiles/Program.dir/build

program/CMakeFiles/Program.dir/clean:
	cd /d D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug\program && $(CMAKE_COMMAND) -P CMakeFiles\Program.dir\cmake_clean.cmake
.PHONY : program/CMakeFiles/Program.dir/clean

program/CMakeFiles/Program.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Studia\InteligentnaAnalizaDanych D:\Studia\InteligentnaAnalizaDanych\program D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug\program D:\Studia\InteligentnaAnalizaDanych\cmake-build-debug\program\CMakeFiles\Program.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : program/CMakeFiles/Program.dir/depend
