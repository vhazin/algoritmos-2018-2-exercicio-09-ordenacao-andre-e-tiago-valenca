//QuickSort com pivô no final
#include <stdio.h>
#include <stdlib.h> 
#include <sys/time.h> 

void trocar(int *a, int *b); 
int divisor (int ar[], int inicio, int fim); 
void quickSort(int ar[], int inicio, int fim); 

int main(void) {
  int numeros;
  printf("Digite o numero de elementos no array : ");
  scanf("%d", &numeros);
  int ar[numeros];
  
  for(int i = 0; i < numeros; i++){
    ar[i] = rand();
  }
  
  struct timeval stop, start;
  gettimeofday(&start, NULL);
  quickSort(ar, 0, numeros-1);
  gettimeofday(&stop, NULL);
  
  printf("[");
  for(int i = 0; i < numeros; i++){
    if(i == 0) printf("%d", ar[i]);
    else printf(" %d", ar[i]);
    if(i != numeros - 1) printf(",");
  }
  printf("]\n");

  printf("O tempo de execução para a ordenação foi de: %d microsegundos\n", stop.tv_usec - start.tv_usec);
  return 0;
}

void trocar(int *a, int *b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t;
    return;
}

int divisor (int ar[], int inicio, int fim) 
{ 
    int pivo = ar[fim];
    int i = (inicio - 1); 
  
    for (int j = inicio; j <= fim- 1; j++) 
    { 
        if (ar[j] <= pivo) 
        { 
            i++; 
            trocar(&ar[i], &ar[j]); 
        } 
    } 
    trocar(&ar[i + 1], &ar[fim]); 
    return (i + 1); 
}

void quickSort(int ar[], int inicio, int fim) 
{ 
    if (inicio < fim) 
    { 
        int index = divisor(ar, inicio, fim); 

        quickSort(ar, inicio, index - 1); 
        quickSort(ar, index + 1, fim); 
    } 
}
