#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 50

int verifica_seguranca(int *report, int tamanho) {
    if (tamanho <= 1) return 1;

    int direcao = (report[1] > report[0]) ? 1 : -1;

    for (int i = 0; i < tamanho - 1; i++) {
        int dif = abs(report[i + 1] - report[i]);
        if (report[i] == report[i + 1] || dif > 3 || (direcao == 1 && report[i + 1] < report[i]) || (direcao == -1 && report[i + 1] > report[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE *inputFile;
    char linha[MAX_LINHA];
    int safe = 0;
    int unsafe = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while (fgets(linha, MAX_LINHA, inputFile)) {
        char *token;
        int *report = NULL;
        int num, cont = 0;

        token = strtok(linha, " ");
        while (token != NULL) {
            num = atoi(token);
            report = (int *) realloc(report, (cont + 1) * sizeof(int));
            report[cont] = num;
            cont++;
            token = strtok(NULL, " ");
        }

        if (verifica_seguranca(report, cont)) {
            safe++;
        } else {
            int seguro_apos_remocao = 0;

            for (int i = 0; i < cont; i++) {
                int *novo_report = (int *) malloc((cont - 1) * sizeof(int));
                int k = 0;

                for (int j = 0; j < cont; j++) {
                    if (j != i) {
                        novo_report[k++] = report[j];
                    }
                }

                if (verifica_seguranca(novo_report, cont - 1)) {
                    seguro_apos_remocao = 1;
                    free(novo_report);
                    break;
                }

                free(novo_report);
            }

            if (seguro_apos_remocao) {
                safe++;
            } else {
                unsafe++;
            }
        }

        free(report);
    }

    fclose(inputFile);

    printf("Safe: %d\n", safe);
    printf("Unsafe: %d\n", unsafe);

    return 0;
}
