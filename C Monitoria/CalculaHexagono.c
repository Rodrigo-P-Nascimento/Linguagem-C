#include <stdio.h>
#include <math.h>

void CalculaHexagono(float l, float *area, float *perimetro){
    *perimetro = l * 6;
    *area = ((3.0 * pow(l, 2.0)) * sqrt(3)) / 2;
}

int main(void){

    float lado, area = 0, perimetro = 0;

    printf("Digite o lado do hexagono: ");
    scanf("%f", &lado);

    CalculaHexagono(lado, &area, &perimetro);

    printf("Perimetro: %.2f\n", perimetro);
    printf("Area: %.2f\n", area);

    return 0;
}