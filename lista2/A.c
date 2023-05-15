#include <stdio.h>
#include <stdlib.h>
#define size 1001

int main(void){
    int N, temp, max = 0;
    scanf("%d", &N);
    int * numbers = calloc(size, sizeof(int));
    for(int i = 0; i < N; i++){
        scanf("%d", &temp);
        numbers[temp]++;
    }
    max = numbers[0];
    for(int i = size - 1; i >= 0; i--){
        if(numbers[i] > numbers[max]) max = i;
    }
    printf("%d\n", max);
}