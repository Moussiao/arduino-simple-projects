#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  char count, maxCount = 15;
  int delay = 500, longDelay = 2000;

  DDRB = maxCount;
  while (1) {
    for (count = 0; count <= maxCount; count++) {
      PORTB = count;
      _delay_ms(delay);
    }

    _delay_ms(longDelay);
  }
}
