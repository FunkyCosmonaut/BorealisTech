cmake_minimum_required(VERSION 3.10)
project(Impetus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GLFW
find_package(glfw3 REQUIRED)

# GLAD
add_subdirectory(ext/glad)

# Engine
include_directories(include/)
file(GLOB_RECURSE IMPETUS_SRC src/*.cpp)
add_library(Impetus STATIC ${IMPETUS_SRC})

target_link_libraries(Impetus glfw glad)

# Example
add_executable(ImpetusExample examples/main.cpp)
target_link_libraries(ImpetusExample Impetus)