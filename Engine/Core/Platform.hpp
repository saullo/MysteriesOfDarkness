#pragma once

#if defined(_WIN32) || defined(_WIN64)
#define PLATFORM_IS_WINDOWS true
#else
#error "Unsupported Platform"
#endif

#if PLATFORM_IS_WINDOWS
#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)
#endif