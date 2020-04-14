#pragma once
#ifndef RPMALLOC_NEW_DELETE_H
#define RPMALLOC_NEW_DELETE_H

// ----------------------------------------------------------------------------
// This header provides convenient overrides for the new and
// delete operations in C++.
//
// This header should be included in only one source file!
// ---------------------------------------------------------------------------

#if defined(__cplusplus)
#include <new>
#include <rpmalloc.h>

void operator delete(void* p) noexcept { coherent_rpmalloc::rpfree(p); };
void operator delete[](void* p) noexcept { coherent_rpmalloc::rpfree(p); };

void* operator new(std::size_t n) noexcept(false) { return coherent_rpmalloc::rpmalloc(n); }
void* operator new[](std::size_t n) noexcept(false) { return coherent_rpmalloc::rpmalloc(n); }

void* operator new  (std::size_t n, const std::nothrow_t& tag) noexcept { (void)(tag); return coherent_rpmalloc::rpmalloc(n); }
void* operator new[](std::size_t n, const std::nothrow_t& tag) noexcept { (void)(tag); return coherent_rpmalloc::rpmalloc(n); }

#if (__cplusplus >= 201402L || _MSC_VER >= 1916)
void operator delete  (void* p, std::size_t n) noexcept { coherent_rpmalloc::rpfree(p); };
void operator delete[](void* p, std::size_t n) noexcept { coherent_rpmalloc::rpfree(p); };
#endif

#endif

#endif // RPMALLOC_NEW_DELETE_H