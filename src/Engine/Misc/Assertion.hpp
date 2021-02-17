#ifndef VOXENG_ASSERTION_HPP
#define VOXENG_ASSERTION_HPP

#define VOXENG_FORCE_SEMICOLON                                                                                                                                 \
    enum                                                                                                                                                       \
    {                                                                                                                                                          \
    }

#ifdef VOXENG_DEBUG_TYPE
#if defined(VOXENG_WINDOWS_OS)
#define VOXENG_DEBUGBREAK() __debugbreak()
#elif defined(VOXENG_MAC_OS)
#define VOXENG_DEBUGBREAK() __builtin_trap()
#elif defined(VOXENG_LINUX_OS)
#include <signal.h>
#define VOXENG_DEBUGBREAK() raise(SIGTRAP)
#endif
#define VOXENG_DEBUGBREAK()
#endif

#ifdef VOXENG_DEBUG_TYPE

#define VOXENG_ASSERT(condition, ...)                                                                                                                          \
    if (static_cast<bool>(condition))                                                                                                                          \
    {                                                                                                                                                          \
        VOXENG_LOG_ERROR(__VA_ARGS__);                                                                                                                         \
        VOXENG_DEBUGBREAK();                                                                                                                                   \
    }                                                                                                                                                          \
    VOXENG_FORCE_SEMICOLON

#define VOXENG_ERROR(...) VOXENG_ASSERT(false, __VA_ARGS__)

#else

#define VOXENG_ASSERT(condition, ...)
#define VOXENG_ERROR(...)

#endif

#endif
