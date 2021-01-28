#include <stdio.h>
#include <pico/stdlib.h>
#include <string.h>

#include "pimoroni-pico/libraries/pico_display/pico_display.hpp"

using namespace pimoroni;

uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
PicoDisplay pico_display(buffer);

int main() {
    stdio_init_all();
    printf("Hello, world!\n");

    pico_display.init();
    pico_display.set_backlight(100);

    bool a_pressed = false;

    pico_display.set_pen(0, 0, 0);
    pico_display.clear();
    pico_display.set_pen(255, 0, 0);
    pico_display.text("2700", Point(10, 10), 150, 10);
    pico_display.update();

    bool screen_on_p = true;
    while (true) {
        if (pico_display.is_pressed(PicoDisplay::A)) {
            screen_on_p = ! screen_on_p;

            if (screen_on_p) {
                pico_display.set_backlight(100);
            }
            else {
                pico_display.set_backlight(0);
            }
            pico_display.update();
            printf("Ping!\n");
        }
        sleep_ms(250);
    }
}
