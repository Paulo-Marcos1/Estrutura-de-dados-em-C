#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 8

void radix_sort(int arr[], int tamanho) {
    int valor_max = arr[0];
    // Encontrar o valor máximo no array
    for(int i = 1; i < tamanho; i++) {
        if(arr[i] > valor_max) {
            valor_max = arr[i];
        }
    }

    int exp = 1;  // A posição do dígito a ser processado (começa pelas unidades)
    int *radix_array[10];
    // Alocar espaço para 10 buckets (um para cada dígito de 0 a 9)
    for(int i = 0; i < 10; i++) {
        radix_array[i] = (int *)malloc(sizeof(int) * tamanho);  // Alocar memória para cada bucket
    }
    int counts[10] = {0};  // Contador para cada bucket (dígito)

    // Iterar sobre cada dígito (unidade, dezena, centena, etc.)
    while (valor_max / exp > 0) {
        // Distribuir os elementos nos buckets de acordo com o dígito atual
        for(int i = 0; i < tamanho; i++) {
            int radix_index = (arr[i] / exp) % 10;  // Obter o dígito correspondente
            radix_array[radix_index][counts[radix_index]] = arr[i];  // Adicionar ao bucket correspondente
            counts[radix_index]++;
        }

        int pos = 0;
        // Recolher os elementos de volta para o array original, ordenados por esse dígito
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < counts[i]; j++) {
                arr[pos] = radix_array[i][j];
                pos++;
            }
            counts[i] = 0;  // Resetar o contador para o próximo dígito
        }

        exp *= 10;  // Avançar para o próximo dígito (dezena, centena, etc.)
    }

    // Liberar a memória alocada para os buckets
    for(int i = 0; i < 10; i++) {
        free(radix_array[i]);
    }
}

int main() {
    int arr[TAMANHO] = {170, 45, 75, 90, 802, 24, 2, 66};
    printf("Array original: ");
    for(int i = 0; i < TAMANHO; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radix_sort(arr, TAMANHO);  // Chamar o algoritmo de ordenação Radix Sort

    printf("Array ordenado: ");
    for(int i = 0; i < TAMANHO; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
