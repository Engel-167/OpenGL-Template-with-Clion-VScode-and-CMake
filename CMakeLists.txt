cmake_minimum_required(VERSION 3.10)
project(Lab1)

# Evitar la caché anterior eliminando el archivo CMakeCache.txt
if(EXISTS "${CMAKE_BINARY_DIR}/CMakeCache.txt")
    file(REMOVE "${CMAKE_BINARY_DIR}/CMakeCache.txt")
endif()

set(CMAKE_CXX_STANDARD 20)

# Add executable and glad.c
add_executable(Lab1 main.cpp Libs/glad/glad.c)

# Properly include the Glad header files for this target
target_include_directories(Lab1 PRIVATE ${CMAKE_SOURCE_DIR}/Libs)

# Find OpenGL
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# Detect OS and set appropriate settings
if (WIN32)
    message(STATUS "Compiling on Windows")

    # Ensure MinGW is used (for Windows compatibility)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_C_COMPILER "C:\\ProgramData\\mingw64\\mingw64\\bin\\gcc.exe")
        set(CMAKE_CXX_COMPILER "C:\\ProgramData\\mingw64\\mingw64\\bin\\g++.exe")    
    endif()

    # Set GLFW static library for Windows (Precompiled for MinGW)
    set(GLFW_LIBRARY_PATH "${CMAKE_SOURCE_DIR}/Libs/GLFW/libglfw3.a")
    set(GLUT_LIBRARY_PATH "${CMAKE_SOURCE_DIR}/Libs/GL/libfreeglut.a")

    # Link against OpenGL and necessary Windows libraries
    target_link_libraries(Lab1 PRIVATE ${GLFW_LIBRARY_PATH} ${GLUT_LIBRARY_PATH} OpenGL::GL glu32 gdi32 winmm)

elseif (UNIX)
    message(STATUS "Compiling on Linux")

    # Find GLFW and GLUT (installed on system)
    find_package(glfw3 REQUIRED)
    find_package(GLUT REQUIRED)

    # Link against OpenGL, GLFW, and GLUT
    target_link_libraries(Lab1 PRIVATE OpenGL::GL glfw GLU glut)
endif()

