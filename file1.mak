all: main

main: main.o quadraticroots.o
	gcc main.o quadraticroots.o -o main

main.o: main.c quadraticroots.h
	gcc -c main.c

quadraticroots.o: quadraticroots.c quadraticroots.h
	gcc -c quadraticroots.c

clean:
	rm -f *.o main