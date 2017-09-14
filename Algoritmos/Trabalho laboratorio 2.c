#include<stdio.h>
#include<stdlib.h>
#define TAM 10

int menu(){
    char op[250];
    int opcao;
    printf("-----------------------------------------\n");
    printf("----------------- Menu ------------------\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar os numeros de todas as estruturas\n");
    printf("3 - Listar os numeros ordenados para cada estrutura auxiliar\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir um elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Limpar tela\n");
    printf("8 - Sair\n");
    do{
        printf("Digite um das opcao: ");
        fflush(stdin);
        gets(op);
         printf("\n ");
    }while(op < 48 && op > 57);


    opcao = atoi(op);

    return opcao;

}
 typedef struct{
    int tam;
    int qtd;
    int *p;
    //int *n;
    int* auxiliar;

}elemento;

void inicializarLista(elemento lista[TAM]){
    int i;
    for (i = 0; i < TAM; i++){
        lista[i].tam = 0;
        lista[i].qtd = 0;
        lista[i].p = NULL;
        //lista[i].n = NULL;
        lista[i].auxiliar = NULL;
    }
}

void inserir(elemento lista[TAM]){
    int pos;
    int i;
    int numero;
    int x=0;
    do{
        printf("Digite o numero da posicao que vc deseja inserir: ");
        scanf("%d",&pos);
    }while(pos < 1 && pos > 10);

    if(lista[pos-1].tam != 0){
        printf("Digite o elemento que vc deseja inserir: ");
        scanf("%d",&numero);
        x=0;
        for(i=0;i<lista[pos-1].tam;i++){
            if(lista[pos-1].p[i] == NULL){
                lista[pos-1].p[i] = numero;
                 //lista[pos-1].qtd++;
                 x=1;
                printf("Numero Inserido com Sucesso na posicao %d\n", i);
                break;
            }
        }
        if(x == 0)
                printf("---------------- Estrutura com todas as posicoes preenchidas----------------\n");
    }
    else{
        printf("Digite o tamanho da estrutura auxiliar: ");
        scanf("%d",&lista[pos-1].tam);

        lista[pos-1].p = (int*)malloc(lista[pos-1].tam*sizeof(int));

        if(lista[pos-1].p){


            for(i=0;i<lista[pos-1].tam;i++)
                lista[pos-1].p[i] = NULL;

            printf("Digite o elemento que vc deseja inserir: ");
            scanf("%d",&numero);
            for(i=0;i<lista[pos-1].tam;i++)
             if(lista[pos-1].p[i] == NULL){
                lista[pos-1].p[i] = numero;
                //lista[pos-1].qtd++;
                printf("Numero Inserido com Sucesso na posicao %d\n", i);
                break;
             }
        }
        else{
             printf("Espaço em memória insuficiente\n");
            free(lista[pos-1].p);
            exit(1);
        }



    }
}
void printar(elemento lista[TAM]){
    int i;
    int j;
    int tamanho;

    for(i=0;i<TAM;i++){
        if(lista[i].tam == 0)
            printf("Estrutura ainda nao criada\n");
        else{
                printf("\n ");
            printf(">>>Estrutura %d\n",i+1);
            printf("Tamanho da estrutura: %d\n",lista[i].tam);
            tamanho = lista[i].tam;
            for(j=0;j<tamanho;j++){
                if(lista[i].p[j]== NULL)
                    printf("Posicao nao preenchida\n");
                else
                    printf("Elemento: %d\n",lista[i].p[j]);
        }
        }
    }
 }
