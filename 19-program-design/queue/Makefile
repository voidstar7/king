queue: queue-client.o array-queue.o
	-gcc -o queue queue-client.o array-queue.o

queue-client.o: main.c queue.h
	-gcc -c queue-client.c

array-queue.o: array-queue.c queue.h
	-gcc -c array-queue.c

clean:
	rm -f queue *.o
