# Variabile CC è il comando che invoca il compilatore
CC=g++
# CCFLAGS: flags per il compilatore
CCFLAGS = -std=c++17 -Wall -march=x86-64

compile: main.o u_vector.o
	$(CC) $(CCFLAGS) main.o u_vector.o -o compile.o

main.o: main.cpp conto_bancario.h
	$(CC) $(CCFLAGS) -c main.cpp

u_vector.o: u_vector.cpp u_vector.h
	$(CC) $(CCFLAGS) -c u_vector.cpp -o u_vector.o

clean:
	rm -f -v *.o