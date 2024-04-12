queue: main.o array-queue.o
	-gcc -o queue main.o array-queue.o

main.o: main.c queue.h
	-gcc -c main.c

array-queue.o: array-queue.c queue.h
	-gcc -c array-queue.c

clean:
	rm -f queue *.o
