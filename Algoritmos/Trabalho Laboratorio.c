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
//  email: danilolive30@hotmail.com
//  Matrícula: 2016116013
//  Semestre: Terceiro

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <wchar.h>
#include <locale.h>
int QtdDigitosBase(int numerobase);
int QtdDigitosBusca(int numerobusca);
int QtdDigitos(int num);
int x;
int y;


int pegaAno(char *data){

	int multi = 1, ano = 0, cont = 0,x;

	//Obtendo o ano

	for( x = strlen(data) - 1;x >= 0;x--){
		int ascii, dec = 0;

		for(ascii=48;ascii<58;ascii++){

			if(data[x] == 47){

				x = -1;

				break;

			}

			if(data[x] == ascii){

				ano = ano + (dec * multi);
				multi = multi * 10;

				break;

			}

			dec++;

		}

		cont++;

	}

	if(cont > 5 || cont == 4){
		return -1;

	} else{

		if(cont == 3){

			ano = ano + 2000;

		}

		return ano;

	}

}



int pegaMes(char *data){

	int multi = 1, mes = 0, cont = 0, cont2 = 0,x;

	for( x = strlen(data) - 1; x >= 0; x--){

		if(data[x] != 47){

			cont++;

		} else{

			cont++;

			break;

		}

	}

	for( x = strlen(data) - 1 - cont;x >= 0;x--){

		int ascii, dec = 0;



		for(ascii=48;ascii<58;ascii++){

			if(data[x] == 47){

				x = -1;

				break;

			}

			if(data[x] == ascii){

				mes = mes + (dec * multi);

				multi = multi * 10;

				break;

			}

			dec++;

		}

		cont2++;

	}

	if(cont2 <= 3){

		return mes;

	} else{

		return -1;

	}

}



int pegaDia(char *data){

	int multi = 1, dia = 0, cont = 0, barra_encontrada = 0, cont2 = 0,x;

	for( x = strlen(data) - 1; x >= 0; x--){
		if(data[x] != 47 || (data[x] == 47 && barra_encontrada < 2)){

			cont++;

		}

		if(data[x] == 47){

			barra_encontrada++;

		}

		if(barra_encontrada > 1){

			break;

		}

	}

	for(x = strlen(data) - 1 - cont;x >= 0;x--){
		int ascii, dec = 0;

		for(ascii=48;ascii<58;ascii++){

			if(data[x] == ascii){

				dia = dia + (dec * multi);

				multi = multi * 10;

				break;

			}

			dec++;

		}

		cont2++;

	}

	if(cont2 <= 2){

		return dia;

	} else{

		return -1;

	}

}



int val_ano_bi(int ano){

	if(ano % 4 == 0){
		return 1;

	} else{

		return 0;

	}

}



