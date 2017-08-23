#include <stdio.h>
#include <stdlib.h>

struct Estrutura {
    int atual;
    int tamanho;
    int* vetor;
}

typedef struct Estrutura s;

int main(){
    s* estrutura = (s*)malloc(10 * sizeof(s));
    estrutura[0]->tamanho = 10;
    estrutura[0]->atual = 0;
    estrutura[0]->vetor = (int*)malloc(10 * sizeof(int));
    estrutura[0]->vetor[1];
} 
