#include <stdio.h>
#include <stdlib.h>

void menu(void){
    printf("1 - Imprimir hora do sistema\n");
    printf("2 - Imprimir a data do sistema\n");
    printf("3 - Somar dois números\n ");
    printf("4 - Imprima os dois valores digitamos pelo úsario\n");
    printf("0 - Encerrar\n");
}
int soma(void){
    int a,b;
    printf("Digite dois numeros\n");
    scanf("%d %d",&a,&b);
    printf("Primeiro numero: %d\n Segundo Numero: %d\n",a,b);
    return a+b;
}

int main()
{
    int op=1;
    while(op!=0){
        menu();
        scanf("%d",&op);
    switch(op){
        case 1:
            printf(">>Opcao 1\n");
            break;
        case 2:
            printf(">>Opcao 2\n");
            break;
        case 3:
            printf(">>Opcao 3\n");
            printf(" Soma: %d\n",soma());
            break;
        case 4:
            printf(">>Opcao 4\n");
            break;
        case 0:
            printf("Encerrando o programa\n");
            break;
        default:
            printf(">> Opcao Invalida\n");
            break;
    }

    }
    return 0;
}
