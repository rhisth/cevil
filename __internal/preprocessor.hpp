/* ---Do not change anything--- */
#ifndef PREPROCESS_H
#define PREPROCESS_H
#define _CRT_SECURE_NO_WARNINGS
#if !defined(__cplusplus)
#error C++ is required.
#elif __cplusplus <=  201402L
#error C++17 or higher is required.
#elif __cplusplus == 201703L
#pragma message("Warning: the project uses C++20 thus some features may be unstable and not working as intended. Consider updating.")
/* Bindings */
#define CXX17
#undef constinit
#define constinit const
#undef consteval
#define consteval constexpr
#include <ctime>
#elif __cplusplus >= 202002L && __cplusplus < 202302L
#pragma message("Building the project...")
#include <chrono>
#include <ranges>
#include <semaphore>
#elif __cplusplus >= 202302L
#error C++23 and later standards aren't supported.
#endif /* __cplusplus */
#include <cstdio> /* C */
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <utility> /* utility */
#include <algorithm>
#include <functional>
#include <random>
#include <array> /* STL */
#include <vector>
#include <future> /* multithreading */
#include <mutex>
#include <atomic>
#include <SDL.h> /* SDL */
#if defined(_MSC_VER)
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)
#define RESTRICT __restrict
#define FORCEINLINE __forceinline
#elif defined(__GNUC__)
#define DLLEXPORT __attribute__((dllexport))
#define DLLIMPORT __attribute__((dllimport))
#define RESTRICT __restrict__
#define FORCEINLINE inline __attribute__((always_inline))
#endif /* compiler check */
#ifdef EXPORT
#define API DLLIMPORT
#else
#define API DLLEXPORT
#endif /* EXPORT */
#endif /* PREPROCESS_H */