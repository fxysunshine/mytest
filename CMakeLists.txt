cmake_minimum_required(VERSION 2.8.12.1)

SET(CMAKE_C_FLAGS "$ENV{CFLAGS} -g -Wall")
SET(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -g -std=c++17 -pthread")

# Project name.
project(mytest)

macro(SINGLE_BINARY_TARGET target)
  set(${target}_SRCS ${target}.cc)
  set(${target}_TARGET ${target})
  add_executable(${${target}_TARGET} ${${target}_SRCS})
endmacro()

macro(SINGLE_BINARY_TARGET_C target)
  set(${target}_SRCS ${target}.c)
  set(${target}_TARGET ${target})
  add_executable(${${target}_TARGET} ${${target}_SRCS})
endmacro()

# add subdirectory targets.
add_subdirectory(cc)
add_subdirectory(c)
