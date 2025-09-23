
cmake_minimum_required(VERSION 3.10.0)
project(lab2 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES 
    src/String.cpp
    src/Utilities.cpp
    src/lab2.cpp
    src/menu.cpp
)

set(HEADERS
    include/String.hpp
    include/Utilities.hpp
    include/menu.hpp
)

add_executable(lab2 ${SOURCES} ${HEADERS})
