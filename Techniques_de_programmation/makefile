all : Secours
alerte.o : alerte.h alerte.c
	cc -c alerte.c

main.o : alerte.h main.c
	cc -c main.c

Secours : alerte.o main.o
	cc -o Secours alerte.o main.o
