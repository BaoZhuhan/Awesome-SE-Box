TARGET = run

clean :
	rm -rf *.o code run

run : 
	gcc -o -g $(TARGET) run.c
	./$(TARGET)

del: clean
	> code.c
	> run.c
	> test.c
	> input.txt
	> PromoteDrafts.md