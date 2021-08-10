#include <stdio.h>
#define TAM 100 // Defini essa constante para facilitar a mudança do limite nas matrizes

//SomaM é do tipo void porque ela não deve retornar nada 
void SomaM(int mat1[TAM][TAM], int mat2[TAM][TAM], int mat3[TAM][TAM], int m , int n){

    int i, j; // são para os contadores, assim como na main

    for(i=0; i < m; i=i+1){
        for(j=0; j < n; j=j+1){
            mat3[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d ", mat3[i][j]);
        }
        puts("");
    }
}

int main(){

    int m, n; // Tamanho das matrizes
    int i, j; //Para o contador
    int mat1[TAM][TAM], mat2[TAM][TAM], mat3[TAM][TAM];

    scanf("%d %d", &m, &n);

    for(i=0; i < m; i = i + 1){
        for(j=0; j < n; j = j + 1){
            scanf("%d", &mat1[i][j]);
        }
    }
    for(i=0; i < m; i++){
        for(j=0; j < n; j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    SomaM(mat1, mat2, mat3, m, n);
    
    return 0;
}