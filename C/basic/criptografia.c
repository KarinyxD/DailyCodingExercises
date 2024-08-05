/* https://judge.beecrowd.com/pt/problems/view/2852 */
#include <stdio.h>
 
int main() {
    /* definindo a matriz */
    char matriz[26][26];
    for (int i = 0; i < 26; i++){
        char letra = 'a' + i;
        for(int j = 0; j < 26; j++){
            matriz[i][j] = letra;
            if(letra == 'z'){letra = 'a';}
            else{letra = letra + 1;}
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}