cmake_minimum_required(VERSION 3.21)
project(raspi_gpio_c C)

set(CMAKE_C_STANDARD 11)

include_directories(lib)

add_executable(raspi_gpio_c
        lib/sysfs_gpio.c
        lib/sysfs_gpio.h
        main.c)
