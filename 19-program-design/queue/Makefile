queue: main.o linked-list-queue.o
	-gcc -o queue main.o linked-list-queue.o

main.o: main.c queue.h
	-gcc -c main.c

linked-list-queue.o: array-queue.c queue.h
	-gcc -c linked-list-queue.c

clean:
	rm -f queue *.o
