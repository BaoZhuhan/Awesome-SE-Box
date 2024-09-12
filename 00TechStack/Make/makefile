CFLAGES = -Wall -g -O2

all:hello world
	@echo "all done"

hello world: main.o message.o
	gcc $(CFLAGES) main.o message.o -o $@

main.o: main.c
	gcc $(CFLAGES) -c $< -o $@

message.o: message.c
	gcc $(CFLAGES) -c message.c

clean: 
	del *.o