cmake_minimum_required(VERSION 3.23)
project(FeedYaUp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FeedYaUp
        Customer.cpp
        Customer.h
        main.cpp
        Meal.cpp
        Meal.h
        Menu.cpp
        Menu.h
        Order.cpp
        Order.h
        System.cpp
        System.h
        Table.cpp
        Table.h)
