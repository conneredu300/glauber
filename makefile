all:	busca-local
busca-local:	busca.c
	gcc busca.c -o busca-local
clean:
	rm busca-local; clear;
