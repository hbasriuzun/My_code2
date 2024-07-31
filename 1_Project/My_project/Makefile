all: movie

movie: main.o
	gcc -o movie main.o

main.o: main.c
	gcc -c main.c

clean:
	rm -f movie main.o
