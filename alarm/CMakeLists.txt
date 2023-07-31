add_executable(alarm
        alarm.c
        )

# pull in common dependencies
target_link_libraries(alarm pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(alarm)
