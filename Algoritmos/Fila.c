#include <stdio.h>
#include <stdlib.h>
int tam;

typedef struct{
    int val;
    struct node* prox;
}node;

int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Inserir\n");
	printf("2. Remover\n");
	printf("3. Exibir\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void criarfila(node* fila){
    fila->prox = NULL;
    tam = 0 ;
}

void Inserir(node* fila){
    node* novo;
    novo = (node*)malloc(sizeof(node));
    node* tmp;

    printf("Digite um numero para inserir na fila: ");
    scanf("%d",&novo->val);

    novo->prox = NULL;

    if(fila->prox == NULL)
        fila->prox = novo;
    else{
        tmp = fila->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    tam++;
}
void retirar(node* fila){
    node* anterior;
    node* old;
    //int pos;
    int i;
    //printf("Digite a posicao que voce deseja retirar: ");
    //scanf("%d",&pos);
    old = fila->prox;
    fila->prox = old->prox;
}
void exibe(node* fila){
    node* tmp;
    tmp = fila->prox;

    while(tmp != NULL){
        printf("%d ",tmp->val);
        tmp = tmp->prox;
    }

}



int main(){
    node* fila = (node*)malloc(sizeof(node));
    criarfila(fila);
    int op;

    do{
        op = menu();
        switch(op){
            case 0:
                printf("Finalizando o programa\n");
                break;
            case 1:
                Inserir(fila);
                break;
            case 2:
                retirar(fila);
                break;
            case 3:
                exibe(fila);
                break;

        }
     }while(op != 0);

    printf("Hello world!\n");
    return 0;
}
