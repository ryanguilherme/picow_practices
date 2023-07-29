add_executable(hc_sr04
        hc_sr04.c
        )

# pull in common dependencies
target_link_libraries(hc_sr04 pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(hc_sr04)
