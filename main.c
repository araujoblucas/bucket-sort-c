#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define tam_bucket 100
#define num_bucket 10

typedef struct {
    int topo;
    int balde[tam_bucket];
} bucket;

void bubble(int v[], int tam) {
    int i, j, temp, flag;
    if (tam) {
        for (j = 0; j < tam - 1; j++) {
            flag = 0;
            for (i = 0; i < tam - 1; i++) {
                if (v[i + 1] < v[i]) {
                    temp = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = temp;
                    flag = 1;
                }
            }
            if (!flag) {
                break;
            }
        }
    }
}

void bucket_sort(int v[], int tam) {
    bucket b[num_bucket];
    int i, j, k;

    for (i = 0; i < num_bucket; i++) {
        b[i].topo = 0;
    }

    printf(" 3 \n");
    for (i = 0; i < tam; i++) {
        j = (num_bucket) - 1;
        while (1) {
            if (j < 0)
                break;
            if (v[i] >= j * 100) {
                b[j].balde[b[j].topo] = v[i];
                (b[j].topo)++;
                break;
            }
            j--;
        }
    }

    for (i = 0; i < num_bucket; i++) {
        if (b[i].topo) {
            bubble(b[i].balde, b[i].topo);
        }
    }

    i = 0;

    for (j = 0; j < num_bucket; j++) {
        for (k = 0; k < b[j].topo; k++) {
            v[i] = b[j].balde[k];
            i++;
        }
    }
}

void main() {
    FILE *arquivo;
    arquivo = fopen("array.txt", "r");
    int *meuArray = NULL;
    int tamanhoArray = 0;

    if (arquivo != NULL) {
        int valorLido;
        meuArray = (int *) malloc(MAX_SIZE * sizeof(int));

        if (meuArray == NULL) {
            printf("Erro de alocação de memória.\n");
            return;
        }

        for (int i = 0; i < MAX_SIZE; i++) {
            meuArray[i] = 0;
        }

        while (fscanf(arquivo, "%d", &valorLido) != EOF && tamanhoArray < MAX_SIZE) {
            meuArray[tamanhoArray] = valorLido;
            tamanhoArray++;
        }

        fclose(arquivo);

        printf("Valores lidos do arquivo 'array.txt':\n");

    } else {
        printf("Erro ao abrir o arquivo.\n");
    }

    for (int i = 0; i < tamanhoArray; i++) {
        printf("%d - %d\n", i, meuArray[i]);
    }

    bucket_sort(meuArray, 1000);

    printf("Valores lidos do arquivo ordenados 'array.txt':\n");
    for (int i = 0; i < tamanhoArray; i++) {
        printf("%d - %d\n", i, meuArray[i]);
    }
}
