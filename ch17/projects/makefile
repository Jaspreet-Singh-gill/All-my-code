
justify : justify.o line.o word.o
	gcc -o justify justify.o word.o line.o

justify.o : line.h word.h
	gcc -c line.c word.c justify.c
line.o : line.h line.c
	gcc -c  line.c
word.o : word.h word.c
	gcc -c  word.c

