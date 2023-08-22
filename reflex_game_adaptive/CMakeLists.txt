add_executable(reflex_game_adaptive
        reflex_game_adaptive.c
        )

# pull in common dependencies
target_link_libraries(reflex_game_adaptive pico_stdlib hardware_gpio hardware_timer)

# create map/bin/hex file etc.
pico_add_extra_outputs(reflex_game_adaptive)
