#pragma once

#if defined(ENGINE_WINDOWS)
#ifdef ENGINE_BUILD
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#error Custom Engine only supports Windows for now.
#endif
