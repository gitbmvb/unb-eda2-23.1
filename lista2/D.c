#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 101

char * words[size];

int hash(char * key, int len){
    int r = 0;
    for(int i = 0; i < len; ++i) r += (key[i] * (i + 1)) % size;
    return (19 * r) % size;
}

int main(void){
    int t, lines, pos, test, len, total;
    char string[30];
    scanf("%d", &t);
    while(t--){
        total = 0;
        scanf("%d", &lines);
        for(int i = 0; i < lines; i++) words[i] = NULL;
        while(lines--){
            scanf("%s", string);
            len = strlen(&string[4]);

            if(string[0] == 'A'){
                test = 1;
                for(int j = 0; j < 20; ++j){
                    pos = (hash(&string[4], len) + j*j + 23*j) % size;
                    if(words[pos] != NULL && strcmp(&string[4], words[pos]) == 0){
                        test = 0;
                        break;
                    }
                }
                if(test){
                    for(int j = 0; j < 20; ++j){
                        pos = (hash(&string[4], len) + j*j + 23*j) % size;
                        if(words[pos] == NULL){
                            words[pos] = malloc(sizeof(char) * (len+1));
                            strcpy(words[pos], &string[4]);
                            total++;
                            break;
                        }
                    }
                }
            } else if(string[0] == 'D'){
                for(int j = 0; j < 20; ++j){
                    pos = (hash(&string[4], len) + j*j + 23*j) % size;
                    if(words[pos] != NULL && strcmp(words[pos], &string[4]) == 0){
                        free(words[pos]);
                        words[pos] = NULL;
                        total--;
                        break;
                    }
                }
            }
        }
        printf("%d\n", total);
        for(int i = 0; i < size; ++i){
            if(words[i] != NULL) printf("%d:%s\n", i, words[i]);
        }
    }
}