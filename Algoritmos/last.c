#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 10
int testarArquivo(FILE *arquivo);

void limpatela(){
    //printf("\nPressione enter para continuar...\n");
    //system("read x");
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int menu(){
    char op[250];
    int opcao;
    int i;
    int y = 1;
    limpatela();
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
    printf("-----------------------------------------\n");
    printf("-----------------------------------------\n");


    do{
        printf("Digite uma das opcao: ");
        fflush(stdin);
        //__fpurge(stdin);
        //gets(op);
        scanf("%s", op);
         fflush(stdin);
        //fgets(op,250,stdin);

        printf("\n ");
        for(i=0;op[i];i++){
            if(op[i] < 48 || op[i] > 57){
                y = 0;
                //limpatela();
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
                    return -1;
                }
                else
                    return pos;
    }
    else{
        printf("Posicao invalida\n");
    }
    return -1;
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
void criarLista(elemento lista[TAM]){ //,FILE* arquivo)
    char posicao[250];
    int pos;
    char tamanho[250];
    int y=0;

     //arquivo = fopen("arquivo.txt","w");

    do{
        printf("Digite o numero da posicao que voce deseja criar uma estrutura: ");
        //gets(posicao);
         scanf("%s", posicao);
         fflush(stdin);
        //fgets( posicao, 250, stdin );
        pos = verificar(posicao);
    }while(pos < 1 || pos > 10);

    //fprintf(arquivo,"Posicao Estrutura Auxiliar: %s ",posicao);

    if(lista[pos-1].tam == 0){
        do{
            printf("Digite o tamanho da estrutura auxiliar: ");
            //gets(tamanho);
             scanf("%s", tamanho);
            fflush(stdin);
            //fgets( tamanho, 250, stdin );
            y = verificarNumero(tamanho);
             //fprintf(arquivo,"%s ",tamanho);
            if(y){
                lista[pos-1].tam = atoi(tamanho);
            }
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

     //fclose(arquivo);
}

void inserir(elemento lista[TAM]){//,FILE* arquivo
    int pos;
    char posicao[250];

    int numero;
    int y=0;
    char n[250];
    //arquivo = fopen("arquivo.txt", "a");

        do{
            printf("Digite o numero da posicao que voce deseja inserir um elemento na estrutura: ");
            //gets(posicao);
            scanf("%s", posicao);
            fflush(stdin);
            //fgets( posicao, 250, stdin );
            pos = verificar(posicao);
        }while(pos < 1 || pos > 10);

    //fprintf(arquivo,"-Posicao estrutura principal que vai inserir: %s ",posicao);
    if(lista[pos-1].tam != 0){
        do{
            printf("Digite o elemento que vc deseja inserir na estrutura: ");
            //gets(n);
            scanf("%s", n);
            fflush(stdin);
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
            //fprintf(arquivo,"-Elemento inserido: %s ",n);
            printf("Numero Inserido com Sucesso na posicao %d\n", lista[pos-1].qtd);

        }
    }
    else{
        printf("Estrutura ainda nao criada\n");
        printf("Escolha a opcao 0 no menu principal para criar uma estrutura\n");
    }
        //fprintf(arquivo,"%s ",lista[pos-1].qtd);
      //fclose(arquivo);
}
void printar(elemento lista[TAM]){//,FILE* arquivo
    int i;
    int j;
    int tamanho;
    //arquivo = fopen("arquivo.txt", "r");

    for(i=0;i<TAM;i++){
        //fscanf(arquivo,"%d %d\n", &lista[i].tam, &lista[i-1].qtd);

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
    //fclose(arquivo);
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
             scanf("%s", posicao);
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
            scanf("%s", posicao);
            fflush(stdin);
            //fgets( posicao, 250, stdin );
            pos = verificar(posicao);
    }while(pos < 1 || pos > 10);

    do{
        printf( "Digite qual numero excluir: ");
        //gets(number);
         scanf("%s",number);
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
         scanf("%s", posicao);
         fflush(stdin);
        //fgets( posicao, 250, stdin );
        pos = verificar(posicao);
   }while(pos < 1 || pos > 10);

    do{
        printf("Digite o numero de inteiros extras a entrarem na estrutura: ");
        //gets(adicionar);
         scanf("%s",adicionar);
         fflush(stdin);

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
        int *cobaia = (int *)realloc(lista[pos-1].p,(add+lista[pos-1].tam)*sizeof(int));
        if(cobaia == NULL){
            printf("\nNao foi possivel aumentar a estrutura (Meomoria indisponivel)!\n");
        } else{
            lista[pos-1].p = cobaia;
            printf(">> Estrutura auxiliar aumentada com sucesso\n");
            lista[pos-1].tam += add;
        }
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
typedef struct Inteiro{
	int num;
	int valido;
}inteiro;
// Converte ASCII para int
inteiro converteASCII(char* string){
	int multi = 1, ascii = 0, sinal = 1, y = 0;
	int z;
	inteiro num;
	num.num = 0;
	num.valido = 1;
	if(string[0] == '-'){
		sinal = -1;
		y = 1;
		for(z = 1; z < strlen(string)-1; z++){
			multi = multi * 10;
		}
	} else{
		for(z = 0; z < strlen(string)-1; z++){
			multi = multi * 10;
		}
	}
	for(;string[y]; y++){
		ascii = 0;
		for(z = 48; z <= 57; z++){
			if(string[y] == z){
				num.num += (ascii * multi);
				break;
			} else{
				if(z == 57){
					num.valido = 0;
					return num;
				}
				ascii++;
			}
		}
		multi = multi / 10;
	}
	num.num = num.num * sinal;
	return num;
}
// Converte Posição, tamanho e quantidade de elementos
int convertePMA(char* pos, char* max, char* atual, inteiro* pma){
    int x;
	*(pma) = converteASCII(pos);
	*(pma+1) = converteASCII(max);
	*(pma+2) = converteASCII(atual);
	for(x = 0; x < 3; x++){
		if(!(pma[x].valido)){
			return 0;
		}
	}
	return 1;
}

// Pega os elementos do vetor no arquivo
int pegaVetor(elemento lista[TAM], char* string, int inicio, int o){
	inteiro num_vetor;
	int y = 0, tama = strlen(string);
	int x;
	char* aux;
	aux = (char *)malloc(tama * sizeof(char));
	for(x = 0;string[inicio];inicio++){
		if(string[inicio] != '.'){
			aux[x] = string[inicio];
			x++;
		} else{
			aux[x] = 0;
			num_vetor = converteASCII(aux);
			lista[o].p[y] = num_vetor.num;
			y++;
			x = 0;
			aux = (char *)malloc(tama * sizeof(char));
		}
	}
	return 1;
}
int pegaPMA(char* linha,char* pos, char* max, char* atual){
	int x = 0;
	int y;
	for(; linha[x] != 46;x++){
		pos[x] = linha[x];
		pos = (char *)realloc(pos, (strlen(pos) + 1) * sizeof(char));
		pos[x+1] = 0;
	}
	x++;
	for(y = 0;linha[x] != 46;x++){
		max[y] = linha[x];
		max = (char *)realloc(max, (strlen(max) + 1) * sizeof(char));
		y++;
		max[y] = 0;
	}
	x++;
	for(y = 0; linha[x] != 46;x++){
		atual[y] = linha[x];
		atual = (char *)realloc(atual, (strlen(atual) + 1) * sizeof(char));
		y++;
		atual[y] = 0;

	}
	return x+1;
}
int lerDados(elemento lista[TAM], FILE *arquivo){
	int aberto;
	arquivo = fopen("arquivo.txt", "r");
	aberto = testarArquivo(arquivo);
	if(aberto){
		int inicio, valido, i, m, a;
		inteiro *pma;
		char linha[99] = {}, *pos, *max, *atual;
		pos = (char *) malloc(2 * sizeof(char));
		max = (char *) malloc(2 * sizeof(char));
		atual = (char *) malloc(2 * sizeof(char));
		if(fgets(linha,sizeof(linha),arquivo) == NULL)
			return 0;
		while(fgets(linha,sizeof(linha),arquivo) != NULL){
			inicio = pegaPMA(linha,pos,max,atual);
			pma = (inteiro *)malloc(3 * sizeof(inteiro));
			valido = convertePMA(pos,max,atual,pma);
			if(valido){
				i = pma->num - 1;
				m = pma[1].num;
				a = pma[2].num;
				lista[i].tam = m;
				lista[i].qtd = a;
				lista[i].p = (int *) malloc(m * sizeof(int));
				valido = pegaVetor(lista,linha,inicio,i);
				if(!valido)
					return 0;
			} else{
				return 0;
			}


		}
		fclose(arquivo);
		free(pos);
		free(max);
		free(atual);
		free(pma);
		return 1;
	}
	return 0;
}
int testarArquivo(FILE *arquivo){
	if(!arquivo)
		return 0;
	else
		return 1;
}
int Escrever(elemento lista[TAM],FILE* arquivo){
   arquivo = fopen("arquivo.txt", "w");
   int aberto,x,y,duplica=1,a;
	aberto = testarArquivo(arquivo);
	if(aberto){
		for(x = 0; x <  TAM; x++){
			if(lista[x].qtd){
				if(duplica){ // Duplicando a primeira linha, pois o programa não está lendo a primeira linha
					for(a = 0; a < 2; a++){
						fprintf(arquivo,"%d.%d.%d.", x+1, lista[x].tam, lista[x].qtd);
						for(y = 0; y < lista[x].qtd; y++){
							fprintf(arquivo, "%d.", lista[x].p[y]);
						}
						fprintf(arquivo,"\n");
					}
					duplica = 0;
				}else{
					fprintf(arquivo,"%d.%d.%d.", x+1, lista[x].tam, lista[x].qtd);
					for(y = 0; y < lista[x].qtd; y++){
						fprintf(arquivo, "%d.", lista[x].p[y]);
					}
					fprintf(arquivo,"\n");
				}
			}
		}
		fclose(arquivo);
		return 1;
	} else{
		return 0;
	}
}
int trataEntrada(){
	char entrada_str[99];
	int y;
	int* entrada_int, sinal, x, retorno, valida_retorno, valido, contInt;
	do{
		valido = 1, sinal = 1, x = 0, retorno = 0, valida_retorno = -1;
		gets(entrada_str);
		fflush(stdin);
		entrada_int = (int *) malloc(strlen(entrada_str) * sizeof(int));
		if(entrada_str[0] == 45){
			sinal = -1;
			x = 1;
		}
		contInt = 0;
		for(; x < strlen(entrada_str) && valido; x++){
			int p = 0;
			for(y = 48; y <= 57; y++){
				if(entrada_str[x] == y){
					*(entrada_int+contInt) = p;
					contInt++;
					break;
				} else{
					if(y == 57){
						printf("\nEntrada invalida! Informe uma entrada valida: ");
						valido = 0;
						break;
					}
					p++;
				}
			}
		}
		if(valido){
			int multi = 1;
			for(y = 0; y < contInt-1; y++){
				multi = multi * 10;
			}
			for(y = 0; y < contInt; y++){
				retorno += (entrada_int[y] * multi);
				multi /= 10;
				if((retorno < 0 || retorno == valida_retorno) && entrada_int[y] != 0){
					valido = 0;
					printf("-> Entrada ultrapassa o tamanho de um tipo inteiro. Informe uma entrada valida: ");
					break;
				}
				valida_retorno = retorno;
			}
			if(valido)
				retorno = retorno * sinal;
		}
	}while(!valido);
	return retorno;
}
int main(){
    int op;
    int x = 0;
    int ler = 0;
    int* y = NULL;
    FILE* arquivo;
    elemento lista[TAM];
    inicializarLista(lista);
    printf("\nDeseja carregar os ultimos dados salvos? 1 -> SIM | 0 -> NAO: ");
	op = trataEntrada();
	if(op){
		ler = lerDados(lista,arquivo);
		if(!ler){
			printf("\nErro ao carregador dados salvos ou nao existem dados salvos!\n");
		} else{
			printf("\nDados carregados com sucesso!\n");
		}
		system("pause");
	}
    do{
        op = menu();
       	limpatela();
        switch(op){
            case 0:
                criarLista(lista);
                 Escrever(lista,arquivo);
                break;
            case 1:
                inserir(lista);
                 Escrever(lista,arquivo);
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
                 Escrever(lista,arquivo);
                break;
            case 6:
                realloca(lista);
                 Escrever(lista,arquivo);
                break;
            case 7:
                printf("Finalizando o programa\n");
                Escrever(lista,arquivo);
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
