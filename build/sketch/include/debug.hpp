#line 1 "c:\\source\\repos\\ed-irrigation\\include\\debug.hpp"
// "Copyright 2021 Francisco Aguilera"

#ifndef INCLUDE_DEBUG_HPP_
#define INCLUDE_DEBUG_HPP_

#define DEBUG
// #define TEST

#if defined(DEBUG)
#include "logger.hpp"
extern falven::ad::Logger
    debug;  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
#define DEBUG_BEGIN(baud) debug.begin(baud);
#define DEBUG_LOCATION()                                            \
  debug << millis() << "ms: " << __FILE__ << ':' << __LINE__ << ' ' \
        << __PRETTY_FUNCTION__ << endl;
#define DEBUG_PRINTLN(str)                                          \
  debug << millis() << "ms: " << __FILE__ << ':' << __LINE__ << ' ' \
        << __PRETTY_FUNCTION__ << ' ' << str << endl;
#elif defined(TEST)
#include <iostream>
#define DEBUG_LOCATION()                                                 \
  std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ \
            << std::endl;
#define DEBUG_PRINTLN(str)                                               \
  std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ \
            << ' ' << str << std::endl;
#else
#define DEBUG_BEGIN(baud)
#define DEBUG_LOCATION()
#define DEBUG_PRINTLN(str)
#endif

#endif  // SRC_DEBUG_HPP_