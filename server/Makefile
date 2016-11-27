TARGET = central
BUILD = build
SRC = src

CC = g++
CFLAGS = -g -Wall

default: build

build:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(BUILD)/$(TARGET) $(SRC)/main.cpp

clean:
	rm -rf $(BUILD)
