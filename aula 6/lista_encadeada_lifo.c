#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct lista{
    int dado;
    struct lista*link;
}no;

no *criarlista(int n){
    no *topo, *p;
    int valor;
    topo = NULL;
    
    for(int i=1; i<=n; i++){
        printf("Digite o valor %d da pilha:",i);
        scanf("%d",&valor);
        
        p=(no*)malloc(sizeof(no));
        p-> dado=valor;
        p->link = topo;
        topo = p;
    }
    return topo;
}

void escrevelista(no*p){
    while (p!=NULL){
        printf("%d\t",p->dado);
        p = p->link;
    }
    printf("\n");
}

int main(){
    no *primeira;
    int n;
    printf("Criando uma pilha\n");
    
    do{
        printf("\nEntre com o numero de nos: ");
        scanf("%d",&n);
    }while(n < 0);
        primeira = criarlista(n);
        if(primeira != NULL){
            printf("\nPilha criada\n");
            escrevelista(primeira);
        }
        else{
            printf("\nPilha vazia\n");
        }
    return 0;
}
