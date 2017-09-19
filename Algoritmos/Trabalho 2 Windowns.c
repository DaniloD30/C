#include<stdio.h>
#include<stdlib.h>
#define TAM 10

int menu(){
    char op[250];


    int opcao;
    printf("-----------------------------------------\n");
    printf("----------------- Menu ------------------\n");
    printf("0- Criar estrutura\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar os numeros de todas as estruturas\n");
    printf("3 - Listar os numeros ordenados para cada estrutura auxiliar\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir um elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Limpar tela\n");
    printf("8 - Sair\n");

    printf("Digite um das opcao: ");
    fflush(stdin);
    gets(op);
    printf("\n ");



    opcao = atoi(op);

    return opcao;

}
 typedef struct{
    int tam;
    int qtd;
    int *p;
    int* auxiliar;

}elemento;

int verificar(char numero[]){
    int i;
    int y=1;

    int pos;
    for(i=0;numero[i];i++){
        if(numero[i] < 48 || numero[i] > 57){
            y = 0;
            break;
        }
    }
    if(y){
        pos = atoi(numero);
                if(pos < 1 || pos > 10){
                    printf(">> Digite uma posicao entre os numeros 1 e 10\n");
                    printf(">> Posicao Invalida\n");

                }
                else
                    return pos;
    }
    else{
        printf("Posicao invalida\n");
        return -1;
    }
}
int verificarNumeroInserido(char numero[]){
    int i;
    int y=1;


    for(i=0;numero[i];i++){
        if(numero[i] == 45){
            y = 1;
            continue;
        }
        if(numero[i] < 48 || numero[i] > 57 ){
            y = 0;
            break;
        }

    }
    if(y)
       return y;
    else{
        printf(">> Caracters especiais ou letras, nao sao possiveis ser inseridos na estrutura\n");
        return y;
    }


}

void inicializarLista(elemento lista[TAM]){
    int i;
    for (i = 0; i < TAM; i++){
        lista[i].tam = 0;
        lista[i].qtd = 0;
        lista[i].p = NULL;
        lista[i].auxiliar = NULL;
    }
}
void criarLista(elemento lista[TAM]){
    char posicao[250];
    int pos;
    int i;


    do{
        printf("Digite o numero da posicao que voce deseja criar uma estrutura: ");
        gets(posicao);
        pos = verificar(posicao);
    }while(pos < 1 || pos > 10);

    if(lista[pos-1].tam == 0){
        printf("Digite o tamanho da estrutura auxiliar: ");
        scanf("%d",&lista[pos-1].tam);

        lista[pos-1].p = (int*)malloc(lista[pos-1].tam*sizeof(int));
        if(lista[pos-1].p)
            for(i=0;i<lista[pos-1].tam;i++)
                lista[pos-1].p[i] = NULL;

        else{
                printf("Estrutura nao criada\n");
                printf("Espaço em memória insuficiente\n");
                free(lista[pos-1].p);
                exit(1);
        }
        printf("Estrutura criada com sucesso\n");
    }
    else
        printf("Estrutura ja criada anteriormente com %d posicoes\n",lista[pos-1].tam);
}

void inserir(elemento lista[TAM]){
    int pos;
    char posicao[250];

    int i;
    int numero;
    int y=0;
    char n[250];
    int x=0;


        do{
            printf("Digite o numero da posicao que voce deseja inserir um elemento na estrutura: ");
            gets(posicao);
            pos = verificar(posicao);
        }while(pos < 1 || pos > 10);


    if(lista[pos-1].tam != 0){
        do{
            printf("Digite o elemento que vc deseja inserir na estrutura: ");
            gets(n);
            y = verificarNumeroInserido(n);
            if(y)
                numero = atoi(n);
        }while(y == 0);
            x=0;
            for(i=0;i<lista[pos-1].tam;i++){
                if(lista[pos-1].p[i] == NULL){
                    lista[pos-1].p[i] = numero;

                    x=1;
                    printf("Numero Inserido com Sucesso na posicao %d\n", i+1);
                    break;
                }
            }
            if(x == 0)
                printf("---------------- Estrutura com todas as posicoes preenchidas----------------\n");
        }
    else{
        printf("Estrutura ainda nao criada\n");
        printf("Escolha a opcao 0 no menu principal para criar uma estrutura\n");
    }


}
void printar(elemento lista[TAM]){
    int i;
    int j;
    int tamanho;

    for(i=0;i<TAM;i++){
        if(lista[i].tam == 0){
            printf(">> Estrutura %d ainda nao criada\n",i+1);
        }
        else{
            printf("\n ");
            printf(">>> Estrutura %d\n",i+1);
            printf(">>> Tamanho da estrutura: %d\n",lista[i].tam);
            tamanho = lista[i].tam;
            for(j=0;j<tamanho;j++){
                if(lista[i].p[j]== NULL){
                    printf(">> Posicao %d nao preenchida\n",j+1);
                    printf("\n");
                }
                else
                    printf("Elemento: %d\n",lista[i].p[j]);
            }
        }
    }

 }
