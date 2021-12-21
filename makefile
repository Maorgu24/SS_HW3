.PHONY:clean all
	
all: stringProg

Ex3.o: Ex3.c 
	gcc -Wall -g -c Ex3.c

stringProg: Ex3.o Ex3.a
	gcc -Wall -g -o stringProg Ex3.o Ex3.a 	

Ex3.a: Ex3.o 
	ar -rcs Ex3.a Ex3.o

clean:
	rm -f *.o *.a stringProg







