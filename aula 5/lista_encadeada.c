#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct lista
{
    int dado;
    struct lista *link;
}no;

no * crialista(int n){
    no * ini , *p, *ult;
    int valor;
    ini=ult=NULL;
    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor %d da lista:",i+1);
        scanf("%d",&valor);
        p=(no*)malloc(sizeof(no));
        p -> dado = valor;
        p->link = NULL;

        if (ult != NULL)
        {
            ult ->link=p;
        }
        else{
            ini=p;
        }
        ult = p;        
    }
    return ini;
}

void escrevelista(no*p){
    while (p != NULL)
    {
        printf("%d\t", p->dado);
        p = p->link;
    }
}

int main(){
    no*primeira;
    int n;
    printf("Criando uma lista encadeada");
    do{
        printf("\n Entre com o numero de nos:");
        scanf("%d",&n);
    }
    while (n<0);
    {
        primeira = crialista(n);
        if (primeira != NULL)
        {
            printf("\nLista criada!");
            printf("\n");
            escrevelista(primeira);
        }
        else{
            printf("\nLista vazia");
        }
    }
    return 0;
}

