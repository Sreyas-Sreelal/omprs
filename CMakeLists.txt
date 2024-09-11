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

if(TARGET_BUILD_ARCH MATCHES "(i[3-6]86|x86)" AND NOT TARGET_BUILD_ARCH MATCHES "(x64|x86_64|amd64)")
    set(CMAKE_C_FLAGS "-m32 ${CMAKE_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "-m32 ${CMAKE_CXX_FLAGS}")
    set(CMAKE_SIZEOF_VOID_P 4)
endif ()
