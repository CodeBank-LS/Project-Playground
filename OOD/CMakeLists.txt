cmake_minimum_required(VERSION 3.23)
project(OOD)

set(CMAKE_CXX_STANDARD 14)

include_directories("restaurant order system")

add_executable(OOD
        "restaurant order system/Customer.cpp"
        "restaurant order system/Customer.h"
        "restaurant order system/main.cpp"
        "restaurant order system/Meal.cpp"
        "restaurant order system/Meal.h"
        "restaurant order system/Menu.cpp"
        "restaurant order system/Menu.h"
        "restaurant order system/Order.cpp"
        "restaurant order system/Order.h"
        "restaurant order system/System.cpp"
        "restaurant order system/System.h"
        "restaurant order system/Table.cpp"
        "restaurant order system/Table.h"
        order.cpp)
