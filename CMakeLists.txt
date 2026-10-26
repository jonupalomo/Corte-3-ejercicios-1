cmake_minimum_required(VERSION 3.16)

project(exercism_exercises CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS date_time)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/clock_test.cpp" OR EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/meetup_test.cpp")
    find_package(Catch2 3 QUIET)
    if(NOT Catch2_FOUND)
        message(WARNING "Catch2 no está instalado; se omitirán las pruebas.")
    endif()
endif()

enable_testing()

# ---------------------------------------------------------
# Ejercicio 1: Clock
# ---------------------------------------------------------
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/clock.cpp")
    add_library(clock clock.cpp clock.h)

    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/clock_test.cpp" AND Catch2_FOUND)
        add_executable(test_clock clock_test.cpp)
        target_link_libraries(test_clock PRIVATE clock Catch2::Catch2WithMain)
        add_test(NAME clock_tests COMMAND test_clock)
    endif()
endif()

# ---------------------------------------------------------
# Ejercicio 2: Meetup
# ---------------------------------------------------------
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/meetup.cpp")
    add_library(meetup meetup.cpp meetup.h)
    target_link_libraries(meetup PUBLIC Boost::date_time)

    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/meetup_test.cpp" AND Catch2_FOUND)
        add_executable(test_meetup meetup_test.cpp)
        target_link_libraries(test_meetup PRIVATE meetup Catch2::Catch2WithMain Boost::date_time)
        add_test(NAME meetup_tests COMMAND test_meetup)
    endif()
endif()

# ---------------------------------------------------------
# Programas adicionales
# ---------------------------------------------------------
foreach(program IN ITEMS ATM AuctionSystem UndergroundSystem)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${program}.cpp")
        add_executable(${program} "${program}.cpp")
    endif()
endforeach()
