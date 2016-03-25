# Declaration of variables
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -std=c11 -fPIC
LD_FLAGS = -shared

# File names
TARGET = out/
OBJDIR = obj
NAME = test.so

# Derived objects
OUTPUT = $(TARGET)$(NAME)
SOURCES = $(shell find . -type f -name '*.c')
OBJECTS = $(patsubst %.c,$(OBJDIR)/%.o,$(SOURCES))

.PHONY: release
release: CC_FLAGS += -O3 -DRELEASE
release: $(OUTPUT)

.PHONY: debug
debug: CC_FLAGS += -g -DDEBUG
debug: $(OUTPUT)

.PHONY: all
all: release

# Main target
$(OUTPUT): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(LD_FLAGS) $(OBJECTS) -o $(OUTPUT)

# To obtain object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
.PHONY: clean
clean:
	rm -f $(OBJECTS)
	rm -f $(OUTPUT)

.PHONY: cleaner
cleaner:
	rm -rf $(TARGET)
	rm -rf $(OBJDIR)
	
