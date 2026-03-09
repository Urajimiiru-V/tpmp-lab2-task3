CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -I./src
TARGET=note_program
SRCDIR=src
SOURCES=$(wildcard $(SRCDIR)/*.c)

all: clean $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

force-rebuild: clean
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) $(SRCDIR)/*.o

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run force-rebuild
