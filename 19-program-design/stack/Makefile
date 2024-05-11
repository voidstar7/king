stack: main.o stack2.o
	cc -o stack main.o stack1.o

main.o: main.c stack1.h
	cc -c main.c

stack2.o: main.c stack1.h
	cc -c stack1.c

clean:
	rm *.o
