cmake_minimum_required(VERSION 3.14)
project(The_sword_refers_to_offer)

set(CMAKE_CXX_STANDARD 11)
#MESSAGE("info message ${PROJECT_SOURCE_DIR}")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(01_AssignmentOperator)
add_subdirectory(02_Singleton)
add_subdirectory(03_Duplicate_Numbers_in_an_array)
add_subdirectory(04_Lookup_of_two_dimensional_array)
add_subdirectory(05_replace_blank)
add_subdirectory(06_Print_from_the_tail_to_the_first)
add_subdirectory(07_Restore_Binary_Tree)