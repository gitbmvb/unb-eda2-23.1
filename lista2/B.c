#include <stdio.h>
#include <stdlib.h>
#define size (-1 + (1 << 31))

int main(void){
    unsigned int number, min = size, max = 0;
    char * msg = malloc(sizeof(char) * size), letter;
    while(scanf("%d %c", &number, &letter) == 2){
        msg[number] = letter;
        if(number > max) max = number;
        else if (number < min) min = number;
    }
    for(int i = min; i <= max; i++) printf("%c", msg[i]);
    printf("\n");
}