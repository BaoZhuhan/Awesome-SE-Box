CC = gcc
CFLAGS = -Wall -g
TARGET = run

all: $(TARGET)

code.o: code.h test.h
	$(CC) $(CFLAGS) -c code.h

run.o: run.c code.h test.h
	$(CC) $(CFLAGS) -c run.c

test.o: test.h
	$(CC) $(CFLAGS) -c test.h

$(TARGET): code.o run.o test.o
	$(CC) $(CFLAGS) -o $(TARGET) code.o run.o test.o

clean:
	rm -f *.o $(TARGET)