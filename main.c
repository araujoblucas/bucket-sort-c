#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//#define tam_bucket 10000
#define num_bucket 10
#define CHUNK_SIZE 100

typedef struct {
    int top;
    int *bucket;
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
    int tam_bucket = tam / num_bucket;
    bucket b[num_bucket];
    int i, j, k;

    for (i = 0; i < num_bucket; i++) {
        b[i].top = 0;
        b[i].bucket = (int *)malloc(tam_bucket * sizeof(int));
    }

    for (i = 0; i < num_bucket; i++) {
        b[i].top = 0;
    }

    for (i = 0; i < tam; i++) {
        j = (num_bucket) - 1;
        while (1) {
            if (j < 0) {
                break;
            }
            if (v[i] >= j * tam_bucket) {
                b[j].bucket[b[j].top] = v[i];
                (b[j].top)++;
                break;
            }
            j--;
        }
    }
#pragma omp parallel for
    for (i = 0; i < num_bucket; i++) {
        if (b[i].top) {
            bubble(b[i].bucket, b[i].top);
        }
    }

    i = 0;

#pragma omp parallel for shared(v, i)
    for (j = 0; j < num_bucket; j++) {
        for (k = 0; k < b[j].top; k++) {
            v[i] = b[j].bucket[k];
            i++;
        }
    }

    for (i = 0; i < num_bucket; i++) {
        free(b[i].bucket);
    }
}

void main(int arg, char *argv[]) {
    FILE *arquivo, *arquivoForWrite;
    arquivo = fopen(argv[1], "r");
    int *meuArray = NULL;
    int tamanhoArray = 0;
    int maxElements = atoi(argv[3]);
    double start, end;

    if (arquivo != NULL) {
        int valorLido;
        meuArray = (int *) malloc(maxElements * sizeof(int));

        if (meuArray == NULL) {
            printf("Failed on memory allocation.\n");
            return;
        }

        for (int i = 0; i < maxElements; i++) {
            meuArray[i] = 0;
        }

        while (fscanf(arquivo, "%d", &valorLido) != EOF && tamanhoArray < maxElements) {
            meuArray[tamanhoArray] = valorLido;
            tamanhoArray++;
        }

        fclose(arquivo);

        printf("Values read from %s\n", argv[1]);

    } else {
        printf("Open file error.\n");
    }

    start = omp_get_wtime();
    {
    bucket_sort(meuArray, maxElements);
    }
    end = omp_get_wtime();

    arquivoForWrite = fopen(argv[2], "w");
    for (int i = 0; i < tamanhoArray; i++) {
        fprintf(arquivoForWrite, "%d\n", meuArray[i]);
    }
    printf("Sorted values saved on %s.\n", argv[2]);
    printf("Tempo: %4.2f\n", end - start);
}
