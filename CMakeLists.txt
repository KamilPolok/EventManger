cmake_minimum_required(VERSION 3.10)

project(Timetable)

add_executable(${PROJECT_NAME} main.cpp 
    Time/Time.cpp
    Timetable/Timetable.cpp
    )

target_include_directories(${PROJECT_NAME} PRIVATE 
    Time 
    Timetable
    )
