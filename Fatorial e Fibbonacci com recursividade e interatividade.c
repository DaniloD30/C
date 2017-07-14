#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int tmp;
double tempo;
clock_t t0, t1;

int fatorial(int x){
    int resultado=0 ;
    t0 = clock();
    if(x==0){
        x = 1;
        return x;
    }
    else
        resultado = x * fatorial(x-1);

    t1 = clock();
     tempo = (double) (t1-t0) / (CLOCKS_PER_SEC) * 1000;
        printf("Interativo n = tempo em msec %f\n", tempo);


    return resultado;

}
int fat(int x ){

    int f=1;
   t0 = clock();
    for(int i=1;i<=x;i++)
        f *= i;

    t1 = clock();
     tempo = (double) (t1-t0) / (CLOCKS_PER_SEC) * 1000;
    printf("Interativo n =  tempo em msec %f\n", tempo);

    return f;
}

int fibo(int n){
    int a=0;
    int b=1;
    int fib=0;
     t0 = clock();
    for(int i=1;i<n;i++){
    fib = a + b;
    a = b;
    b = fib;
    }
     t1 = clock();
     tempo = (double) (t1-t0) / (CLOCKS_PER_SEC) * 1000;
    printf("Fibbo interativo n =  tempo em msec %f\n", tempo);
    return fib;

}

int f(int n){
    int fibo =0;
    t0 = clock();
    if(n==1||n==2)
        return 1;

    else
        fibo += f(n-1) + f(n-2);

    t1 = clock();
    tempo = (double) (t1-t0) / (CLOCKS_PER_SEC) * 1000;
    printf("Fibbo recursivo n =  tempo em msec %f\n", tempo);

    return fibo;

}
int main(){

    int n ;
    int resultado;

    scanf("%d",&n);

    resultado = fatorial(n);
    printf("Fatorial Recursiva:%d\n",resultado );
    resultado = fat(n);
    printf("Fatorial Interativo :%d\n",resultado );
    resultado = fibo(n);
    printf("Fibo interativo:%d\n",resultado );
    resultado = f(n);
    printf("Fibo Recursiva:%d\n",resultado );

    return 0;

}
