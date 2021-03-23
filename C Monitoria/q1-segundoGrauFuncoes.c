#include <stdio.h>
#include <math.h>

double Delta(double a, double b, double c){
    return b*b - 4*a*c;
}

double RaizX1(double a, double b, double delta){
    if (a == 0 || delta < 0){
        /* Nesses dois casos o programa executaria uma operacao ilegal,
        dividindo por zero ou raiz de um numero negativo. Entao,
        preventivamente, retornamos a contante NAN (Not a Number) para
        indicar ao programador */
        return NAN;
    }
    return (-b + sqrt(delta)) / (2*a);
}

double RaizX2(double a, double b, double delta){
    if (a == 0 || delta < 0){
        /* Nesses dois casos o programa executaria uma operacao ilegal,
        dividindo por zero ou raiz de um numero negativo. Entao,
        preventivamente, retornamos a contante NAN (Not a Number) para
        indicar ao programador */
        return NAN;
    }
    return (-b - sqrt(delta)) / (2*a);
}


int main(void){
    double a, b, c, delta, x1, x2;

    printf("Digite os coeficientes a, b e c da equacao: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0){
        printf("Os coeficientes nao formam uma equacao do segundo grau (a = 0).\n");
        return 1;
    }

    delta = Delta(a, b, c); /* aqui, mesmo as variaveis dos parametros reais
                               terem o mesmo nome que dos parametros formais
                               eles sao espacos e variaveis diferentes na
                               memoria */

    if (delta < 0){
        printf("A equacao informada nao possui raizes reais (delta < 0).\n");
        return 0;
    }

    x1 = RaizX1(a, b, delta);
    x2 = RaizX2(a, b, delta);

    printf("As raizes da equacao sao:\n\tx1: %.2lf\n\tx2: %.2lf\n", x1, x2);


    return 0;
}
