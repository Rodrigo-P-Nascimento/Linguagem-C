#include <stdio.h>
#include <stdlib.h>

int main(void){
    float numero_1, numero_2;

    printf("Digite dois numeros para ser feita a analise deles.\nN1: ");
    scanf("%f", &numero_1);
    printf("N2: ");
    scanf("%f", &numero_2);

    if (numero_1 == numero_2){
        puts("Os dois numeros sao iguas!");
    }else{
        if (numero_1 > numero_2)
            printf("O maior dentre eles eh o primeiro numero %.2f", numero_1);
        if (numero_1 < numero_2)
            printf("O maior dentre eles eh o segundo numero %.2f", numero_2);
    }

    return 0;
}