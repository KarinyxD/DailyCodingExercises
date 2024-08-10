/*Dado a posição inicial de um cavalo em um tabuleiro de xadrez e a posição destino, 
deve se dizer se, com exatamente um único movimento, o cavalo consegue alcançar a 
posição destino. Se isso for possível, o movimento é classificado como válido, caso 
contrário, o movimento é dito inválido.
A entrada é composta por uma única linha contendo a posição inicial do cavalo e a posição destino.
A saída consiste em uma linha contendo a mensagem "VALIDO" caso o movimento seja um movimento válido 
de um cavalo no jogo de xadrez ou "INVALIDO" caso contrário.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    char posicao[3];
    char destino[3];

    scanf("%s %s", posicao, destino);

    /*verifica se a letra esta (1 posicao acima ou abaixo) e a numeracao
    esta (2 posicoes a direita ou a esquerda)*/
    if((posicao[0] + 1 == destino[0] || posicao[0] - 1 == destino[0]) && 
    (posicao[1] + 2 == destino[1] || posicao[1] - 2 == destino[1])){
        printf("VALIDO\n");
    }
    /*verifica se a letra esta (2 posicoes acima ou abaixo) e a numeracao
    esta (1 posicao a direita ou a esquerda)*/
    else if ((posicao[0] + 2 == destino[0] || posicao[0] - 2 == destino[0]) && 
    (posicao[1] + 1 == destino[1] || posicao[1] - 1 == destino[1])){
        printf("VALIDO\n");
    }
    //senao cumprir nenhuma das condicoes acima, o movimento eh invalido
    else{
        printf("INVALIDO\n");
    }

    return 0;
}