#include <stdio.h>
#include <stdlib.h>
#define M 216091

typedef struct cell {
    int key;
    struct cell * next;
} cell;

int hash(int key){
    return key % size;
}

void insert_hash(cell * v, int n){
    cell * aux;
    for(aux = v[hash(n)].next; aux && aux->key != n; aux = aux->next);
    if(aux) return;
    else{
        aux = malloc(sizeof(cell));
        aux->key = n;
        aux->next = v[hash(n)].next;
        v[hash(n)].next = aux;
    }

}

void search_hash(cell * v, int n){
    cell * aux;
    for(aux = v[hash(n)].next; aux && aux->key != n; aux = aux->next);
    aux ? printf("sim\n") : printf("nao\n");
}

int main(void){
    int N, temp;
    cell * numbers = calloc(size, sizeof(cell));
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        insert_hash(numbers, temp);
    }
    while(scanf("%d", &temp) == 1) search_hash(numbers, temp);
}