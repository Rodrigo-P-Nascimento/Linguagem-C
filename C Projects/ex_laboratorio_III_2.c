#include <stdio.h>

int main(void){

    int x, y, z;
    int soma, produto;
    float media;

    puts("Digite os valores de X, Y e Z");
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);
    printf("Z: ");
    scanf("%d", &z);

    soma = x+y+z;
    produto = x*y*z;
    media = soma /3;

    printf("SOMA = %d", soma);
    printf("\nPRODUTO = %d", produto);
    printf("\nMEDIA = %.2f", media);

    return 0;
}