#pragma once

// Operating System
#undef FAT_OS_WINDOWS
#undef FAT_OS_ANDROID
#undef FAT_OS_LINUX

#if defined(_WIN64) || defined(_WIN32)
#  define FAT_OS_WINDOWS 1
#elif defined(__ANDROID__)
#  define FAT_OS_ANDROID 1
#elif defined(__linux__)
#  define FAT_OS_LINUX   1
#else
#  error Unsupported Operating System
#endif

// Build Configuration
#if defined(FAT_DEBUG_BUILD)
#  define FAT_DEBUG_BUILD   1
#  define FAT_RELEASE_BUILD 0
#elif defined(FAT_RELEASE_BUILD)
#  define FAT_DEBUG_BUILD   0
#  define FAT_RELEASE_BUILD 1
#else
#  error Where is the build configuration?
#endif

#if FAT_OS_WINDOWS && FAT_DEBUG_BUILD
// Enable run-time memory check for debug builds
// https://github.com/kasicass/blog/blob/master/fat3d/2020_09_11_memory_leak_detection.md
#  define _CRTDBG_MAP_ALLOC
#  include <crtdbg.h>
#endif

// vulkan headers
#include <vulkan/vulkan.h>

// c headers
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// c++ headers
#include <vector>

const char* GetErrorString(VkResult result);

// result < 0 means error
// https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkResult.html
#if FAT_DEBUG_BUILD
#  ifndef VKCHK
#  define VKCHK_DECL VkResult result
#  define VKCHK(x) \
   { \
     result = (x); \
     if (result < 0) \
     { \
       printf("%s Error: %s\n", #x, GetErrorString(result)); \
       assert(0); \
     } \
   }
#  endif
#else
#  ifndef VKCHK
#  define VKCHK_DECL
#  define VKCHK(x) x
#  endif
#endif
