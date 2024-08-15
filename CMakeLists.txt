cmake_minimum_required(VERSION 3.14)

project(3D_curves_hierarchy)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (UNIX)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

find_package(OpenMP REQUIRED)

add_subdirectory(lib)

set(HDR
    app/solution.h
)

set(SRC
    app/main.cpp
    app/solution.cpp
)

add_executable(3D_curves_hierarchy ${SRC} ${HDR})

target_include_directories(3D_curves_hierarchy PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/Circle"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/Curve"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/Ellipse"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/Helix"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/Point"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/Directives"
)

target_link_libraries(3D_curves_hierarchy PUBLIC curves_lib)

if(OpenMP_CXX_FOUND)
    target_link_libraries(3D_curves_hierarchy PUBLIC OpenMP::OpenMP_CXX)
endif()