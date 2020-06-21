#include <stdio.h>

int main(void){

    float diametro, raio, area, perimetro;

    printf("Digite o diametro do circulo: ");
    scanf("%f", &diametro);

    raio = diametro / 2;
    area = 3.14 * (raio * raio);
    perimetro = (2 * 3.14) * raio;

    puts("Esse circulo tem os seguintes valores:");
    printf("Diametro = %.2f", diametro);
    printf("\nPerimetro = %.2f", perimetro);
    printf("\nRaio = %.2f", raio);
    printf("\nArea = %.2f", area);

    return 0;
}