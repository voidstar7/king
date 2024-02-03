CFLAGS = -Wall -g

inventory: inventory.o readline.o
	cc -o inventory inventory.o readline.o

inventory.o: inventory.c readline.h
	cc $(CFLAGS) -c inventory.c

readline.o: readline.c readline.h
	cc $(CFLAGS) -c readline.c

clean: 
	rm -f inventory *.o
