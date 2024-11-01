/* ---Do not change anything--- */
#ifndef __PREPROCESS_H
#define __PREPROCESS_H
#if !defined(__cplusplus)
#error C++ is required.
#elif __cplusplus <= 201103L
#error C++14 or higher is required.
#elif __cplusplus == 201402L
#pragma message("Warning: the project uses C++20 thus some features may be unstable and not working as intended. Consider updating.")
#elif __cplusplus == 201703L
#pragma message("Warning: the project uses C++20 thus some features may be unstable and not working as intended. Consider updating.")
#elif __cplusplus >= 202002L && __cplusplus < 202302L
#pragma message("Building the project...")
#elif __cplusplus >= 202302L
#error C++23 and later isn't supported.
#endif /* __cplusplus */
#if defined(_MSC_VER)
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)
#define NORETURN __declspec(noreturn)
#define RESTRICT __restrict
#define FORCEINLINE __forceinline
#elif defined(__GNUC__)
#define DLLEXPORT __attribute__((dllexport))
#define DLLIMPORT __attribute__((dllimport))
#define NORETURN __attribute__((noreturn))
#define RESTRICT __restrict__
#define FORCEINLINE inline __attribute__((always_inline))
#endif /* _MSC_VER */
#ifdef EXPORT
#define API DLLIMPORT
#else
#define API DLLEXPORT
#endif /* EXPORT */
#endif /* __PREPROCESS_H */