#ifndef _DEPENDENCIAS_H
#define _DEPENDENCIAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/wait.h>

int tamanho = 0;

typedef struct processo
{
	int tempoProcessamento;
	int tempoPreparacao;
	int tempoEntrega;
	int index;
	struct processo* prox;
}processo;

int parseInt(char* chars);
int powInt(int x, int y);
void insere(int processamento, int preparacao, int entrega, processo *p);
void exibe(processo *lista);
void lerArquivo(char *url[], processo *lista);
void iniciaLista(processo *lista);
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
	tamanho++;
	processo *novo = malloc (sizeof (processo));
	processo *inicio = lista->prox;

	iniciaLista(novo);

	novo->tempoProcessamento = processamento;
	novo->tempoPreparacao = preparacao;
	novo->tempoEntrega = entrega;
	novo->index = tamanho;
	novo->prox = inicio;

	lista->prox = novo;
}

void exibe(processo *lista)
{
	int contador = 0;

	while(lista->prox != NULL){
		contador++;
		printf("%d %d %d %d\n",lista->index, lista->tempoProcessamento, lista->tempoPreparacao, lista->tempoEntrega);
		if(contador == tamanho+1){
			break;
		}
		lista = lista->prox;
	}

	printf("Fim da lista\n");
}

void lerArquivo(char *url[], processo *lista)
{
	system("clear");
	printf("Aguarde, lendo arquivo...\n");
	sleep(1);
	FILE *arquivo;
	char a[5],b[5],c[5];
	arquivo = fopen(url,"r");
	while(!feof(arquivo))
	{
		fscanf(arquivo,"%s %s %s",&a,&b,&c);
		insere(parseInt(a),parseInt(b),parseInt(c),lista);
	}

	fclose(arquivo);
	sleep(3);
}

int buscaMenorValorNaLista (processo *lista){
	int contador = 0;
	int index;

	while(lista->prox != NULL){
		contador++;

		if(lista->tempoEntrega <= 0){
			index = lista->index;
		}

		lista = lista->prox;
		
		if(contador == tamanho+1)
			break;

	}

	return index;
}

processo *retornaPosicao(int x, processo *lista){
	int contador = 0;
	
	while(lista->prox != NULL){
		contador++;

		if(contador == tamanho)
			break;
		
		if(lista->index == x){
			return lista;
		}

		lista = lista->prox;
	}
}

int buscaMenorValor (processo *lista, int valor){
	int contador = 0;
	int index;

	while(lista->prox != NULL){
		contador++;

		if(lista->tempoEntrega <= valor){
			index = lista->index;
		}else{
			index = valor;
		}

		lista = lista->prox;
		
		if(contador == tamanho+1)
			break;

	}

	return index;
}

void exibePosicao(int x, processo *lista){
	int contador = 0;
	
	while(lista->prox != NULL){
		contador++;

		if(contador == tamanho+1)
			break;
		
		if(lista->index == x){
			printf("%d %d %d %d\n", lista->index, lista->tempoProcessamento, lista->tempoPreparacao, lista->tempoEntrega);
		}

		lista = lista->prox;
	}
}

void removerIndice(int index, processo *lista){
	processo *temp;
	int contador = 0;

	while(lista->prox != NULL){
		contador++;

		if(lista->index == index){
			   processo *lixo;
			   lixo = lista;
			   lista->prox = lixo->prox;
			   free (lixo);
		}

		if(contador == tamanho+1)
			break;

		lista = lista->prox;
	}
}

void grasp(processo *lista)
{
	processo *menor = lista->prox;
	processo *temp;

	printf("%d\n",menor->tempoEntrega);
}

void iniciaLista(processo *lista){
	lista = NULL;
}

void status(int estado){
	int peso,i;

	peso = (tamanho - estado)/100;
	system("clear");
	printf("Contagem Regressiva: %d\n",peso);
}

void insereNo(processo *lista, processo *no){
	insere(no->tempoPreparacao, no->tempoProcessamento, no->tempoEntrega, &lista);
}