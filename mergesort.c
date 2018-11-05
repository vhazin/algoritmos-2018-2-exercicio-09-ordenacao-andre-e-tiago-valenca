/* Código do método de ordenação MergeSort */

# include <stdio.h>
# include <math.h>
# include <sys/time.h>

void mergeSort(int *,int,int,int);


int main() {

    int n, m, media;
    printf("Digite o tamanho da sequência: ");
    scanf("%d", &n);

    int array[n];

    printf("Digite a sequência: ");

    for (m = 0; m < n; m++) {
        scanf("%d", &array[m]);
    }

    printf("\n");

    media = (n - 1)/2;

    struct timeval start, stop;

    gettimeofday(&start, NULL); 
    mergeSort(array,0,media,n);
    gettimeofday(&stop, NULL);

    printf("Tempo de execução da ordenação: %lu ms\n", stop.tv_usec - start.tv_usec);

    return 0;
}

void mergeSort(int A[], int p, int q, int r) {
    int n1, n2, s, t, a, b, i, j, k;
    n1 = q - p + 1;
    n2 = (r - 1) - q;

    s = n1 + 1;
    t = n2 + 1;
    int L[s], R[t];

    //p = p + 1; // correção para o vetor L[].

    for (i = 1; i < s; i++) {
        a = p + i - 1; // trabalhar nesta expressão
        L[i - 1] = A[a];
    }

    for (j = 1; j < t; j++) {
        b = q + j;
        R[j - 1] = A[b];
    }

    // Representação de números infinitos //
    L[s] = 2147483647;
    R[t] = 2147483647; 

    i = j = 0;
    
    for (k = p; k < r; k++) {

        if (L[i] <= R[j]) {

            A[k] = L[i];
            i = i + 1;

        } else {

            A[k] = R[j];
            j = j + 1;
        }
    }
    
    
    for (int y = 0; y < r; y++) {
        printf("%d ", A[y]);
    }
    

    /*
    for (int y = 0; y < n1; y++) {
        printf("%d ", L[y]);
    }
    
    printf("\n");

    for (int y = 0; y < n2; y++) {
        printf("%d ", R[y]);
    }
    */
    printf("\n");
}