void ordenar(elemento lista[TAM]){
    int i;
    //int aux=0;
    //int tamanho=0;
    int y;
    //int x=0;
    //int menor=0;
    int aux=0;
    int j;
    //int p=0;
    //int t=0;
        //int tamanho;
        //int auxiliar[t];
    for(y=0;y<TAM;y++){
            if(lista[y].tam != 0 ){
                lista[y].auxiliar = (int*)malloc(lista[y].tam*sizeof(int));
                for(i=0;i< lista[y].tam;i++)
                    lista[y].auxiliar[i] = lista[y].p[i];

                for(i=lista[y].tam -1;i>=1;i--){
                    for(j=0;j<i;j++)
                        if(lista[y].auxiliar[j]>lista[y].auxiliar[j+1]){
                            aux = lista[y].auxiliar[j];
                            lista[y].auxiliar[j] = lista[y].auxiliar[j+1];
                            lista[y].auxiliar[j+1] = aux;
                        }
                        //auxiliar[i] = lista[y].p[p];
                        //auxiliar[p] = lista[y].p[i];
                }

                }
            }
    for(i=0;i<TAM;i++){
        if(lista[i].tam == 0)
            printf("Estrutura ainda nao criada\n");
        else{
            printf("\n ");
            printf(">>>Estrutura %d\n",i+1);
            printf("Tamanho da estrutura: %d\n",lista[i].tam);

            for(j=0;j<lista[i].tam;j++){
                if(lista[i].auxiliar[j]== NULL)
                    printf("Posicao nao preenchida\n");
                else
                    printf("Elemento: %d\n",lista[i].auxiliar[j]);
        }
        }
    }

}

int* criarvetor(int*x,int* y,elemento lista[TAM]){
    int i;
    int j;


     for(i=0;i<TAM;i++){
        if(lista[i].tam != 0){
            y = (int*)realloc(y,(*x+lista[i].tam)*sizeof(int));
             //for(i=0;i<lista[i].tam;i++)
                //lista[i].n[i] = NULL;
            if(y){

                for(j=0;j< lista[i].tam;j++){
                    y[*x + j] = lista[i].p[j];
                }

            *x+=lista[i].tam;
            }
            else{
                 printf("Espaço em memória insuficiente\n");
                free(y);
                exit(1);
            }

        }
     }
     return y;

}

void ordenarVetor(int x,int* y){
    //int tamanho;
    //tamanho = criarvetor(lista);
    int j;
    int aux=0;
    int menor =0;
    int p;
    int i;
    for(i=x-1;i>=1;i--){
        for(j=0;j<i;j++)
            if(y[j]>y[j+1]){
                aux = y[j];
                y[j] = y[j+1];
                y[j+1] = aux;
            }
                        //auxiliar[i] = lista[y].p[p];
                        //auxiliar[p] = lista[y].p[i];
    }

    }



void listarVetor(int x,int* y){
    int i;
    //int tamanho;
    //tamanho = criarvetor(lista);
    for(i = 0;i<x;i++)
        printf("Elemento: %d\n",y[i]);




    free(y);

}

void excluir(elemento lista[TAM]){
    int pos;
    int numero;
    int x=0;
    int i;
    printf(">> Informe a posição da estrutura principal: ");
    scanf("%d",&pos);
    printf( Digite qual numero excluir: ");
    scanf("%d",&numero);

    for(j=0;j<lista[pos].tam;j++){
        if(lista[pos].p[j] == numero)
            x = j;









}
void liberar(int* y, elemento lista[TAM]){
    int i;
    free(y);
    for(i=0;i<TAM;i++){
        free(lista[i].p);
        free(lista[i].auxiliar);
    }
}
int main(){
    int op;
    int x = 0;

    int* y = NULL;
    elemento lista[TAM];
    inicializarLista(lista);
    do{
        op = menu();
        switch(op){
            case 1:
                inserir(lista);
                break;
            case 2:
                printar(lista);
                break;
            case 3:
                ordenar(lista);
                //printar(lista);
                break;
            case 4:
                 y = criarvetor(&x,y,lista);
                ordenarVetor(x,y);
                listarVetor(x,y);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("Limpando tela\n");
                system("cls");
                op = menu();
                break;
            case 8:
                printf("Finalizando o programa\n");
                return 0;
                break;
            default:
                printf("Numero invalido\n");
                break;
        }
    }while(op != 7);


    return 0;
}
