#include <stdio.h>

int main (int argc, char *argv[]){ // Dois argumentos para uso via console 
	
	FILE *fp; // Armazena o ende�o do arquivo
	char nome[50];
	
	if ((fp = fopen("\\:nomes.txt", "w")) != NULL){ // Posso usar \\: para arquivos armazenados no mesmo diret�rio
		for(int i = 0; i<10; i++){
			printf("Escreva um nome: ");
			gets(nome);
			fprintf(fp, "Nome %d: %s\n ", i+1, nome);
		}
	}
	
	fclose(fp);
	
} // C�digo incompleto
