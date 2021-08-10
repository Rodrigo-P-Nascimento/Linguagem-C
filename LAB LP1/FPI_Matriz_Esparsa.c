#include <stdio.h>
#define TAM 10  //Definição da constante que é usada no tamanho das matrizes

// Declaração da função EhEsparsa que retorna um valor do ripo float
float EhEsparsa(int mat[TAM][TAM], int largura, int altura){
    int i, j;
    int contZero = 0; //Contador para guardar o número de vezes em que o 0 aparece na matriz

    for(i=0; i < largura; i++){
        for(j=0; j < altura; j++){
            if(mat[i][j] == 0){
                contZero++;
            }
        }
    }
    return (contZero * 100 ) / (largura * altura); //Calculo da porcetagem, na qual o float representa a porcentagem. Ex: 70.0 = 70.0%
}

int main(){

    int lar, alt;
    int i, j;
    int matriz[TAM][TAM];
    float resul;

    scanf("%d %d", &lar, &alt); // Leitura da largura e da altura da matriz, com um maximo de 10 de tamanho

    for(i=0; i < lar; i++){
        for(j=0; j < alt; j++){
            scanf("%d", &matriz[i][j]); 
        }
    }

    resul = EhEsparsa(matriz, lar, alt);

    if(resul <=  70.0){
        puts("A matriz não é esparsa\n");
    }else{
        puts("A matriz é esparsa\n");
    }

    return 0;
}