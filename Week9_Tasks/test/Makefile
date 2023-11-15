CC = gcc
CFLAGS = -Wall

# List of source files
SOURCES = main.c

# Output executable name
EXECUTABLE = test

all: $(SOURCES)
\t$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
\trm -f $(EXECUTABLE)

.PHONY: all clean
