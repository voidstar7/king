quicksort: quicksort.o qsort.o
	-gcc -o quicksort quicksort.o qsort.o

quicksort.o: quicksort.c quicksort.h
	-gcc -c quicksort.c

qsort.o: qsort.c quicksort.h
	-gcc -c qsort.c 

clean:
	rm -f quicksort *.o
