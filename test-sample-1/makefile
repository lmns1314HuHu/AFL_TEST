main : main.o fun.o
	afl-gcc -o main main.o fun.o
main.o : main.c
	afl-gcc -c main.c
fun.o : fun.c
	afl-gcc -c fun.c
.PHONY : clean
clean: 
	rm -f fun.o main.o main fun.i fun.s main.i main.s