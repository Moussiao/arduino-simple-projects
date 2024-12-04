#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  unsigned char delay = 100;

  int cycle;
  unsigned char cycleMoveDirection;
  unsigned char cycleMove = 3, maxCycle = 100, minCycle = 20;

  DDRB |= 1 << DDB1;
  // digital pin 9 переключаем в "аналоговый" режим.
  // Регистр TCCR1A служит для задания режимов работы таймера/счётчика.
  TCCR1A |= (_BV(COM1A1) | _BV(WGM10));
  // Регистр TCCR1A служит для установлении скорости счета TC1.
  TCCR1B |= (_BV(WGM12) | _BV(CS11) | _BV(CS10));

  cycle = minCycle;
  cycleMoveDirection = 1;

  while (1) {
    cycle = cycleMoveDirection ? cycle + cycleMove : cycle - cycleMove;
    if (cycle < minCycle) {
      cycle = minCycle;
      cycleMoveDirection = 1;
    } else if (cycle > maxCycle) {
      cycle = maxCycle;
      cycleMoveDirection = 0;
    }

    // Регистр OCR1A служит для задания значения, при достижении
    // которого в режиме счета, TC1 генерирует соотвествующие прерывание.
    // Если более абстракнто, прядставляя аналоговый режим, изменяем вольтаж.
    OCR1A = cycle;
    _delay_ms(delay);
  }
}
