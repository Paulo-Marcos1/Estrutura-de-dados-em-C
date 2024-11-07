#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBinaria {
    int elem;
    struct arvoreBinaria *dir, *esq;
} arvoreBinaria;

arvoreBinaria* insere(arvoreBinaria *a, int el);
arvoreBinaria* remover(arvoreBinaria *a, int el);
void preOrdem(arvoreBinaria *a);
void emOrdem(arvoreBinaria *a);
void posOrdem(arvoreBinaria *a);

int main() {
    arvoreBinaria *raiz = NULL;
    int x;
    char op;

    do {
        fflush(stdin);
        printf("\n1- Inserir\n2- Excluir\n3- PreOrdem\n4- EmOrdem\n5- PosOrdem\n6- Sair ");
        scanf(" %c", &op); // Note the space before %c to skip whitespace
        switch (op) {
            case '1':
                printf("\nValor? ");
                scanf("%d", &x);
                raiz = insere(raiz, x);
                break;
            case '2':
                if (raiz != NULL) {
                    printf("\nDigite um valor: ");
                    scanf("%d", &x);
                    raiz = remover(raiz, x);
                } else {
                    printf("\nÁrvore vazia.\n");
                }
                break;
            case '3':
                printf("Pre ordem: ");
                preOrdem(raiz);
                break;
            case '4':
                printf("Em ordem: ");
                emOrdem(raiz);
                break;
            case '5':
                printf("Pos ordem: ");
                posOrdem(raiz);
                break;
        } // fim switch
    } while (op != '6');

    return 0;
}

arvoreBinaria* insere(arvoreBinaria *a, int el) {
    if (a == NULL) {
        a = (arvoreBinaria*)malloc(sizeof(arvoreBinaria));
        a->elem = el;
        a->esq = NULL;
        a->dir = NULL;
        printf("\nInserido.");
    } else {
        if (el <= a->elem) {
            a->esq = insere(a->esq, el);
        } else {
            a->dir = insere(a->dir, el);
        }
    }
    return a;
}

arvoreBinaria* remover(arvoreBinaria *a, int el) {
    arvoreBinaria *p, *p2;

    if (a == NULL) {
        printf("Elemento não encontrado.\n");
        return NULL;
    }

    if (a->elem == el) {
        if (a->esq == NULL && a->dir == NULL) {
            // remoção de folha
            free(a);
            return NULL;
        } else if (a->esq == NULL) { // filho à direita
            p = a->dir;
            free(a);
            return p;
        } else if (a->dir == NULL) { // filho à esquerda
            p = a->esq;
            free(a);
            return p;
        } else { // tem 2 filhos
            p2 = a->dir;
            p = a->dir;
            while (p->esq != NULL) {
                p = p->esq;
            }
            p->esq = a->esq;
            free(a);
            return p2;
        }
    }

    if (el < a->elem) {
        a->esq = remover(a->esq, el);
    } else {
        a->dir = remover(a->dir, el);
    }

    return a;
}

void preOrdem(arvoreBinaria *a) {
    if (a != NULL) {
        printf("%d ", a->elem);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void emOrdem(arvoreBinaria *a) {
    if (a != NULL) {
        emOrdem(a->esq);
        printf("\n%d ", a->elem);
        emOrdem(a->dir);
    }
}

void posOrdem(arvoreBinaria *a) {
    if (a != NULL) {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("\n%d ", a->elem);
    }
}
