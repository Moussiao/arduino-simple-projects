default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
	avr-gcc -o led.bin led.o
	avr-objcopy -O ihex -R .eeprom led.bin led.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex

sample:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led_digital_sample.o led_digital_sample.c
	avr-gcc -o led_digital_sample.bin led_digital_sample.o
	avr-objcopy -O ihex -R .eeprom led_digital_sample.bin led_digital_sample.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led_digital_sample.hex
