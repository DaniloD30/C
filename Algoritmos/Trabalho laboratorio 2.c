#include<stdio.h>
#include<stdlib.h>
#define TAM 10

int menu(){
    int op;
    printf("-----------------------------------------\n");
    printf("----------------- Menu ------------------\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar os numeros de todas as estruturas\n");
    printf("3 - Listar os numeros ordenados para cada estrutura auxiliar\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir um elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Sair\n");
    printf("Digite um das opcao: ");
    scanf("%d",&op);
    return op;

}
 typedef struct{
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
                 lista[pos-1].qtd++;
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

        lista[pos-1].p = (int*)malloc(lista[pos].tam*sizeof(int));

        for(i=0;i<lista[pos-1].tam;i++)
            lista[pos-1].p[i] = NULL;

        printf("Digite o elemento que vc deseja inserir: ");
        scanf("%d",&numero);
        for(i=0;i<lista[pos-1].tam;i++)
             if(lista[pos-1].p[i] == NULL){
                lista[pos-1].p[i] = numero;
                lista[pos-1].qtd++;
                printf("Numero Inserido com Sucesso na posicao %d\n", i);
                break;
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
            printf("Estrutura %d\n",i+1);
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
    int x=0;
    int menor=0;
    int aux=0;
    int j;
    int p;
    for(y=0;y<TAM;y++){
        for(i=0;i<lista[y].tam;i++){
            menor = lista[y].p[i];
            for( j=i+1;j<lista[y].tam;j++)
                if(lista[y].p[j]<menor){
                    menor = lista[y].p[j];
                    p=j;
                }
            if(menor!=lista[y].p[i]){
                aux = lista[y].p[i];
                lista[i].p[y]= lista[y].p[p];
                lista[y].p[p] = aux;
            }
        }
    }
}
int criarvetor(int* n,elemento lista[TAM]){
    int x=0;
    int i;
    int j;
    int tamanho;
     for(i=0;i<TAM;i++){
        n = (int*)realloc(n,(x+lista[i].tam)*sizeof(int));
        tamanho = lista[i].tam;
        for(j=0;j<=tamanho;j++)
          n[j] = lista[i].p[j];

       x+=lista[i].tam;
     }
     return x;

}

void ordenarVetor(int* n,elemento lista[TAM]){
    int tamanho;
    tamanho = criarvetor(n,lista);
    int j;
    int aux;
    for(j=0;j<=tamanho;j++)
        if(n[j+1] < n[j]){
            aux = n[j+1];
            n[j+1] = n[j];
            n[j] = aux;
            }
    }

void listarVetor(int* n,elemento lista[TAM]){
    int i;
    int tamanho;
    tamanho = criarvetor(n,lista);
    for(i = 0;i<tamanho;i++)
        printf("%d",n[i]);

}





int main(){
    int op;
    int* n = NULL;
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
                printar(lista);
                break;
            case 4:
                criarvetor(n,lista);
                ordenarVetor(n,lista);
                listarVetor(n,lista);
                break;
            case 7:
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
#include<stdio.h>
#include<stdlib.h>
#define TAM 10

int menu(){
    int op;
    printf("-----------------------------------------\n");
    printf("----------------- Menu ------------------\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar os numeros de todas as estruturas\n");
    printf("3 - Listar os numeros ordenados para cada estrutura auxiliar\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir um elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Sair\n");
    printf("Digite um das opcao: ");
    scanf("%d",&op);
    return op;

}
 typedef struct{
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
                 lista[pos-1].qtd++;
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

        lista[pos-1].p = (int*)malloc(lista[pos].tam*sizeof(int));

        for(i=0;i<lista[pos-1].tam;i++)
            lista[pos-1].p[i] = NULL;

        printf("Digite o elemento que vc deseja inserir: ");
        scanf("%d",&numero);
        for(i=0;i<lista[pos-1].tam;i++)
             if(lista[pos-1].p[i] == NULL){
                lista[pos-1].p[i] = numero;
                lista[pos-1].qtd++;
                printf("Numero Inserido com Sucesso na posicao %d\n", i);
                break;
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
            printf("Estrutura %d\n",i+1);
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
    int x=0;
    int menor=0;
    int aux=0;
    int j;
    int p;
    for(y=0;y<TAM;y++){
        for(i=0;i<lista[y].tam;i++){
            menor = lista[y].p[i];
            for( j=i+1;j<lista[y].tam;j++)
                if(lista[y].p[j]<menor){
                    menor = lista[y].p[j];
                    p=j;
                }
            if(menor!=lista[y].p[i]){
                aux = lista[y].p[i];
                lista[i].p[y]= lista[y].p[p];
                lista[y].p[p] = aux;
            }
        }
    }
}
int criarvetor(int* n,elemento lista[TAM]){
    int x=0;
    int i;
    int j;
    int tamanho;
     for(i=0;i<TAM;i++){
        n = (int*)realloc(n,(x+lista[i].tam)*sizeof(int));
        tamanho = lista[i].tam;
        for(j=0;j<=tamanho;j++)
          n[j] = lista[i].p[j];

       x+=lista[i].tam;
     }
     return x;

}

void ordenarVetor(int* n,elemento lista[TAM]){
    int tamanho;
    tamanho = criarvetor(n,lista);
    int j;
    int aux;
    for(j=0;j<=tamanho;j++)
        if(n[j+1] < n[j]){
            aux = n[j+1];
            n[j+1] = n[j];
            n[j] = aux;
            }
    }

void listarVetor(int* n,elemento lista[TAM]){
    int i;
    int tamanho;
    tamanho = criarvetor(n,lista);
    for(i = 0;i<tamanho;i++)
        printf("%d",n[i]);

}





int main(){
    int op;
    int* n = NULL;
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
                printar(lista);
                break;
            case 4:
                criarvetor(n,lista);
                ordenarVetor(n,lista);
                listarVetor(n,lista);
                break;
            case 7:
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
#include<stdio.h>
#include<stdlib.h>
#define TAM 10

int menu(){
    int op;
    printf("-----------------------------------------\n");
    printf("----------------- Menu ------------------\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar os numeros de todas as estruturas\n");
    printf("3 - Listar os numeros ordenados para cada estrutura auxiliar\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir um elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Sair\n");
    printf("Digite um das opcao: ");
    scanf("%d",&op);
    return op;

}
 typedef struct{
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
                 lista[pos-1].qtd++;
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

        lista[pos-1].p = (int*)malloc(lista[pos].tam*sizeof(int));

        for(i=0;i<lista[pos-1].tam;i++)
            lista[pos-1].p[i] = NULL;

        printf("Digite o elemento que vc deseja inserir: ");
        scanf("%d",&numero);
        for(i=0;i<lista[pos-1].tam;i++)
             if(lista[pos-1].p[i] == NULL){
                lista[pos-1].p[i] = numero;
                lista[pos-1].qtd++;
                printf("Numero Inserido com Sucesso na posicao %d\n", i);
                break;
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
            printf("Estrutura %d\n",i+1);
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
    int x=0;
    int menor=0;
    int aux=0;
    int j;
    int p;
    for(y=0;y<TAM;y++){
        for(i=0;i<lista[y].tam;i++){
            menor = lista[y].p[i];
            for( j=i+1;j<lista[y].tam;j++)
                if(lista[y].p[j]<menor){
                    menor = lista[y].p[j];
                    p=j;
                }
            if(menor!=lista[y].p[i]){
                aux = lista[y].p[i];
                lista[i].p[y]= lista[y].p[p];
                lista[y].p[p] = aux;
            }
        }
    }
}
int criarvetor(int* n,elemento lista[TAM]){
    int x=0;
    int i;
    int j;
    int tamanho;
     for(i=0;i<TAM;i++){
        n = (int*)realloc(n,(x+lista[i].tam)*sizeof(int));
        tamanho = lista[i].tam;
        for(j=0;j<=tamanho;j++)
          n[j] = lista[i].p[j];

       x+=lista[i].tam;
     }
     return x;

}

void ordenarVetor(int* n,elemento lista[TAM]){
    int tamanho;
    tamanho = criarvetor(n,lista);
    int j;
    int aux;
    for(j=0;j<=tamanho;j++)
        if(n[j+1] < n[j]){
            aux = n[j+1];
            n[j+1] = n[j];
            n[j] = aux;
            }
    }

void listarVetor(int* n,elemento lista[TAM]){
    int i;
    int tamanho;
    tamanho = criarvetor(n,lista);
    for(i = 0;i<tamanho;i++)
        printf("%d",n[i]);

}





int main(){
    int op;
    int* n = NULL;
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
                printar(lista);
                break;
            case 4:
                criarvetor(n,lista);
                ordenarVetor(n,lista);
                listarVetor(n,lista);
                break;
            case 7:
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
#include<stdio.h>
#include<stdlib.h>
#define TAM 10

int menu(){
    int op;
    printf("-----------------------------------------\n");
    printf("----------------- Menu ------------------\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar os numeros de todas as estruturas\n");
    printf("3 - Listar os numeros ordenados para cada estrutura auxiliar\n");
    printf("4 - Listar todos os numeros de forma ordenada\n");
    printf("5 - Excluir um elemento\n");
    printf("6 - Aumentar o tamanho de uma estrutura auxiliar\n");
    printf("7 - Sair\n");
    printf("Digite um das opcao: ");
    scanf("%d",&op);
    return op;

}
 typedef struct{
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
                 lista[pos-1].qtd++;
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

        lista[pos-1].p = (int*)malloc(lista[pos].tam*sizeof(int));

        for(i=0;i<lista[pos-1].tam;i++)
            lista[pos-1].p[i] = NULL;

        printf("Digite o elemento que vc deseja inserir: ");
        scanf("%d",&numero);
        for(i=0;i<lista[pos-1].tam;i++)
             if(lista[pos-1].p[i] == NULL){
                lista[pos-1].p[i] = numero;
                lista[pos-1].qtd++;
                printf("Numero Inserido com Sucesso na posicao %d\n", i);
                break;
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
            printf("Estrutura %d\n",i+1);
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
    int x=0;
    int menor=0;
    int aux=0;
    int j;
    int p;
    for(y=0;y<TAM;y++){
        for(i=0;i<lista[y].tam;i++){
            menor = lista[y].p[i];
            for( j=i+1;j<lista[y].tam;j++)
                if(lista[y].p[j]<menor){
                    menor = lista[y].p[j];
                    p=j;
                }
            if(menor!=lista[y].p[i]){
                aux = lista[y].p[i];
                lista[i].p[y]= lista[y].p[p];
                lista[y].p[p] = aux;
            }
        }
    }
}
int criarvetor(int* n,elemento lista[TAM]){
    int x=0;
    int i;
    int j;
    int tamanho;
     for(i=0;i<TAM;i++){
        n = (int*)realloc(n,(x+lista[i].tam)*sizeof(int));
        tamanho = lista[i].tam;
        for(j=0;j<=tamanho;j++)
          n[j] = lista[i].p[j];

       x+=lista[i].tam;
     }
     return x;

}

void ordenarVetor(int* n,elemento lista[TAM]){
    int tamanho;
    tamanho = criarvetor(n,lista);
    int j;
    int aux;
    for(j=0;j<=tamanho;j++)
        if(n[j+1] < n[j]){
            aux = n[j+1];
            n[j+1] = n[j];
            n[j] = aux;
            }
    }

void listarVetor(int* n,elemento lista[TAM]){
    int i;
    int tamanho;
    tamanho = criarvetor(n,lista);
    for(i = 0;i<tamanho;i++)
        printf("%d",n[i]);

}





int main(){
    int op;
    int* n = NULL;
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
                printar(lista);
                break;
            case 4:
                criarvetor(n,lista);
                ordenarVetor(n,lista);
                listarVetor(n,lista);
                break;
            case 7:
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
