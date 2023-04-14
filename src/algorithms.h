#pragma once


#ifdef _WIN32
  #define ALGORITHMS_EXPORT __declspec(dllexport)
#else
  #define ALGORITHMS_EXPORT
#endif

ALGORITHMS_EXPORT void getInfo();
