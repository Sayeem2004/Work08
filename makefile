all: main.o mystring.o
	gcc -o main main.o mystring.o

main.o: main.c mystring.h
	gcc -c main.c

mystring.o: mystring.c
	gcc -c mystring.c

run:
	./main

clean:
	rm main.o mystring.o
