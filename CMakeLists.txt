cmake_minimum_required(VERSION 3.16)

project(Timetable VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp
    Time/Time.cpp
    Timetable/Timetable.cpp
    Model.cpp
    View.cpp
    )

target_include_directories(${PROJECT_NAME} PRIVATE
    .
    Time 
    Timetable
    )
