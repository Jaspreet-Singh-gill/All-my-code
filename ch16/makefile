database: database.o quicksort.o word.o
	gcc  quicksort.o word.o database.o -o database
database.o: database.c database.h
	gcc -c database.c
quicksort.o: quicksort.c quicksort.h database.h
	gcc quicksort.c -c
word.o: word.h word.c
	gcc -c  word.c


