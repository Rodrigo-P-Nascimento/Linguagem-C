#include <stdio.h>

int main(void){

    int raio;
    float area;

    printf("Digite um valor para o raio do circulo: ");
    scanf("%d", &raio);
    area = 3.14 * raio*raio;

    printf("A area do circulo de raio %d tem valor: %.2f", raio, area);

    return 0;
}