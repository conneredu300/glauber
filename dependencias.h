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

void insere(int processamento, int preparacao, int entrega, processo *p)
{
	processo *novo;
	novo =(processo *) malloc (sizeof (processo));
	novo->tempoProcessamento = processamento;
	novo->tempoPreparacao = preparacao;
	novo->tempoEntrega = entrega;
	novo->prox = p->prox;
	p->prox = novo;
}

void exibe(processo *lista)
{
	int contador = 0;
	
	while(lista->prox != NULL){
		printf("\n%d° %d %d %d",
		contador,
		lista->tempoProcessamento,
		lista->tempoPreparacao,
		lista->tempoEntrega		
		);
	
	contador++;
	lista = lista->prox;
	}
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
	int x = lista->tempoEntrega;
   	if (lista == NULL)  return NULL;
   	if (lista->tempoEntrega >= x)  return lista;
   	return buscaR (lista->prox);
}

void buscaLocal(processo *lista)
{
	while(lista->prox != NULL){
		processo *temp = buscaR(lista);
		lista = lista->prox;
		printf("%d %d %d\n", temp->tempoProcessamento, temp->tempoPreparacao, temp->tempoEntrega);
	}
}

void iniciaLista(processo *lista){
	lista = NULL;
}