CC = gcc 
CFLAGS = -g -std=c99 -Wall -Werror

auto: main.o CDH.o CP.o CR.o CR_CDH.o CSG.o HashTable.o LinkedList.o SNAP.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm auto main.o CDH.o CP.o CR.o CR_CDH.o CSG.o HashTable.o LinkedList.o SNAP.o