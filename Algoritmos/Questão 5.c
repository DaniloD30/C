#include <stdio.h>
#include <stdlib.h>

int QtdDigitos(int num);

int q5(int num){
    int TAM;
    int vetor[TAM];
    int mult=1;
    int n=0;
    for(int i=0;i<TAM;i++){  //PREENCHENDO VETOR DA BASE COM CADA DIGITO DO NUMERO DA BASE
        vetor[i] = num/x;
        numerobase = num%x;
        x = x/10;
    }
    for(int i=TAM-1;i>=0;i--){
        n+=vetor[i]*mult;
        mult*=10;
    }
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
int main()
{
    printf("Hello world!\n");
    return 0;
}
