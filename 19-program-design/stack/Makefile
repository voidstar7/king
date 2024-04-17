stack: main.o stack2.o
	cc -o stack main.o stack2.o

main.o: main.c stack.h
	cc -c main.c

stack2.o: main.c stack.h
	cc -c stack2.c

clean:
	rm *.o
