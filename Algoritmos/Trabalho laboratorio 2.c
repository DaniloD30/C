#include<stdio.h>
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
    printf("Digite o numero da posicao que vc deseja inserir: ");
    scanf("%d",&pos);
    if(pos >= 0 && pos < TAM)
    if (lista[pos-1].p != NULL){
        
        
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
               
                
                
            case 7:
                return 0;
                break;
        }
    }while(op != 7);


    
}
