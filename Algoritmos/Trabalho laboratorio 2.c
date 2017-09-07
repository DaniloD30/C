#include<stdio.h>
#include<stdlib.h>
#define TAM 10

int menu(){
    int op;
    printf("----------------- Menu ------------------\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar os numeros de todas as estruturas\n");
    printf("3 - Listar os numeros ordenados para cada estrutura auxiliar\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir um elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Sair\n");
    scanf("%d",&op);
    return op;

}
 typedef struct  {
    int tam;
    int qtd;
    int *p;
}elemento;

void inicializarLista(elemento lista[TAM]){
    int i;
    for (i = 0; i < TAM; i++){
        lista[i].tam = 0;
        lista[i].qtd = 0;
        lista[i].p = NULL;
    }
}

void inserir(elemento lista[TAM]){
    int pos;
    int i;
    int numero;
    printf("Digite o numero da posicao que vc deseja inserir: ");
    scanf("%d",&pos);
    if(lista[pos-1]->p == NULL){
        printf("Digite o elemento que vc deseja inserir: ");
        scanf("%d",&numero);
        for(i=0;i<TAM;i++){
            if(lista[pos-1]->p[i+1]!= 0){
                lista[pos-1]->qtd++;
                if( lista[pos-1]->qtd == TAM)
                    printf("Nao tem mais espacos para inserir um numero nessa estrutura\n");
            }
            else
                p[i+1] = numero;
                 lista[pos-1]->qtd++;
        }
    }
    else{
        inicializarLista(lista);
        printf("Digite o tamanho da estrutura auxiliar: ");
        scanf("%d",&lista[pos-1].tam);
        *p = (int*)malloc(lista[pos].tam*sizeof(int));
        printf("Digite o elemento que vc deseja inserir: ");
        scanf("%d",&numero);
        for( i=0;i<TAM;i++){
            if(lista.[pos-1]->p[i+1]!= 0){
                lista[pos-1]->qtd++;
                if( lista[pos-1]->qtd == TAM)
                    printf("Nao tem mais espacos para inserir um numero nessa estrutura\n");
            }
            else{
                lista[pos-1]->p[i+1] = numero;
                 lista[pos-1].qtd++;
            }
        }
    }
}


 void listar(elemento lista[TAM]){
    int i;
    int n;
    for(i=0;i<TAM;i++){
        if(lista[i+1]->p != NULL){
            printf("Estrutura ainda nao criada\n");
            return 0;
        }
        printf("Estrutura %d",i+1);

        for(j=0;j<=lista[i+1]->p;j++)
                printf("Elemento: %d\n",lista[i+1]->p[j+1]);


    }


 }
void ordenar(elemento lista[TAM]){
    int i;
    int aux=0;
    for(i=0;i<TAM;i++){
        for(j=1;j<=lista[i]->p;j++){
            if(lista[i]->p[j+1] < lista[i]->p[j]){
                aux = lista[i]->p[j+1];
                lista[i]->p[j+1] = lista[i]->p[j];
                lista[i]->p[j] = aux;
            }
        }
    }


}


int main(){
    int op;
    elemento lista[TAM];
    int pos;
    do{
        op = menu();
        switch(op){
            case 1:
                inserir(lista);
                break;
            case 2:
                listar(lista);
                break;
            case 3:

            case 7:
                return 0;
                break;
        }
    }while(op != 7);



}
