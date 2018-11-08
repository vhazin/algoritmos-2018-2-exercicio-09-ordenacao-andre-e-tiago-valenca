#include <stdio.h>
#include <sys/time.h>

void heapSort(int ar[], int tamanho);

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
  heapSort(ar, numeros);
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

void heapSort(int ar[], int tamanho) {
   int i = tamanho / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = ar[i];
      } else {
          tamanho--;
          if (tamanho == 0) return;
          t = ar[tamanho];
          ar[tamanho] = ar[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < tamanho) {
          if ((filho + 1 < tamanho)  &&  (ar[filho + 1] < ar[filho]))
              filho++;
          if (ar[filho] < t) {
             ar[pai] = ar[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      ar[pai] = t;
   }
}