int q1(char *data){

	int multi = 1, ano = 0, mes = 0, dia = 0, pos_verificada = 0;



	ano = pegaAno(data);

	mes = pegaMes(data);

	dia = pegaDia(data);


	if((dia > 0 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && ano > 0){

		return 1;

	} else if((dia > 0 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11) && ano > 0){

		return 1;

	} else if((dia > 0 && dia <= 28) && mes == 2 && !val_ano_bi(ano) && ano > 0){

		return 1;

	} else if((dia > 0 && dia <= 29) && mes == 2 && val_ano_bi(ano) && ano > 0){

		return 1;

	} else{

		return 0;

	}

}



int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){

    *qtdDias = 0;

    *qtdMeses = 0;

    *qtdAnos = 0;

	int validaI = q1(datainicial), validaFinal = q1(datafinal), anoI, mesI, diaI, anoF, mesF, diaF;

    if(validaI == 0 )
        return 2;
    if(validaFinal == 0)
        return 3;

    if(validaI == 1 && validaFinal == 1){

    	anoI = pegaAno(datainicial);

		mesI = pegaMes(datainicial);

		diaI = pegaDia(datainicial);

		anoF = pegaAno(datafinal);

		mesF = pegaMes(datafinal);

		diaF = pegaDia(datafinal);

		*qtdAnos = anoF - anoI;

		*qtdMeses = mesF - mesI;

		*qtdDias = diaF - diaI;

    if((diaF < diaI) && (mesF <= mesI) && (anoF <= anoI))
        return 4;
    if((diaF <= diaI) && (mesF<mesI) && (anoF <= anoI))
        return 4;
    if((diaF<= diaI) && (mesF<=mesI) && (anoF < anoI))
        return 4;

		if(anoF - anoI >= 0 && mesF - mesI < 0){

			*qtdAnos = *qtdAnos - 1;

			*qtdMeses = 12 - (mesI - mesF);

		}

		if(diaF - diaI < 0){

			if(*qtdMeses == 0){

				if(diaF == 28 && diaI == 29 && mesF == 2 && mesI == 2 && val_ano_bi(anoI) && !val_ano_bi(anoF)){

					*qtdDias = 0;

					*qtdMeses = 0;

				} else{

					*qtdAnos = *qtdAnos - 1;

					*qtdMeses = 11;

					*qtdDias = diaF;

				}

			}else{

				*qtdMeses = *qtdMeses - 1;

				if(mesI == 1 || mesI == 3 || mesI == 5 || mesI == 7 || mesI == 8 || mesI == 10 || mesI == 12){

					*qtdDias = (31 - diaI) + diaF;

				} else if(mesI == 4 || mesI == 6 || mesI == 9 || mesI == 11){

					*qtdDias = (30 - diaI) + diaF;

				} else if(mesI == 2 && !val_ano_bi(anoI)){
					if(!val_ano_bi(anoF)){

						*qtdDias = (28 - diaI) + diaF;

					} else {

						*qtdDias = (28 - diaI) + diaF + 1;

					}

				} else if(mesI == 2 && val_ano_bi(anoI)){
					if(mesF == 2){

						if(val_ano_bi(anoF)){

							*qtdDias = 29 - diaI + diaF;

						}else{

							*qtdDias = 28 - diaI + diaF;

						}

					} else{

						*qtdDias = (29 - diaI) + diaF;

					}

				}

			}

    	}

    	return 1;

	} else {

    	return 0;

   	}

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
    int i;
    char maiuscula,minuscula;
    tam =strlen(texto);
    if(c > 64 && c < 91 ){
        maiuscula = c;
        minuscula = c + 32;
    }
    else{
        maiuscula = c - 32;
        minuscula = c;
    }

    if(isCaseSensitive==1){
    for( i=0;i<=tam;i++)
        if(texto[i]== c) //SOMENTE VAI CONTAR UM TIPO DE LETRA
            count++;
    }
    else{
        for( i=0;i<=tam;i++)
            if(texto[i]==maiuscula||texto[i]== minuscula) //VAI CONTAR AS LETRAS MINUSCULAS E MAIUSCULAS;
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
 void parseToWchar(wchar_t* new, const char* string, const int len){
    // Gambiarra do setlocale pq sem essa zorra o código não pega
    setlocale(LC_ALL, "");
    // Só sei que depois do setlocale e dessa função funciona
    mbstowcs(new, string, len);
}

void clearWString(wchar_t* str, const int len){
    // é necessário limpar a string de wchar_t, essa zorra inicia com lixo
    int i;
    for( i = 0; i<len; i++)
        str[i] = '\0';
}

int size(const wchar_t* str){
    // código na big hand para recuperar o size da string de wchar_t
    int cont = 0,i;
    for( i = 0; str[i]; i++)
        cont++;
    return cont;
}
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int n=0,y=0,inicio=0,igual=0,count=0,qtdOcorrencias = 0,j=0,k=0,i;
     wchar_t word[250];
    wchar_t search[250];

    clearWString(word, 250);
    clearWString(search, 250);

    parseToWchar(word, strTexto, strlen(strTexto));
    parseToWchar(search, strBusca, strlen(strBusca));

    n=strlen(strTexto);
    y=strlen(strBusca);

    for( i=0;i<n;i++){
        j=i;
        k=0;
       while(j<n){
            if(word[j]==search[k]){
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
    int TAM=0, mult=1, n=0,i;
    TAM = QtdDigitos(num);
    int vetor[TAM];
    mult=x;
    for( i=0;i<TAM;i++){  //PREENCHENDO VETOR DA BASE COM CADA DIGITO DO NUMERO DA BASE
        vetor[i] = num/x;
        num = num%x;
        x = x/10;
    }
    for( i=TAM-1;i>=0;i--){
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
    int j,k,i;
    TAM = QtdDigitosBase(numerobase);
    TamBusca = QtdDigitosBusca(numerobusca);
    int vetorBase[TAM];
    int vetorBusca[TamBusca];
    for( i=0;i<TAM;i++){  //PREENCHENDO VETOR DA BASE COM CADA DIGITO DO NUMERO DA BASE
        vetorBase[i] = numerobase/x;
        numerobase = numerobase%x;
        x = x/10;
    }
    for( i=0;i<TamBusca;i++){  //PREENCHENDO VETOR DA BUSCA COM CADA DIGITO DO NUMERO DA BUSCA
        vetorBusca[i] = numerobusca/y;
        numerobusca = numerobusca%y;
        y = y/10;
    }
    //printf("Tamanho vetor base: %d\n Tamanho vetor busca: %d\n",TAM,TamBusca);
    for(i=0;i<TAM;i++){
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
