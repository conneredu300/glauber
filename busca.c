#include<stdio.h>
#include<stdlib.h>

typedef struct processo{
	int tempoProcessamento;
	int tempoPreparacao;
	int tempoEntrega;
	struct processo* prox;
}processo;

void insere(int processamento, int preparacao, int entrega, processo *p){
	processo *novo;
	novo =(processo *) malloc (sizeof (processo));
	novo->tempoProcessamento = processamento;
	novo->tempoPreparacao = preparacao;
	novo->tempoEntrega = entrega;
	novo->prox = p->prox;
	p->prox = novo;
}

void exibe(processo *lista){
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

void lerArquivo(char *url[], processo *lista){
	FILE *arquivo;
	char a,b,c;
	arquivo = fopen(url,"r");
	while(!feof(arquivo))
	{
		a='0';
		b='0';
		c='0';
		fscanf(arquivo,"%s %s %s",&a,&b,&c);
		insere(atoi(a),atoi(b),atoi(c),&lista);
	}

	fclose(arquivo);
}

void iniciaLista(processo *lista){
	lista = NULL;
}

int main(int argc, int *argv[]){
	processo *lista;
	iniciaLista(&lista);
	// lerArquivo(argv[1],&lista);
	insere(1,2,3,&lista);
	insere(1,2,3,&lista);
	insere(1,2,3,&lista);
	exibe(&lista);
	printf("concluido com sucesso\n");
}







