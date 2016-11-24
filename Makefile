connectn.out: connectn.o main.o 

	gcc -g -Wall -o connectn.out connectn.o main.o

connectn.o: connectn.c connectn.h

	gcc -g -Wall -c -o connectn.o connectn.c

main.o: main.c connectn.h

	gcc -g -Wall -c -o main.o main.c

clean:

	rm *.o *.out