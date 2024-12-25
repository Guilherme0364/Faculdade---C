#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

// Estrutura das informa��es a serem armazenadas no n� da lista
struct Embaixador{
	
	char nome[40];
	char curso[30];
	char ra[8];
	struct Embaixador *proximo; // Mesma coisa do n� inicial
	
};


// Define o n� inicial da lista
struct Embaixador *inicio = NULL; // Tipo de vari�vel do n� deve ser igual ao do tipo que ela guarda


// Fun��o para carregar os embaixadores de um arquivo na lista encadeada
void leEmbaixador(){
	
	
	// Tenta abrir o arquivo e declara as vari�veis
	FILE *arquivo = NULL;
	char nome[40];
	
	
	arquivo = fopen("embaixadores.txt", "r");
	
	
	// Enquanto houver dados: 
	if(arquivo != NULL){
		while(fscanf(arquivo, "%s", nome) != EOF){ // "End of file"
	
	
	// Algoritmo de inser��o no come�o, crie um novo n�
	struct Embaixador *novo = (struct Embaixador*)malloc(sizeof(struct Embaixador)); // N� deve ser do tipo struct, pois percorre por ela (no caso a lista encadeada percorre)
	
	
	// Colocar os dois lados lidos no novo n�
	strcpy(novo -> nome, nome);
	
	
		// Ler o nome, ra, curso e colocar na lista encadeada	
		fscanf(arquivo, "%s", novo -> ra);
		fscanf(arquivo, "%s", novo -> curso);
			
		novo -> proximo = inicio;
		inicio = novo;	
	}
	
	// Fecha o arquivo
	fclose(arquivo);

	}
	
}
void listarEmbaixador(){
	
	// Obter um n� auxiliador
	struct Embaixador *aux = inicio;
	
	
	// Enquanto houver elemento na lista
	while(aux != NULL){
		
		// Imprime os dados
		printf("\nNome: %s", aux -> nome);
		printf("\nRA: %s", aux -> ra);
		printf("\nCurso: %s", aux -> curso);
		
		// Atualiza aux passando ele para o pr�ximo elemento da lista
		aux = aux -> proximo;
		
	}
	
}

void substituir(){
	
	char curso[30];
	int encontrou = 0;
	printf("\n\n---- Substitui��o ----");
	printf("\nCurso que vai mudar o embaixador: ");
	scanf("%s", curso);
	
	struct Embaixador *aux = inicio;
		while(aux != NULL){
			if(strcmp(aux -> curso, curso) == 0);{
				
				printf("Nome do novo embaixador: ");
				scanf("%s", aux -> nome);
				printf("RA: ");
				scanf("%s", aux -> ra);
				encontrou = 1;
				break;				
				
			}
			
			aux = aux -> proximo;
			
			if(encontrou == 0);
			printf("Curso n�o encontrado. ");
			
		}
			
}

int main (){
	
	setlocale(LC_ALL, "Portuguese");
	
	leEmbaixador();
	listarEmbaixador();
	substituir();
	listarEmbaixador();
	
}
