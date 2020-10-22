#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

#define BLINK_DELAY_MS 5000

void blink_Led(void) {
    //arduino digital pin 8(8 av PORTB) output
    DDRB |= (1 << PB0);

    while (1) {
        //LED ON   
        PORTB |= (1 << PB0);
        _delay_ms(BLINK_DELAY_MS);
        PORTB &= ~(1 << PB0);
        _delay_ms(BLINK_DELAY_MS);
    }
}