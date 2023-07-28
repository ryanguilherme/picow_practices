add_executable(lcd_i2c
        lcd_i2c.c
        )

# pull in common dependencies
target_link_libraries(lcd_i2c pico_stdlib hardware_i2c)

# create map/bin/hex file etc.
pico_add_extra_outputs(lcd_i2c)
