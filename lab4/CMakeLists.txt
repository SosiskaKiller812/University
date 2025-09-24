
cmake_minimum_required(VERSION 3.10.0)
project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES 
    src/Transport.cpp
    src/InputSystem.cpp
    src/Bicycle.cpp
    src/Car.cpp
    src/Carriage.cpp
    src/Utilities.cpp
    src/String.cpp
    src/lab4.cpp
)

set(HEADERS
    include/Transport.hpp
    include/InputSystem.hpp
    include/Bicycle.hpp
    include/Car.hpp
    include/Carriage.hpp
    include/Utilities.hpp
    include/String.hpp
    include/consts.hpp
)

add_executable(lab3 ${SOURCES} ${HEADERS})
