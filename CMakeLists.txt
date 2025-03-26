# Set the minimum CMake version required for this project
cmake_minimum_required(VERSION 3.10)
# Set the name of the project, if you want to modify your project name just change MY_PROJECT_NAME by whatever you want
set(PROJECT_NAME "MY_PROJECT_NAME")

# naming the project
project(${PROJECT_NAME})

# Clear the former CMakeCache.txt
if(EXISTS "${CMAKE_BINARY_DIR}/CMakeCache.txt")
    file(REMOVE "${CMAKE_BINARY_DIR}/CMakeCache.txt")
endif()

set(CMAKE_CXX_STANDARD 20)

# Add executable and glad.c
add_executable(${PROJECT_NAME} main.cpp Libs/glad/glad.c)

# Properly include the Glad header files for this target
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Libs)

# Find OpenGL
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# Detect OS and set appropriate settings
if (WIN32)
    message(STATUS "Compiling on Windows")

    # Ensure MinGW is used (for Windows compatibility)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

            # Automatically find GCC and G++ in the system
            find_program(CMAKE_C_COMPILER NAMES gcc)
            find_program(CMAKE_CXX_COMPILER NAMES g++)

            if (NOT CMAKE_C_COMPILER OR NOT CMAKE_CXX_COMPILER)
                message(FATAL_ERROR "GCC or G++ not found. Please ensure they are installed and available in PATH.")
            endif()

        #(Previous implementation)you can find where are your gcc and g++ compilers by using "where gcc" or "where g++" in a powershell
        #set(CMAKE_C_COMPILER "C:\\ProgramData\\mingw64\\mingw64\\bin\\gcc.exe")
        #set(CMAKE_CXX_COMPILER "C:\\ProgramData\\mingw64\\mingw64\\bin\\g++.exe")

    endif()

    # Set GLFW static library for Windows (Precompiled for MinGW)
    set(GLFW_LIBRARY_PATH "${CMAKE_SOURCE_DIR}/Libs/GLFW/libglfw3.a")
    set(GLUT_LIBRARY_PATH "${CMAKE_SOURCE_DIR}/Libs/GL/libfreeglut.a")
    set(GLEW_LIBRARY_PATH "${CMAKE_SOURCE_DIR}/Libs/GL/libglew32.a")

    # Link against OpenGL and necessary Windows libraries
    target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW_LIBRARY_PATH} ${GLUT_LIBRARY_PATH} ${GLEW_LIBRARY_PATH} OpenGL::GL glu32 gdi32 winmm)

elseif (UNIX)
    message(STATUS "Compiling on Linux")

    # Find GLFW and GLUT (installed on system)
    # install them by using your package manager, Arch:sudo pacman -S glfw glu freeglut Ubuntu:sudo apt install libglfw3-dev libgl1-mesa-dev freeglut3 freeglut3-dev glew-utils binutils-gold
    find_package(glfw3 REQUIRED)
    find_package(GLUT REQUIRED)
    find_package(glew REQUIRED)

    # Link against OpenGL, GLFW, and GLUT
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw GLU glut glew)
endif()

