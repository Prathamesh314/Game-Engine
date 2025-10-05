#pragma once

// macOS uses different macros for shared library export/import
#ifdef __APPLE__
    #ifdef HAZEL_BUILD_DLL
        #define HAZEL_API __attribute__((visibility("default")))
    #else
        #define HAZEL_API
    #endif
// this is for windows [way to import export dll files.]
#else
    #ifdef HAZEL_BUILD_DLL
        #define HAZEL_API __declspec(dllexport)
    #else
        #define HAZEL_API __declspec(dllimport)
    #endif
#endif
