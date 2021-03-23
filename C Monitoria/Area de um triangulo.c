#include <stdio.h>

int main(void){
    int altura, base;
    int area;

    puts("Para cancular a area de um triangulo basta digitar os valores da Altura e da Base.");
    printf("Altura[metros]: ");
    scanf("%d", &altura);
    printf("Base[metros]: ");
    scanf("%d", &base);

    area = (base*altura) / 2;

    printf("A area desse triangulo eh: %d m2.", area);

    return 0;
}