file(GLOB_RECURSE VOXPLT_SOURCES [a-zA-Z0-9]*.hpp [a-zA-Z0-9]*.cpp)

add_executable(VoxelPlanet ${VOXPLT_SOURCES})
target_link_libraries(VoxelPlanet PRIVATE VoxelEngine)
