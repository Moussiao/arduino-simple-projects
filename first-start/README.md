# Описание

Основан на видео https://www.youtube.com/watch?v=j4xw8QomkXs

## Логика работы

Управление мерцанием светодиода на самой плате.
На основе схемы, представленной на данном ресурсе, https://supereyes.ru/articles/other/obzor_kontrollerov_apparatnoy_platformy_arduino/
мы знаем, что управлять `LED_BUILTIN` мы можем через порт `PB5`. (PORTB - The Port B Data Register)

## Подробнее про Arduino UNO

Поставляется на базе микро-контроллера Atmega 328p

## Как запустить

Ввести `make`, который скомпилирует вашу программу и загрузит на подключенный Arduino Uno.

Найти подключенный arduino можно через директорию где отображаются все подлкюченные устройства:
`ls /dev/ | grep ACM`

В частности, у меня, он отображается как `ttyACM0` на Ubuntu.
