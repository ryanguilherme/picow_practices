add_executable(button
        button.c
        )

# pull in common dependencies
target_link_libraries(button pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(button)
