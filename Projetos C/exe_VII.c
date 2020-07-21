#include <stdio.h>
#include <math.h>

/*  Funcao Delta() > Calcula o delta da funcao do segundo grau. 

    entrada: parametros 'a', 'b' e 'c'
    saida: valor do delta do tipo float
*/
float Delta(float a, float b, float c){
    float delta = (b * b) - (4 * a * c);
    return delta;
}
/*  Funcao RaizX1() > Calcula a raiz da funcao do segundo grau. 

    entrada: parametros 'a', 'b' e 'delta'.
    saida: um valor float 
    Neste o valor a ser retornado se refere a X1
*/
float RaizX1(float a, float b, float delta){
    float x1 = (-b + sqrt(delta)) / (2 * a);
    return x1;
}
/*  Funcao RaizX2() > Calcula a raiz da funcao do segundo grau. 

    entrada: parametros 'a', 'b' e 'delta'.
    saida: um valor float 
    Neste o valor a ser retornado se refere a X2
*/
float RaizX2(float a, float b, float delta){
    float x2 = (-b - sqrt(delta)) / (2 * a);
    return x2;
}

int main(void){
    float coeA, coeB, coeC;
    float delta, raizX1, raizX2;

    puts("Digite os valores dos coeficientes da funcao:");
    printf("A: ");
    scanf("%f", &coeA);
    printf("B: ");
    scanf("%f", &coeB);
    printf("C: ");
    scanf("%f", &coeC);

    if(coeA == 0) {
        printf("Os coeficientes nao formam uma equacao do segundo grau.");
        return 1;
    }

    delta = Delta(coeA, coeB, coeC);

    if(delta < 0) {
        printf("As raizes nao puderem ser calculadas, pois o valor de delta eh negativo.");
        return 2;
    }

    raizX1 = RaizX1(coeA, coeB, delta);
    raizX2 = RaizX2(coeA, coeB, delta);

    printf("X1: %.2f\n", raizX1);
    printf("X2: %.2f\n", raizX2);
    
    return 0;
}