void ordenar(elemento lista[TAM]){
    int i;
    int x=0;
    int aux=0;
    int j;
    int pos;
    char posicao[250];


     do{
            printf("Digite a posicao que voce deseja ordenar: ");
            gets(posicao);
            pos = verificar(posicao);
     }while(pos < 1 || pos > 10);

    if(lista[pos-1].tam != 0 ){
                x=1;
                lista[pos-1].auxiliar = (int*)malloc(lista[pos-1].tam*sizeof(int));
                for(i=0;i< lista[pos-1].tam;i++){
                    if(lista[pos-1].p[i] != NULL){
                        lista[pos-1].auxiliar[i] = lista[pos-1].p[i];
                        lista[pos-1].qtd++;
                    }
                }

                for(i=lista[pos-1].qtd-1;i>=1;i--){
                    for(j=0;j<i;j++)
                        if(lista[pos-1].auxiliar[j]>lista[pos-1].auxiliar[j+1]){
                            aux = lista[pos-1].auxiliar[j];
                            lista[pos-1].auxiliar[j] = lista[pos-1].auxiliar[j+1];
                            lista[pos-1].auxiliar[j+1] = aux;
                        }

                }

                }
    else{
        printf(">> Estrutura %d ainda nao criada\n",pos);
        printf(">> Escolha a opcao 0 no menu principal para criar uma estrutura\n");
        x = 0;
    }

    if(x){
            printf("\n ");
            printf(">>>Estrutura %d\n",pos);

            printf("---Elementos Ordenados:\n");
            for(j=0;j<lista[pos-1].qtd;j++){
               printf("Elemento: %d\n",lista[pos-1].auxiliar[j]);
            }

            lista[pos-1].qtd = 0;

        }

}

int* criarvetor(int*x,int* y,elemento lista[TAM]){
    int i;
    int j;
    int z = 0;

     for(i=0;i<TAM;i++){
        if(lista[i].tam != 0){
                z=1;
                y = (int*)realloc(y,(*x+lista[i].tam)*sizeof(int));
                for(j=0;j< lista[i].tam;j++){
                      y[*x + j] = lista[i].p[j];

                }
                *x+=lista[i].tam;
        }

    }

    if(z==0){
         printf("Nenhuma estrutura criada\n");
        printf("Escolha a opcao 0 no menu principal para criar uma estrutura\n");
    }


     return y;

}

void ordenarVetor(int x,int* y){

    int j;
    int aux=0;

    int i;
    for(i=x-1;i>=1;i--){
        for(j=0;j<i;j++)
            if(y[j]>y[j+1]){
                aux = y[j];
                y[j] = y[j+1];
                y[j+1] = aux;
            }

    }

    }



void listarVetor(int x,int* y){
    int i;

    if(x != 0)
        for(i = 0;i<x;i++){
            if(y[i] != NULL)
                printf("Elemento: %d\n",y[i]);
        }

}

void excluir(elemento lista[TAM]){
    int pos;

    char posicao[250];
    int numero;
    int x=0;

    int j;
    int tamanho =0;

    do{
            printf(">> Informe a posicao da estrutura principal: ");
            gets(posicao);
            pos = verificar(posicao);
    }while(pos < 1 || pos > 10);

    printf( "Digite qual numero excluir: ");
    scanf("%d",&numero);

    if(lista[pos-1].tam != 0){
        tamanho = lista[pos-1].tam;
        for(j=0;j<tamanho;j++){
            if(lista[pos-1].p[j] == numero){
                x = 1;
                lista[pos-1].p[j] = lista[pos-1].p[tamanho - 1];
                lista[pos-1].p[tamanho - 1] = NULL;
                printf(">> Numero excluido com sucesso\n");
                break;
            }
        }

    }
     if(x==0)
            printf(">> Numero inexistente na estrutura %d\n",pos);
}
void realloca(elemento lista[TAM]){
    int add;
    int pos;

    char posicao[250];
    int i;
    int tamanhoAnterior =0;

   do{
            printf("Informe a posicao da estrutura principal que voce deseja aumentar o tamanho: ");
            gets(posicao);
            pos = verificar(posicao);
   }while(pos < 1 || pos > 10);

    printf("Digite o numero de inteiros extras a entrarem na estrutura: ");
    scanf("%d",&add);
    if(lista[pos-1].tam != 0){
        tamanhoAnterior = lista[pos-1].tam;
        lista[pos-1].p = (int*)realloc(lista[pos-1].p,(add+lista[pos-1].tam)*sizeof(int));
        lista[pos-1].tam += add;
        for(i=tamanhoAnterior;i<lista[pos-1].tam;i++){
            lista[pos-1].p[i] = NULL;
        }
        printf(">> Estrutura auxiliar aumentada com sucesso\n");
    }
    else
        printf(">> Estrutura ainda nao criada para adicionar inteiros extras\n");
}
void liberar(elemento lista[TAM]){
    int i;

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
            case 0:
                criarLista(lista);

                break;
            case 1:
             inserir(lista);
                break;
            case 2:
                printar(lista);
                break;
            case 3:
                ordenar(lista);
                break;
            case 4:
                 y = criarvetor(&x,y,lista);
                ordenarVetor(x,y);
                listarVetor(x,y);
                 free(y);
                 y = NULL;
                 x = 0;
                break;
            case 5:
                excluir(lista);
                break;
            case 6:
                realloca(lista);
                break;
            case 7:
                printf("Limpando tela\n");
                system("cls");
                break;
            case 8:
                printf("Finalizando o programa\n");
                liberar(lista);
                return 0;
                break;
            default:
                printf("Numero invalido\n");
                break;
        }
    }while(op != 7);
    return 0;
}
