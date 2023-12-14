cmake_minimum_required(VERSION 3.1...3.27)

project(3dep-explorer VERSION 0.1 LANGUAGES CXX)

add_subdirectory(${CMAKE_SOURCE_DIR}/cpp/third_party/pybind11)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/cpp/src/*.cpp ${CMAKE_SOURCE_DIR}/cpp/src/*.h)
file(GLOB_RECURSE TEST_FILES ${CMAKE_SOURCE_DIR}/cpp/test/*.cpp ${CMAKE_SOURCE_DIR}/cpp/test/*.h)
file(GLOB_RECURSE PYBIND_DEFINIITON_FILES ${CMAKE_SOURCE_DIR}/cpp/pybind/*.cpp ${CMAKE_SOURCE_DIR}/cpp/pybind/*.h)

set(DEPENDENCY_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/cpp/third_party/eigen)

add_library(cppalgs SHARED ${SRC_FILES})
target_include_directories(cppalgs PRIVATE ${DEPENDENCY_INCLUDE_DIRS})

add_executable(tests ${TEST_FILES})
target_link_libraries(tests PRIVATE cppalgs)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/cpp/src ${CMAKE_SOURCE_DIR}/cpp/third_party/Catch2/single_include ${DEPENDENCY_INCLUDE_DIRS})

pybind11_add_module(cpphelpers ${PYBIND_DEFINIITON_FILES})
target_include_directories(cpphelpers PRIVATE ${CMAKE_SOURCE_DIR}/cpp/src ${DEPENDENCY_INCLUDE_DIRS})
target_link_libraries(cpphelpers PRIVATE cppalgs)
