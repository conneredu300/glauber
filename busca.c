#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dependencias.h"

int main(int argc, int *argv[]){
	processo *lista;
	processo *listaAtualizada;
	int menor;
	iniciaLista(lista);
	lerArquivo(argv[1],&lista);
	grasp(&lista);
	printf("concluido com sucesso\n");

	return 0;
}