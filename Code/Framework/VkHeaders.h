#pragma once

// vulkan headers
#include <vulkan/vulkan.h>

// c headers
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// c++ headers
#include <vector>

#if defined(FAT_DEBUG_BUILD)
#  define FAT_DEBUG_BUILD   1
#  define FAT_RELEASE_BUILD 0
#elif defined(FAT_RELEASE_BUILD)
#  define FAT_DEBUG_BUILD   0
#  define FAT_RELEASE_BUILD 1
#else
#  error Where is the build configuration?
#endif

const char* GetErrorString(VkResult result);

// result < 0 means error
// https://www.khronos.org/registry/vulkan/specs/1.2-extensions/man/html/VkResult.html
#if FAT_DEBUG_BUILD
#  ifndef VKCHK
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
#  define VKCHK(x) { (void)result; x; }
#  endif
#endif
