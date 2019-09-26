cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")
project(learnVulkan)

if(UNIX)
    set(CMAKE_EXE_LINKER_FLAGS "-fno-pie -no-pie")
    add_definitions("-Ofast -std=c++17")
    add_definitions(-DVK_USE_PLATFORM_XCB_KHR)
elseif(WIN32)
    add_definitions(-DNOMINMAX)
    add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)
endif()

FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/base)
include_directories(${PROJECT_SOURCE_DIR}/include/external)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(src)