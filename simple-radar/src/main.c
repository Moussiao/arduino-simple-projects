#include <avr/io.h>
#include <util/delay.h>

#define SERVO_DELAY 30
#define MAX_DISTANCE 10

long int pulseIn() {
  long int duration = 0;
  long int timeout_count = 0;

  while (((PIND & (1 << PIND5)) >> PIND5) == 1) {
    if (++timeout_count > 1000000) {
      return duration;
    }
  }

  while (((PIND & (1 << PIND5)) >> PIND5) != 1) {
    if (++timeout_count > 1000000) {
      return duration;
    }
  }

  while (((PIND & (1 << PIND5)) >> PIND5) == 1) {
    if (++timeout_count > 1000000) {
      return 0;
    }
    duration++;
  }

  return duration;
}

long int calculateDistance() {
  long int duration;

  PORTD &= ~(1 << PORTD6);
  _delay_us(5);
  PORTD |= (1 << PORTD6);
  _delay_us(10);
  PORTD &= ~(1 << PORTD6);

  duration = pulseIn();
  return duration / 59;
}

int main(void) {
  long int distance;

  /* sonar */
  DDRD |= (1 << DDD6);
  DDRD &= ~(1 << DDD5);

  /* servo */
  DDRB |= 1 << DDB1;

  TCCR1A |= (1 << WGM11) | (1 << COM1A1);
  TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);

  ICR1 = 39999;

  while (1) {
    for (int i = 800; i <= 5100; i += 50) {
      distance = calculateDistance();
      if (distance > MAX_DISTANCE) {
        OCR1A = i;
      } else {
        i -= 50;
      }
      _delay_ms(SERVO_DELAY);
    }

    for (int i = 5100; i > 800; i -= 50) {
      distance = calculateDistance();
      if (distance > MAX_DISTANCE) {
        OCR1A = i;
      } else {
        i += 50;
      }
      _delay_ms(SERVO_DELAY);
    }
  }

  return 0;
}
