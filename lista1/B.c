#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula * nova = malloc(sizeof(celula));
    nova->dado = x;
    if(!le->prox) le->prox = nova;
    else {
        nova->prox = le->prox;
        le->prox = nova;
    }
}

void insere_antes (celula *le, int x, int y){
    celula * aux = le, * nova = malloc(sizeof(celula));
    nova->dado = x;
    while(aux->prox){
        if(aux->prox->dado == y) break;
        aux = aux->prox;
    }
    nova->prox = aux->prox;
    aux->prox = nova;
}