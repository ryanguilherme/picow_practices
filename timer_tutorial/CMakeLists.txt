add_executable(timer_tutorial
        timer_tutorial.c
        )

# pull in common dependencies
target_link_libraries(timer_tutorial pico_stdlib hardware_timer hardware_gpio)

# create map/bin/hex file etc.
pico_add_extra_outputs(timer_tutorial)
