all:	busca-local
busca-local:	busca.c dependencias.h
	gcc dependencias.h busca.c -o busca-local
clean:
	rm busca-local; clear;
