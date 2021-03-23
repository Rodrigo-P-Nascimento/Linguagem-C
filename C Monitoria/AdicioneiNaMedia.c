#include <stdio.h>

double AdicioneNaMedia(double valor){
    static double soma = 0;
    static int quantidade = 0;

    soma += valor;
    quantidade++;

    return soma/quantidade;
}

int main(void){
    int q;
    double a, media;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &q);

    while(q--){
        printf("Digite um valor: ");
        scanf("%lf", &a);
        media = AdicioneNaMedia(a);
        printf("Media ate agora: %.2lf\n", media);
    }

    return 0;
