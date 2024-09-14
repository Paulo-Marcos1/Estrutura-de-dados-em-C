#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct{
    int topo;
    int bin[TAM];
    
}pilhavet;
void empilha(int resto, pilhavet *p){
    if(p->topo == TAM-1){
        printf("\n pilha cheia");
        exit(0);
        
    }
    p-> topo++;
    p-> bin[p->topo]=resto;
    
}
int desempilha (pilhavet*p){
    int n;
    if(p->topo<0){
        printf("\n pilha vazia");
        exit(1);
    }
    n = p->bin[p->topo];
    p->topo--;
    return n;
    
}
int main (){
    pilhavet pilha;
    int resto;
    int num;
    pilha.topo =-1;
    printf("digite o valor a ser convertido para binario\n");
    scanf("%d",&num);
    
    while(num>0){
        resto = num%2;
        empilha(resto,&pilha);
        num=num/2;
        
    }
    while(pilha.topo>-1){
        printf("%d",desempilha(&pilha));
        
    }
    return(0);
}
