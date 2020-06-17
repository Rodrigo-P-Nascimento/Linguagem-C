#include <stdio.h>

int main(void){
    int raio;
    float area;

    raio = 5;
    area = 3.14 * raio*raio;

    printf("A area do circulo de raio %d tem valor: %.2f", raio, area);

    return 0;
}