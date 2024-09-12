TARGET := prog
SRC_DIR := src
BLD_DIR := build
PROJECT :=  task4

SRC_DIRS := $(shell find $(SRC_DIR) -type d) 
SRCS := $(wildcard $(addsuffix /*.c,$(SRC_DIRS)))
HEADERS := $(wildcard $(addsuffix /*.h,$(SRC_DIRS)))
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BLD_DIR)/%.o,$(SRCS))

CC := avr-gcc
CFLAGS := -mmcu=atmega32
CFLAGS += -O3
CFLAGS += -Isrc

.PHONY: all clean
.SECONDEXPANSION:

all: $(OBJS) | $(BLD_DIR)/
	$(CC) $(CFLAGS) $^ -o $(BLD_DIR)/$(TARGET).elf
	avr-objcopy -O ihex -R .eeprom $(BLD_DIR)/$(TARGET).elf $(TARGET).hex
	cp $(TARGET).hex ../$(PROJECT)

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)| $(BLD_DIR)/$$(dir %)
	@echo Building $< into $@
	$(CC) $(CFLAGS) -c $< -o $@

%/:
	mkdir -p $@

clean:
	rm -rf $(BLD_DIR) $(TARGET).hex
