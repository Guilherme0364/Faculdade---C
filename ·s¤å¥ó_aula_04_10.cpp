#include <stdio.h>

struct No{	
	int dado;
	
	struct No* esq;
	struct No* dir;
};

struct No* raiz = NULL;

/*
	Insere um valor em uma ABB
	Input: valor a ser inserido
	Output: 1 - se foi poss�vel
			0 - se n�o foi poss�vel
*/


int insere(struct No** raiz, int dado){
	
	// Verifica se a raiz est� vazia
	if((*raiz) == NULL){
		
		// Ent�o o valor deve ficar nesta raiz		
		(*raiz) = malloc(sizeof(struct No));
		
		(*raiz)->dado = valor;
		
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
	}
	
	else{
		
		// Observar se o valor ter� que ser um filho � esquerda ou � direita
		if(valor->(*raiz)->dado){
			insere(&((*raiz)->dir), valor);
		}
		
		else if(valor->(*raiz)->dado){
		insere(&((*raiz)->esq), valor);
		}
		
		else{
			return 0;
		}
	}	
}

int preOrdem(){
	
	if(raiz != NULL){
		printf("\n", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
	
}

int main(){
	insere(&raiz, 2);
	insere(&raiz, 1);
	insere(&raiz, 3);
	
	preOrdem(raiz);
	
}












