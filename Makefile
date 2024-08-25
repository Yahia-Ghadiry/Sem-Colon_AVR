TARGET := prog
SRC_DIR := src
BLD_DIR := build


SRC_DIRS := $(shell find $(SRC_DIR) -type d) 
SRCS := $(wildcard $(addsuffix /*.c,$(SRC_DIRS)))
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BLD_DIR)/%.o,$(SRCS))

CC := avr-gcc
CFLAGS := -mmcu=atmega32
CFLAGS := -I $(SRC_DIR)

.PHONY: all clean
.SECONDEXPANSION:

all: $(BLD_DIR)/$(TARGET).elf
	avr-objcopy -j .text -O ihex  $(BLD_DIR)/$(TARGET).elf $(TARGET).hex

$(BLD_DIR)/$(TARGET).elf: $(OBJS) | $(BLD_DIR)/
	$(CC) $(CFLAGS) $^ -o $(BLD_DIR)/$(TARGET).elf

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c | $(BLD_DIR)/$$(dir %)
	@echo Building $< into $@
	$(CC) $(CFLAGS) -c $< -o $@

%/:
	mkdir -p $@

clean:
	rm -rf $(BLD_DIR) $(TARGET).hex
