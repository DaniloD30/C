#include <stdio.h>
#include <stdlib.h>
#define TAM 4
int* criarvetor(int*x,int* p){

    int j;
    int add;
    int numero;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&add);
    p = (int*)realloc(p,(*x+add)*sizeof(int));
             //for(i=0;i<lista[i].tam;i++)
                //lista[i].n[i] = NULL;
    if(p){
        for(j=0;j<add;j++){
            printf("Digite o elemento que voce deseja inserir: ");
            scanf("%d",&p[*x+j]);
        }
        *x+=add;
    }
    else{
        printf("Espaço em memória insuficiente\n");
        free(p);
        exit(1);
    }
    return p;
}

int menu(){
    int op;
    printf("1 - Vetor Dinamico\n");
    printf("2 - Ordenar Vetor\n");
    printf("3 - Imprimir vetor\n");
    printf("4 - Excluir\n");
    printf("5 - Sair\n");
    printf("Digite a opcao: ");
    scanf("%d",&op);

    return op;
}
void printa(int x,int* p){
    int i;
    for(i=0;i<x;i++)
        printf("elementos: %d\n",p[i]);
}
void ordenarVetor(int x,int* p){
    //int tamanho;
    //tamanho = criarvetor(lista);
    int j;
    int aux=0;


    int i;

                for(i=x-1;i>=1;i--){
                    for(j=0;j<i;j++)
                        if(p[j]>p[j+1]){
                            aux = p[j];
                            p[j] = p[j+1];
                            p[j+1] = aux;
                        }
                        //auxiliar[i] = lista[y].p[p];
                        //auxiliar[p] = lista[y].p[i];
                }

        }

void excluir(int x,int* p){

    int numero;
    int y=0;
    int i;
    int aux=0;
    int j;
    printf( "Digite qual numero excluir: ");
    scanf("%d",&numero);

    for(j=0;j<x;j++){
        if(p[j] == numero){
            y = j;
            p[j] = NULL;
        }
    }
    for(i=x;i>y-1;i--){
        aux = p[i];
        p[i] = p[i-1];
        p[i-1] = aux;

    }
    }










int main()
{
    int opcao;
    int* p = NULL;
    int x=0;
     do{
        opcao = menu();
        switch(opcao){
            case 1:
                p = criarvetor(&x,p);
                break;
            case 2:
                ordenarVetor(x,p);
                 printa(x,p);
                break;
            case 3:
                printa(x,p);

                //printar(lista);
                break;
            case 4:
                excluir(x,p);
                break;
            case 5:
                printf("Finalizando o programa\n");

                return 0;
                break;
        }
    }while(opcao != 7);
    free(p);
    return 0;
}
