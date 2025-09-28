
cmake_minimum_required(VERSION 3.10.0)
project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES 
    src/menuText.cpp
    src/lab5.cpp
)

set(HEADERS
    include/Utilities.hpp
    include/Stack.hpp
    include/menuText.hpp
    include/menu.hpp
)

add_executable(lab5 ${SOURCES} ${HEADERS})
