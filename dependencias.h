#ifndef _DEPENDENCIAS_H
#define _DEPENDENCIAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct processo
{
	int tempoProcessamento;
	int tempoPreparacao;
	int tempoEntrega;
	struct processo* prox;
}processo;

int parseInt(char* chars);
int powInt(int x, int y);
void insere(int processamento, int preparacao, int entrega, processo *p);
void exibe(processo *lista);
void lerArquivo(char *url[], processo *lista);
void iniciaLista(processo *lista);
processo *buscaR (processo *lista);
void buscaLocal(processo *lista);
void finalizaLista(processo *lista);

#endif

int powInt(int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        x *= 10;
    }
    return x;
}

int parseInt(char* chars)
{
    int sum = 0;
    int len = strlen(chars);
    for (int x = 0; x < len; x++)
    {
        int n = chars[len - (x + 1)] - '0';
        sum = sum + powInt(n, x);
    }
    return sum;
}

void insere(int processamento, int preparacao, int entrega, processo *lista)
{
	processo *novo = malloc (sizeof (processo));
	processo *velho = lista->prox;
	
	novo->tempoProcessamento = processamento;
	novo->tempoPreparacao = preparacao;
	novo->tempoEntrega = entrega;
	
	lista->prox = novo;
	novo->prox = velho;
}

void exibe(processo *lista)
{
	if(lista->tempoEntrega >= 0 && lista->prox != NULL) {
		printf("%d %d %d\n", lista->tempoProcessamento, lista->tempoPreparacao, lista->tempoEntrega);
		return exibe(lista->prox);
	}
	printf("Fim da lista\n");
}

void lerArquivo(char *url[], processo *lista)
{
	FILE *arquivo;
	char a[5],b[5],c[5];
	arquivo = fopen(url,"r");
	while(!feof(arquivo))
	{
		fscanf(arquivo,"%s %s %s",&a,&b,&c);
		insere(parseInt(a),parseInt(b),parseInt(c),lista);
	}

	fclose(arquivo);
}

processo *buscaR (processo *lista)
{

}

int buscaMenorValor (processo *lista){
	int menorValor;
	int temp = 0;

	while(lista->prox != NULL){

		if(lista->tempoEntrega >= 0){
			if(temp <= lista->tempoEntrega){
				menorValor = temp;
			}else{
				menorValor = lista->tempoEntrega;
			}
		}

		printf("%d\n", menorValor);
		lista = lista->prox;
	}

	printf("%d\n", menorValor);
	return menorValor;
}

void buscaLocal(processo *lista)
{
	processo *menor;
	menor = buscaR(lista);
	printf("%d\n",menor->tempoEntrega);
}

void iniciaLista(processo *lista){
	lista = NULL;
}