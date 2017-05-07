file(GLOB_RECURSE EXT_SOURCES "*.cpp" "*.hpp")
add_library(ext EXCLUDE_FROM_ALL ${EXT_SOURCES})
target_link_libraries(ext)
