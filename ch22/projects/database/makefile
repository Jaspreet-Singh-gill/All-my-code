inventory: database.o inventory.o word.o
	gcc -o inventory inventory.o database.o  word.o

database.o : database.h inventory.h database.c word.c
	gcc database.c -c
inventory.o : database.h inventory.c inventory.h
	gcc inventory.c -c
word.o: word.c word.h
	gcc word.c -c

