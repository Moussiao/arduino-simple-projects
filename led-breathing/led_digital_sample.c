#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  DDRB |= 1 << DDB0;
  while (1) {
    // Получаем эффект, что светодиод горит тусклым светом.
    // Из-за того, что человеческий глаз, при низкой частоте, может не улавливать мерцание.
    PORTB |= 1 << PORTB0;
    _delay_ms(1);
    PORTB &= ~(1 << PORTB0);
    _delay_ms(4);
  }
}
