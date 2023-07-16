cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(rotatevideo_demo C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(rotatevideo_demo
	rotate_demo.c
	graphlib.c
	rotatevideo_lcd.c
	ff.C
	pico-sdmm.c
)

# Pull in basic dependencies
target_link_libraries(rotatevideo_demo pico_stdlib hardware_spi)

# create map/bin/hex file etc.
pico_add_extra_outputs(rotatevideo_demo)
