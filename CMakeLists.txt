cmake_minimum_required (VERSION 2.6)

project(oj-leetcode-solution)


include_directories("include/")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/")
link_libraries(gtest) 

aux_source_directory("src/" DIR_SRCS)
add_executable(oj ${DIR_SRCS})
