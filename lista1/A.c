#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le){
    le = le->prox;
    while(le){
        printf("%d -> ", le->dado);
        le = le->prox;
    }
    printf("NULL\n");
}


void imprime_rec (celula *le){
    if(!le->prox){
        printf("NULL\n"); return;
    }else{
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }    
}