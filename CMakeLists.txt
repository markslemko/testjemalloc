cmake_minimum_required(VERSION 3.15)
project(testjemalloc)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(jemalloc)
include_directories(jemalloc/include)

if (CMAKE_SYSTEM_NAME MATCHES Windows)
message("including windows compatibility files")
include_directories(jemalloc/include/msvc_compat)
endif ()

list(APPEND SOURCES
        jemalloc/src/arena.c
        jemalloc/src/base.c
        jemalloc/src/bitmap.c
        jemalloc/src/chunk.c
        jemalloc/src/chunk_dss.c
        jemalloc/src/chunk_mmap.c
        jemalloc/src/ckh.c
        jemalloc/src/ctl.c
        jemalloc/src/extent.c
        jemalloc/src/huge.c
        jemalloc/src/jemalloc.c
        jemalloc/src/mb.c
        jemalloc/src/mutex.c
        jemalloc/src/prof.c
        jemalloc/src/quarantine.c
        jemalloc/src/rtree.c
        jemalloc/src/stats.c
        jemalloc/src/tcache.c
        jemalloc/src/tsd.c
        jemalloc/src/util.c
)

add_executable(testjemalloc main.cpp ${SOURCES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(testjemalloc Threads::Threads)

