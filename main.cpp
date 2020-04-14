#include <iostream>
#include "rpmalloc.h"

int main() {
    // initialize allocator
    coherent_rpmalloc::rpmalloc_initialize();

    int size = 10;

    std::cout << "allocate\n";
    int *p = (int *)coherent_rpmalloc::rpmalloc(size * sizeof(int));

    std::cout << "initialize\n";
    for (int i = 0; i<size; i++) {
        p[i] = i;
    }

    std::cout << "display\n";
    for (int i = 0; i<size; i++) {
        std::cout << p[i] << std::endl;
    }

    std::cout << "release\n";
    coherent_rpmalloc::rpfree(p);

    std::cout << "bad access\n";
    for (int i = 0; i<size; i++) {
        std::cout << p[i] << std::endl;
    }
    std::cout << "done\n";


    coherent_rpmalloc::rpmalloc_finalize();
    return 0;
}
