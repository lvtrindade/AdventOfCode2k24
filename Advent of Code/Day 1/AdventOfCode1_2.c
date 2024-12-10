#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    FILE *inputFile;
    char linha[MAX_LEN];
    int *listaD = NULL;
    int *listaE = NULL;
    int cont = 0;
    int resultado = 0;
    
    inputFile = fopen("input.txt", "r");
    
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    
    char *token;
    int numD;
    int numE;
    
    while (fgets(linha, MAX_LEN, inputFile) != NULL) {
        token = strtok(linha, " ");
        
        if (token != NULL) {
            numD = atoi(token);
        }
        
        token = strtok(NULL, " ");
        
        if (token != NULL) {
            numE = atoi(token);
        }

        listaD = (int *)realloc(listaD, (cont + 1) * sizeof(int));
        listaE = (int *)realloc(listaE, (cont + 1) * sizeof(int));
        
        listaD[cont] = numD;
        listaE[cont] = numE;
        
        cont++;
    }
    
    qsort(listaD, cont, sizeof(int), comparar);
    qsort(listaE, cont, sizeof(int), comparar);
    
        printf("\nLista D:\n");
    for (int i = 0; i < cont; i++) {
        printf("%d \n", listaD[i]);
    }
    
    printf("Lista E:\n");
    for (int i = 0; i < cont; i++) {
        printf("%d \n", listaE[i]);
    }
    
    int qntE = 0;
    int soma = 0;
    
    for (int i = 0; i < cont; i++) {
    	
    	qntE = 0;
    	
    	for (int j = 0; j < cont; j++) {
    		if (listaD[i] == listaE[j]) {
    			qntE++;
			}
		}
		
		soma += (listaD[i] * qntE);
		printf("\nSoma: %d\nlistaD[i]: %d\nqntE: %d", soma, listaD[i], qntE);
	}
    
    printf("\nSoma:\n%d\n", soma);
    
    free(listaD);
    free(listaE);
    
    fclose(inputFile);
    return 0;
}
