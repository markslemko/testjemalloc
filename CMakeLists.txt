cmake_minimum_required(VERSION 3.15)
project(testrpmalloc)

set(CMAKE_CXX_STANDARD 14)

include_directories(rpmalloc)

list(APPEND SOURCES
        rpmalloc/rpmalloc.cpp
        rpmalloc/rpallocate_win.cpp
)

add_executable(testrpmalloc main.cpp ${SOURCES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(testrpmalloc Threads::Threads)

