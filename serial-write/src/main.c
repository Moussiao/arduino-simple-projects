#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <util/setbaud.h>

#include "uart.h"

int main(void) {
  init_serial();

  while (1) {
    printf("test\n");
    _delay_ms(1000);
  }
}
