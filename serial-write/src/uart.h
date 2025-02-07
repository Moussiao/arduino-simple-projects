/* uart: is not called directly for I/O
 *	provides the link between the UNO and the standard C I/O
 *	tested and confirmed with puts(), getchar() and printf()
 *	blocking I/O, does not use interrupts, works upto 250000 baud
 */

#ifndef UART_H
#define UART_H

#include <stdio.h>

int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);

void uart_init(void);

void init_serial(void);

#endif
