#include <stdio.h>
#include <math.h>

int ResolveEquacao2Grau(float a, float b, float c, float *x1, float *x2){

    if(a == 0) return -1;

    float delta = b * b - 4 * a* c; 

    if(delta < 0) return -2;

    *x1 = (-b + sqrt(delta)) / (2*a);
    *x2 = (-b - sqrt(delta)) / (2*a);
    return 0;

}

int main(void){

    float a, b, c, raiz1, raiz2;
    int resultado;

    printf("Digite os valores dos coeficientes a, b, e c: ");
    scanf("%f %f %f", &a, &b, &c);

    resultado = ResolveEquacao2Grau(a, b, c, &raiz1, &raiz2);

    if(resultado == 0) printf("Suas raizes sao x1: %.2f x2: %.2f", raiz1, raiz2);

    if(resultado == -1) puts("Nao forma uma equacao do 2 grau.");

    if(resultado == -2) puts("Nao possui raizes reais.");

    return 0;
}