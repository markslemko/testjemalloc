cmake_minimum_required(VERSION 3.15)
project(testmimalloc)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(mimalloc)
include_directories(mimalloc/include)

list(APPEND SOURCES
        mimalloc/src/alloc.c
        mimalloc/src/alloc-aligned.c
        mimalloc/src/alloc-posix.c
        mimalloc/src/arena.c
        mimalloc/src/bitmap.inc.c
        mimalloc/src/heap.c
        mimalloc/src/init.c
        mimalloc/src/options.c
        mimalloc/src/os.c
        mimalloc/src/page.c
        mimalloc/src/random.c
        mimalloc/src/region.c
        mimalloc/src/segment.c
        mimalloc/src/stats.c
)

add_executable(testmimalloc main.cpp ${SOURCES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(testmimalloc Threads::Threads)

