
cmake_minimum_required(VERSION 3.10.0)
project(lab_1 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCES 
    src/lab1.cpp
    src/Matrix.cpp
    src/InputSystem.cpp
    src/menu.cpp
)

set(HEADERS
    include/lab1.hpp
    include/Matrix.hpp
    include/InputSystem.hpp
    include/menu.hpp
)

add_executable(lab1 ${SOURCES} ${HEADERS})
