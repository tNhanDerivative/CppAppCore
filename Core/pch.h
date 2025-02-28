#pragma once
#include<memory>
#include<stdint.h>
#include <functional>

// Runtime assert
#define MY_ASSERT assert

// Static assert
#if defined(__clang__) || defined(__gcc__)
	#define MY_STATIC_ASSERT _Static_assert
#else
	#define MY_STATIC_ASSERT static_assert
#endif

#if defined(__clang__) || defined(_gcc__)
	#define MY_FORCE_INLINE __attribute__((always_inline)) inline
	#define MY_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
	#define MY_FORCE_INLINE __forceinline
	#define MY_NOINLINE __declspec(noinline)
#else
	#define MY_FORCE_INLINE inline
	#define MY_NOINLINE
#endif

#define MY_FREE_MEMORY(memory) if (memory != nullptr) { delete memory; memory = nullptr; }

#define BIND_EVENT_FUNCTION(function) [this](auto&... args) -> decltype(auto)\
	{ return this->function(std::forward<decltype(args)>(args)...); }