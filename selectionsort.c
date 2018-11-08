#include <stdio.h>
#include <sys/time.h>

void selectionSort(int vetor[], int tamanho) { 
  int i, j, min, aux;
  for (i = 0; i < (tamanho-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tamanho; j++) {
       if(vetor[j] < vetor[min]) 
         min = j;
     }
     if (vetor[i] != vetor[min]) {
       aux = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = aux;
     }
  }
}

int main(void) {
  int numeros;
  printf("Digite o numero de elementos no array : ");
  scanf("%d", &numeros);
  int ar[numeros];
  
  for(int i = 0; i < numeros; i++){
    //scanf("%d", &ar[i]);
    ar[i] = rand();
  }
  
  struct timeval stop, start;
  gettimeofday(&start, NULL);
  selectionSort(ar, numeros);
  gettimeofday(&stop, NULL);
  
  printf("[");
  for(int i = 0; i < numeros; i++){
    if(i == 0) printf("%d", ar[i]);
    else printf(" %d", ar[i]);
    if(i!=numeros - 1) printf(",");
  }
  printf("]");

  printf("O tempo de execução para a ordenação foi de: %d microsegundos\n", stop.tv_usec - start.tv_usec);
  return 0;
}
