#include <wchar.h>

void parseToWchar(wchar_t* new, const char* string, const int len){
    // Gambiarra do setlocale pq sem essa zorra o código não pega
    setlocale(LC_ALL, "");
    // Só sei que depois do setlocale e dessa função funciona
    mbstowcs(new, string, len);
}

void clearWString(wchar_t* str, const int len){
    // é necessário limpar a string de wchar_t, essa zorra inicia com lixo
    for(int i = 0; i<len; i++)
        str[i] = '\0';
}

int size(const wchar_t* str){
    // código na big hand para recuperar o size da string de wchar_t
    int cont = 0;
    for(int i = 0; str[i]; i++)
        cont++;
    return cont;
}

int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int i;
    int cont;
    int j;
    int qtdOcorrencias = 0;
    int aux = 0;
    int qtdposic = 0;
    
    wchar_t palavra[250];
    wchar_t busca[250];
    
    clearWString(palavra, 250);
    clearWString(busca, 250);
    
    parseToWchar(palavra, strTexto, strlen(strTexto));
    parseToWchar(busca, strBusca, strlen(strBusca));
    
    for(i = 0; palavra[i];i++){
        cont = 0;
        j = 0;
        if(palavra[i] == busca[j]){
            aux = i;
            for(j; busca[j];j++){
                if(palavra[aux] == busca[j]){
                    cont++;
                    aux++;
                }
            }
            if(cont == size(busca)){
                posicoes[qtdposic] = i+1;
                posicoes[qtdposic+1] = i = aux;
                qtdposic+=2;
                qtdOcorrencias++;
            }
        }
    }



    return qtdOcorrencias;
}
