
cmake_minimum_required(VERSION 3.10.0)
project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES 
    src/BusFlight.cpp
    src/InputSystem.cpp
    src/lab7.cpp
    src/Time.cpp
    src/utilities.cpp
)

set(HEADERS
    include/BusFlight.hpp
    include/consts.hpp
    include/InputSystem.hpp
    include/Time.hpp
    include/utilities.hpp
)

add_executable(lab7 ${SOURCES} ${HEADERS})
