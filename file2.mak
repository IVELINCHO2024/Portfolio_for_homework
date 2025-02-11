all: taskmanager.out

taskmanager.out: processes.o taskmanager.o
	gcc taskmanager.o processes.o -o taskmanager.out

processes.o: processes.c processes.h
	gcc -c processes.c -o processes.o

taskmanager.o: taskmanager.c processes.h
	gcc -c taskmanager.c -o taskmanager.o

clean:
	rm -f *.o *.out
