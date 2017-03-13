
all: lab7

lab7: main.o list.o
	gcc -o lab7 main.o list.o 

list.o: tree.h tree.c
	gcc -c -o list.o tree.c

main.o: tree.h tree.o
	gcc -c -o main.o main.c

clean:
	rm -rf *o lab7


