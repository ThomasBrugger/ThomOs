#Lets build ThomOs

APP_NAME = ThomOs
BUILD_FOLDER := build
CC := gcc
INCLUDES := $(shell find include -type d)
INCLUDE_FLAGS := $(addprefix -I,$(INCLUDES))
CFLAGS = -Wall $(INCLUDE_FLAGS)
SRC = $(shell find src -name "*.c")
OBJ = $(patsubst src/%.c,$(BUILD_FOLDER)/%.o,$(SRC))

all: $(OBJ)
	$(CC) $(OBJ) -o $(BUILD_FOLDER)/main

$(BUILD_FOLDER)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_FOLDER)