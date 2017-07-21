#include <stdio.h>
#include <stdlib.h>
int QtdDigitosBase(int numerobase);
int QtdDigitosBusca(int numerobusca);
int x;
int y;
//Inicio da função
int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0,TAM=0,TamBusca=0,achou=0;
    int j,k;
    TAM = QtdDigitosBase(numerobase);
    TamBusca = QtdDigitosBusca(numerobusca);
    int vetorBase[TAM];
    int vetorBusca[TamBusca];
    for(int i=0;i<TAM;i++){  //PREENCHENDO VETOR DA BASE COM CADA DIGITO DO NUMERO DA BASE
        vetorBase[i] = numerobase/x;
        numerobase = numerobase%x;
        x = x/10;
    }
    for(int i=0;i<TamBusca;i++){  //PREENCHENDO VETOR DA BUSCA COM CADA DIGITO DO NUMERO DA BUSCA
        vetorBusca[i] = numerobusca/y;
        numerobusca = numerobusca%y;
        y = y/10;
    }
    //printf("Tamanho vetor base: %d\n Tamanho vetor busca: %d\n",TAM,TamBusca);
    for(int i=0;i<TAM;i++){
        j=i;
        k=0;
        //printf("Valor de i percorrendo o vetor: %d\n",i);
        while(j<TAM){
            if(vetorBase[j]==vetorBusca[k]){
                achou++;
                printf("Vetor base %d\n Vetor Busca %d\n",vetorBase[j],vetorBusca[k]);
                j++;
            }
            else
                break;



            k++;
        }
        if(achou==TamBusca)
            qtdOcorrencias++;
            achou=0;
    }
    //printf("Quantidade de ocorrencia: %d\n",qtdOcorrencias);


    return qtdOcorrencias;
}
int QtdDigitosBase(int numerobase){
        int i=1;
        int qtd=0;
        while(i<=numerobase){
            i*=10;
            qtd++;
        }
        x=i/10;

        return qtd;

}
int QtdDigitosBusca(int numerobusca){
        int i=1;
        int qtd=0;
        while(i<=numerobusca){
            i*=10;
            qtd++;
        }
        y=i/10;

        return qtd;

}
int main()
{
    int numerobase;
    int numerobusca;
    int ocorrencia=0;
    printf("Digite um numero: \n");
    scanf("%d", &numerobase);
    printf("Digite um numero a ser pesquisado: \n");
    scanf("%d", &numerobusca);
    ocorrencia = q6(numerobase,numerobusca);


    printf("Numero de ocorrencias eh de: %d\n",ocorrencia);
    return 0;
}
