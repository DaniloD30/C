//  ----- Dados do Aluno -----
//  Nome: Danilo Oliveira Dias
//  email: danilolive30@hotmail.com
//  Matrícula: 2016116013
//  Semestre: 2017.1
//  Questão: 07 (Jogo da Velha)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tabuleiro(int tab[][3], int jogador[][3]){
    int x,y;

	// Mostrando tabuleiro
	printf("==================================================\n");
	printf("\t\tJOGO DA VELHA\n");
	printf("==================================================\n\n");
	printf("    1     2     3");
	for( x = 0; x < 3; x++){
		printf("\n%c ", 65 + x);
		for( y = 0; y < 3; y++){
			if(tab[x][y] == 1){
				if(jogador[x][y] == 1){
					printf("__X__");
				} else if(jogador[x][y] == 2){
					printf("__O__");
				}
			} else{
				if(65 + x == 67){
					printf("     ");
				} else{
					printf("_____");
				}
			}
			if(y == 2)
				break;
			printf("|");
		}
	}
}

void escolherPos(int player, int jogador[][3], int tab[][3]){
	int celula_valida = 0, erro = 0,x,y;
	char celula[3];
	while(!celula_valida){
		if(erro){
			system("clear");
			tabuleiro(tab, jogador);
			printf("\n\nCelula ja selecionada ou invalida! Player %d, informe uma outra celula: ", player);
			fflush(stdin);
			fgets(celula, 3, stdin);
		} else{
			system("clear");
			tabuleiro(tab, jogador);
			printf("\n\nPlayer %d, informe a celula desejada: ", player);
			fflush(stdin);
			fgets(celula, 3, stdin);
		}
		erro = 0;
		for(x = 0; x < 3 && !celula_valida && !erro; x++){
			for( y = 0; y < 3; y++){
				if(celula[0] == 65 + x && celula[1] == 49 + y){
					if(tab[x][y] != 1){
						tab[x][y] = 1;
						if(player == 1){
							jogador[x][y] = 1;
							celula_valida = 1;
							break;
						} else if(player == 2){
							jogador[x][y] = 2;
							celula_valida = 1;
							break;
						}
					} else{
						erro = 1;
						break;
					}

				}
				if(x == 2 && y == 2){
					erro = 1;
				}
			}
		}
	}
}

int verifica_vencedor(int jogador[][3]){
	int vencedor_1 = 0, vencedor_2 = 0, vencedor = 0,x,y;
	for( x = 0; x < 3 && !vencedor; x++){
		vencedor_1 = 0;
		vencedor_2 = 0;
		for( y = 0; y < 3; y++){
			if(jogador[x][y] == 1){
				vencedor_1++;
			} else if(jogador[x][y] == 2){
				vencedor_2++;
			}
			if(vencedor_1 == 3){
				return 1;
			} else if(vencedor_2 == 3){
				return 2;
			}
		}
	}
	for( x = 0; x < 3 && !vencedor; x++){
		vencedor_1 = 0;
		vencedor_2 = 0;
		for( y = 0; y < 3; y++){
			if(jogador[y][x] == 1){
				vencedor_1++;
			} else if(jogador[y][x] == 2){
				vencedor_2++;
			}
			if(vencedor_1 == 3){
				return 1;
			} else if(vencedor_2 == 3){
				return 2;
			}
		}
	}
	vencedor_1 = 0;
	vencedor_2 = 0;
	for( x = 0; x < 3 && !vencedor; x++){
			if(jogador[x][x] == 1){
				vencedor_1++;
			} else if(jogador[x][x] == 2){
				vencedor_2++;
			}
			if(vencedor_1 == 3){
				return 1;
			} else if(vencedor_2 == 3){
				return 2;
			}
	}
	vencedor_1 = 0;
	vencedor_2 = 0;
	for( x = 0; x < 3;){
		for( y = 2; y >= 0; y--){
			if(jogador[x][y] == 1){
				vencedor_1++;
			} else if(jogador[x][y] == 2){
				vencedor_2++;
			}
			if(vencedor_1 == 3){
				return 1;
			} else if(vencedor_2 == 3){
				return 2;
			}
			x++;
		}
	}
	return 0;
}

int main(){
	int tab[3][3], jogador[3][3], jogadas = 0, player = 1, vencedor = 0;
	tabuleiro(tab, jogador);

	while(jogadas != 9 || !vencedor){
		if(player == 1){
			escolherPos(player, jogador, tab);
			jogadas++;
			vencedor = verifica_vencedor(jogador);
			player = 2;
		}
		if(vencedor == 1){
			system("clear");
			tabuleiro(tab, jogador);
			printf("\n\nO Player 1 venceu!");
			break;
		}
		if(jogadas == 9){
			system("clear");
			tabuleiro(tab, jogador);
			printf("\n\nNao houve vencedor!");
			break;
		}
		if(player == 2){
			escolherPos(player, jogador, tab);
			vencedor = verifica_vencedor(jogador);
			jogadas++;
			player = 1;
		}
		if(vencedor == 2){
			system("clear");
			tabuleiro(tab, jogador);
			printf("\n\nO Player 2 venceu!");
			break;
		}
		if(jogadas == 9){
			system("clear");
			tabuleiro(tab, jogador);
			printf("\n\nNao houve vencedor!");
			break;
		}
	}
	return 0;
}
