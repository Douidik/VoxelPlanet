file(GLOB_RECURSE VOXENG_SOURCES [a-zA-Z0-9]*.hpp [a-zA-Z0-9]*.cpp)

add_library(VoxelEngine STATIC ${VOXENG_SOURCES})

target_link_libraries(VoxelEngine PRIVATE ${CONAN_LIBS})
target_include_directories(VoxelEngine PUBLIC ./)
target_precompile_headers(VoxelEngine PRIVATE Core/PCH.hpp)

# Meta detection

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  add_compile_definitions(VOXENG_WINDOWS_OS)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
  add_compile_definitions(VOXENG_MAC_OS)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  add_compile_definitions(VOXENG_LINUX_OS)
else()
  message(FATAL_ERROR "Voxel Planet is not yet compatible with ${CMAKE_SYSTEM_NAME}")
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
  add_compile_definitions(VOXENG_RELEASE_MODE)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  add_compile_definitions(VOXENG_DEBUG_MODE)
else()
  message(WARNING "Unknown build type ${CMAKE_BUILD_TYPE} defaulted to Release mode")
  add_compile_definitions(VOXENG_RELEASE_MODE)
