SENSOR = sensor
BUILD = build
SRC = src

CC = avr-gcc
CFLAGS=-Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
MCU = atmega328p
F_CPU=16000000UL

OBJCOPY = avr-objcopy
BIN_FORMAT=ihex

PORT = /dev/tty.usbmodem1421
BAUD=115200
PROTOCOL=arduino
PART=ATMEGA328P
AVRDUDE = avrdude -F -V

.PHONY: sensor
sensor:
	mkdir -p $(SENSOR)/$(BUILD)
	$(CC) $(CFLAGS) -c -o $(SENSOR)/$(BUILD)/sensor.o $(SENSOR)/$(SRC)/main.c
	$(CC) -mmcu=$(MCU) $(SENSOR)/$(BUILD)/sensor.o -o $(SENSOR)/$(BUILD)/sensor
	$(OBJCOPY) -O $(BIN_FORMAT) -R .eeprom $(SENSOR)/$(BUILD)/sensor $(SENSOR)/$(BUILD)/sensor.hex
	$(AVRDUDE) -c $(PROTOCOL) -p $(PART) -P $(PORT) -b $(BAUD) -U flash:w:$(SENSOR)/$(BUILD)/sensor.hex

