#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
int q3(char string[], char x, int c){
    int tam;
    int count=0;
    tam =strlen(string);
    if(c==1){
    for(int i=0;i<=tam;i++)
        if(string[i]== x) //SOMENTE VAI CONTAR AS LETRAS MINUSCULAS;
            count++;
    }
    else{
        for(int i=0;i<=tam;i++)
            if(string[i]==tolower(x)||string[i]== toupper(x)) //VAI CONTAS AS LETRAS MINUSCULAS E MAIUSCULAS;
                count++;
    }
    return count;
}
int main(){
    char string[250];
    char l;
    int ocorrencia=0;
    int cas;
    printf("Digite o texto\n");
    gets(string);
    fflush(stdin);
    printf("Digite uma letra a ser procurada no texto\n");
    scanf("%c",&l);
    printf("Se isCaseSensitive = 1, a pesquisa deve considerar diferencias entre maiusculos e minusculos\n Se isCaseSensitive != 1, a pesquisa nao deve  considerar diferencias entre maiusculos e minusculos\n Digite qual caso vc quer: ");
    scanf("%d",&cas);
    ocorrencia =q3(string,l,cas);
    printf("Ocorrencias da letra %c eh: %d\n",l,ocorrencia);
    return 0;
}

