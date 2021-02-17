project(VoxelEngine
  DESCRIPTION "Custom engine used in the Voxel planet game"
  LANGUAGES CXX)

project(VoxelPlanet
  DESCRIPTION "Open Source C++20 Voxel Game heavily inspired by Minecraft"
  LANGUAGES CXX)

project(Test
  DESCRIPTION "Voxel planet test suite"
  LANGUAGES CXX)

cmake_minimum_required(VERSION 3.17)

# The project use C++20
set(CMAKE_CXX_STANDARD 20)

# We have to export compile commands for the lsp
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Custom output for libraries and executables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)

# Setup dependencies management with conan
include(bin/conanbuildinfo.cmake)
conan_basic_setup()

# Adding the subdirectories
add_subdirectory(src/Engine)
add_subdirectory(src/Game)
add_subdirectory(src/Test)

# Building parameters

option(ENABLE_TESTS "Build and run the test suite" ON)

