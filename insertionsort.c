#include <stdio.h>
#include <sys/time.h>

void insertionSort(int vetor[], int tamanho) {

  int escolhido, j;

  for (int i = 1; i < tamanho; i++) {
		escolhido = vetor[i];
		j = i - 1;
		
		while ((j >= 0) && (vetor[j] > escolhido)) {
			vetor[j + 1] = vetor[j];
			j--;
		}
		
		vetor[j + 1] = escolhido;
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
  insertionSort(ar, numeros);
  gettimeofday(&stop, NULL);
  
  printf("[");
  for(int i = 0; i < numeros; i++){
    if(i == 0) printf("%d", ar[i]);
    else printf(" %d", ar[i]);
    if(i!=numeros - 1) printf(",");
  }
  printf("]\n\n");
  printf("\n");
  printf("O tempo de execução para a ordenação foi de: %lu microsegundos\n", stop.tv_usec - start.tv_usec);
  return 0;
}
