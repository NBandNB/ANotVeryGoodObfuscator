cmake_minimum_required(VERSION 3.10)

project(ANotVeryGoodObfuscator VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
add_subdirectory(src)