cmake_minimum_required (VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)

project (omprs)

add_subdirectory(sdk)
add_library(${PROJECT_NAME} SHARED main.cpp omprs.cpp core.cpp)

set_target_properties(omprs PROPERTIES OUTPUT_NAME "Rust")
set_target_properties(omprs PROPERTIES PREFIX "")

target_link_libraries(${PROJECT_NAME} PRIVATE
    OMP-SDK
)