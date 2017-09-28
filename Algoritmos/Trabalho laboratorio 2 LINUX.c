#include<stdio.h>
#include<stdlib.h>
#define TAM 10
void limpatela();

int menu(){
    char op[250];
    int opcao;
    int i;
    int y = 1;
    printf("-----------------------------------------\n");
    printf("----------------- Menu ------------------\n");
    printf("0 - Criar estrutura\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar os numeros de todas as estruturas\n");
    printf("3 - Listar os numeros ordenados para cada estrutura auxiliar\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir um elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Sair\n");
    printf("8 - Imprimir na ordem de tamanho da quantidade de elementos\n");
    printf("9 - Imprimir na ordem da soma dos elementos de cada estrutura\n");
    printf("-----------------------------------------\n");
    printf("-----------------------------------------\n");


    do{
        printf("Digite uma das opcao: ");
        fflush(stdin);
        //__fpurge(stdin);
        //gets(op);
        scanf("%s",&op);
         fflush(stdin);
        //fgets(op,250,stdin);

        printf("\n ");
        for(i=0;op[i];i++){
            if(op[i] < 48 || op[i] > 57){
                y = 0;
                limpatela();
                break;
            }
            else
                y = 1;
        }
    }while(y == 0);

    opcao = atoi(op);

    return opcao;

}
 typedef struct{
    int tam;
    int qtd;
    int *p;
    int* auxiliar;

    //int guardarposicao;
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
             if(numero[i+1] < 48 || numero[i+1] > 57 ){
                y = 0;
                break;
             }
             else
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
int verificarNumero(char numero[]){
    int i;
    int y=1;
    for(i=0;numero[i];i++){
        if(numero[i] == 45){
                 if(numero[i+1] < 48 || numero[i+1] > 57 ){
                    y=0;
                    break;
                 }
                 else
                    continue;
        }
        if(numero[i] < 48 || numero[i] > 57 ){
            y = 0;
            break;
        }

    }
    if(y)
       return y;
    else
        return y;

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
    char tamanho[250];
    int y=0;

    do{
        printf("Digite o numero da posicao que voce deseja criar uma estrutura: ");
        //gets(posicao);
         scanf("%s",&posicao);
         fflush(stdin);
        //fgets( posicao, 250, stdin );
        pos = verificar(posicao);
    }while(pos < 1 || pos > 10);

    if(lista[pos-1].tam == 0){
        do{
            printf("Digite o tamanho da estrutura auxiliar: ");
            //gets(tamanho);
             scanf("%s",&tamanho);
            fflush(stdin);
            //fgets( tamanho, 250, stdin );
            y = verificarNumero(tamanho);
            if(y)
                lista[pos-1].tam = atoi(tamanho);
            else
                printf(">> O Tamanho da estrutura deve ser um numero positivo\n");
        }while(y == 0);

        lista[pos-1].p = (int*)malloc(lista[pos-1].tam*sizeof(int));
        if(lista[pos-1].p)
            printf("Estrutura criada com sucesso\n");
        else{
                printf("Estrutura nao criada\n");
                printf("Espaço em memória insuficiente\n");
                free(lista[pos-1].p);
                exit(1);
        }

    }
    else
        printf("Estrutura ja criada anteriormente com %d posicoes\n",lista[pos-1].tam);
}

void inserir(elemento lista[TAM]){
    int pos;
    char posicao[250];

    int numero;
    int y=0;
    char n[250];


        do{
            printf("Digite o numero da posicao que voce deseja inserir um elemento na estrutura: ");
            //gets(posicao);
            scanf("%s",&posicao);
            fflush(stdin);
            //fgets( posicao, 250, stdin );
            pos = verificar(posicao);
        }while(pos < 1 || pos > 10);


    if(lista[pos-1].tam != 0){
        do{
            printf("Digite o elemento que vc deseja inserir na estrutura: ");
            gets(n);
            //fgets( n, 250, stdin );
            y = verificarNumeroInserido(n);
            if(y)
                numero = atoi(n);
        }while(y == 0);

         if(lista[pos-1].qtd == lista[pos-1].tam )
                printf("---------------- Estrutura com todas as posicoes preenchidas----------------\n");

        else{

            lista[pos-1].p[lista[pos-1].qtd] = numero;
            lista[pos-1].qtd++;

            printf("Numero Inserido com Sucesso na posicao %d\n", lista[pos-1].qtd);

        }



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
            tamanho = lista[i].qtd;
            for(j=0;j<tamanho;j++)
                printf("Elemento: %d\n",lista[i].p[j]);

        }
    }

 }
 void copiandoVetor(int pos,elemento lista[TAM]){
    int i;

    lista[pos-1].auxiliar = (int*)malloc(lista[pos-1].tam*sizeof(int));

    if(lista[pos-1].auxiliar)
        for(i=0;i< lista[pos-1].qtd;i++){
                   lista[pos-1].auxiliar[i] = lista[pos-1].p[i];
        }
    else{
        printf("Espaço em memória insuficiente\n");
        free(lista[pos-1].auxiliar);
    }


 }
 void ordenandoTemporariamente(int pos,elemento lista[TAM]){
    int i;
    int j;
    int aux;

    for(i=lista[pos-1].qtd-1;i>=1;i--){
        for(j=0;j<i;j++)
            if(lista[pos-1].auxiliar[j]>lista[pos-1].auxiliar[j+1]){
                aux = lista[pos-1].auxiliar[j];
                lista[pos-1].auxiliar[j] = lista[pos-1].auxiliar[j+1];
                lista[pos-1].auxiliar[j+1] = aux;
            }

    }

 }
 void ListarOrdenadoTemporario(int pos,elemento lista[TAM]){

     int j;
     printf("\n ");
    printf(">>>Estrutura %d\n",pos);
    printf("---Elementos Ordenados:\n");
    for(j=0;j<lista[pos-1].qtd;j++){
        printf("Elemento: %d\n",lista[pos-1].auxiliar[j]);
    }

 }
