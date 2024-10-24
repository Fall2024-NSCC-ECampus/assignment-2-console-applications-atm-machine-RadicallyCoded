cmake_minimum_required(VERSION 3.27)
project(ATM_Machine)

set(CMAKE_CXX_STANDARD 17)

add_executable(ATM_Machine main.cpp
        menus.cpp
        Account.cpp
)
