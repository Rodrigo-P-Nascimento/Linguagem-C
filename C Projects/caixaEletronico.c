#include <stdlib.h>
#include <stdio.h>

int main(){
    int quantia, resto, celula;

    printf("Este eh o caixa 23.9 horas, digite a quantia que deseja retirar: R$");
    scanf("%d", &quantia);

    celula = quantia / 100;
    resto = quantia % 100;
    printf("Nota(s) de R$100: %d\n", celula);

    quantia = resto;
    celula =  quantia / 50;
    resto = quantia % 50;
    printf("Nota(s) de R$50: %d\n", celula);

    quantia = resto;
    celula =  quantia / 20;
    resto = quantia % 20;
    printf("Nota(s) de R$20: %d\n", celula);

    quantia = resto;
    celula =  quantia / 10;
    resto = quantia % 10;
    printf("Nota(s) de R$10: %d\n", celula);

    quantia = resto;
    celula =  quantia / 5;
    resto = quantia % 5;
    printf("Nota(s) de R$5: %d\n", celula);

    quantia = resto;
    celula =  quantia / 2;
    resto = quantia % 2;
    printf("Nota(s) de R$2: %d\n", celula);


    return 0;
}