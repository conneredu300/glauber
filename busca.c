#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dependencias.h"

int main(int argc, int *argv[]){
	processo *lista;
	int menor;
	iniciaLista(lista);
	lerArquivo(argv[1],&lista);
	// buscaMenorValor(&lista);
	exibe(&lista);
	printf("concluido com sucesso\n");

	return 0;
}