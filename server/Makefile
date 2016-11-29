TARGET = central
BUILD = build
SRC = src

CC = g++
CFLAGS = -g -Wall

default: build

build:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/$(TARGET) $(SRC)/**.cpp

clean:
	rm -rf $(BUILD)
