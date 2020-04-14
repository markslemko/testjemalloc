#include <iostream>
#include "rpmalloc_new_delete.h"
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


    // test really huge allocations
    char* largeArray = new char[1024 * 1024 * 1024];
    char* largeArray2 = new char[1024 * 1024 * 1024];
    char* largeArray3 = new char[1024 * 1024 * 1024];
    char* largeArray4 = new char[1024 * 1024 * 1024];
    
    largeArray[1000] = 120;
    largeArray[1000000] = 121;
    largeArray[1000000000] = 122;
    largeArray2[1000000000] = 123;
    
    printf("%zx %d\n", largeArray[999], largeArray[1000]);
    printf("%zx %d\n", largeArray[999999], largeArray[1000000]);
    printf("%zx %d\n", largeArray[999999999], largeArray[1000000000]);
    printf("%zx %d\n", largeArray2[999999999], largeArray2[1000000000]);
    
    delete[] largeArray;
    delete[] largeArray2;
    delete[] largeArray3;
    delete[] largeArray4;
    
    printf("done\n");

    coherent_rpmalloc::rpmalloc_finalize();
    return 0;
}
