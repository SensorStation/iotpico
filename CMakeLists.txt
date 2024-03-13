cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(iot_pico C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(iotpico
  main.cc
)

pico_enable_stdio_usb(iotpico 1)
pico_enable_stdio_uart(iotpico 1)
pico_add_extra_outputs(iotpico)
target_link_libraries(iotpico pico_stdlib)

target_include_directories(iotpico PRIVATE ${CMAKE_CURRENT_LIST_DIR} )
target_link_libraries(iotpico pico_cyw43_arch_lwip_threadsafe_background pico_stdlib)
