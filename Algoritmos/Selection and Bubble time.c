#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tmp;
double tempo;
clock_t t0, t1;
void ordenar(int *vetor, int n){
    int menor=0,aux=0,p=0;
     t0 = clock();
    for(int i=0;i<n;i++){
        menor = vetor[i];
        for(int j=i+1;j<n;j++)
            if(vetor[j]<menor){
                menor = vetor[j];
                p=j;
            }
        if(menor!=vetor[i]){
            aux = vetor[i];
            vetor[i]= vetor[p];
            vetor[p] = aux;
        }
    }
     t1 = clock();
    tempo = (double) (t1-t0) / (CLOCKS_PER_SEC) * 1000;
    printf("n = %d tempo em msec %f\n",n,tempo);
}
void ordenarB(int *vetor, int n){
    int aux=0;
    t0 = clock();
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<i;j++)
            if(vetor[j]>vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
    }
    t1 = clock();
     tempo = (double) (t1-t0) / (CLOCKS_PER_SEC) * 1000;
    printf("n = %d tempo em msec %f\n",n,tempo);
}
void aleatorio(int *vetor,int n){
 for(int i=0;i<n;i++)
         vetor[i] = (int) (rand()%n);

}


int main(){
    int v[100],v1[1000],v2[10000],v3[100000];
    aleatorio(v,100);
    aleatorio(v1,1000);
    aleatorio(v2,10000);
    aleatorio(v3,100000);

    printf(">> Selection Sort\n");
    ordenar(v,100);
    ordenar(v1,1000);
    ordenar(v2,10000);
    ordenar(v3,100000);
    printf(">>Bubble Sort\n");
    ordenarB(v,100);
    ordenarB(v1,1000);
    ordenarB(v2,10000);
    ordenarB(v3,100000);


    return 0;
}
