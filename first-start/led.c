#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // Делаем PORTB5 выходным
  DDRB = DDRB | (1 << DDB5); // DDRB == 00100000

  while (1) {
    // Включает светодиод
    PORTB = PORTB | (1 << PORTB5); // PORTB == 00100000
    _delay_ms(1000);
    // Выключает светодиод
    PORTB = PORTB & ~(1 << PORTB5); // PORTB == 00000000
    _delay_ms(1000);
  }
}
