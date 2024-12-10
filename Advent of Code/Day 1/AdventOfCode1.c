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
    
    inputFile = fopen("inputTest.txt", "r");
    
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
    
    printf("Lista D:\n");
    for (int i = 0; i < cont; i++) {
        printf("%d \n", listaD[i]);
    }
    
    printf("\nLista E:\n");
    for (int i = 0; i < cont; i++) {
        printf("%d \n", listaE[i]);
    }
    
    for (int i = 0; i < cont; i++) {
        if (listaD[i] > listaE[i]) {
            resultado += (listaD[i] - listaE[i]);
        } else {
            resultado += (listaE[i] - listaD[i]);
        }
    }
    
    printf("\nResultado: \n");
    printf("%d \n", resultado);
    
    int qntD = 0;
    int soma = 0;
    
    
    
    free(listaD);
    free(listaE);
    
    fclose(inputFile);
    return 0;
}
