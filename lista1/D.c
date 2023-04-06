#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


celula *busca (celula *le, int x){
    celula * aux = le->prox;
    while(aux){
        if(aux->dado == x) break;
        aux = aux->prox;
    }
    return aux;
}

celula *busca_rec (celula *le, int x){
    if(!le->prox) return NULL;
    return le->prox->dado == x ? le->prox : busca_rec(le->prox, x);
}