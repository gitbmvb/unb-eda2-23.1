#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula * l3p = l3;
    while(l1->prox && l2->prox){
        if(l1->prox->dado <= l2->prox->dado){
            l3p->prox = l1->prox; l1->prox = l1->prox->prox;
        } else{
            l3p->prox = l2->prox; l2->prox = l2->prox->prox;
        }
        l3p = l3p->prox;
    }
    while(l1->prox){
        l3p->prox = l1->prox; l1->prox = l1->prox->prox;
        l3p = l3p->prox;
    }
    while(l2->prox){
        l3p->prox = l2->prox; l2->prox = l2->prox->prox;
        l3p = l3p->prox;
    }
}