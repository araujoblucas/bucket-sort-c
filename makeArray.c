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

int main() {
    // Seu array de exemplo
    int tamanhoArray = 1000; // Obtém o tamanho do array
    int meuArray[tamanhoArray];

        FILE *arquivo;
        arquivo = fopen("array.txt", "w"); // Abre o arquivo para escrita (cria se não existir)

    if (arquivo != NULL) {
        // Escreve cada elemento do array no arquivo
        for (int i = 0; i < tamanhoArray; i++) {
            meuArray[i] = i;
        }

        for (int i = 0; i < tamanhoArray; i++) {
            printf( "%d\n", meuArray[i]);
        }

        for (int i = 0; i < tamanhoArray; i++) {
            fprintf(arquivo, "%d\n", meuArray[i]);
        }


        fclose(arquivo); // Fecha o arquivo
        printf("Array salvo no arquivo 'array.txt'.\n");
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }

    return 0;
}
