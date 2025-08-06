#pragma once

#if defined(CENGINE_WINDOWS)
#ifdef CENGINE_BUILD
#define CENGINE_API __declspec(dllexport)
#else
#define CENGINE_API __declspec(dllimport)
#endif
#else
#define CENGINE_API
#endif
