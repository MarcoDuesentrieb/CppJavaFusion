cmake_minimum_required(VERSION 3.10)

project("Fusion")

find_package(JNI REQUIRED)
find_package(Threads REQUIRED)
if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()

add_executable(main src/main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${JNI_INCLUDE_DIRS})

target_link_libraries(main ${JNI_LIBRARIES} Threads::Threads)