void ordenar(elemento lista[TAM]){

    int x=0;


    int pos;
    char posicao[250];


     do{
            printf("Digite a posicao que voce deseja ordenar: ");
            //gets(posicao);
             scanf("%s",&posicao);
            fflush(stdin);
            //fgets( posicao, 250, stdin );
            pos = verificar(posicao);
     }while(pos < 1 || pos > 10);

    if(lista[pos-1].tam != 0 ){
                x=1;
                copiandoVetor(pos,lista);
                ordenandoTemporariamente(pos,lista);
    }
    else{
        printf(">> Estrutura %d ainda nao criada\n",pos);
        printf(">> Escolha a opcao 0 no menu principal para criar uma estrutura\n");
        x = 0;
    }

    if(x){
         ListarOrdenadoTemporario(pos,lista);
    }

}

int* criarvetor(int*x,int* y,elemento lista[TAM]){
    int i;
    int j;
    int z = 0;
    for(i=0;i<TAM;i++){
        if(lista[i].tam != 0 ){
            z=1;
            if(lista[i].qtd != 0){
                y = (int*)realloc(y,(*x+lista[i].qtd)*sizeof(int));
                for(j=0;j< lista[i].qtd;j++){
                      y[*x + j] = lista[i].p[j];
                }
                *x+=lista[i].qtd;
            }
            else
                printf("Nenhuma posicao preenchida na estrutura\n");
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
    if(x != 0){
        printf("---Elementos Ordenados:\n");
        for(i = 0;i<x;i++){
           printf("Elemento: %d\n",y[i]);
        }
    }

}

void excluir(elemento lista[TAM]){
    int pos;
    char posicao[250];
    int numero;
    char number[250];
    int x=0;
    int y=0;
    int j;
    int tamanho =0, aux = 0;

    do{
            printf(">> Informe a posicao da estrutura principal: ");
            //gets(posicao);
            scanf("%s",&posicao);
            fflush(stdin);
            //fgets( posicao, 250, stdin );
            pos = verificar(posicao);
    }while(pos < 1 || pos > 10);

    do{
        printf( "Digite qual numero excluir: ");
        //gets(number);
         scanf("%s",&number);
         fflush(stdin);
        //fgets( number, 250, stdin );
        y = verificarNumero(number);
        if(y)
            numero = atoi(number);
        else
            printf("Nao existe letras ou caracters na estrutura para excluir\n");
    }while(y == 0);

    if(lista[pos-1].tam != 0){
        tamanho = lista[pos-1].qtd;
        for(j=0;j<tamanho;j++){
            if(lista[pos-1].p[j] == numero){
                x = 1;
               if(j == tamanho - 1)
                    lista[pos-1].qtd--;
               else{
                    while(j != tamanho){
                        aux = lista[pos-1].p[j];
                        lista[pos-1].p[j] = lista[pos-1].p[j+1];
                        lista[pos-1].p[j+1] = aux;
                        j++;
                    }

                    lista[pos-1].qtd--;
               }

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
    int y=0;
    char adicionar[250];
    char posicao[250];

    do{
        printf("Informe a posicao da estrutura principal que voce deseja aumentar o tamanho: ");
        //gets(posicao);
         scanf("%s",&posicao);
         fflush(stdin);
        //fgets( posicao, 250, stdin );
        pos = verificar(posicao);
   }while(pos < 1 || pos > 10);

    do{
        printf("Digite o numero de inteiros extras a entrarem na estrutura: ");
        //gets(adicionar);
         scanf("%s",&adicionar);
         fflush(stdin);
        //fgets( adicionar, 250, stdin );
        y = verificarNumero(adicionar);
        if(y){
            add = atoi(adicionar);
            if(add < 1){
                printf("O numero deve ser maior que 0\n");
                y = 0;
            }
        }
        else
            printf("Numero invalido\n");

    }while(y == 0);

    if(lista[pos-1].tam != 0){
        //tamanhoAnterior = lista[pos-1].tam;
        lista[pos-1].p = (int*)realloc(lista[pos-1].p,(add+lista[pos-1].tam)*sizeof(int));
        lista[pos-1].tam += add;

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
void ImprimirOrdem(elemento lista[TAM]){

    int i;
    int* p;
    int aux=0;
    int j;
    int z=0;
    int count = 0;
    p = (int*)malloc(TAM*sizeof(int));

      for(i=0;i<TAM;i++){
          if(lista[i].tam != 0)
            if(lista[i].qtd != 0){
                p[i] = lista[i].qtd ;
                count++;
            }
      }


      for(i=count-1;i>=1;i--){
            for(j=0;j<i;j++)
                if(p[j]>p[j+1]){
                    aux = p[j];
                    p[j] = p[j+1];
                    p[j+1] = aux;
                }
    }


    for(i=0;i<count;i++){
        for(j=0;j<TAM;j++){
            if(lista[j].tam != 0)
                if(lista[j].qtd != 0)
                    if(p[i] == lista[j].qtd){
                        while(z < p[i]){
                            printf("%d\n",lista[j].p[z]);
                            z++;
                        }
                        z=0;
                    }
            }
    }

}

void ImprimirOrdemDaSoma(elemento lista[TAM]){
    int i;
    int soma=0;
    int count=0;
    int* p;
    int* y;
    int aux=0;
    int z=0;
    int j;
     p = (int*)malloc(TAM*sizeof(int));
    y = (int*)malloc(TAM*sizeof(int));
    for(i=0;i<TAM;i++){
        if(lista[i].tam != 0)
            if(lista[i].qtd != 0){
                for(j=0;j<lista[i].qtd;j++){
                    soma+=lista[i].p[j];
                }
                p[i] = soma;
                y[i] = soma;
                soma = 0 ;
                count++;
            }
    }


    for(i=count-1;i>=1;i--){
            for(j=0;j<i;j++)
                if(p[j]>p[j+1]){
                    aux = p[j];
                    p[j] = p[j+1];
                    p[j+1] = aux;
                }
    }

    for(i=0;i<count;i++){
        for(j=0;j<TAM;j++){
            if(lista[j].tam != 0)
                if(lista[j].qtd != 0)
                    if(p[i] == y[j]){
                        while(z < lista[j].qtd){
                            printf("%d\n",lista[j].p[z]);
                            z++;
                        }
                        z=0;
                    }
            }
    }





}
void limpatela(){

    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int main(){
    int op;
    int x = 0;
    int* y = NULL;
    elemento lista[TAM];
    inicializarLista(lista);
    do{
        op = menu();
        limpatela();
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
                printf("Finalizando o programa\n");
                liberar(lista);
                return 0;
                break;
            case 8:
                ImprimirOrdem(lista);
                break;
            case 9:
                ImprimirOrdemDaSoma(lista);
                break;
            default:
                printf("Numero invalido\n");
                break;
        }
    }while(op != 7);
    return 0;
}
