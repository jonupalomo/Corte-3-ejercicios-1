cmake_minimum_required(VERSION 3.16)
project(Corte3_Entrega1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS date_time)

# Bibliotecas de Exercism
add_library(clock clock.cpp clock.h)
add_library(meetup meetup.cpp meetup.h)
target_link_libraries(meetup PUBLIC Boost::date_time)

# Programas ejecutables para los ejercicios
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/underground_system.cpp")
    add_executable(underground_system underground_system.cpp)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/atm_machine.cpp")
    add_executable(atm_machine atm_machine.cpp)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/auction_system.cpp")
    add_executable(auction_system auction_system.cpp)
endif()
