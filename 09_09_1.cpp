#include <stdio.h>

int main(){
	
	char str [80];
	float f;
	
	FILE *pFile = NULL;
	
	pFile = fopen ("C:\\Users\\Android\\E:\\myfile.txt","r"); // Nome do usuário vai mudar conforme o computador
	
	if(pFile != NULL){
		fscanf(pFile, "%f", &f);
		fscanf(pFile, "%s", str);
		fclose(pFile);
		
		printf("Li: %f e %s \n", f, str);
	}
	
}
