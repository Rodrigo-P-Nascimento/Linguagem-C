#include <stdio.h>
#include <math.h>

int main(void){
    float a, b, c;
    float delta, x1, x2;

    puts("Digite os valores para A, B e C.");
    printf("Digite o valor do coeficente a: ");
    scanf("%f", &a);
    printf("Digite o valor do coeficente b: ");
    scanf("%f", &b);
    printf("Digite o valor do coeficente c: ");
    scanf("%f", &c);

    if (a == 0){
        puts("Os valores nao formam uma equacao do segundo grau.");
        return 1;
    }else{
        delta = b*b - 4*a*c;
        if (delta < 0){
            printf("Esta equacao nao possui raizes reais.\n");
            return 2;
        }else{
            x1 = (-b + sqrt(delta)) / (2*a);
            x2 = (-b - sqrt(delta)) / (2*a);
            printf("x1 = %.1f, x2 = %.1f\n", x1, x2);
        }
    }
    return 0;
}