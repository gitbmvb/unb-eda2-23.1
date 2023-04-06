#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois (celula *p){
    if(p->prox) {
        int temp = p->prox->dado;
        p->prox = p->prox->prox;
        return temp;
    }
    return p->dado;
}

void remove_elemento (celula *le, int x){
    celula * aux = le, * lixo;
    while(aux->prox){
        if(aux->prox->dado == x) break;
        aux = aux->prox;
    }
    if(aux->prox){
        lixo = aux->prox;
        aux->prox = lixo->prox;
    }
}

void remove_todos_elementos (celula *le, int x){
    celula * aux = le;
    while(aux->prox){
        if(aux->prox->dado == x && aux->prox){
            aux->prox = aux->prox->prox;
        } else aux = aux->prox;
    }
    
}