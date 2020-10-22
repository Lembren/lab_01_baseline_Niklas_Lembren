#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"
#include "led.h"


#define FOSC 16000000 // Clock Speed, fOSC System oscillator clock frequency
#define BAUD 38400 //Baud rate (in bits per second, bps)
#define MYUBRR FOSC/16/BAUD-1 




int main(void){
    //blink_Led();
    uart_init(MYUBRR);
    //char n = 'N';
    char str[] = "Niklas\n";
    while (1) {
        uart_putstr(str);
    //    uart_putchar(n);
    //    uart_echo();
        _delay_ms(2000);
    }
    return 0;
}
