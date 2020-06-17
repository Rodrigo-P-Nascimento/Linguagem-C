#include <stdio.h>

int main(void){

    float altura, comprimento, rendimento, volume;
    float nlatas, area, red_area;

    printf("Para que o programa possa lhe informar o numero de latas para a sua pintura, informe as seguintes informacoes:\n");
    printf("A altura(metros): ");
    scanf("%f", &altura);
    
    printf("O comprimento(metros): ");
    scanf("%f", &comprimento);

    printf("O rendimento(em m2/L): ");
    scanf("%f", &rendimento);

    printf("O volume de cada lata(em Litros): ");
    scanf("%f", &volume);

    area = altura*comprimento;
    red_area = area/rendimento;
    nlatas = red_area/volume;
    
    printf("A parede tem cerca de %.2f metros quadrados de area.\n", area);
    printf("O numero de latas para a pintura e de: %.2f", nlatas);

    return 0;
}