stack: stack.o stackADT.o 
	-cc -o stack stack.o stackADT.o

stack.o: stack.c ../../19-program-design/adt/stackADT.h
	-cc -c stack.c 

stackADT.o: ../../19-program-design/adt/stackADT.c ../../19-program-design/adt/stackADT.h
	-cc -c ../../19-program-design/adt/stackADT.c ../../19-program-design/adt/stackADT.h

clean:
	-rm stack *.o
