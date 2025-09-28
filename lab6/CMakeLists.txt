
cmake_minimum_required(VERSION 3.10.0)
project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES 
    src/CargoTransport.cpp
    src/InputSystem.cpp
    src/LinkedList.cpp
    src/Auto.cpp
    src/Plane.cpp
    src/Train.cpp
    src/String.cpp
    src/Utilities.cpp
    src/lab6.cpp
)

set(HEADERS
    include/CargoTransport.hpp
    include/InputSystem.hpp
    include/LinkedList.hpp
    include/Auto.hpp
    include/Plane.hpp
    include/Train.hpp
    include/consts.hpp
    include/String.hpp
    include/Utilities.hpp
)

add_executable(lab6 ${SOURCES} ${HEADERS})
