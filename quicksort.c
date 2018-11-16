/* Algoritmo de Ordenação Quicksort */

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

int partition(int *,int,int);
void quicksort(int *,int,int);

int main() {
    int n, k;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int A[n];

    for (k = 0; k < n; k++) {
        //scanf("%d", &A[k]);
        A[k] = rand();
    }

    struct timeval start, stop;

    gettimeofday(&start,NULL);
    quicksort(A,0,n);
    gettimeofday(&stop,NULL);

    for (k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }

    printf("\n\n");

    printf("Tempo de execução: %lu us\n", stop.tv_usec - start.tv_usec);
    return 0;
}

void quicksort(int A[],int p,int r){

    int q;

    if (p < r) {
        q = partition(A,p,r);
        quicksort(A,p,q);
        quicksort(A,q+1,r);
    }
    
}

int partition(int A[],int p,int r) {

    // O pivô x é colocado no início do vetor.
    int x = A[p], i, j, aux;
    i = r;
    for (j = r - 1; j > p; j--) {
        if (A[j] >= x) {
            i = i - 1;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        } 
    }
    aux = A[i-1];
    A[i-1] = A[p];
    A[p] = aux;

    return (i-1);
}

