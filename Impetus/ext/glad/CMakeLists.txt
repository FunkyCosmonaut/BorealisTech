cmake_minimum_required(VERSION 3.10)
project(glad)

set(GLAD_SRC src/glad.c)
set(GLAD_INCLUDE include/)

add_library(glad SHARED ${GLAD_SRC})
target_include_directories(glad PUBLIC ${GLAD_INCLUDE})
