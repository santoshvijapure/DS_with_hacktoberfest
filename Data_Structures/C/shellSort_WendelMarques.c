// LANGUAGE: C
// ENV: gcc
// AUTHOR: WendelMarques
// GITHUB: https://github.com/WendelMarques

#include <stdio.h>
#define TAM 1000

void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }

}

int main ( ) {

  int vet[] = {4, 6, 15, 1515, 1, 23};
  int size = 6, i;

  shellSort(vet, size);

  for(i = 0; i < size; i++)
    printf("%i ", vet[i]);
  printf("\n");

  return 0;
}
