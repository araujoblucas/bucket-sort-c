#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define numberOfBuckets 10

typedef struct {
    int top;
    int *bucket;
} bucket;

void bubble_sort(int v[], int size) {
    int i, j, temp, flag;
    if (size) {
        for (j = 0; j < size - 1; j++) {
            flag = 0;
            for (i = 0; i < size - 1; i++) {
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

void bucket_sort(int v[], int size) {
    int sizeBucket = size / numberOfBuckets;
    bucket b[numberOfBuckets];
    int i, j, k;

    for (i = 0; i < numberOfBuckets; i++) {
        b[i].top = 0;
        b[i].bucket = (int *) malloc(sizeBucket * sizeof(int));
    }

    for (i = 0; i < numberOfBuckets; i++) {
        b[i].top = 0;
    }

    for (i = 0; i < size; i++) {
        j = (numberOfBuckets) - 1;
        while (1) {
            if (j < 0) {
                break;
            }
            if (v[i] >= j * sizeBucket) {
                b[j].bucket[b[j].top] = v[i];
                (b[j].top)++;
                break;
            }
            j--;
        }
    }

#pragma omp parallel for schedule(dynamic)
    for (i = 0; i < numberOfBuckets; i++) {
        if (b[i].top) {
            bubble_sort(b[i].bucket, b[i].top);
        }
    }

    i = 0;

    for (j = 0; j < numberOfBuckets; j++) {
        for (k = 0; k < b[j].top; k++) {
            v[i] = b[j].bucket[k];
            i++;
        }
    }

    for (i = 0; i < numberOfBuckets; i++) {
        free(b[i].bucket);
    }
}

int main(int arg, char *argv[]) {
    FILE *file, *fileForWrite;
    file = fopen(argv[1], "r");
    int *array = NULL;
    int sizeArray = 0;
    int maxElements = atoi(argv[3]);
    double start, end;

    if (file != NULL) {
        int readValue;
        array = (int *) malloc(maxElements * sizeof(int));

        if (array == NULL) {
            printf("Failed on memory allocation.\n");
            return 1;
        }

        for (int i = 0; i < maxElements; i++) {
            array[i] = 0;
        }

        while (fscanf(file, "%d", &readValue) != EOF && sizeArray < maxElements) {
            array[sizeArray] = readValue;
            sizeArray++;
        }

        fclose(file);

        printf("Values read from %s\n", argv[1]);

    } else {
        printf("Open file error.\n");
        return 1;
    }

    start = omp_get_wtime();

    bucket_sort(array, maxElements);

    end = omp_get_wtime();

    fileForWrite = fopen(argv[2], "w");
    for (int i = 0; i < sizeArray; i++) {
        fprintf(fileForWrite, "%d\n", array[i]);
    }
    printf("Sorted values saved on %s.\n", argv[2]);
    printf("Tempo: %4.2f\n", end - start);
}
