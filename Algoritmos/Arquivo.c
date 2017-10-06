//Exemplo: Abrindo, gravando e fechando arquivo
#include <stdio.h>
//#include <conio.h>



int main(void){
    
    FILE *pont_arq; // cria variável ponteiro para o arquivo
    char palavra[20]; // variável do tipo string

    pont_arq = fopen("arquivo_palavra.txt", "r");

    if(pont_arq == NULL){
        //abrindo o arquivo com tipo de abertura w
        pont_arq = fopen("arquivo_palavra.txt", "w");

        printf("Escreva uma palavra para testar gravacao de arquivo: ");
        scanf("%s", palavra);

        //usando fprintf para armazenar a string no arquivo
        fprintf(pont_arq, "%s", palavra);

        //usando fclose para fechar o arquivo
        fclose(pont_arq);

        printf("Dados gravados com sucesso!");
        return(0);
    }
    else{
        char frase[100];
        while(fgets(frase, 100, pont_arq) != NULL){
            printf(" %s",frase);
        }
        fclose(pont_arq);
        //printf(" %s",palavra);
        //fprintf(pont_arq, " %s\n", palavra);
        return 0;

    }
    //  getch();

}

