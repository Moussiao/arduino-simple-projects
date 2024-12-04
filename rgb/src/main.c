#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <util/setbaud.h>

#include "analogRead.h"
#include "uart.h"

#define ANALOG_TO_VOLTAGE_DIVEDER 205

int main(void) {
  char test[15];
  // Значение от 0 - 1023, которое получаем при прочении аналогового значения.
  int analogVoltage;
  // Вещественные числа лучше не использовать, Atmega328P апаратно не имеет логики работы с данными
  // числами. Использовать их можно, но компилятор встроит код по работе с ними, который медленнее
  // чем апаратное решение, а также много весит.
  float voltage;

  init_serial();

  while (1) {
    analogVoltage = analogRead(0);
    if (analogVoltage == 1023) {
      voltage = 5.0;
    } else if (analogVoltage > 0) {
      voltage = (float)analogVoltage / ANALOG_TO_VOLTAGE_DIVEDER;
    } else {
      voltage = 0;
    }

    dtostrf(voltage, 3, 2, test);
    printf("A0 Voltage = %s (%d) \n", test, analogVoltage);
    _delay_ms(1000);
  }
}
