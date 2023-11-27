#include <stdio.h>
#include <stdlib.h>


void shuffle(int *array, int size) {
    if (size > 1) {
        int i;
        for (i = 0; i < size - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (size - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main(int arg, char *argv[]) {
    char *name = argv[1];
    int arraySize = atoi(argv[2]);
    int array[arraySize];

    FILE *file;
    file = fopen(name, "w");

    if (file != NULL) {
        for (int i = 0; i < arraySize; i++) {
            array[i] = i;
        }

        shuffle(array, arraySize);

        for (int i = 0; i < arraySize; i++) {
            fprintf(file, "%d\n", array[i]);
        }
        fclose(file);
    } else {
        printf("Open file error.\n");
    }

    return 0;
}
