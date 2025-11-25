
cmake_minimum_required(VERSION 3.10.0)
project(lab8 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
    src/lab8.cpp
    src/Ring.cpp
    src/Iterator.cpp
    src/Algorithms.cpp
)

set(HEADERS
    include/Ring.hpp
    include/Iterator.hpp
    include/Algorithms.hpp
    include/RingMenu.hpp
    include/Utilities.hpp
)

add_executable(lab8 ${SOURCES} ${HEADERS})
