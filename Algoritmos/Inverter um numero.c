#include <stdio.h>
#include <stdlib.h>

int QtdDigitos(int num);
int x;
int q5(int num){
    int TAM=0, mult=1, n=0;
    TAM = QtdDigitos(num);
    int vetor[TAM];
    mult=x;
    for(int i=0;i<TAM;i++){  //PREENCHENDO VETOR DA BASE COM CADA DIGITO DO NUMERO DA BASE
        vetor[i] = num/x;
        num = num%x;
        x = x/10;
    }
    for(int i=TAM-1;i>=0;i--){
        n+=vetor[i]*mult;
        mult=mult/10;
    }
    num=n;
    return num;
}
 int QtdDigitos(int num){
        int i=1;
        int qtd=0;
        while(i<=num){
            i*=10;
            qtd++;
        }
        x=i/10;

        return qtd;
}
int main(){
    int num,invertido=0;
    printf("Digite um numero para ser invertido: ");
    scanf("%d",&num);
    invertido =  q5(num);
    printf("Numero Invertido: %d\n",invertido);

    return 0;
}
