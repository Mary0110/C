lab7: main.c books.c readers.c
	gcc -std=c99 -pedantic main.c books.c readers.c -o lab7
lab7test: books.c readers.c test7.c
	gcc -o test7 -Dmain=_main test7.c books.c readers.c