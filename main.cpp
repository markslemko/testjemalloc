#include <iostream>
#include "jemalloc/jemalloc.h"

int main() {
    int size = 10;

    std::cout << "allocate\n";
    int *p = (int *)je_malloc(size * sizeof(int));

    std::cout << "initialize\n";
    for (int i = 0; i<size; i++) {
        p[i] = i;
    }

    std::cout << "display\n";
    for (int i = 0; i<size; i++) {
        std::cout << p[i] << std::endl;
    }

    std::cout << "release\n";
    je_free(p);

    std::cout << "bad access\n";
    for (int i = 0; i<size; i++) {
        std::cout << p[i] << std::endl;
    }
    std::cout << "done\n";


    return 0;
}
