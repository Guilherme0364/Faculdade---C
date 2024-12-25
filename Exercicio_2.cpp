#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

// Estrutura das informações a serem armazenadas no nó da lista
struct Embaixador{
	
	char nome[40];
	char curso[30];
	char ra[8];
	struct Embaixador *proximo; // Mesma coisa do nó inicial
	
};


// Define o nó inicial da lista
struct Embaixador *inicio = NULL; // Tipo de variável do nó deve ser igual ao do tipo que ela guarda


// Função para carregar os embaixadores de um arquivo na lista encadeada
void leEmbaixador(){
	
	
	// Tenta abrir o arquivo e declara as variáveis
	FILE *arquivo = NULL;
	char nome[40];
	
	
	arquivo = fopen("embaixadores.txt", "r");
	
	
	// Enquanto houver dados: 
	if(arquivo != NULL){
		while(fscanf(arquivo, "%s", nome) != EOF){ // "End of file"
	
	
	// Algoritmo de inserção no começo, crie um novo nó
	struct Embaixador *novo = (struct Embaixador*)malloc(sizeof(struct Embaixador)); // Nó deve ser do tipo struct, pois percorre por ela (no caso a lista encadeada percorre)
	
	
	// Colocar os dois lados lidos no novo nó
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
	
	// Obter um nó auxiliador
	struct Embaixador *aux = inicio;
	
	
	// Enquanto houver elemento na lista
	while(aux != NULL){
		
		// Imprime os dados
		printf("\nNome: %s", aux -> nome);
		printf("\nRA: %s", aux -> ra);
		printf("\nCurso: %s", aux -> curso);
		
		// Atualiza aux passando ele para o próximo elemento da lista
		aux = aux -> proximo;
		
	}
	
}

void substituir(){
	
	char curso[30];
	int encontrou = 0;
	printf("\n\n---- Substituição ----");
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
			printf("Curso não encontrado. ");
			
		}
			
}

int main (){
	
	setlocale(LC_ALL, "Portuguese");
	
	leEmbaixador();
	listarEmbaixador();
	substituir();
	listarEmbaixador();
	
}
