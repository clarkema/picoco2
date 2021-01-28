# See https://github.com/raspberrypi/pico-sdk for a walkthrough
# of this setup

cmake_minimum_required(VERSION 3.12)

# initialize pico_sdk from submodule
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)
include(pimoroni-pico/pico_sdk_import.cmake)
include(pimoroni-pico/libraries/pico_display/pico_display.cmake)

project(picoco2)

# initialize the Pico SDK
pico_sdk_init()

add_executable(picoco2
    main.cpp
)

target_link_libraries(
    picoco2
    pico_stdlib
    hardware_spi # display
    hardware_pwm # display
    hardware_dma # display
    pico_display
)

# Enable stdin / stdout over USB serial
pico_enable_stdio_usb(picoco2 1)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(picoco2)
