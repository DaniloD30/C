#include <stdio.h>
#include <stdlib.h>
int digitos(int numerobase);

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias;
    int TAM=0;
    TAM = digitos(numerobase);
    int vetor[TAM];
    for(int i=0;i<=TAM;i++){
        vetor[i] = numerobase/TAM;


    }
     for(int i=0;i<=TAM;i++)
            if(vetor[i]==numerobusca)
                qtdOcorrencias++;


    return qtdOcorrencias;
}
int digitos(int numerobase){
        int i=1;
        int qtd=0;
        while(i<numerobase){
            i*=10;
            qtd++;
        }
        return qtd;

}
int main()
{
    int numerobase;
    int numerobusca;
    int ocorrencia=0;
    scanf("%d %d",&numerobase,&numerobusca);
    ocorrencia = q6(numerobase,numerobusca);


    printf("Numero de ocorrencias eh de: %d\n",ocorrencia);
    return 0;
}


