#ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <assert.h>

namespace coherent_rpmalloc
{
	void* rpmalloc_allocate_memory_external(size_t bytes) {
		void* ptr = VirtualAlloc(0, bytes, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		if (!ptr) {
			assert(ptr && "Failed to map virtual memory block");
			return 0;
		}
		return ptr;
	}

	void rpmalloc_deallocate_memory_external(void* ptr) {
		if (!VirtualFree(ptr,  0, MEM_RELEASE)) {
			assert(ptr && "Failed to unmap virtual memory block");
		}
	}
}