#include <stdio.h>
#include <stdlib.h>
int tam=0;
int tamPilha = 0;
int menu(void)
{
	int opt;
    printf("\n");
	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Inserir na fila\n");
	printf(">2. Inserir na pilha\n");
	printf("3. Remover na fila\n");
	printf(">4. Remover na pilha\n");
	printf("5. Exibir fila\n");
	printf(">6. Exibir pilha\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}


void Enqueue(int* p){
    int novo;

    printf("Digite o numero para inserir: ");
    scanf("%d",&novo);

    p = (int*)realloc(p,sizeof(int));

    p[tam] = novo;
    tam++;
}
void Push(int* y){
    int novo;

    printf("Digite o numero para inserir: ");
    scanf("%d",&novo);

    y = (int*)realloc(y,sizeof(int));

    y[tamPilha] = novo;
    tamPilha++;
}
void Pop(int* y){
    tamPilha--;
}
void ExibePilha(int* y){
     int i;
   for(i=tamPilha-1;i>=0;i--){
        printf("%d\n ",y[i]);
    }
    printf("\n");

}
void Dequeue(int* p){
    int j=0;
    int aux=0;

    while(j != tam){
            aux = p[j];
            p[j] = p[j+1];
            p[j+1] = aux;
            j++;
    }

    tam--;
}
void exibe(int* p){
   int i;
   for(i=0;i<tam;i++){
        printf("%d ",p[i]);
    }
    printf("\n");

}



int main(){
   int* p;
   p = (int *) malloc(tam * sizeof(int));
   int* y;
   y = (int *) malloc(tam * sizeof(int));
    int op;

    do{
        op = menu();
        switch(op){
            case 0:
                printf("Finalizando o programa\n");
                free(p);
                free(y);
                break;
            case 1:
                Enqueue(p);
                break;
            case 2:
                Push(y);
                break;
            case 3:
                Dequeue(p);
                break;
            case 4:
                Pop(y);
                break;
            case 5:
                exibe(p);
                break;
            case 6:
                ExibePilha(y);
                break;


        }
     }while(op != 0);


    return 0;
}
