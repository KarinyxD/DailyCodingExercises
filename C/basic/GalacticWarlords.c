//https://judge.beecrowd.com/pt/problems/view/3230
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int srsGuerra, nLinhas;
    scanf(" %d %d", &srsGuerra, &nLinhas);
    float pontosLinha[nLinhas][4];
    for (int i = 0; i < nLinhas; i++){ 
        scanf("%f %f %f %f", &pontosLinha[i][0], &pontosLinha[i][1], &pontosLinha[i][2], &pontosLinha[i][3]);
    }

    //encontrar a equacao de cada reta(coeficiente angular e o b(intercepto com o eixo y))
    float equacao[nLinhas][2];
    for (int i = 0; i < nLinhas; i++){
        //calculo do coeficiente angular
        float deltaY = pontosLinha[i][3] - pontosLinha[i][1];
        float deltaX = pontosLinha[i][2] - pontosLinha[i][0];
        if(deltaX == 0){
            equacao[i][0] = INFINITY;
            equacao[i][1] = pontosLinha[i][0];
        }else{
            float coefAng = (deltaY / deltaX);
            equacao[i][0] = coefAng;
            equacao[i][1] = coefAng * -(pontosLinha[i][0]) + pontosLinha[i][1];
        }
    }
    
    //verificar se tem alguma reta igual a outra
    for(int i = 0; i < nLinhas; i++){
        for (int j = i+1; j < nLinhas; j++){
            if(equacao[i][0] == equacao[j][0] && equacao[i][1] == equacao[j][1]){
                equacao[j][0] = NAN;
                equacao[j][1] = NAN;
            }
        }
    }

    //a cada reta, acrescentamos dois setores infinitos
    int setores = 0;
    for(int i = 0; i < nLinhas; i++){
        if (!isnan(equacao[i][0])){
            setores += 2;
        }
    }
    if ((srsGuerra - setores) >= 0){
       // printf("%d, %d\n", srsGuerra, setores);
        printf("%d\n", (int)ceil((srsGuerra - setores)/2.0));
    }else{
        printf("0\n");
    }

    // Exibir as equações para verificação
   // for (int i = 0; i < nLinhas; i++) {
     //   printf("%s\n", equacao[i]);
    //}
    return 0;
}