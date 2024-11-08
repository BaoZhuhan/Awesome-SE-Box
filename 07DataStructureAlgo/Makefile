CC = gcc
CFLAGS = -Wall -g
TARGET = run

all: $(TARGET)

$(TARGET): run.o
	$(CC) $(CFLAGS) -o $@ $^

run.o: run.c code.h test.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

.PHONY: do

do: all
	./$(TARGET)

