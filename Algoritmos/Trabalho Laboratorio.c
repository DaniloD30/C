// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Danilo Oliveira Dias
//  email:
//  Matrícula: 2016116013
//  Semestre: Terceiro

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include<locale.h>
int QtdDigitosBase(int numerobase);
int QtdDigitosBusca(int numerobusca);
int QtdDigitos(int num);
int x;
int y;
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
    int datavalida = 1;
    char dia[2],mes[2],ano[4];
    int i,j,k,d=0,a=0,m=0,y=0,v=0;

    for(i=0;data[i]!='/';i++){
        dia[i] = data[i];
          //printf("Dia: %c \n",dia[i]);
    }
    dia[i] = '\0';
    for(j = i+1;data[j]!='/';j++){
        mes[y] = data[j];
          //printf("Mes: %c \n",mes[y]);
        y++;
    }
    mes[y] = '\0';
    y=0;
    for(k = j+1;data[k]!='\0';k++){
        ano[y] = data[k];
        //printf("y: %d\n",y);
        //printf("Ano: %c \n",ano[y]);
        y++;
    }
    ano[y] = '\0';

    if(strlen(ano)!=2 && strlen(ano)!= 4)
        return 0;
    if(strlen(dia)!=1 && strlen(dia)!= 2)
        return 0;
    if(strlen(mes)!=1 && strlen(mes)!= 2)
        return 0;

    d = atoi(dia);
    m = atoi(mes);
    a = atoi(ano);

    if(d<=31 && d>0)
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
             datavalida = 1;
             v = 1;
        }
    if(d<=30 && d>0)
        if(m==4||m==6||m==9||m==11){
            datavalida = 1;
            v=1;
        }
    if(d==29 && m==2)
        if((a%4==0 && a%100!=0 )|| (a%400==0 && a%100!=0)){
            datavalida = 1;
            v=1;
        }
    if(d<29 && m==2){
        datavalida =1;
        v=1;
    }
    if(v==0)
        datavalida = 0;


    if (datavalida)
        return 1;
    else
        return 0;

}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial < datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    *qtdDias = 10;
    *qtdAnos = 20;
    *qtdMeses = 30;

    //printf("%s\n", datainicial);
    //printf("%s\n", datafinal);

    return 1;

}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

int q3(char *texto, char c, int isCaseSensitive){
    int tam;
    int count=0;
    tam =strlen(texto);
    if(isCaseSensitive==1){
    for(int i=0;i<=tam;i++)
        if(texto[i]== c) //SOMENTE VAI CONTAR AS LETRAS MINUSCULAS;
            count++;
    }
    else{
        for(int i=0;i<=tam;i++)
            if(texto[i]==tolower(c)||texto[i]== toupper(c)) //VAI CONTAS AS LETRAS MINUSCULAS E MAIUSCULAS;
                count++;
    }
    return count;
}



/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int n=0,y=0,inicio=0,igual=0,count=0,qtdOcorrencias = 0,j=0,k=0;
    n=strlen(strTexto);
    y=strlen(strBusca);
    for(int i=0;i<n;i++){
        j=i;
        k=0;
       while(j<n){
            if(strTexto[j]==strBusca[k]){
                igual++;
                //printf("Vetor base %c\n Vetor Busca %c\n",strTexto[j],strBusca[k]);
                j++;
            }
            else
                break;



            k++;
        }
        if(igual==y){
            inicio = i+1;
            posicoes[count] = inicio;
            count++;
            posicoes[count] = j; // k = FIM ;
            count++;
            qtdOcorrencias++;

        }
        igual=0;
    }
    return qtdOcorrencias;

}



/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    int TAM=0, mult=1, n=0;
    TAM = QtdDigitos(num);
    int vetor[TAM];
    mult=x;
    for(int i=0;i<TAM;i++){  //PREENCHENDO VETOR DA BASE COM CADA DIGITO DO NUMERO DA BASE
        vetor[i] = num/x;
        num = num%x;
        x = x/10;
    }
    for(int i=TAM-1;i>=0;i--){
        n+=vetor[i]*mult;
        mult=mult/10;
    }
    num=n;
    return num;
}
int QtdDigitos(int num){
        int i=1;
        int qtd=0;
        while(i<=num){
            i*=10;
            qtd++;
        }
        x=i/10;

        return qtd;
}


/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0,TAM=0,TamBusca=0,achou=0;
    int j,k;
    TAM = QtdDigitosBase(numerobase);
    TamBusca = QtdDigitosBusca(numerobusca);
    int vetorBase[TAM];
    int vetorBusca[TamBusca];
    for(int i=0;i<TAM;i++){  //PREENCHENDO VETOR DA BASE COM CADA DIGITO DO NUMERO DA BASE
        vetorBase[i] = numerobase/x;
        numerobase = numerobase%x;
        x = x/10;
    }
    for(int i=0;i<TamBusca;i++){  //PREENCHENDO VETOR DA BUSCA COM CADA DIGITO DO NUMERO DA BUSCA
        vetorBusca[i] = numerobusca/y;
        numerobusca = numerobusca%y;
        y = y/10;
    }
    //printf("Tamanho vetor base: %d\n Tamanho vetor busca: %d\n",TAM,TamBusca);
    for(int i=0;i<TAM;i++){
        j=i;
        k=0;
        //printf("Valor de i percorrendo o vetor: %d\n",i);
        while(j<TAM){
            if(vetorBase[j]==vetorBusca[k]){
                achou++;
                //printf("Vetor base %d\n Vetor Busca %d\n",vetorBase[j],vetorBusca[k]);
                j++;
            }
            else
                break;



            k++;
        }
        if(achou==TamBusca)
            qtdOcorrencias++;
            achou=0;
    }
    //printf("Quantidade de ocorrencia: %d\n",qtdOcorrencias);

    return qtdOcorrencias;
}
int QtdDigitosBase(int numerobase){
        int i=1;
        int qtd=0;
        while(i<=numerobase){
            i*=10;
            qtd++;
        }
        x=i/10;

        return qtd;

}
int QtdDigitosBusca(int numerobusca){
        int i=1;
        int qtd=0;
        while(i<=numerobusca){
            i*=10;
            qtd++;
        }
        y=i/10;

        return qtd;

}
