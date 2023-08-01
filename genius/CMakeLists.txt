add_executable(genius
        genius.c
        )

# pull in common dependencies
target_link_libraries(genius pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(genius)
