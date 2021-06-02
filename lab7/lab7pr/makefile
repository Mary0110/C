lab7: main.c books.c readers.c
	gcc -std=c89 -pedantic main.c books.c readers.c -o lab7
lab7test: main.c books.c readers.c test7.c
	gcc -o test7 -Dmain=_main main.c test7.c books.c readers.c