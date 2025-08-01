#pragma once

#if defined(_WIN32) || defined(__CYGWIN__)
#ifdef CENGINE_BUILD
#define CENGINE_API __declspec(dllexport)
#else
#define CENGINE_API __declspec(dllimport)
#endif
#else
#define CENGINE_API
#endif