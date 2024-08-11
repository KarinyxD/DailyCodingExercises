#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int x;
    scanf("%d", &x);
    char sentencas[x][15];
    getchar(); // limpar buffer
    
    int i = 0;
    while(i < x){
        fgets(sentencas[i], 15, stdin);
        
        // Remover o caractere de nova linha\n, se presente
        size_t len = strlen(sentencas[i]);
        if (len > 0 && sentencas[i][len - 1] == '\n') {
            sentencas[i][len - 1] = '\0';
        }
        i++;
    }

    i = 0;
    while(i < x){
        if(strcmp(sentencas[i], "P=NP") != 0){
            char *a = strtok(sentencas[i], "+");
            char *b = strtok(NULL, "+");
            
            printf("%d\n", (atoi(a) + atoi(b)));
        }else{
            printf("skipped\n");
        }
        i++;
    }
    return 0;
}