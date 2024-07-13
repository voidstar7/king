queue: queue-client.o linked-list-queue.o
	-gcc -o queue queue-client.o linked-list-queue.o

queue-client.o: queue-client.c linked-list-queue.h
	-gcc -c queue-client.c

linked-list-queue.o: linked-list-queue.c linked-list-queue.h
	-gcc -c linked-list-queue.c

clean:
	rm -f queue *.o
