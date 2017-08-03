#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int q1(char *data){

    int datavalida = 0;

    char dia[3],mes[3],ano[5];

    int i,j,k,d=0,a=0,m=0,y=0,v=1;



    for(i=0;data[i]!='/';i++){

        dia[i] = data[i];

          printf("Dia: %c \n",dia[i]);

    }

    dia[i] = '\0';

    for(j = i+1;data[j]!='/';j++){

        mes[y] = data[j];

          printf("Mes: %c \n",mes[y]);

        y++;

    }

    mes[y] = '\0';

    y=0;

    for(k = j+1;data[k]!='\0';k++){

        ano[y] = data[k];

        //printf("y: %d\n",y);

        printf("Ano: %c \n",ano[y]);

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

    printf("Dia: %d  Mes: %d  Ano: %d\n",d,m,a);

    if((d<=31) && (d>0)){
        //printf("Entrou\n");
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
            datavalida = 1;
            v = 1;

        }
    }

    if((d<=30) && (d>0)){
        //printf("Entrou\n");
        if(m==4||m==6||m==9||m==11){

            datavalida = 1;

            v=1;

        }
    }

    if((d==29) && (m == 2)){
        //printf("Entrou\n");
        if((a%4==0 && a%100!=0 )|| (a%400==0 && a%100!=0)){
            datavalida = 1;
            v=1;
            }
    }
    if((d<29) && (m==2)&& (a > 0)){
        datavalida =1;
        v=1;

    }
    if(v==0)
        datavalida = 0;





    if(datavalida)
        return 1;
    else
        return 0;



}

int main(){

    char data[11];

    //char dia[2],mes[2],ano[4];

    //int i,j,k;//d=0,a=0,m=0,y=0,//datavalida=0;

    int valida =0;

    gets(data);

    valida = q1(data);

    printf("%d\n",valida);

    /*

    for(i=0;data[i]!='/';i++){

        dia[i] = data[i];

          //printf("Dia: %c \n",dia[i]);



    }

    for(j = i+1;data[j]!='/';j++){

        mes[y] = data[j];

          //printf("Mes: %c \n",mes[y]);

        y++;

    }

    y=0;

    for(k = j+1;data[k]!='\0';k++){

        ano[y] = data[k];

        //printf("y: %d\n",y);

        //printf("Ano: %c \n",ano[y]);

        y++;

    }

    d = atoi(dia);

    m = atoi(mes);

    a = atoi(ano);



    if(d<=31 && d>0)

        if(m==1||m==3||m==5||m==7||m==8||m==10==||m==12)

             datavalida = 1;

    if(d<=30 && d>0)

        if(m==4||m==6||m==9||m==11)

            datavalida = 1;

    if(d==29 && m==2)

        if(a%4==0 && a%100!=0 || a%400==0 && a%100!=0)

            datavalida = 1;

    if(d<29&& m==2)

        datavalida =1;



    if (datavalida)

        return 1;

    else

        return 0;



*/



   // printf("Dia: %d  Mes: %d  Ano: %d\n",d,m,a);

    return 0;

}
