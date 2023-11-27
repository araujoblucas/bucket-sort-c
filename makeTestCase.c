#include <stdio.h>
#include <stdlib.h>


void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main(int arg,char* argv[]) {
    char *name = argv[1];
    int arraySize = atoi(argv[2]);
    int array[arraySize];

        FILE *arquivo;
        arquivo = fopen(name, "w");

    if (arquivo != NULL) {
        for (int i = 0; i < arraySize; i++) {
            array[i] = i;
        }

        shuffle(array, arraySize);

        for (int i = 0; i < arraySize; i++) {
            fprintf(arquivo, "%d\n", array[i]);
        }
        fclose(arquivo);
    } else {
        printf("Open file error.\n");
    }

    return 0;
}
