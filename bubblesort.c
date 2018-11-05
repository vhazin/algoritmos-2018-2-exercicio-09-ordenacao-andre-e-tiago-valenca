/* Código do algoritmo de ordenação BubbleSort */

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

void bubbleSort(int *, int);

int main() {
    int n, i;
    printf("Digite o tamanho da sequência: ");
    scanf("%d", &n);

    int sequencia[n];

    printf("Digite os elementos da sequência: ");

    for (i = 0; i < n; i++)
        scanf("%d", &sequencia[i]);
    
    struct timeval start, stop;
    gettimeofday(&start, NULL);
    bubbleSort(sequencia, n);
    gettimeofday(&stop, NULL);

    printf("Tempo de execução da ordenação: %lu ms\n", stop.tv_usec - start.tv_usec);

    return 0;
}

void bubbleSort(int array[], int tamanho) {
    int j = tamanho, k, temp, m = tamanho - 2;

    for (k = 0; k < tamanho; k++) {
        
        for (j = tamanho - 1; j >= k + 1; j--) {

            if (array[j] < array[m]) {
                temp = array[j];
                array[j] = array[m];
                array[m] = temp;
                
            }

            m--;
        }

        m = tamanho - 2;
    }

    for (k = 0; k < tamanho; k++)
        printf("%d ", array[k]);

    printf("\n");

}